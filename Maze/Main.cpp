#include <iostream>
#include <map>
#include <windows.h>

#include "SimpleMazeCreator.h"
#include "KeyboardWalker.h"

using namespace std;

void ColorPrint(string text, map<char, int> colors)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    map<char, int>::iterator it;
    for (char ch : text)
    {
        it = colors.find(ch);
        if (it != colors.end())
            SetConsoleTextAttribute(h, it->second);
        else
            SetConsoleTextAttribute(h, 30);

        cout << ch;
    }
    SetConsoleTextAttribute(h, 30);
}

int main()
{
    srand(time(NULL));
    map<char, int> colors = 
    {
        {Maze::START, 31},
        {Maze::END, 32},
        {WalkerBase::PATH, 240},
        {WalkerBase::WALKER, 15},
        {Cell::WALL, 128},
        {Cell::WHITE_SPACE, 255},
    };
    int x = 5, y = 5;
    cout << "Select maze size (x, y): ";
    cin >> x >> y;

    Coord end(rand() % x, rand() % y);
    Maze maze = SimpleMazeCreator().Create(x, y, end);
    KeyboardWalker walker(maze);

    while (true)
    {
        ColorPrint(walker.ToString(), colors);
        walker.NextStep();
        system("cls");
    }
}
