#include "../headers/managermenu.h"

void managerMenu(char username[], char rights[]){													//ManagerMenu function begin.																											
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		
																									//Variables definition begin.
char *managerart = "art/border1.dat";
FILE *art = NULL, *notes11;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice;
																									//Variables definition end.

system("CLS");																						//Clear screen.
if((art = fopen(managerart,"r")) == NULL)															//-----------------------------------------------------------------------------------
    {																								//
        fprintf(stderr,"error opening %s\n",managerart);											//If condition in case of a missing ascii art file.
        return 1;																					//
}																									//-----------------------------------------------------------------------------------
print_title(art);																					//Print on screen the ascii art file.	
gotoxy(62,2);																						//-----------------------------------------------------------------------------------
printf("Welcome Back: ");																			//									Top Menu begin.
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
printf("%d", lowquantity());																		//									Bottom Menu end.
gotoxy(105, 15);																					//-----------------------------------------------------------------------------------
printf("~~Administration Menu~~");																	//									Menu Options.			
gotoxy(105, 17);																					//
printf("1. Registries Menu");																		//
gotoxy(105, 18);																					//
printf("2. Warehouse Menu");																		//
gotoxy(105, 19);																					//
printf("3. Statistics");																			//
gotoxy(105, 20);																					//
printf("4. Invoices");																				//
gotoxy(105, 21);																					//
printf("5. Notes Menu");																			//
gotoxy(105, 22);																					//
printf("6. Exit");																					//
gotoxy(105, 24);																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);							//
printf("Enter your Choice: ");																		//
scanf("%d", &choice);																				//Read the user input for choice.
switch(choice)																						//Switch function for the choice variable.
{																									//
	case 1:																							//Case 1.	
		registries(username, rights);																//Call registries function.
		break;																						//
	case 2:																							//Case 2.	
		warehousemenu(username, rights);															//Call warehousemenu function.	
		break;																						//	
	case 3:																							//Case 3.
		statsmenu(username, rights);																//Call statsmenu function.
		break;																						//
	case 4:																							//Case 4.
		invoices(username, rights);																	//Call invoices function.	
		break;																						//
	case 5:																							//Case 5.	
		notes(username, rights);																	//Call notes function.
		break;																						//
	case 6:																							//Case 6.
		exit(1);																					//Exit the program.
		break;																						//
}																									//		
fclose(managerart);																					//Close the ascii art file.
}																									//Managermenu function ends.
