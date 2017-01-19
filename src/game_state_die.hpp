#ifndef INCLUDED_GAME_STATE_DIE_HPP
#define INCLUDED_GAME_STATE_DIE_HPP

#include <game_state.hpp>

class GameStateDie : public GameState
{
public:
    virtual std::unique_ptr<GameState> handleInput(
            Game& game,
            sf::Keyboard::Key key) override;
    virtual std::unique_ptr<GameState> step(Game& game) override;
};

#endif // INCLUDED_GAME_STATE_DIE_HPP
