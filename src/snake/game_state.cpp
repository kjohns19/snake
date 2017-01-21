#include <snake/game_state.hpp>
#include <SFML/Window/Event.hpp>

namespace snake {

void GameState::processEvents(Game& game, const std::vector<sf::Event>& events)
{
    for(auto& event: events)
        processEvent(game, event);
}

} // close namespace snake

