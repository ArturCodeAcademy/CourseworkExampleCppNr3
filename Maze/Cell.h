#pragma once

#include <string>

#include "Border.h"

using namespace std;

class Cell
{
public:
    static const char WALL = '#';
    static const char WHITE_SPACE = ' ';
    Border borders;

public:

    Cell(Border borders = All);

    bool HasBorder(Border border);

    string ToString();
};