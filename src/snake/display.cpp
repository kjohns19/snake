#include <snake/display.hpp>
#include <snake/grid.hpp>
#include <SFML/Graphics.hpp>

namespace snake {

Display::Display(int cellSize)
: d_cellSize(cellSize) {}

void Display::display(const Grid& grid, sf::RenderTarget& target)
{
    float cellSize = d_cellSize;
    sf::RectangleShape cellRect;
    cellRect.setOutlineColor(sf::Color::Black);
    cellRect.setOutlineThickness(-2.0f);
    cellRect.setSize({cellSize, cellSize});

    for(auto& cell: grid)
    {
        auto& loc = cell.location();
        cellRect.setPosition({loc.x()*cellSize, loc.y()*cellSize});
        if (cell.hasSnake())
            cellRect.setFillColor(sf::Color::Blue);
        else if (cell.hasFood())
            cellRect.setFillColor(sf::Color::Red);
        else
            cellRect.setFillColor(sf::Color::White);
        target.draw(cellRect);
    }
}

} // close namespace snake

