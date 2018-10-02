#pragma once
#include"Libraries.h"
#include"Functions.h"

Figure RandFigure();

void  game_console(int gameMode) {//game mode esli raven 1 to igra novaya esli raven 2 to prodoljenie soxranennoy
	print_field(Height, Width, gameMode);

	Figure figure = RandFigure();
	Figure nextfigure;

	while (true)
	{
		nextfigure = RandFigure();
		
		Figure clear = Game_Information(nextfigure);
		RandFigure();

		if (!MoveFigure(figure))
		{
			system("cls");
			print_field(Height, Width, 1);
		}

		FigureClear(clear, false);
		figure = nextfigure;
	}
}

Figure RandFigure()//viiraet i vozvrawaet randomno odnu figuru
{
	srand(time(0));
	Figure figure;
	int number = rand() % 19 + 1;

	switch (number)
	{
	case 1:
		set_color(ConsoleColor::Blue, ConsoleColor::Red);
		figure = Filling(arr_LT);
		break;
	case 2:
		set_color(ConsoleColor::Blue, ConsoleColor::Green);
		figure = Filling(arr_I);

		break;
	case 3:
		set_color(ConsoleColor::Blue, ConsoleColor::Yellow);
		figure = Filling(arr_F);
		break;
	case 4:
		set_color(ConsoleColor::Blue, ConsoleColor::LightRed);
		figure = Filling(arr_7);
		break;
	case 5:
		set_color(ConsoleColor::Blue, ConsoleColor::Magenta);
		figure = Filling(arr_z);
		break;
	case 6:
		set_color(ConsoleColor::Blue, ConsoleColor::Brown);
		figure = Filling(arr_s);
		break;
	case 7:
		set_color(ConsoleColor::Blue, ConsoleColor::LightCyan);
		figure = Filling(arr_T);
		break;
	case 8:
		set_color(ConsoleColor::Blue, ConsoleColor::Green);
		figure = Filling(arr_I2);
		break;
	case 9:
		set_color(ConsoleColor::Blue, ConsoleColor::Yellow);
		figure = Filling(arr_F2);
		break;
	case 10:
		set_color(ConsoleColor::Blue, ConsoleColor::Yellow);
		figure = Filling(arr_F3);
		break;
	case 11:
		set_color(ConsoleColor::Blue, ConsoleColor::Yellow);
		figure = Filling(arr_F4);
		break;
	case 12:
		set_color(ConsoleColor::Blue, ConsoleColor::LightRed);
		figure = Filling(arr_72);
		break;
	case 13:
		set_color(ConsoleColor::Blue, ConsoleColor::LightRed);
		figure = Filling(arr_73);
		break;
	case 14:
		set_color(ConsoleColor::Blue, ConsoleColor::LightRed);
		figure = Filling(arr_74);
		break;
	case 15:
		set_color(ConsoleColor::Blue, ConsoleColor::Magenta);
		figure = Filling(arr_z2);
		break;
	case 16:
		set_color(ConsoleColor::Blue, ConsoleColor::Brown);
		figure = Filling(arr_s2);
		break;
	case 17:
		set_color(ConsoleColor::Blue, ConsoleColor::LightCyan);
		figure = Filling(arr_T2);
		break;
	case 18:
		set_color(ConsoleColor::Blue, ConsoleColor::LightCyan);
		figure = Filling(arr_T3);
		break;
	case 19:
		set_color(ConsoleColor::Blue, ConsoleColor::LightCyan);
		figure = Filling(arr_T4);
		break;
	}

	return figure;
}