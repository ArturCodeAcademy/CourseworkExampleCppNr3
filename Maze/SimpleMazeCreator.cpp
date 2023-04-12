#include "SimpleMazeCreator.h"

Maze SimpleMazeCreator::Create(int width, int height, Coord end) const
{
    Maze maze(width, height);
    Coord* start = nullptr;
    bool** walked = new bool* [width];
    for (int i = 0; i < width; i++)
        walked[i] = new bool[height];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            walked[i][j] = false;

    stack<Coord> path;
    path.push(end);
    walked[end.x][end.y] = true;

    // Add first direction
    vector<Coord> v;
    Coord nextCell;

    do
    {
        v = GetNeghbours(path.top(), width, height);
        if (v.size() == 0)
        {
            if (start == nullptr)
                start = new Coord(path.top().x, path.top().y);
            path.pop();
            continue;
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (!walked[v[i].x][v[i].y])
            {
                nextCell = v[i];
                break;
            }

            if (i + 1 == v.size())
            {
                if (start == nullptr)
                    start = new Coord(path.top().x, path.top().y);
                path.pop();
                goto continueWhile;
            }
        }

        walked[nextCell.x][nextCell.y] = true;
        MakeTransition(maze, path.top(), nextCell);
        path.push(nextCell);

    continueWhile:;
    } while (path.top() != end);

    maze.SetStart(Coord(start->x, start->y));
    maze.SetEnd(end);

    for (int i = 0; i < width; i++)
        delete[] walked[i];
    delete[] walked;
    delete start;

    return maze;
}
