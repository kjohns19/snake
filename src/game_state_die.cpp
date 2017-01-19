#include <game_state_die.hpp>
#include <game_state_play.hpp>
#include <grid.hpp>
#include <snake.hpp>
#include <game.hpp>

std::unique_ptr<GameState> GameStateDie::handleInput(
        Snake& snake,
        sf::Keyboard::Key key)
{
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
