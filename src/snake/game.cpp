#include <snake/game.hpp>
#include <snake/game_state_new.hpp>
#include <SFML/Window/Event.hpp>

namespace snake {

namespace {

constexpr int windowWidth  = 800;
constexpr int windowHeight = 800;

constexpr int gameWidth = 20;
constexpr int gameHeight = 20;
constexpr int stepInterval = 6;

constexpr int startSize = 3;
constexpr int startX = gameWidth/2;
constexpr int startY = gameHeight/2;
constexpr int foodCount = 5;

constexpr int cellSize = 40;

} // close anonymous namespace

Game::Game()
: d_window(sf::VideoMode(windowWidth, windowHeight), "Snake")
, d_grid(gameWidth, gameHeight)
, d_snake(d_grid, {startX, startY}, startSize)
, d_display(cellSize)
, d_state(std::make_unique<GameStateNew>())
, d_exited(false)
{
    d_window.setFramerateLimit(60);
    d_grid.addFood(foodCount);
}

void Game::loop()
{
    int step = 0;

    std::vector<sf::Event> events;
    while(d_window.isOpen())
    {
        pollEvents(&events);

        if (d_exited)
            break;

        if (++step == stepInterval)
        {
            d_state->processEvents(*this, events);
            d_state->step(*this);
            step = 0;
            events.clear();
        }

        d_window.clear();
        d_display.display(d_grid, d_window);
        d_window.display();
    }
}

void Game::reset()
{
    d_grid.reset();
    d_snake.reset({startX, startY}, startSize);
    d_grid.addFood(foodCount);
}

void Game::exit()
{
    d_window.close();
    d_exited = true;
}

void Game::setState(std::unique_ptr<GameState> state)
{
    d_state = std::move(state);
}

void Game::pollEvents(std::vector<sf::Event>* events)
{
    sf::Event event;
    while(d_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            exit();
            break;
        }
        else if (event.type == sf::Event::KeyPressed)
            events->push_back(event);
    }
}

} // close namespace snake

