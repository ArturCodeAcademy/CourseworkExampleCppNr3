#include "Maze.h"

string Maze::ToString(bool spaces)
{
    string* lines = new string[height * 3];

    for (int i = 0, li = 0; i < height; i++, li += 3)
        for (int j = 0; j < width; j++)
        {
            string cellStr = cells[i][j].ToString();
            if (start.x == j && start.y == i)
                cellStr[5] = START;
            if (end.x == j && end.y == i)
                cellStr[5] = END;

            lines[li] += string({ cellStr[0], cellStr[1], cellStr[2] }) + (spaces ? " " : "");
            lines[li + 1] += string({ cellStr[4], cellStr[5], cellStr[6] }) + (spaces ? " " : "");
            lines[li + 2] += string({ cellStr[8], cellStr[9], cellStr[10] }) + (spaces ? " " : "");
        }

    string mazeStr = "";
    for (int i = 0; i < height * 3; i++)
    {
        mazeStr += lines[i] + "\n";

        if (spaces && (i + 1) % 3 == 0)
            mazeStr += "\n";
    }
    delete[] lines;
    return mazeStr;
}
