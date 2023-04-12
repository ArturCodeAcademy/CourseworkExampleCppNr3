#pragma once

#include <stack>

#include "Maze.h"
#include "MazeCreatorBase.h"

class SimpleMazeCreator : public MazeCreatorBase
{
public:

    Maze Create(int width, int height, Coord end) const override;
};