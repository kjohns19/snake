#ifndef INCLUDED_SNAKE_GAME_STATE_HPP
#define INCLUDED_SNAKE_GAME_STATE_HPP

#include <vector>

namespace sf { class Event; }

namespace snake {

class Game;

class GameState
{
public:
    virtual ~GameState() {}
    void processEvents(Game& game, const std::vector<sf::Event>& events);
    virtual void processEvent(Game& game, const sf::Event& event) = 0;
    virtual void step(Game& game) = 0;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_GAME_STATE_HPP
