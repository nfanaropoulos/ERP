#include "../headers/employeemenu.h"

void employeeMenu(char username[], char rights[]){															//Employee Menu function.										
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
																											//Variable definition start.			
char *employeeart = "art/border1.dat";
FILE *art = NULL, *notes11;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice;
																											//Variable definition ends.
system("CLS");																								//Clear screen.		
if((art = fopen(employeeart,"r")) == NULL)																	//--------------------------------------------------------------------------
    {																										//		
        fprintf(stderr,"error opening %s\n",employeeart);													//If condition the ascii art file does not exist.
        return 1;																							//
}																											//--------------------------------------------------------------------------	
print_title(art);																							//Print on screen the ascii art file.		
	gotoxy(62,2);																							//--------------------------------------------------------------------------		
	printf("Welcome Back: ");																				//								Top menu beggin.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
	printf("%s", username);																					//
	gotoxy(62,3);																							//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
	printf("Date: ");																						//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
	printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);										//		
	gotoxy(62,4);																							//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
	printf("Notes: ");																						//
	gotoxy(175, 2);																							//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
	printf("Low Quantity: ");																				//	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
	printf("%d", lowquantity());																			//Print on screen the return of the function lowquantity.
																											//								Top menu bends.		
	gotoxy(105, 15);																						//--------------------------------------------------------------------------
	printf("~~Employee Menu~~");																			//Menu options.			
	gotoxy(105, 17);																						//
	printf("1. Invoices");																					//Invoices.	
	gotoxy(105,18);																							//
	printf("2. Notes.");																					//Notes.	
	gotoxy(105, 19);																						//
	printf("3. Exit");																						//Exit.	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);								//
	gotoxy(105,20);																							//	
	printf("Enter your Choice: ");																			//	
	scanf("%d", &choice);																					//User input to choose between the options.	
	switch(choice)																							//Switch function for each user choice.
	{
		case 1:																								//Case 1.
			invoices(username, rights);																		//Call invoices function.
			break;																							//	
		case 2:																								//Case 2.
			notes(username, rights);																		//Call notes function.			
			break;																							//
		case 3:																								//Case 3.			
			exit(1);																						//Exit the program.
			break;																							//
	}	
fclose(employeeart);																						//Close the ascii art file.
}																											//End of employee menu function.
