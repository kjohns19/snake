#include <game_state_die.hpp>
#include <game_state_play.hpp>
#include <snake.hpp>
#include <game.hpp>

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
