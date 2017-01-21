#ifndef INCLUDED_SNAKE_GAME_STATE_NEW_HPP
#define INCLUDED_SNAKE_GAME_STATE_NEW_HPP

#include <snake/game_state.hpp>

namespace snake {

class GameStateNew : public GameState
{
public:
    GameStateNew();

    virtual void processEvent(Game& game, const sf::Event& event) override;
    virtual void step(Game& game) override;
private:
    int d_time;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_GAME_STATE_NEW_HPP
