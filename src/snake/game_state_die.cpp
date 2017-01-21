#include <snake/game_state_die.hpp>
#include <snake/game_state_new.hpp>
#include <snake/snake.hpp>
#include <snake/game.hpp>

#include <SFML/Window/Event.hpp>

namespace snake {

namespace {

void resetGame(Game& game);

} // close anonymous namespace

void GameStateDie::processEvent(Game& game, const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return;

    if (event.key.code == sf::Keyboard::Space)
        resetGame(game);
}

void GameStateDie::step(Game& game)
{
    if (game.snake().die())
        resetGame(game);
}

namespace {

void resetGame(Game& game)
{
    game.reset();
    game.setState(std::make_unique<GameStateNew>());
}

} // close anonymous namespace

} // close namespace snake
