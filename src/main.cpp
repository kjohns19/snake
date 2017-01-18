#include <kj/random.hpp>
#include <SFML/Graphics.hpp>
#include <grid.hpp>
#include <snake.hpp>
#include <iostream>
#include <map>

struct Game
{
    Game(int width, int height, const Location& snakeLocation)
    : grid(width, height)
    , snake(grid, snakeLocation) {}

    Grid grid;
    Snake snake;
};

void drawGrid(const Grid& grid, sf::RenderTarget& target);

void addFood(Grid& grid, int amount);

void reset(Game& game);

int main(int argc, char* argv[])
{
    const int width = 800;
    const int height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML Template");
    window.setFramerateLimit(60);

    Game game(20, 20, {10, 10});

    int every = 10;
    bool dead = false;

    reset(game);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                static std::map<sf::Keyboard::Key, Direction> directions{
                    { sf::Keyboard::Left,  Direction::LEFT },
                    { sf::Keyboard::Right, Direction::RIGHT },
                    { sf::Keyboard::Up,    Direction::UP },
                    { sf::Keyboard::Down,  Direction::DOWN },
                };
                auto search = directions.find(event.key.code);
                if (search != directions.end())
                {
                    Direction dir = search->second;
                    game.snake.turn(dir);
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && dead)
                {
                    reset(game);
                    dead = false;
                }
            }
        }

        if (!dead && --every == 0)
        {
            if (!game.snake.move())
            {
                std::cout << "DEAD!" << std::endl;
                dead = true;
            }
            else
            {
                Cell& atHead = game.grid[game.snake.location()];
                if (atHead.hasFood())
                {
                    atHead.hasFood(false);
                    game.snake.grow(3);
                    addFood(game.grid, 1);
                }
            }
            every = 10;
        }

        window.clear(sf::Color::White);
        drawGrid(game.grid, window);
        window.display();
    }

    return 0;
}

void drawGrid(const Grid& grid, sf::RenderTarget& target)
{
    float cellSize = 40.0f;
    sf::RectangleShape cellRect;
    cellRect.setOutlineColor(sf::Color::Black);
    cellRect.setOutlineThickness(-2.0f);
    cellRect.setSize({cellSize, cellSize});

    for(auto& cell: grid)
    {
        auto& loc = cell.location();
        cellRect.setPosition({loc.x()*cellSize, loc.y()*cellSize});
        if (cell.hasSnake())
            cellRect.setFillColor(sf::Color::Blue);
        else if (cell.hasFood())
            cellRect.setFillColor(sf::Color::Red);
        else
            cellRect.setFillColor(sf::Color::White);
        target.draw(cellRect);
    }
}

void addFood(Grid& grid, int amount)
{
    static kj::Random<int> random;
    std::vector<Cell*> validCells;
    for(auto& cell: grid)
    {
        if (!cell.hasFood() && !cell.hasSnake())
            validCells.push_back(&cell);
    }
    int maxSize = validCells.size();
    for(int i = 0; i < amount && i < maxSize; i++)
    {
        Cell& cell = *validCells[random(0, maxSize-1)];
        cell.hasFood(true);
        std::swap(validCells[i], validCells[maxSize-1]);
        maxSize--;
    }
}

void reset(Game& game)
{
    for(auto& cell: game.grid)
    {
        cell.hasSnake(false);
        cell.hasFood(false);
    }
    game.snake.reset({10, 10});
    addFood(game.grid, 5);
}
