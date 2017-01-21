#ifndef INCLUDED_SNAKE_GRID_HPP
#define INCLUDED_SNAKE_GRID_HPP

#include <snake/location.hpp>
#include <snake/cell.hpp>

#include <vector>

namespace snake {

class Grid
{
public:
    Grid(int width, int height);

    bool hasLocation(const Location& location) const;
    int width() const { return d_width; }
    int height() const { return d_height; }

    Cell& operator[](const Location& location);
    const Cell& operator[](const Location& location) const;

    void addFood(int amount=1);

    using iterator = std::vector<Cell>::iterator;
    using const_iterator = std::vector<Cell>::const_iterator;

    iterator begin() { return d_cells.begin(); }
    iterator end() { return d_cells.end(); }

    const_iterator begin() const { return d_cells.begin(); }
    const_iterator end() const { return d_cells.end(); }
private:
    int index(const Location& location) const;

    std::vector<Cell> d_cells;
    int d_width;
    int d_height;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_GRID_HPP
