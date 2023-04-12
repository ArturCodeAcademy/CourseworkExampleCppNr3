#include "Cell.h"

Cell::Cell(Border borders) : borders(borders) {}

bool Cell::HasBorder(Border border)
{
    return border == (border & borders);
}

string Cell::ToString()
{
    if (borders == Border::All)
        return  string({ WALL, WALL, WALL, '\n', WALL, WALL, WALL, '\n', WALL, WALL, WALL });

    string cellStr = { WALL };                                // TL
    cellStr += borders & Border::Top ? WALL : WHITE_SPACE;    // TC
    cellStr += WALL;                                          // TR
    cellStr += '\n';
    cellStr += borders & Border::Left ? WALL : WHITE_SPACE;   // CL
    cellStr += WHITE_SPACE;                                   // CC
    cellStr += borders & Border::Right ? WALL : WHITE_SPACE;  // CR
    cellStr += '\n';
    cellStr += WALL;                                          // BL
    cellStr += borders & Border::Bottom ? WALL : WHITE_SPACE; // BC
    cellStr += WALL;                                          // BR

    return cellStr;
}
