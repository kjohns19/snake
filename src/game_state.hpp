#ifndef INCLUDED_GAME_STATE_HPP
#define INCLUDED_GAME_STATE_HPP

#include <SFML/Window/Keyboard.hpp>
#include <memory>

class Snake;
class Game;

class GameState
{
public:
    virtual std::unique_ptr<GameState> handleInput(
            Snake& snake,
            sf::Keyboard::Key key) = 0;
    virtual std::unique_ptr<GameState> step(Game& game) = 0;
};

#endif // INCLUDED_GAME_STATE_HPP
