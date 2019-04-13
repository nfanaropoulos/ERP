#include "../headers/warehousemenu.h"

void warehousemenu(char username[], char rights[]){

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
char *warehouseart = "art/border1.dat";
FILE *art = NULL;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice;

system("CLS");
if((art = fopen(warehouseart,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",warehouseart);
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
	printf("~~Warehouse Menu~~");
	gotoxy(105, 17);
	printf("1. Add Product");
	gotoxy(105, 18);
	printf("2. Edit Product");
	gotoxy(105, 19);
	printf("3. Order Product");
	gotoxy(105, 20);
	printf("4. Note");
	gotoxy(105, 21);
	printf("5. Back");
	gotoxy(105, 22);
	printf("6. Exit");
	gotoxy(105, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("Enter your Choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			addproduct(username, rights);
			break;
		case 2:
			editproduct(username, rights);
//			system("\data\\products.csv");
//			warehousemenu(username, rights);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
            if(rights[0] == 'y')
				managerMenu(username, rights);
			break;
		case 6:
			break;
	}
}
