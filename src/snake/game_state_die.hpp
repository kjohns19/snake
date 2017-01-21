#ifndef INCLUDED_SNAKE_GAME_STATE_DIE_HPP
#define INCLUDED_SNAKE_GAME_STATE_DIE_HPP

#include <snake/game_state.hpp>

namespace snake {

class GameStateDie : public GameState
{
public:
    virtual std::unique_ptr<GameState> handleInput(
            Game& game,
            sf::Keyboard::Key key) override;
    virtual std::unique_ptr<GameState> step(Game& game) override;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_GAME_STATE_DIE_HPP
