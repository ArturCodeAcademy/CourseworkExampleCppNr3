#include "MazeCreatorBase.h"

vector<Coord> MazeCreatorBase::GetNeghbours(Coord c, int width, int height) const
{
    vector<Coord> coords;
    if (c.x - 1 >= 0)
        coords.push_back(c + Coord::LEFT);
    if (c.x + 1 < width)
        coords.push_back(c + Coord::RIGHT);

    if (c.y - 1 >= 0)
        coords.push_back(c + Coord::DOWN);
    if (c.y + 1 < height)
        coords.push_back(c + Coord::UP);

    random_shuffle(coords.begin(), coords.end());
    return coords;
}

void MazeCreatorBase::MakeTransition(Maze& maze, Coord from, Coord to) const
{
    Border* fb = &maze.GetCell(from.x, from.y)->borders;
    Border* tb = &maze.GetCell(to.x, to.y)->borders;

    if (from.x < to.x)
    {
        *fb = (Border)(~Right & *fb);
        *tb = (Border)(~Left & *tb);
        return;
    }

    if (from.x > to.x)
    {
        *fb = (Border)(~Left & *fb);
        *tb = (Border)(~Right & *tb);
        return;
    }

    if (from.y < to.y)
    {
        *fb = (Border)(~Bottom & *fb);
        *tb = (Border)(~Top & *tb);
        return;
    }

    if (from.y > to.y)
    {
        *fb = (Border)(~Top & *fb);
        *tb = (Border)(~Bottom & *tb);
        return;
    }
}
