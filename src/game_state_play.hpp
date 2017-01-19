#ifndef INCLUDED_GAME_STATE_PLAY_HPP
#define INCLUDED_GAME_STATE_PLAY_HPP

#include <game_state.hpp>

class GameStatePlay : public GameState
{
public:
    virtual std::unique_ptr<GameState> handleInput(
            Snake& snake,
            sf::Keyboard::Key key) override;
    virtual std::unique_ptr<GameState> step(Game& game) override;
};

#endif // INCLUDED_GAME_STATE_PLAY_HPP
