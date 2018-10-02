#pragma once
#include"Libraries.h"
#include"GameConsole.h"

void menu_design(int y, int x) {// dizayn menu pri vxode(upravlenie strelkami i td)
	char button_code = 0;
	my_set_cursor(y, x);
	cout << char(253);
	my_set_cursor(y, x + 11);
	cout << char(253);
	int a = 1;
	while (true)
	{
		my_set_cursor(1, 7);
		cout << "TETRIS";
		my_set_cursor(5, 8);
		cout << "MENU";
		my_set_cursor(8, 6);
		cout << "New Game";
		my_set_cursor(10, 5);
		cout << "Load  Game";
		my_set_cursor(12, 6);
		cout << "Controls";
		my_set_cursor(14, 8);
		cout << "Exit";
		button_code = _getch();
		if (button_code == Controls::Acceleration)
		{
			PlaySound(TEXT("00171.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (y < 14) {
				y = y + 2;
				my_set_cursor(y, x);


				cout << char(253);
				my_set_cursor(y, x + 11);
				cout << char(253);
				my_set_cursor(y - 2, x);
				cout << " ";
				my_set_cursor(y - 2, x + 11);
				cout << " ";
				a++;
			}
		}
		else if (button_code == Controls::Rotate)
		{
			PlaySound(TEXT("00171.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (y > 8) {
				y = y - 2;
				my_set_cursor(y, x);
				cout << char(253);
				my_set_cursor(y, x + 11);
				cout << char(253);
				my_set_cursor(y + 2, x);
				cout << " ";
				my_set_cursor(y + 2, x + 11);
				cout << " ";
				a--;
			}
		}
		else if (button_code == Controls::Enter)
		{
			if (a == 1) {

				PlaySound(TEXT("tetris"), NULL, SND_ASYNC | SND_LOOP);
				system("cls");
				game_console(a);
			}
			else if (a == 2) {
				PlaySound(TEXT("tetris"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				game_console(a);


			}
			else if (a == 3) {
				PlaySound(TEXT("00171.wav"), NULL, SND_FILENAME | SND_ASYNC);

				system("cls");

				while (true)
				{
					my_set_cursor(2, 2);
					cout << "R-restart";
					my_set_cursor(4, 2);
					cout << "P-pause";
					my_set_cursor(6, 2);
					cout << "S-save";
					my_set_cursor(8, 2);
					cout << "ArrowUP-rotate";
					my_set_cursor(10, 2);
					cout << "ArrowDown-boost";
					my_set_cursor(12, 2);
					cout << "ArrowLeft-Left";
					my_set_cursor(14, 2);
					cout << "ArrowRight-Right";
					my_set_cursor(20, 0);
					cout << "Press Enter to Menu";
					button_code = _getch();
					if (button_code == Controls::Enter)
					{
						PlaySound(TEXT("00171.wav"), NULL, SND_FILENAME | SND_ASYNC);
						system("cls");
						menu_design(8, 4);
					}

				}

			}
			else if (a == 4) {
				PlaySound(TEXT("00171.wav"), NULL, SND_FILENAME | SND_ASYNC);

				exit(0);
			}
		}

	}

}




