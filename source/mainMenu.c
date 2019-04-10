# include "../headers/mainMenu.h"
# define MAX_LEN 128
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>


void mainMenu(){														//Main Menu
system("CLS");

char *borderart = "art/border.dat"; 
FILE *art = NULL;
int choice;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
    if((art = fopen(borderart,"r")) == NULL)                                 
    {                                                                      
        fprintf(stderr,"error opening %s\n",borderart);                          
        return;                                                                  
    }                                                                           
    print_title(art);
	gotoxy(60,18);
	printf("Main Menu");
	gotoxy(55,26);
	printf("2. Login:");
	gotoxy(55,28);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("Please Select (1-2): ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			system("CLS");
			reg();
			break;
		case 2:
			system("CLS");
			login();
			break;
	}
fclose(borderart);                             
}
