#pragma once

#include <chrono>
#include <windows.h>

#include "SimpleMazeCreator.h"
#include "KeyboardWalker.h"

using namespace chrono;

class Walker3D
{
private:
	int nScreenWidth = 120;			// Console Screen Size X (columns)
	int nScreenHeight = 40;			// Console Screen Size Y (rows)
	int nMapWidth;				    // World Dimensions
	int nMapHeight;

	float fPlayerX;			        // Player Start Position
	float fPlayerY;
	float fPlayerA = 0.0f;			// Player Start Rotation
	float fFOV;	                    // Field of View
	float fDepth = 16.0f;			// Maximum rendering distance
	float fSpeed = 5.0f;			// Walking Speed

	wstring map;

	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten = 0;
	float fElapsedTime = 0;

	system_clock::time_point tp1 = chrono::system_clock::now();
	system_clock::time_point tp2 = chrono::system_clock::now();

public:
	inline Walker3D(wstring map, float playerX, float playerY, int mapWidth, int mapHeight, float fov = 3.14159f / 4.0f)
		: map(map), fPlayerX(playerX), fPlayerY(playerY), nMapWidth(mapWidth), nMapHeight(mapHeight), fFOV(fov)
	{
		screen = new wchar_t[nScreenWidth * nScreenHeight];
		hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);

	}

	inline ~Walker3D()
	{
		delete screen;
	}

	void Control();
	void Draw();
};