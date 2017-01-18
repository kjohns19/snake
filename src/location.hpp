#ifndef INCLUDED_LOCATION_HPP
#define INCLUDED_LOCATION_HPP

enum class Direction { UP, RIGHT, DOWN, LEFT };

class Location
{
public:
    Location();
    Location(int x, int y);

    int x() const { return d_x; }
    int y() const { return d_y; }

    void x(int x) { d_x = x; }
    void y(int y) { d_y = y; }

    void moveInDirection(Direction dir, int amount=1);
    Location inDirection(Direction dir, int amount=1) const;

    void set(int x, int y) { d_x = x; d_y = y; }

    void translate(int xAmount, int yAmount);
    Location translated(int xAmount, int yAmount) const;
private:
    int d_x;
    int d_y;
};

bool operator==(const Location& l1, const Location& l2);
bool operator!=(const Location& l1, const Location& l2);

#endif // INCLUDED_LOCATION_HPP
