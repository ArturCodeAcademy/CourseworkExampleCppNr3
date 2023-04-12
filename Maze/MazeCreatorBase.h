#pragma once

#include <vector>
#include <algorithm>

#include "Maze.h"

class MazeCreatorBase
{
public:

    virtual Maze Create(int width, int height, Coord end) const = 0;

protected:
    vector<Coord> GetNeghbours(Coord c, int width, int height) const;

    void MakeTransition(Maze& maze, Coord from, Coord to) const;
};