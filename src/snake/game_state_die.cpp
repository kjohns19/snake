#include <snake/game_state_die.hpp>
#include <snake/game_state_play.hpp>
#include <snake/snake.hpp>
#include <snake/game.hpp>

namespace snake {

std::unique_ptr<GameState> GameStateDie::handleInput(
        Game& game,
        sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Space)
    {
        game.reset();
        return std::make_unique<GameStatePlay>();
    }
    return std::make_unique<GameStateDie>();
}

std::unique_ptr<GameState> GameStateDie::step(Game& game)
{
    if (game.snake().die())
    {
        game.reset();
        return std::make_unique<GameStatePlay>();
    }
    return std::make_unique<GameStateDie>();
}

} // close namespace snake
