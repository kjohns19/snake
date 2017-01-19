#include <game_state_play.hpp>
#include <game_state_die.hpp>
#include <grid.hpp>
#include <snake.hpp>
#include <game.hpp>
#include <map>
#include <iostream>

std::unique_ptr<GameState> GameStatePlay::handleInput(
        Game& game,
        sf::Keyboard::Key key)
{
    static std::map<sf::Keyboard::Key, Direction> directions{
        { sf::Keyboard::Left,  Direction::LEFT },
        { sf::Keyboard::Right, Direction::RIGHT },
        { sf::Keyboard::Up,    Direction::UP },
        { sf::Keyboard::Down,  Direction::DOWN },
    };
    auto search = directions.find(key);
    if (search != directions.end())
    {
        Direction dir = search->second;
        game.snake().turn(dir);
    }
    return std::make_unique<GameStatePlay>();
}

std::unique_ptr<GameState> GameStatePlay::step(Game& game)
{
    auto& snake = game.snake();
    auto& grid  = game.grid();
    if (!snake.move())
    {
        std::cout << "DEAD! Score: " << snake.length() << std::endl;
        return std::make_unique<GameStateDie>();
    }

    Cell& atHead = grid[snake.location()];
    if (atHead.hasFood())
    {
        atHead.hasFood(false);
        snake.grow(3);
        grid.addFood(1);
    }
    return std::make_unique<GameStatePlay>();
}
