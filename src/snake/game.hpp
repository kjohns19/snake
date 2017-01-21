#ifndef INCLUDED_SNAKE_GAME_HPP
#define INCLUDED_SNAKE_GAME_HPP

#include <snake/grid.hpp>
#include <snake/snake.hpp>
#include <snake/game_state.hpp>

#include <SFML/Window/Keyboard.hpp>

#include <memory>

namespace sf { class RenderTarget; }

namespace snake {

class Game
{
public:
    Game(int width, int height, const Location& startPos, int startSize);

    void handleInput(sf::Keyboard::Key key);
    void step();
    void draw(sf::RenderTarget& target) const;

    void reset();

    Grid& grid() { return d_grid; }
    const Grid& grid() const { return d_grid; }

    Snake& snake() { return d_snake; }
    const Snake& snake() const { return d_snake; }
private:
    Grid d_grid;
    Snake d_snake;
    Location d_startPos;
    int d_startSize;
    std::unique_ptr<GameState> d_gameState;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_GAME_HPP
