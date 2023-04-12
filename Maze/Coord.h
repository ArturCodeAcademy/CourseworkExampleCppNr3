#pragma once

class Coord
{
public:
    static const Coord UP;
    static const Coord RIGHT;
    static const Coord DOWN;
    static const Coord LEFT;

    int x, y;

    inline Coord(int x = 0, int y = 0) : x(x), y(y) {}

    inline Coord operator +(Coord c)
    {
        return Coord(x + c.x, y + c.y);
    }

    inline Coord operator -(Coord c)
    {
        return Coord(x - c.x, y - c.y);
    }

    inline Coord operator *(int c)
    {
        return Coord(x * c, y * c);
    }

    inline Coord operator /(int c)
    {
        return Coord(x / c, y / c);
    }

    inline Coord operator +=(Coord c)
    {
        x += c.x;
        y += c.y;
        return *this;
    }

    inline Coord operator -=(Coord c)
    {
        x -= c.x;
        y -= c.y;
        return *this;
    }

    inline bool operator ==(Coord c)
    {
        return x == c.x && y == c.y;
    }

    inline bool operator !=(Coord c)
    {
        return !(*this == c);
    }
};