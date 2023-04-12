#pragma once

#include <list>
#include <sstream>

#include "Coord.h"
#include "Maze.h"
#include "Direction.h"

class WalkerBase
{
public:
    static const char WALKER = 'W';
    static const char PATH = '*';

private:
    list<Coord> path;
    Maze maze;
    Coord pos;

public:

    inline WalkerBase(Maze& maze) : maze(maze)
    {
        pos = maze.GetStart();
    }

    void NextStep();

    string ToString();

protected:
    virtual Direction TakeStep() = 0;

private:
    list<Coord> GetFullPath(list<Coord> coords, Coord current);
};