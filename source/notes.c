#include "../headers/notes.h"

struct notes{																								//Struct for persona notes.
		
	int id;																									//Struct variable id.
	char text[200];																							//Struct variable text.
};																											//End of struct.
struct notes n;																								//Define struct with a shortcut used as n.

void notes(char username[], char rights[]){																	//Notes function.
																											//Variables definition start.
char *notesart = "art/border1.dat"; 
FILE *art = NULL, *notes, *notes_copy;
long int recsize = sizeof(notes);
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice1, check = NULL, i, del_id, p, tmp =1, count = 0;
char* dirname = username;
char str[220], turnname[10], test[] = "test.txt";;
int ids = 0;
char c, ch, cha, last = '\n';
																											//Variables definition ends.	

strcpy(turnname, username);																					//Saving the string username by copying it to a temporary one named turnname.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//			
system("CLS");																								//Clear screen.
if((art = fopen(notesart,"r")) == NULL)                                 									//--------------------------------------------------------------------------
	{                                                                      									//
        fprintf(stderr,"error opening %s\n",notesart);                          							//If condition in case of a missing ascii file.	
        return;                                                                  							//
    }                                                                           							//--------------------------------------------------------------------------	
print_title(art);																							//Print on screen the ascii art file.
gotoxy(62,2);																								//--------------------------------------------------------------------------
printf("Welcome Back: ");																					//							Top menu starts.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%s", username);																						//
gotoxy(62,3);																								//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Date: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);											//		
gotoxy(62,4);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Notes: ");																							//	
sprintf(dirname, "%s.txt", username);																		//
notes = fopen(dirname, "rb");																				//Open the personal notes file named as the active user .txt .
for(cha = getc(notes); cha != EOF; cha = getc(notes)){														//For loop to read the personal notes file char by char until end of file.
	if(cha == '\n' && last != '\n')																			//If condition a new line char is found "\n" and the last char is not "\n"
		count++;																							//Increase the count by one (count is the variable that counts notes.
	last = cha;																								//Set last to be the same as cha.
}																											//
	
fclose(notes);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", count);																						//Print the amount of notes found from previous loop.
gotoxy(175, 2);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Low Quantity: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//	
printf("%d", lowquantity());																				//Print on screen the return of the lowquantity function for low prods in warehouse.
gotoxy(105,14);																								//								Top menu ends.
printf("Personal Notes Page");																				//--------------------------------------------------------------------------
gotoxy(105,16);																								//
printf("1. Add Note");																						//	
gotoxy(105,17);																								//
printf("2. Read Note");																						//
gotoxy(105,18);																								//
printf("3. Delete Note");																					//			
gotoxy(105,20);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);									//
printf("Enter your Choice: ");																				//
scanf("%d", &choice1);																						//Read the user input as saving it as choice1.
switch(choice1)																								//Switch function for choice1 (previous user input).
{																											//	
case 1:																										//Case 1.
	if(fopen(dirname, "rb") == NULL)																		//If the personal notes file does not exist to open in read and binary.
	{																										//	
	notes = fopen(dirname, "wb");																			//Create the personal notes file and open it in write and binary mode.			
	gotoxy(74,14);																							//	
	printf("ID: ");																							//
	for (c = getc(notes); c != EOF; c = getc(notes)){														//For loop that read the personal notes file char by char until end of file.			
	if (c == '\n')																							//If a new line is found "\n".
		ids += 1;																							//Increase the ids variable by one.
	}																										//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//	
	printf("%d", ids);																						//Print on screen the ids variable (total notes etries found).	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
	gotoxy(74,26);																							//
	printf("Note: ");																						//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//	
	getchar();																								//		
	gets(n.text);                            															    //Receive the user input for the text of the note.
	fseek(notes, 0, SEEK_END);																				//Go to the end of the personal notes file.
	fprintf(notes, "%d %s\n", ids, n.text);																	//Print in the personal notes file the note registered by the user.	
	fclose(notes);																							//Close the personal notes file.
	strcpy(username, turnname);																				//Return the username string saved in turnname.		
	managerMenu(username, rights);																			//Call the managerMenu function to go back.
	}																										//
	else{																									//Else.
	notes = fopen(dirname, "rb+");																			//open the personal notes file in read, binary and append mode.
	gotoxy(74,14);																							//
	printf("ID: ");																							//	
	for (c = getc(notes); c != EOF; c = getc(notes)){														//Read all characters one by one from the personal notes file until end of file.
	if (c == '\n')																							//If a new line is found "\n".
		ids = ids + 1;																						//Increase ids variable by one (ids is the total lines/entries found).	
	}																										//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//	
	printf("%d", ids);																						//																				
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
	gotoxy(74,26);																							//
	printf("Note: ");																						//		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
	getchar();																								//Wait for any user input.
	gets(n.text);                               															//Receive the user input as the text of the personal note to save.
	fseek(notes, 0, SEEK_END);																				//Go to the end of the personal notes file.
	fprintf(notes, "%d %s\n", ids, n.text);																	//And save the data as a new line (new note).	
	fclose(notes);																							//Close the personal notes file.
	strcpy(username, turnname);																				//Copy the saved string turnname to the old one username.
	if(rights[0] == 'y')																					//If the rights of the active user is admin.
		managerMenu(username, rights);																		//Call the managerMenu function to go back.
	else 																									//Else (in case of a non admin user).
		employeeMenu(username, rights);																		//Call the employeeMenu function to go back.	
	}																										//
	break;																									//Break statement.
case 2:																										//Case 2.

	if(fopen(dirname, "rb") == NULL)																		//If condition in case of the personal notes file is not avaiable.
	{																										//
		printf("Unable to find the Notes file for %s user", username);										//Print message on screen.
		break;																								//
	}																										//
	else{																									//	
	notes = fopen(dirname, "rb");																			//Open the personal notes file in read and binary mode.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
	gotoxy(0,36);																							//
	while ((p = getc(notes)) != EOF)																		//While loop that read all personal notes file char by char until end of file.
	{																										//
		putchar(p);																							//Type on screen the character taken from the file.
	}																										//
	getch();																								//Wait for any user input.	
	fclose(notes);																							//Close the personal notes file.		
	strcpy(username, turnname);																				//Copy the saved turnname string into username.
								
	if(rights[0] == 'y')																					//If condition the user has administrator rights.	
		managerMenu(username, rights);																		//Call the managerMenu function to go back.
	else																									//Else.
		employeeMenu(username, rights);																		//Call the employeeMenu function to go back.	
}																											//
	break;																									//
case 3:																										//Case 3.
	gotoxy(74,14);																							//
	printf("ID: ");																							//
	scanf("%d", &del_id);																					//Read the user input for the notes id to delete.
	notes = fopen(dirname, "rb");   																		//Open the personal notes file in read and binary mode.
	del_id = del_id + 1;            																		//
	notes_copy = fopen("test.txt", "w");																	//Open the temporary notes file called test.txt in write mode.	
	rewind(notes);																							//Reset the personal notes file to the beggining of the file.	
	ch = 'A';																								//Set ch variable to be "A".
	while (ch != EOF)																						//While loop char taken from the file isn't the end of file.
	{																										//	
		ch = getc(notes);																					//Set ch variable to be the next character from personal notes file.	
		if(ch == EOF)																						//If the character taken was the end of file.
			break;																							//Leave loop.		
		if (ch == '\n')																						//If the character taken was the new line "\n".		
			tmp++;																							//Increase the tmp variable by one.
		if (tmp != del_id)																					//If the tmp character is not the del_id given by the user.	
			putc(ch, notes_copy);																			//Put the character taken from the personal notes to the temporary notes file.	
		else																								//Else do nothing.
		{
		}
	}
	
fclose(notes);																								//Close the personal notes file.
fclose(notes_copy);																							//Close the temporary notes file.
gotoxy(140, 36);																							//
printf("Please wait...");																					//Print message on screen.
sleep(5);																									//Sleep function to delay.
gotoxy(140, 37);																							//
printf("Please wait...");																					//Print message on screen.
remove(dirname);																							//Remove the personal notes file.		
gotoxy(140, 38);																							//
printf("Almost done...");																					//Print message on screen.
sleep(5);																									//Sleep function to delay.
gotoxy(140, 39);																							//
printf("Done");																								//
gotoxy(140,40);																								//
printf("Please press any key...");																			//Print message on screen.
getch();																									//Wait for any character input.	
rename(test, dirname);																						//Rename the test file to turnname (turnname has the active user name on it).
strcpy(username, turnname);																					//Return the username string which was saved in turnname.
if(rights[0] == 'y')																						//If the user rights is administrator.	
	managerMenu(username, rights);																			//Call the managerMenu function to go back.
else																										//Else.
	employeeMenu(username, rights);																			//Call the employeeMenu function to go back.
	break;																									//
}																											//
}																											//
