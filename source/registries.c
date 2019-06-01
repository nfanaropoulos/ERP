#include "../headers/registries.h"

void registries(char username[], char rights[]){														//Registries function begin.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
																										//Variables definition begin.
char *managerart = "art/border1.dat";
FILE *art = NULL;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice;
																										//Variables definition ends.
system("CLS");																							//Clear screen.	
if((art = fopen(managerart,"r")) == NULL)																//-------------------------------------------------------------------------------
    {																									//
        fprintf(stderr,"error opening %s\n",managerart);												//If condition in case of a missing ascii art file.
        return 1;																						//			
}																										//-------------------------------------------------------------------------------
print_title(art);																						//Print on screen the ascii art file.

	gotoxy(62,2);																						//								Top Menu.
	printf("Welcome Back: ");																			//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
	printf("%s", username);																				//
	gotoxy(62,3);																						//	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
	printf("Date: ");																					//		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
	printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);									//
	gotoxy(62,4);																						//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
	printf("Notes: ");																					//
	gotoxy(175, 2);																						//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
	printf("Low Quantity: ");																			//	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
	printf("%d", lowquantity());																		//Print on screen the return of the lowquantity function to show products that are low.
	gotoxy(105, 15);																					//
	printf("~~Registries Menu~~");																		//Menu options.
	gotoxy(105, 17);																					//
	printf("1. Add Employee");																			//
	gotoxy(105, 18);																					//
	printf("2. Edit Employee");																			//
	gotoxy(105, 19);																					//	
	printf("3. Add Supplier");																			//
	gotoxy(105, 20);																					//
	printf("4. Edit Supplier");																			//
	gotoxy(105, 21);																					//
	printf("5. Add Client");																			//
	gotoxy(105, 22);																					//
	printf("6. Edit Client");																			//
	gotoxy(105, 23);																					//
	printf("7. Back");																					//
	gotoxy(105, 25);																					//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);							//
	printf("Enter your Choice: ");																		//
	scanf("%d", &choice);																				//Read the user input.
	switch(choice)																						//Switch function for choice.
	{																									//
		case 1:																							//Case 1.
			reg(username, rights);																		//Call reg function.
			break;																						//
		case 2:																							//Case 2.	
			edit_reg(username, rights);																	//Call edit_reg function.
			break;																						//
		case 3:																							//Case 3.
			supplier(username, rights);																	//Call supplier function.
			break;																						//
		case 4:																							//Case 4.
			edit_supplier(username,rights);																//Call edit_supplier function.	
			break;																						//
		case 5:																							//Case 5.
			clients(username, rights);																	//Call clients function.
			break;																						//
		case 6:																							//Case 6.
			edit_clients(username, rights);																//Call edit_clients function.
			break;																						//
		case 7:																							//Case 7.
			managerMenu(username, rights);																//Call managerMenu function.		
			break;																						//
	}																									//	
}																										//Registries function ends.	
