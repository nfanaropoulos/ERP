#include "../headers/managermenu.h"

void managerMenu(char username[]){

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
char *managerart = "art/border1.dat";
FILE *art = NULL;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice;

system("CLS");
if((art = fopen(managerart,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",managerart);
        return 1;
}
print_title(art);

	gotoxy(62,2);
	printf("Welcome Back: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
	printf("%s", username);
	gotoxy(62,3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("Date: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
	printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	gotoxy(62,4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("Notes: ");
	gotoxy(200, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("Low Quantity: ");
	gotoxy(105, 15);
	printf("~~Administration Menu~~");
	gotoxy(105, 17);
	printf("1. Registries");
	gotoxy(105, 18);
	printf("2. Warehouse");
	gotoxy(105, 19);
	printf("3. Statistics");
	gotoxy(105, 20);
	printf("4. Receipt/Invoices");
	gotoxy(105, 21);
	printf("5. Orders");
	gotoxy(105, 22);
	printf("6. Add Note");
	gotoxy(105, 23);
	printf("7. Exit");
	gotoxy(105, 26);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("Enter your Choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			reg(username);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
	}
}
