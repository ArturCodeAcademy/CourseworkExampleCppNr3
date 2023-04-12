#pragma once

#include <conio.h>

#include "WalkerBase.h"

class KeyboardWalker : public WalkerBase
{
private:
    Direction lastDirection = UpDir;

public:
    inline KeyboardWalker(Maze& maze) : WalkerBase(maze) {}

protected:

    Direction TakeStep() override;
};