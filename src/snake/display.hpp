#ifndef INCLUDED_SNAKE_DISPLAY_HPP
#define INCLUDED_SNAKE_DISPLAY_HPP

namespace sf { class RenderTarget; }

namespace snake {

class Grid;

class Display
{
public:
    Display(int cellSize);

    void display(const Grid& grid, sf::RenderTarget& target);
private:
    int d_cellSize;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_DISPLAY_HPP
