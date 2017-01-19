#include <game.hpp>
#include <game_state_play.hpp>
#include <SFML/Graphics.hpp>

Game::Game(int width, int height, const Location& startPos, int startSize)
: d_grid(width, height)
, d_snake(d_grid, startPos, startSize)
, d_startPos(startPos)
, d_startSize(startSize)
, d_gameState(std::make_unique<GameStatePlay>())
{
    reset();
}

void Game::handleInput(sf::Keyboard::Key key)
{
    d_gameState = d_gameState->handleInput(d_snake, key);
}

void Game::step()
{
    d_gameState = d_gameState->step(*this);
}

void Game::draw(sf::RenderTarget& target) const
{
    float cellSize = 40.0f;
    sf::RectangleShape cellRect;
    cellRect.setOutlineColor(sf::Color::Black);
    cellRect.setOutlineThickness(-2.0f);
    cellRect.setSize({cellSize, cellSize});

    for(auto& cell: d_grid)
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

void Game::reset()
{
    for(auto& cell: d_grid)
    {
        cell.hasSnake(false);
        cell.hasFood(false);
    }
    d_snake.reset(d_startPos, d_startSize);
    d_grid.addFood(5);
}
