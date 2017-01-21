#include <snake/grid.hpp>
#include <kj/random.hpp>
#include <cassert>

namespace snake {

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

void Grid::addFood(int amount)
{
    static kj::Random<int> random;
    std::vector<Cell*> validCells;
    for(auto& cell: *this)
    {
        if (!cell.hasFood() && !cell.hasSnake())
            validCells.push_back(&cell);
    }
    int maxSize = validCells.size();
    for(int i = 0; i < amount && i < maxSize; i++)
    {
        Cell& cell = *validCells[random(0, maxSize-1)];
        cell.hasFood(true);
        std::swap(validCells[i], validCells[maxSize-1]);
        maxSize--;
    }
}

void Grid::reset()
{
    for(auto& cell: d_cells)
    {
        cell.hasFood(false);
        cell.hasSnake(false);
    }
}

} // close namespace snake
