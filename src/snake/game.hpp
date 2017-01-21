#ifndef INCLUDED_SNAKE_GAME_HPP
#define INCLUDED_SNAKE_GAME_HPP

#include <snake/grid.hpp>
#include <snake/snake.hpp>
#include <snake/display.hpp>
#include <snake/game_state.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <memory>

namespace snake {

class Game
{
public:
    Game();

    void loop();

    void reset();
    void exit();

    Grid& grid() { return d_grid; }
    const Grid& grid() const { return d_grid; }

    Snake& snake() { return d_snake; }
    const Snake& snake() const { return d_snake; }

    void setState(std::unique_ptr<GameState> state);
private:
    void pollEvents(std::vector<sf::Event>* events);

    sf::RenderWindow d_window;
    Grid d_grid;
    Snake d_snake;
    Display d_display;
    std::unique_ptr<GameState> d_state;
    bool d_exited;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_GAME_HPP
