#pragma once
#include"Libraries.h"

bool ValidGameOver();
void ArrayLoad();
void PrintSave();
void ClearLine(int x);
bool ValidLine(int x);
int Score = 0;
int lvl = 0;
bool gameover = true;
int mainsleep = 300;
struct Point
{
	int x;
	int y;
};

struct Figure//t,k kajdaya figura sostoit iz 4x kubikov ya sdelal massiv point ctob dalje ne pisat kajdiy raz sstolko pointov vrucnuyu a progonat v cikle
{
	Point point[4];
};

void FigureClear(Figure figure, bool Moving);
Figure Game_Information(Figure figure);
bool Valid(Figure figure);
void ArrayRestore();
bool ValidSide(Figure figure, int koef);

Figure currfiqure;//figura kotoraya 

const int Height = 20;
const int Width = 10;
int Array[Height + 1][Width + 2] = { 0 };

int sleep = 300;


Point moving;




void  console_resolution(int X, int Y)//sjimaet konsol iz pramougolnoy formi v kvadrat
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 2;
	cfi.dwFontSize.X = X;
	cfi.dwFontSize.Y = Y;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	ArrayRestore();
}

Figure Game_Information(Figure figure) {//vivodit na ekran  

	for (int i = 0; i < 4; i++)
	{
		figure.point[i].x += 5;
		figure.point[i].y += 13;
		my_set_cursor(figure.point[i].x, figure.point[i].y);
		cout << char(219);
	}

	set_color(ConsoleColor::Blue, ConsoleColor::Yellow);
	my_set_cursor(1, 12);
	cout << "Score:";
	my_set_cursor(2, 12);
	cout << Score;
	my_set_cursor(3, 12);
	cout << "Next:\n";
	my_set_cursor(10, 12);
	cout << "LVL:\n";
	my_set_cursor(11, 12);
	cout << lvl;

	return figure;
}

void print_field(int height, int width, int gameMode) {//risuet pole
	set_color(ConsoleColor::Blue, ConsoleColor::LightGreen);
	int lateral_field = 7;
	width = width + lateral_field + 2;
	for (int i = 0; i < height + 2; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((i > 0 && i < (height + 1)) && (j > 0 && j < (width - 1) && (j != width - lateral_field - 1)))
			{
				cout << " ";
			}
			else
			{
				cout << (char)(178);
			}
		}
		cout << endl;

	}

	if (gameMode == 1)//esli game mod raven 1 to nacinaetsa novaya igra
		ArrayRestore();
	else if (gameMode == 2)//esli raven 2 to risuetsa soxranennoe pole
		ArrayLoad();
}

Figure Filling(int arr[][4])//ctobi bilo legce predstavlaem strukturu cerez matricu 
{
	Figure figure;
	for (int i = 0, index = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 1)
			{
				figure.point[index].x = i;
				figure.point[index].y = j;
				index++;
			}
		}
	}
	return figure;
}

void Input() {//upravlenie
	char button_code;
	{
		button_code = 0;

		while (_kbhit())
		{
			button_code = _getch();
		}

		if (button_code == Controls::Restart)
		{

			system("cls");
			ArrayRestore();
			print_field(Height, Width, 1);
		}
		else if (button_code == Controls::RIGH)
		{
			if (ValidSide(currfiqure, 1))
			{
				FigureClear(currfiqure, true);
				moving.y++;
			}
		}
		else if (button_code == Controls::LEFT)
		{
			if (ValidSide(currfiqure, -1))
			{
				FigureClear(currfiqure, true);
				moving.y--;
			}
		}

		else if (button_code == Controls::Pause)
		{
			while (true)
			{
				if (_getch() == Controls::Pause)
					break;
			}
		}

		else if (button_code == Controls::Save)
		{
			//zapis v fayl
			const int size = (Height + 1)*(Width + 2) + 1+3;
			FILE * save = fopen("save.txt", "w");
			int array[size] = {};
			int i = 0;
				for (int j = 0; j < Height + 1; j++)
				{
					for (int m = 0; m < Width + 2; m++)
					{
						array[i] = Array[j][m];
						i++;
					}
				}
				array[i] = Score;
				i++;
				array[i] = mainsleep;
				i++;
				array[i] = lvl;

			
			if (save != NULL) {
				fwrite(array, sizeof(int), size, save);
				
				fclose(save);
				save = NULL;
			}
			
			Sleep(2000);
		}
		else if (button_code == Controls::Acceleration)
		{
			sleep = 50;
		}
		else if (button_code == Controls::Rotate)
		{
			Figure fiq;
			for (int i = 0; i < 4; i++)
			{
				int x = currfiqure.point[i].x;
				int y = currfiqure.point[i].y;

				fiq.point[i].x = 3 - y;
				fiq.point[i].y = x;
			}
			if (Valid(fiq) && ValidSide(fiq, 1))
			{
				currfiqure = fiq;
			}
		}
	}

}

