#pragma once

#include "Coord.h"
#include "Cell.h"

class Maze
{
public:
    static const char START = 'S';
    static const char END = 'E';

protected:
    Coord start;
    Coord end;
    int width;
    int height;
    Cell** cells;

public:

    Maze(int width, int height) : width(width), height(height), start(0, 0), end(0, 0)
    {
        cells = new Cell * [height];
        for (int i = 0; i < height; i++)
            cells[i] = new Cell[width];
    }

    ~Maze()
    {
        for (int i = 0; i < height; i++)
            delete[] cells[i];
        delete[] cells;
    }

    inline void SetStart(Coord start)
    {
        this->start = start;
    }

    inline void SetEnd(Coord end)
    {
        this->end = end;
    }

    inline Coord GetStart()
    {
        return start;
    }

    inline Coord GetEnd()
    {
        return end;
    }

    inline Cell* GetCell(Coord c)
    {
        return cells[c.y] + c.x;
    }
    
    inline Cell* GetCell(int x, int y)
    {
        return cells[y] + x;
    }

    inline int GetHeight()
    {
        return height;
    }

    inline int GetWidth()
    {
        return width;
    }

    inline bool CoordExists(Coord c)
    {
        return c.x >= 0 && c.x < width&& c.y >= 0 && c.y <= height;
    }

    string ToString(bool spaces = false);
};