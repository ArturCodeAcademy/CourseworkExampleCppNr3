#include "KeyboardWalker.h"

Direction KeyboardWalker::TakeStep()
{
    switch (_getch())
    {
    case 's':
        lastDirection = UpDir;
        break;
    case 'a':
        lastDirection = LeftDir;
        break;
    case 'w':
        lastDirection = DownDir;
        break;
    case 'd':
        lastDirection = RightDir;
        break;
    }

    return lastDirection;
}