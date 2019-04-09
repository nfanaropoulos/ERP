#include "../headers/gotoxy.h"

 
void gotoxy(int x, int y){											//Function found on internet to positioning the cursor.
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
