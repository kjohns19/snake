#ifndef INCLUDED_GAME_STATE_HPP
#define INCLUDED_GAME_STATE_HPP

#include <SFML/Window/Keyboard.hpp>
#include <memory>

class Game;

class GameState
{
public:
    virtual std::unique_ptr<GameState> handleInput(
            Game& game,
            sf::Keyboard::Key key) = 0;
    virtual std::unique_ptr<GameState> step(Game& game) = 0;
};

#endif // INCLUDED_GAME_STATE_HPP
