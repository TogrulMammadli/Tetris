#pragma once
#include <limits.h>
#include<conio.h>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include<MMSystem.h>
#include <mciapi.h>
using namespace std;
enum Controls
{
	LEFT = 75,
	RIGH = 77,
	Restart = 114, //R
	Pause = 112, //P
	Rotate = 72, //Up
	Acceleration = 80, //Down
	Enter = 13, //Enter
	Save = 115 //S

};
typedef enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
}ConsoleColor;
void set_color(ConsoleColor backgound_text_color, ConsoleColor text_color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((backgound_text_color << 4) | text_color));
}
void my_set_cursor(int y, int x)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords = {};
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(h, coords);
}
void Without_Cursor() {
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}

//vse figuri vvide 1 i 0 v massive
int arr_LT[4][4] = { 1,1,0,0,  1,1,0,0,  0,0,0,0,  0,0,0,0 };
int arr_I[4][4] = { 1,0,0,0,  1,0,0,0,  1,0,0,0,  1,0,0,0 };
int arr_I2[4][4] = { 1,1,1,1,  0,0,0,0,  0,0,0,0,  0,0,0,0 };
int arr_F[4][4] = { 1,1,0,0,  1,0,0,0,  1,0,0,0,  0,0,0,0 };
int arr_F2[4][4] = { 1,1,1,0,  1,0,0,0,  0,0,0,0,  0,0,0,0 };
int arr_F3[4][4] = { 0,1,0,0,  0,1,0,0,  1,1,0,0,  0,0,0,0 };
int arr_F4[4][4] = { 1,0,0,0,  1,1,1,0,  0,0,0,0,  0,0,0,0 };
int arr_7[4][4] = { 1,1,0,0,  0,1,0,0,  0,1,0,0,  0,0,0,0 };
int arr_72[4][4] = { 0,0,1,0,  1,1,1,0,  0,0,0,0,  0,0,0,0 };
int arr_73[4][4] = { 1,0,0,0,  1,0,0,0,  1,1,0,0,  0,0,0,0 };
int arr_74[4][4] = { 1,1,1,0,  1,0,0,0,  0,0,0,0,  0,0,0,0 };
int arr_z[4][4] = { 1,1,0,0,  0,1,1,0,  0,0,0,0,  0,0,0,0 };
int arr_z2[4][4] = { 0,1,0,0,  1,1,0,0,  1,0,0,0,  0,0,0,0 };
int arr_s[4][4] = { 0,1,1,0,  1,1,0,0,  0,0,0,0,  0,0,0,0 };
int arr_s2[4][4] = { 1,0,0,0,  1,1,0,0,  0,1,0,0,  0,0,0,0 };
int arr_T[4][4] = { 1,1,1,0,  0,1,0,0,  0,0,0,0,  0,0,0,0 };
int arr_T2[4][4] = { 1,0,0,0,  1,1,0,0,  1,0,0,0,  0,0,0,0 };
int arr_T3[4][4] = { 0,1,0,0,  1,1,1,0,  0,0,0,0,  0,0,0,0 };
int arr_T4[4][4] = { 0,1,0,0,  1,1,0,0,  0,1,0,0,  0,0,0,0 };