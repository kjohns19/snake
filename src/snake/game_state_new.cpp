#include <snake/game_state_new.hpp>
#include <snake/game_state_play.hpp>
#include <snake/game.hpp>

namespace snake {

GameStateNew::GameStateNew()
: d_time(5) {}

void GameStateNew::processEvent(Game& game, const sf::Event& event)
{
    // Do nothing
}

void GameStateNew::step(Game& game)
{
    if (--d_time == 0)
        game.setState(std::make_unique<GameStatePlay>());
}

} // close namespace snake

