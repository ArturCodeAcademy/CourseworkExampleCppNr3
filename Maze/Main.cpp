#include <iostream>
#include <map>
#include <windows.h>

#include "SimpleMazeCreator.h"
#include "KeyboardWalker.h"
#include "Walker3D.h"

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

    int x, y;
    cout << "Select maze size (x, y): ";
    cin >> x >> y;

    Coord end(rand() % x, rand() % y);
    Maze maze = SimpleMazeCreator().Create(x, y, end);

	int selection;
	cout << "3D (1) or 2D (2): ";
	cin >> selection;

	if (selection == 1)
	{

		Walker3D walker(maze.ToWstring(), maze.GetStart().y * 3 + 1, maze.GetStart().x * 3 + 1, maze.GetWidth() * 3, maze.GetHeight() * 3 + 1);

		while (true)
		{
			walker.Control();
			walker.Draw();
		}
	}
	else
	{
		KeyboardWalker walker(maze);

		while (true)
		{
			ColorPrint(walker.ToString(), colors);
			walker.NextStep();
			system("cls");
		}
	}
}
