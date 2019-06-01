# include "../headers/mainMenu.h"
# define MAX_LEN 128
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>

void mainMenu(){																					//Main Menu.
system("CLS");																						//Clearing String.

char *borderart = "art/border.dat"; 																//Defining the input stream for MainMenu art.
FILE *art = NULL;																					
int choice =0;																						

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//Colorizing the text.	
    if((art = fopen(borderart,"r")) == NULL)                                 						//If the file containing the art does not exist.
    {                                                                      
        fprintf(stderr,"error opening %s\n",borderart);                          					//Print the error message.
        return;                                                                  
    }                                                                           
    print_title(art);																				//Start printing the art for Main Menu.
	gotoxy(100,18);																					//Setting the cursor to the apropriate coordinates.
	printf("Main Menu");																			
	gotoxy(100,26);																					//Setting the cursor to the apropriate coordinates.
	printf("1. Login.");
	gotoxy(100,27);																					//Setting the cursor to the apropriate coordinates.
	printf("2. Exit.");
	gotoxy(100,29);																					//Setting the cursor to the apropriate coordinates.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);						//Colorizing the text.
	printf("Please Select (1-2): ");
	while(choice != 1)																				//While loop to verify that the user input is correct.
	{
		gotoxy(121,29);																				//Setting the cursor to the apropriate coordinates.
		scanf("%d", &choice);
		switch(choice)																				//Switch Function to redirecting the user to the apropriate menu.
		{
			case 1:																					//Case 1.
				system("CLS");																		//Clear Screen.
				login();																			//Calling login Function.
				break;																				//Break statement. 
			case 2:																					//Case 2.
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0);
				exit(1);																			//Exit the program.
		}
		MessageBox(0, "Please Press 1 or 2!", "WARNING", 0);										//Error message pop up when the user gives wrong input.
	}
	fclose(borderart);                             													//Closing the art file.
}
