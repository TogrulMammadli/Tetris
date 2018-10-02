#include"Menu.h"
#include"GameConsole.h"
#include"Functions.h"


int main() {
	

	Without_Cursor();
	console_resolution(20, 20);
	system("mode con lines=23 cols=19");
	menu_design(8, 4);
	system("pause");
	return 0;

}
