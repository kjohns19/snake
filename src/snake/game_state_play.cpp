#include <snake/game_state_play.hpp>
#include <snake/game_state_die.hpp>
#include <snake/grid.hpp>
#include <snake/snake.hpp>
#include <snake/game.hpp>
#include <SFML/Window/Event.hpp>
#include <map>
#include <iostream>

namespace snake {

void GameStatePlay::processEvent(Game& game, const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return;
    
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
        game.snake().turn(dir);
    }
}

void GameStatePlay::step(Game& game)
{
    auto& snake = game.snake();
    auto& grid  = game.grid();
    if (!snake.move())
    {
        std::cout << "DEAD! Score: " << snake.length() << std::endl;
        game.setState(std::make_unique<GameStateDie>());
    }

    Cell& atHead = grid[snake.location()];
    if (atHead.hasFood())
    {
        atHead.hasFood(false);
        snake.grow(3);
        grid.addFood(1);
    }
}

} // close namespace snake
