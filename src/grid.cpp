#include <grid.hpp>
#include <cassert>

Grid::Grid(int width, int height)
: d_cells(width*height)
, d_width(width)
, d_height(height)
{
    int i = 0;
    for(int y = 0; y < d_height; y++)
        for(int x = 0; x < d_width; x++)
            d_cells[i++].location().set(x, y);
}

bool Grid::hasLocation(const Location& location) const
{
    return location.x() >= 0 && location.x() < d_width &&
           location.y() >= 0 && location.y() < d_height;
}

Cell& Grid::operator[](const Location& location)
{
    assert(hasLocation(location));
    return d_cells[index(location)];
}
const Cell& Grid::operator[](const Location& location) const
{
    assert(hasLocation(location));
    return d_cells[index(location)];
}

int Grid::index(const Location& location) const
{
    return d_width*location.y() + location.x();
}