bool MoveFigure(Figure figure) 
{
	Score += 5;
	int lvl_old = lvl;
	lvl = Score / 150;
	if (lvl > lvl_old&& mainsleep > 100)
	{
		mainsleep -= 50;
	}
	sleep = mainsleep;

	currfiqure = figure;
	moving.x = 0;
	moving.y = Width / 2;
	while (true)
	{
		if (Valid(currfiqure))
		{
			for (int j = 0; j < 4; j++)
			{
				int x = moving.x + currfiqure.point[j].x;
				int y = moving.y + currfiqure.point[j].y;
				my_set_cursor(x, y);
				cout << char(219);
			}
			Sleep(sleep);
			FigureClear(currfiqure, true);
			Input();
			moving.x++;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int x = moving.x + currfiqure.point[i].x - 1;
				int y = moving.y + currfiqure.point[i].y;
				my_set_cursor(x, y);
				cout << char(219);
				Array[x - 1][y] = 1;
			}
			break;
		}
	}
	if (ValidGameOver())
		return false;

	for (int i = 0; i < Height; i++)
	{
		if (ValidLine(i))
		{
			Score += 10;
			ClearLine(i);
		}
	}
	sleep = mainsleep;
	return true;
}

void FigureClear(Figure figure, bool Moving)//t.k pri system("cls") ujasno morgala konsol ya vrucnuyu zapisivay probel pri spuske figur
{
	int x;
	int y;
	for (int i = 0; i < 4; i++)
	{
		if (Moving) {
			x = moving.x + figure.point[i].x;
			y = moving.y + figure.point[i].y;
		}
		else
		{
			x = figure.point[i].x;
			y = figure.point[i].y;
		}

		my_set_cursor(x, y);
		cout << " ";
	}

}

bool Valid(Figure figure)
{
	for (int j = 0; j < 4; j++)
	{
		int x = moving.x + figure.point[j].x;
		int y = moving.y + figure.point[j].y;

		if (x > 0 && Array[x - 1][y] == 1)
			return false;
	}
	return true;
}

bool ValidSide(Figure figure, int koef)
{//esli koef 1 to proverka pravoy casti,esli -1 nalevo
	for (int j = 0; j < 4; j++)
	{
		int x = moving.x + figure.point[j].x;
		int y = moving.y + figure.point[j].y + koef;

		if (x > 0 && Array[x][y] == 1)
			return false;
	}
	return true;
}

bool ValidLine(int x)//proverka ctob pri zapolnenii polnoy linii ona stiralas
{
	for (int i = 1; i < Width + 1; i++)
	{
		if (Array[x][i] == 0)
			return false;
	}
	return true;
}

void ClearLine(int x)//stiranie pri zapolnenii  linii
{
	for (int i = x; i > 0; i--)
	{
		for (int j = 1; j < Width + 1; j++)
		{
			Array[i][j] = Array[i - 1][j];
			my_set_cursor(i + 1, j);
			if (Array[i][j] == 1)
			{
				cout << char(219);
			}
			else
			{
				cout << ' ';
				if (i == x)
					Sleep(30);
			}
		}
	}
}

void ArrayRestore()//zapolnaet massiv dla nacala igri
{
	for (int i = 0; i < Height + 1; i++)
	{
		for (int j = 0; j < Width + 2; j++)
		{
			Array[i][j] = 0;
		}
	}
	for (int i = 0; i < Width + 2; i++)
	{
		Array[Height][i] = 1;
	}
	for (int i = 0; i < Height; i++)
	{
		Array[i][0] = 1;
		Array[i][Width + 1] = 1;
	}
	Score = 0;

}




void ArrayLoad()//scitivanie soxranennoy igri s file
{
	FILE * save = fopen("save.txt", "r");

	int size = (Height + 1)*(Width + 2) + 1+3 ;
	
	int *arr = new int[size];
	fread_s(arr, sizeof(int) * size, sizeof(int), size, save);
	

	
	int k=0;//ctobi zapisat score v totje file gde soxranaetsa massiv zapo,
	for (int i = 0; i < Height + 1; i++)
	{
		for (int j = 0; j < Width + 2; j++)
		{
			Array[i][j] = arr[k];
			k++;
		}
	}
	
	Score = arr[k];
	k++;
	mainsleep = arr[k];
	k++; 
	lvl = arr[k];

	PrintSave();
}

void PrintSave()
{
	for (int i = 1; i < Height; i++)
	{
		for (int j = 1; j < Width + 1; j++)
		{
			if (Array[i][j] == 1)
			{
				my_set_cursor(i + 1, j);
				cout << char(219);
			}
		}
	}
}

bool ValidGameOver()// proverka konca igri
{
	char button = 0;
	for (int i = 1; i < Width + 1; i++)
	{
		if (Array[0][i] == 1)
		{
			system("cls");


			for (size_t i = 0; i < 20; i++)
			{
				if (i % 2 == 0) {
					set_color(ConsoleColor::Blue, ConsoleColor::Red);
				}
				else {
					set_color(ConsoleColor::Blue, ConsoleColor::White);
				}
				my_set_cursor(5, 5);
				cout << "Game over!";
				Sleep(100);
			}

			my_set_cursor(10, 2);
			cout << "Please Enter to \n     restart!";

			while (true)
			{

				button = _getch();

				if (button == Controls::Enter) {
					break;
				}
			}
			mainsleep = 300;
			ArrayRestore();
			return true;

		}
	}
	return false;
}