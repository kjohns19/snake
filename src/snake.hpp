#ifndef INCLUDED_SNAKE_HPP
#define INCLUDED_SNAKE_HPP

#include <location.hpp>
#include <deque>
#include <queue>

class Grid;

class Snake
{
public:
    Snake(Grid& grid, const Location& location);

    void reset(const Location& location);

    void turn(Direction direction);

    bool move();

    void grow(int amount=1);

    const Location& location() const;
private:
    Grid& d_grid;
    Direction d_direction;
    std::deque<Direction> d_nextDirections;
    std::deque<Location> d_locations;
};

#endif // INCLUDED_SNAKE_HPP
