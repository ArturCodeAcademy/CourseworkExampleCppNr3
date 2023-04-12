#include "WalkerBase.h"

void WalkerBase::NextStep()
{
    Direction dir = TakeStep();
    Coord nextPos = pos;
    switch (dir)
    {
    case UpDir:
        nextPos += Coord::UP;
        if (!maze.CoordExists(nextPos) || maze.GetCell(pos)->HasBorder(Border::Bottom))
            return;
        break;
    case DownDir:
        nextPos += Coord::DOWN;
        if (!maze.CoordExists(nextPos) || maze.GetCell(pos)->HasBorder(Border::Top))
            return;
        break;
    case LeftDir:
        nextPos += Coord::LEFT;
        if (!maze.CoordExists(nextPos) || maze.GetCell(pos)->HasBorder(Border::Left))
            return;
        break;
    case RightDir:
        nextPos += Coord::RIGHT;
        if (!maze.CoordExists(nextPos) || maze.GetCell(pos)->HasBorder(Border::Right))
            return;
        break;
    default:
        return;
    }

    if (path.size() > 0 && nextPos == *path.rbegin())
        path.pop_back();
    else
        path.push_back(pos);
    pos = nextPos;
}

string WalkerBase::ToString()
{
    string* lines = new string[maze.GetHeight() * 3];
    string walkerStr;

    stringstream ss = stringstream{ maze.ToString() };
    int i = 0;
    for (string line; getline(ss, line, '\n'); i++)
        lines[i] = line;

    if (path.size() > 0)
    {
        list<Coord> fullPath;
        for (Coord p : path)
            fullPath.push_back(Coord(p.x * 3 + 1, p.y * 3 + 1));
        fullPath = GetFullPath(fullPath, Coord(pos.x * 3 + 1, pos.y * 3 + 1));
        Coord start = maze.GetStart() * 3 + Coord(1, 1);
        for (Coord p : fullPath)
        {
            if (p != start)
                lines[p.y][p.x] = PATH;
        }
    }
    lines[pos.y * 3 + 1][pos.x * 3 + 1] = WALKER;

    for (int i = 0; i < maze.GetHeight() * 3; i++)
        walkerStr += lines[i] + "\n";

    return walkerStr;
}

list<Coord> WalkerBase::GetFullPath(list<Coord> coords, Coord current)
{
    coords.push_back(current);
    list<Coord>::iterator it = coords.begin(), nextIt = it;
    nextIt++;
    while (nextIt != coords.end())
    {
        if (nextIt == coords.end())
            break;

        Coord next;
        if (it->x > nextIt->x)
            next = *it + Coord::LEFT;
        if (it->x < nextIt->x)
            next = *it + Coord::RIGHT;
        if (it->y > nextIt->y)
            next = *it + Coord::DOWN;
        if (it->y < nextIt->y)
            next = *it + Coord::UP;

        auto newIt = it;
        newIt++;
        coords.insert(newIt, next);
        it++;
        if (*it == *nextIt)
            it = nextIt++;
    }
    return coords;
}
