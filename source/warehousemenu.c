#include "../headers/warehousemenu.h"

void warehousemenu(char username[], char rights[]){														//warehousemenu function begin.			
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
																										//Variables definition begin.
char *warehouseart = "art/border1.dat";
FILE *art = NULL, *notes;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice, count = 0;
char cha, last = '\n', turnname[10];
strcpy(turnname, username);
char *dirname = username, *piko = rights;
																										//Variables definition end.	
system("CLS");																							//Clear screen.
if((art = fopen(warehouseart,"r")) == NULL)																//-------------------------------------------------------------------------------	
    {																									//
        fprintf(stderr,"error opening %s\n",warehouseart);												//If condition in case the ascii art is missing.
        return 1;																						//
}																										//-------------------------------------------------------------------------------
print_title(art);																						//Print on screen the ascii art file.
gotoxy(62,2);																							//-------------------------------------------------------------------------------
printf("Welcome Back: ");																				//									Top Menu.
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
sprintf(dirname, "%s.txt", username);																	//
notes = fopen(dirname, "rb");																			//Open the personal notes file in read and binary mode.
for(cha = getc(notes); cha != EOF; cha = getc(notes)){													//For loop that begin with the first character taken from the notes file until end of file.	
	if(cha == '\n' && last != '\n')																		//If condition the character taken is new line and the last character isn't new line.
		count++;																						//Increase the count variable which is the entries inside the personal notes file.
	last = cha;																							//Set last to be the same as char.
}																										//
fclose(notes);																							//Close personal notes file.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//	
printf("%d", count);																					//Print on screen the count variable found (total notes).
gotoxy(175, 2);																							//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("Low Quantity: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("%d", lowquantity());																			//Print on screen the return of lowquantity function that show low products in warehouse.
gotoxy(105, 14);																						//	
printf("~~Warehouse Menu~~");																			//Menu options.
gotoxy(105, 17);																						//				
printf("1. Add Product");																				//
gotoxy(105, 18);																						//
printf("2. Edit Product");																				//	
gotoxy(105, 19);																						//
printf("3. Order Product");																				//
gotoxy(105, 20);																						//
printf("4. Returns");																					//
gotoxy(105, 21);																						//
printf("5. Back");																						//	
gotoxy(105, 22);																						//
printf("6. Exit");																						//
gotoxy(105, 24);																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);								//
strcpy(username, turnname);																				//Return to username the previously saved string.
printf("Enter your Choice: ");																			//	
scanf("%d", &choice);																					//Read the user input for choice.
switch(choice)																							//Switch function for choice.
{																										//
	case 1:																								//Case 1.
		addproduct(username, rights);																	//Call function addproduct to add products to warehouse.
		break;																							//	
	case 2:																								//Case 2.
		edit_prod(username, rights);																	//Call edit_prod function to edit already registered products.	
		break;																							//
	case 3:																								//Case 3.	
		orders(username, rights);																		//Call orders function to order new quantities of products.
		break;																							//	
	case 4:																								//Case 4.
		returns(username, rights);																		//Call returns function to add returned products to the warehouse.
		break;																							//	
	case 5:																								//Case 5.
        if(rights[0] == 'y')																			//Going back by checking the rights of the user (should be only for administrators).
			managerMenu(username, rights);																//Call the managerMenu function.
		break;																							//
}																										//
fclose(warehouseart);																					//Close the ascii art file.
}																										//warehousemenu function ends.
