#ifndef INCLUDED_SNAKE_CELL_HPP
#define INCLUDED_SNAKE_CELL_HPP

#include <snake/location.hpp>

namespace snake {

class Cell
{
public:
    Cell()
    : d_location()
    , d_hasSnake(false)
    , d_hasFood(false) {}

    Location& location() { return d_location; }
    const Location& location() const { return d_location; }

    bool hasSnake() const { return d_hasSnake; }
    void hasSnake(bool has) { d_hasSnake = has; }

    bool hasFood() const { return d_hasFood; }
    void hasFood(bool has) { d_hasFood = has; }
private:
    Location d_location;
    bool d_hasSnake;
    bool d_hasFood;
};

} // close namespace snake

#endif // INCLUDED_SNAKE_CELL_HPP
