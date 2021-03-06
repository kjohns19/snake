#ifndef INCLUDED_SNAKE_GAME_STATE_DIE_HPP
#define INCLUDED_SNAKE_GAME_STATE_DIE_HPP

#include <snake/game_state.hpp>

namespace snake {

class GameStateDie : public GameState
{
public:
    virtual void processEvent(Game& game, const sf::Event& event) override;
    virtual void step(Game& game) override;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_GAME_STATE_DIE_HPP
