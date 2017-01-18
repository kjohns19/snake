#include <location.hpp>

Location::Location()
: d_x(0)
, d_y(0) {}
Location::Location(int x, int y)
: d_x(x)
, d_y(y) {}

void Location::moveInDirection(Direction dir, int amount)
{
    static constexpr int xAmounts[] = { 0, 1, 0, -1 };
    static constexpr int yAmounts[] = { -1, 0, 1, 0 };
    int dirValue = static_cast<int>(dir);
    translate(xAmounts[dirValue]*amount, yAmounts[dirValue]*amount);
}

Location Location::inDirection(Direction dir, int amount) const
{
    auto copy = *this;
    copy.moveInDirection(dir, amount);
    return copy;
}

void Location::translate(int xAmount, int yAmount)
{
    d_x += xAmount;
    d_y += yAmount;
}

Location Location::translated(int xAmount, int yAmount) const
{
    auto copy = *this;
    copy.translate(xAmount, yAmount);
    return copy;
}


bool operator==(const Location& l1, const Location& l2)
{
    return l1.x() == l2.x() && l1.y() == l2.y();
}

bool operator!=(const Location& l1, const Location& l2)
{
    return !(l1 == l2);
}
