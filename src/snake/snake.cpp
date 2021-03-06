#include <snake/snake.hpp>
#include <snake/grid.hpp>
#include <cassert>

namespace snake {

Snake::Snake(Grid& grid, const Location& location, int startSize)
: d_grid(grid)
, d_direction(Direction::LEFT)
, d_locations(startSize, location)
{
    d_grid[d_locations.back()].hasSnake(true);
}

void Snake::reset(const Location& location, int startSize)
{
    d_nextDirections.clear();
    d_locations.clear();
    d_locations.assign(startSize, location);
    d_grid[d_locations.back()].hasSnake(true);
    d_direction = Direction::LEFT;
}

void Snake::turn(Direction direction)
{
    // Don't add duplicates
    if (!d_nextDirections.empty() && d_nextDirections.back() == direction)
        return;

    // Limit the number of next directions
    if (d_nextDirections.size() < 3)
        d_nextDirections.push_back(direction);
}

bool Snake::move()
{
    assert(!d_locations.empty());

    if (!d_nextDirections.empty())
    {
        auto nextDir = d_nextDirections.front();
        d_nextDirections.pop_front();

        int dirValue = static_cast<int>(nextDir);
        int curValue = static_cast<int>(d_direction);
        if (d_locations.size() > 1 && dirValue % 2 == curValue % 2)
            {} // Can't turn around if size > 1
        else
            d_direction = nextDir;
    }

    Location head = d_locations.back();
    head.moveInDirection(d_direction);

    if (!d_grid.hasLocation(head))
        return false;

    Cell& headCell = d_grid[head];
    if (headCell.hasSnake())
        return false;

    headCell.hasSnake(true);

    d_locations.push_back(head);

    auto oldTail = d_locations.front();
    d_locations.pop_front();
    if (oldTail != d_locations.front())
        d_grid[oldTail].hasSnake(false);
    return true;
}

void Snake::grow(int amount)
{
    for(int i = 0; i < amount; i++)
        d_locations.push_front(d_locations.front());
}

bool Snake::die()
{
    if (d_locations.empty())
        return true;
    auto front = d_locations.front();
    auto back  = d_locations.back();
    d_locations.pop_front();
    if (!d_locations.empty())
        d_locations.pop_back();
    d_grid[front].hasSnake(false);
    d_grid[back ].hasSnake(false);
    return false;
}

const Location& Snake::location() const
{
    return d_locations.back();
}

} // close namespace snake
