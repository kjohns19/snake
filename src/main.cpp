#include <kj/random.hpp>
#include <SFML/Graphics.hpp>
#include <game.hpp>
#include <iostream>
#include <map>

int main(int argc, char* argv[])
{
    const int width = 800;
    const int height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "Snake");
    window.setFramerateLimit(60);

    Game game(20, 20, {10, 10}, 3);

    int interval = 8;
    int step = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
                game.handleInput(event.key.code);
        }

        if (step++ == interval)
        {
            game.step();
            step = 0;
        }

        window.clear(sf::Color::White);
        game.draw(window);
        window.display();
    }
    return 0;
}
