#include <kj/random.hpp>
#include <SFML/Graphics.hpp>
#include <grid.hpp>
#include <snake.hpp>
#include <iostream>
#include <map>

void drawGrid(const Grid& grid, sf::RenderTarget& target);

void addFood(Grid& grid, int amount);

void reset(Grid& grid, Snake& snake);

int main(int argc, char* argv[])
{
    const int width = 800;
    const int height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML Template");
    window.setFramerateLimit(60);

    Grid grid(20, 20);
    Snake snake(grid, {10, 10});

    int every = 10;
    bool dead = false;

    reset(grid, snake);

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
                    snake.turn(dir);
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && dead)
                {
                    reset(grid, snake);
                    dead = false;
                }
            }
        }

        if (!dead && --every == 0)
        {
            if (!snake.move())
            {
                std::cout << "DEAD!" << std::endl;
                dead = true;
            }
            else
            {
                Cell& atHead = grid[snake.location()];
                if (atHead.hasFood())
                {
                    atHead.hasFood(false);
                    snake.grow(3);
                    addFood(grid, 1);
                }
            }
            every = 10;
        }

        window.clear(sf::Color::White);
        drawGrid(grid, window);
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
    for(int i = 0; i < amount; i++)
    {
        Cell* cell;
        do
        {
            Location loc(random(0, grid.width()-1), random(0, grid.height()-1));
            cell = &grid[loc];
        }
        while(cell->hasFood() || cell->hasSnake());
        cell->hasFood(true);
    }
}

void reset(Grid& grid, Snake& snake)
{
    for(auto& cell: grid)
    {
        cell.hasSnake(false);
        cell.hasFood(false);
    }
    snake.reset({10, 10});
    addFood(grid, 5);
}
