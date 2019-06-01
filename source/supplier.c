#include "../headers/supplier.h"
#include "../headers/structs2.h"
#define MAX_SUPPNAME_SIZE 40
#define MAX_SUPPCONTACT_SIZE 40
#define MAX_SUPPADDRESS_SIZE 55
#define MAX_SUPPCITY_SIZE 40

void edit_supplier(char username[], char rights[]){														//Edit_supplier function begin.
																										//Variables definition start.		
char *editsuppart = "art/border1.dat"; 
FILE *art = NULL, *supp, *supp_co, *notes;
int o, count = 0, j=0, l=3, y=36, counta=0, tmp_sid, tmp_spostal, id;
char acc_id[4], characteri = 'a', cha, last = '\n', c, line[1024], turnname[10], sname[40];
char* dirname = username;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
char *tmp_sname, *tmp_scontact, *tmp_saddress, *tmp_scity, *tmp_semail; 
long long int tmp_tel, tmp_stel;
																										//Variables definition ends.
strcpy(turnname, username);																				//Copy the username string into turnname.		
supp=fopen("data/suppliers.csv","rb+");																	//Open the suppliers.csv file in read, binary and append mode.			
supp_co=fopen("data/suppliers_copy.csv", "w");															//Open the suppliers_copy.csv file in write mode. Rewrite is ok.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//	
system("CLS");																							//Clear screen.
if((art = fopen(editsuppart,"r")) == NULL)                                 								//------------------------------------------------------------------------------	
	{                                                                      								//
        fprintf(stderr,"error opening %s\n",editsuppart);                          						//If condition in case the ascii art file does not exist.	
        return;                                                                  						//	
    }                                                                           						//------------------------------------------------------------------------------			
print_title(art);																						//Print on screen the ascii art file.

gotoxy(62,2);																							//------------------------------------------------------------------------------
printf("Welcome Back: ");																				//								Top Menu begin.	
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
notes = fopen(dirname, "rb");																			//Open the active's user personal notes file in read and binary mode.
for(cha = getc(notes); cha != EOF; cha = getc(notes)){													//For loop to receive all characters one by one from personal notes until end of file.
	if(cha == '\n' && last != '\n')																		//If condition the char received is the new line "\n" and last isn't new line.
		count++;																						//Increase the count variable (which counts the lines = notes).
	last = cha;																							//Set the last to be the same as cha.		
}																										//

fclose(notes);																							//Close the personal notes file.

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("%d", count);																					//Print on screen the number of personal notes found.
gotoxy(175, 2);																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("Low Quantity: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("%d", lowquantity());																			//Print on screen the return of the function lowquantity() which show the low products.
gotoxy(105,14);																							//									Top Menu ends.
printf("Supplier Edit Page");																			//------------------------------------------------------------------------------

gotoxy(74,14);																							//
printf("ID: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
scanf("%d", &id);																						//Read the user input for id.

while (fgets(line, 1024, supp) != NULL)                                          						//While loop to read all lines of suppliers.csv file line by line.
{																										//And temporarily save the line formated as below with sscanf.
	sscanf(line, "%d,%s,%s,%s,%s,%lu,%s,%d[^\n]", &s.sid, s.sname, s.scontact, s.saddress, s.scity, &s.stel, s.semail, &s.spostal);
	if(id == s.sid)																						//If condition the id given by the user match the id found in the line.		
	{         																							//
		tmp_sid = atoi(strtok(line, ","));																//Split the line string into smaller one until first "," and convert it to int.
		tmp_sname = strtok(NULL, ",");																	//Split the line string into smaller one until next ",".	
		tmp_scontact = strtok(NULL, ",");																//Split the line string into smaller one until next ",".		
		tmp_saddress = strtok(NULL, ",");																//Split the line string into smaller one until next ",".
		tmp_scity = strtok(NULL, ",");																	//Split the line string into smaller one until next ",".
		tmp_stel = atoll(strtok(NULL, ","));															//Split the line string into smaller one until next "," and convert it to long long int.
		tmp_semail = strtok(NULL, ",");																	//Split the line string into smaller one until next ",".
		tmp_spostal = atoi(strtok(line, ","));                											//Split the line string into smaller one until next "," and convert it to int.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		gotoxy(74,16); 																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		printf("Supplier's  Name: ");																	//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);		//
		fflush(stdin);																					//
		scanf("%s", &sname);																			//Receive user input for supplier name.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		gotoxy(74,18);																					//
		printf("Contact's Name: ");																		//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);		//
		fflush(stdin);																					//
		fgets(tmp_scontact, MAX_SUPPCONTACT_SIZE, stdin);												//Receive the user input for contact name, with max size MAX_SUPPCONTACT_SIZE.	
		if ((strlen(tmp_scontact) > 0) && (tmp_scontact[strlen (tmp_scontact) - 1] == '\n'))			//If the string length is bigger than 0 and the prelast character is the new line.
    		tmp_scontact[strlen (tmp_scontact) - 1] = '\0';												//Then replace the prelast character with the end string character "\0".		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		gotoxy(74,20);																					//
		printf("Supplier's Address: ");																	//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);		//
		fflush(stdin);																					//
		fgets(tmp_saddress, MAX_SUPPADDRESS_SIZE, stdin);												//Receive the user input for the address, with max size MAX_SUPPADDRESS_SIZE.
		if ((strlen(tmp_saddress) > 0) && (tmp_saddress[strlen (tmp_saddress) - 1] == '\n'))			//If the string length is bigger than 0 and the prelast character is the new line.
    		tmp_saddress[strlen (tmp_saddress) - 1] = '\0';												//Then replace the prelast character with the end string character "\0".
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		gotoxy(74,22);																					//
		printf("Supplier's City': ");																	//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);		//
		fflush(stdin);																					//
		fgets(tmp_scity, MAX_SUPPCITY_SIZE, stdin);														//Receive the user input for the city, with max size MAX_SCITY_SIZE.
		if ((strlen(tmp_scity) > 0) && (tmp_scity[strlen (tmp_scity) - 1] == '\n'))						//If the string length is bigger than 0 and the prelast character is the new line.	
    		tmp_scity[strlen (tmp_scity) - 1] = '\0';													//Then replace the prelast character with the end string character "\0".		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		gotoxy(74,24);																					//
		printf("Supplier's Phone: ");																	//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);		//
		fflush(stdin);																					//
		do{																								//Do while loop for the telephone validation.		
			fflush(stdin);																				//Flush the standard input file.
			gotoxy(92, 24);																				//
			scanf("%lu", &s.stel);																		//Read the user input for the supplier telephone number.
			tmp_tel = s.stel;																			//Save the telephone number in a temporary variable for the validation calculations.
			while(tmp_tel != 0)																			//While loop the temporary variable is not 0.	
   			{																							//
       			tmp_tel /= 10;																			//With each loop divide the temporary variable by 10.
        		counta++;																				//Increase the counta variable (counts the digits of the number).
    		}																							//
    		if(counta <  10 || counta > 10)																//If the digits are below 10 or above 10.		
    		{																							//
				if(y == 45)																				//If the y axis of the log area is 45 (end of log area).	
				{																						//	
					gotoxy(5,46);																		//
					printf("Press any key to continue...");												//Print message on screen.
					getch();																			//Wait for any user input.
					gotoxy(0,36);																		//
					for(j=36;j<=49; j++)																//For loop that traverse the log area line by line.
					{																					//		
						gotoxy(0,j);																	//
						for(l=0;l<=150; l++)															//Nested for loop that traverse the entire x axis of each line.
							printf(" ");																//Fake clear screen of log area by replacing what is written with " ".		
					}																					//
					gotoxy(0,36);																		//	
					y = 36;																				//Reset the y axis.
				}																						//
    			gotoxy(5,y);																			//
    			printf("Error: Please give me a valid 10 digit number as phone number.");				//Print the error message.
    			counta = 0 ;																			//Reset the digit counter to 0.
    			y++;																					//Increase the y axis (new line) each time an error input is given.
     		}																							//
    
		}while(counta < 10 || counta >= 11);															//While condition (including the 11 digits for telephone numbers from Athens.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		gotoxy(74,26);																					//
		printf("Email: ");																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);		//	
		do{																								//Do while loop for email validation.
			gotoxy(81,26);																				//		
			scanf("%s", &s.semail);																		//Read the user input for supplier email.
			if(validate_local_address(s.semail) == 0)													//If the return of the validate_local_address function is 0.	
			{																							//
				if(y == 45)																				//If the y axis of the log area is 45 (full log area).
				{																						//
					gotoxy(5,46);																		//
					printf("Press any key to continue...");												//Print message on screen.
					getch();																			//Wait for any user input.
					gotoxy(0,36);																		//
					for(j=36;j<=49; j++)																//For loop that traverse the log area line by line.
					{																					//
						gotoxy(0,j);																	//
						for(l=0;l<=150; l++)															//Nested for loop that traverse each line in x axis.		
							printf(" ");																//Fake clear screen of log area by replacing what is written with " ".
					}																					//
					gotoxy(0,36);																		//
					y = 36;																				//Reset the y axis of the log area.
				}																						//
				gotoxy(5, y);																			//
				printf("Error: Please use proper Email Address.");										//Print on screen the error message.
				y++;																					//Increase the y axis of the log area by one with each error message.
			}																							//
		}while(validate_local_address(s.semail) == 0);													//While condition.
		gotoxy(116,16);																					//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	//
		printf("Postal Code: ");																		//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);		//
		fflush(stdin);																					//
		scanf("%d", &s.spostal);																		//Read the user input for the supplier postal code.
										
		fseek(supp_co, 0, SEEK_END);																	//Move to the end of the suppliers_copy.csv file.
		fprintf(supp_co, "%d,%s,%s,%s,%s,%lu,%s,%d\n", s.sid, sname, tmp_scontact, tmp_saddress, tmp_scity, s.stel, s.semail, s.spostal);		
	}																									//Print in the file the given data with the format as above.
	else																								//Else.
	{																									//
		fseek(supp_co, 0, SEEK_END);																	//Move to the end of the suppliers_copy.csv file.
		fputs(line, supp_co);																			//Put the line as taken untouched.
	}																									//
} 																										//
fclose(supp);																							//Close the suppliers.csv file.	
fclose(supp_co);																						//Close the suppliers_copy.csv file.	
gotoxy(2,36);																							//
printf("Wait while files are being updated....                                                              ");
sleep(7);																								//Sleep function for delay to give time to rename /remove functions to complete.
rename("data/suppliers.csv", "data/suppliers-backup.csv");												//Rename suppliers.csv file to suppliers-backup.csv .					
gotoxy(2,37);																							//
printf("Wait while files are being updated....                                                               ");
sleep(7);																								//Sleep function for delay to give time to rename /remove functions to complete.
rename("data/suppliers_copy.csv", "data/suppliers.csv");												//Rename suppliers_copy.csv file to suppliers.csv .
sleep(7);																								//Sleep function for delay to give time to rename /remove functions to complete.		
remove("data/suppliers-backup.csv");																	//Remove the suppliers-backup.csv file.
gotoxy(2,39);																							//
printf("Files updated....                                                                                     ");
gotoxy(77,36);																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);								//
printf("Update Successful. Please Press any key to go back to Manager Menu.");							//Print message with each successful edit supplier.
strcpy(username, turnname);																				//Return the string username by copying it from the temporary turnname.	
getch();																								//Wait for any suer input.
registries(username, rights);																			//Call the registries function to go back.	
fclose(editsuppart);																					//Close the ascii art file.
}																										//

void supplier(char username[], char rights[]){															//Supplier function begin.		
																										//Variables definition begin.
char *suppart = "art/border1.dat"; 
FILE *art = NULL, *supp, *notes, *supp_cp;
char* dirname = username;
s.sid = 0;
long int recsize = sizeof(s);
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int count = 0, j, k, l, counter = 1, y = 36, counta = 0, ids = 0;
char last = '\n', cha, c, line[1024], turnname[10];
long long int tmp_tel1;
																										//Variables definition ends.		
strcpy(turnname, username);																				//Save temporarily the username string by copying it to turnname.
system("copy data\\suppliers.csv data\\suppliers.txt"); 												//Copy suppliers.csv file to suppliers.txt.	
supp_cp=fopen("data/suppliers.txt", "r");																//Open the suppliers.txt file in read mode.
supp=fopen("data/suppliers.csv","rb+");																	//Open the suppliers.csv file in read binary and append mode.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
system("CLS");																							//Clear screen.
if((art = fopen(suppart,"r")) == NULL)                                 									//------------------------------------------------------------------------------
	{                                                                      								//
        fprintf(stderr,"error opening %s\n",suppart);                          							//If condition in case of a missing ascii art file.
        return;                                                                  						//
    }                                                                           						//------------------------------------------------------------------------------
print_title(art);																						//Print on screen the ascii art file.
gotoxy(62,2);																							//------------------------------------------------------------------------------
printf("Welcome Back: ");																				//							Top Menu begins.
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
for(cha = getc(notes); cha != EOF; cha = getc(notes)){													//For loop that retrieve all characters one by one from the personal notes until end of file.
	if(cha == '\n' && last != '\n')																		//If a new line character is found "\n" and the last variable isn't the new line.	
		count++;																						//Increase the count variable by one (counts the personal notes).
	last = cha;																							//Set last to be the same as cha.
}																										//
		
fclose(notes);																							//Close the personal notes file.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("%d", count);																					//Print on screen the amount of personal notes found for active user.
gotoxy(62,5);																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("View Suppliers List : ");																		//								Shortcuts begin.	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("~");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("   Print Suppliers List : ");																	//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("^");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("   View Notes : ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("#");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("   Print Notes : ");																			//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf(">");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("   Back : ");																					//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("!");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);								//
gotoxy(90,6);																							//
printf("   NOTE!! : Shortcuts work only at the Suppliers Name Entry!");									//
gotoxy(175, 2);																							//								Shortcuts end.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("Low Quantity: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("%d", lowquantity());																			//Print on screen the return of the lowquantity function that show low products.
gotoxy(102,14);																							//
printf("Supplier Registration Page");																	//
gotoxy(43,14);																							//
for (c = getc(supp); c != EOF; c = getc(supp)){															//For loop that starts with receiving character from suppliers.csv until end of file.
	if (c == '\n')																						//If the character received is the new line character "\n".	
		ids++;																							//Increase the ids variable which counts the amount of registries (how many are they).
}																										//
gotoxy(74,14);																							//
printf("ID: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
printf("%d", ids);																						//Print on screen the amount of the suppliers found + 1 (ids++) for the new one.			
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
gotoxy(74,16);																							//
printf("Supplier Name: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
fclose(notes);																							//Close the personal notes file.
do																										//Do while loop for shortcuts.
{																										//
	fflush(stdin);																						//Flush the standard input file.
	fgets(s.sname, MAX_SUPPNAME_SIZE, stdin);															//Receive from stdin the s.name variable with max size = MAX_SUPPNAME_SIZE.
	if ((strlen(s.sname) > 0) && (s.sname[strlen (s.sname) - 1] == '\n'))								//If the string length received is bigger than 0 and the prelast position char is \n.
    	s.sname[strlen (s.sname) - 1] = '\0';															//Replace that position entry wtih \0 which is the end string character.
	if(s.sname[0] == '!')																				//! shortcut. 
		managerMenu(username, rights);																	//Call the previous menu function managerMenu.
	if(s.sname[0] == '^')																				//^ shortcut.
	{																									//
		gotoxy(0,36);																					//
	
		while(fgets(line, 1024, supp_cp))																//While loop that receive the entries of suppliers.txt line by line saved in line[1024]. 
		{																								//
			if(counter == 10)																			//If condition counter variable (counts lines in log area) reach 10.
			{																							//
				printf("\n Press any key to continue...");												//Print message on screen.		
				getch();																				//Wait for any user input.
				gotoxy(0,36);																			//
				for(j=36;j<=49; j++)																	//For loop that traverse the log area line by line.
				{																						//	
					gotoxy(0,j);																		//Move each time to new line.
					for(l=0;l<=150; l++)																//Traverse the x axis of each line.
					printf(" ");																		//Replace what is written at each line with " " .
				}																						//
			gotoxy(0,36);																				//
			counter = 1;																				//Reset the counter variable to 1 with each log area cleaning.
			}																							//	
			printf("%s\n", line);																		//Print the line received from the file to the log area.
			counter++;																					//Each time a new line is printed increase the counter by one.
		}																								//
	gotoxy(89,16);																						//Return the cursor to the same spot for new user input.	
	}																									//
	if(s.sname[0] == '~')																				//~ shortcut.
	{																									//
		system("data\\suppliers.txt");																	//Open for the user to see the suppliers.txt file.
		gotoxy(89,16);																					//Return the cursor to the shortcut area.	
	}																									//
	if(s.sname[0] == '#')																				//# shortcut.
	{																									//		
		system(dirname);																				//Open the personal notes file.
		gotoxy(89,16);																					//Return the cursor to the shortcut area.
	}																									//
	if(s.sname[0] == '>')																				//> shortcut.
	{																									//
		notes = fopen(dirname, "rb");																	//Open the personal notes file in read and binary mode.
		gotoxy(0,36);																					//
		for(j=36;j<=49; j++)																			//For loop to clear the log area before printing the notes (j = y axis lines).
		{																								//
			gotoxy(0,j);																				//Move each time to a new line.
			for(l=0;l<=150; l++)																		//Nested for loop to traverse the x axis of each line of log area.
				printf(" ");																			//Fake clear screen of log area by replacing what is written with " ".
		}																								//
		gotoxy(0,36);																					//
		k = fgetc(notes);																				//Set k char to be the character received from the personal notes file.
		while (k != EOF)																				//While loop k char is not reached the end of file.
		{																								//
			printf ("%c", k);																			//Print on screen the character taken.
			k = fgetc(notes); 																			//Set k to be the next character taken from personal notes file.	
		}																								//	
	gotoxy(89,16);																						//Move again to the s.sname position for user entry.
	s.sname[0] = '^';																					//Set shortcut to be ^ so that the while does not end unless user choose it.
	}																									//		
}while(s.sname[0] == '>' || s.sname[0] == '~' || s.sname[0] == '^' || s.sname[0] == '#');				//While conditions.	
fclose(supp_cp);																						//Close the suppliers.txt file.
fclose(notes);																							//Close the personal notes file.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
gotoxy(74,18);																							//
printf("Contact Name: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
fflush(stdin);																							//Flush the standard input file.
fgets(s.scontact, MAX_SUPPCONTACT_SIZE, stdin);															//Receive from standard input file the s.scontact with max size = MAX_SUPPCONTACT_SIZE.
if ((strlen(s.scontact) > 0) && (s.scontact[strlen (s.scontact) - 1] == '\n'))							//If condition the string received is bigger than 0 and the prelast character is new line.	
    s.scontact[strlen (s.scontact) - 1] = '\0';															//Replace that character with the end string character "\0".
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
gotoxy(74,20);																							//
printf("Address: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
fflush(stdin);																							//Flush the standard input file.
fgets(s.saddress, MAX_SUPPADDRESS_SIZE, stdin);															//Receive from standard input file the s.saddress with max size = MAX_SUPPADDRESS_SIZE.
if ((strlen(s.saddress) > 0) && (s.saddress[strlen (s.saddress) - 1] == '\n'))							//If condition the string received is bigger than 0 and the prelast character is new line.		
    s.saddress[strlen (s.saddress) - 1] = '\0';															//Replace that character with the end string character "\0".			
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//	
gotoxy(74,22);																							//
printf("City: ");																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
fflush(stdin);																							//Flush the standard input file.
fgets(s.scity, MAX_SUPPCITY_SIZE, stdin);																//Receive from standard input file the s.scity with max size = MAX_SUPPCITY_SIZE.
if ((strlen(s.scity) > 0) && (s.scity[strlen (s.scity) - 1] == '\n'))									//If condition the string received is bigger than 0 and the prelast character is new line.	
    s.scity[strlen (s.scity) - 1] = '\0';																//Replace that character with the end string character "\0".
gotoxy(116,16);																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("Tel: ");																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
fflush(stdin);																							//Flush the standard input file.
do{																										//Do while loop for phone number validation.	
	fflush(stdin);																						//Flush the standard input file.
	gotoxy(121, 16);																					//With each wrong phone number given move cursor back to the proper position.	
	scanf("%lu", &s.stel);																				//Read the user input for the phone number saved in long unsinged variable.	
	tmp_tel1 = s.stel;																					//Save temporarily for the calculations the phone number in tmp_tel1.
	while(tmp_tel1 != 0)																				//While the temporary variable is not 0.
   	{																									//
       	tmp_tel1 /= 10;																					//Divide with each loop the temporary variable by 10.	
        counta++;																						//With each division increase the counta (digits counting) by one.
    }																									//
    if(counta <  10 || counta > 10)																		//If condition the digits are below 10 or above 10.
    {																									//
		if(y == 45)																						//If condition the log area reached the last line.
		{																								//	
			gotoxy(0,46);																				//
			printf("Press any key to continue...");														//Print message on screen.		
			getch();																					//Wait for any user input.
			gotoxy(0,36);																				//
			for(j=36;j<=49; j++)																		//For loop that traverse the whole log area (y axis - lines).
			{																							//
				gotoxy(0,j);																			//With each loop move cursor to the new line.
				for(l=0;l<=150; l++)																	//Nested for loop to traverse the x axis of the log area.	
					printf(" ");																		//Fake clear screen on log area by replacing all that is written with " ".	
			}																							//
			gotoxy(0,36);																				//
			y = 36;																						//set the log area y axis to be 36 (begining of the log area). 	
		}																								//
    	gotoxy(0,y);																					//Move to the current y axis of the log area.																	
  		printf("Error: Please give me a valid 10 digit number as phone number.");						//Print on screen the error message.	
    	counta = 0 ;																					//Set counta (digits for phone number) back to 0 (reset).
    	y++;																							//With each error message increase the log area line by one.
    }																									//
    
}while(counta < 10 || counta >= 11);																	//While conditions.	
gotoxy(116,18);																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//	
printf("Email: ");																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
do{																										//Do while loop for email verification.
	gotoxy(123,18);																						//
	scanf("%s", &s.semail);																				//Receive the user input for the email address.
	if(validate_local_address(s.semail) == 0)															//If condition the return of the validate_local_address is 0 (no @ given).
	{																									//	
		if(y == 45)																						//If the y axis (log area line) is 45 (end of log area).
		{																								//
			gotoxy(0,46);																				//	
			printf("Press any key to continue...");														//Print message on screen.		
			getch();																					//Wait for any user input.
			gotoxy(0,36);																				//
			for(j=36;j<=49; j++)																		//For loop to traverse the whole y axis of the log area.
			{																							//	
				gotoxy(0,j);																			//With each loop move to the next line.
				for(l=0;l<=150; l++)																	//Nested for loop to traverse the whole x axis of each line.
				printf(" ");																			//Fake clear the log area x axis by replacing all that is written with " ".
			}																							//
			gotoxy(0,36);																				//	
			y = 36;																						//Set y (log area axis) to be 36 which is the begining of the log area.
		}																								//	
		gotoxy(0, y);																					//
		printf("Error: Please use proper Email Address.");												//Print the error message on screen with each wrong input.
		y++;																							//Each wrong input increase the y axis of log area by one.
	}																									//	
}while(validate_local_address(s.semail) == 0);															//While condition.
gotoxy(116,20);																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
printf("Postal Code: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
fflush(stdin);																							//Flush the standard input.
scanf("%d", &s.spostal);																				//Read the user input for s.spostal.
fseek(supp, 0, SEEK_END);																				//Go to the end of the suppliers.csv file and save the data received before with the format given below.
fprintf(supp, "%d,%s,%s,%s,%s,%lu,%s,%d\n", ids, s.sname, s.scontact, s.saddress, s.scity, s.stel, s.semail, s.spostal);
fclose(supp);																							//Close the suppliers.csv file.
gotoxy(77,36);																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);								//				
printf("Registration Successful. Please Press any key to go back to Manager Menu.");					//With each successfull registration print message on screen.	
strcpy(username, turnname);																				//Replace the saved string for username from turnname to username again.
getch();																								//Wait for any user input.
sleep(2);																								//Sleep function for giving the necessary time for files to update.
system("copy data\\suppliers.csv data\\suppliers.txt"); 												//Copy the suppliers.csv file to suppliers.txt file.	
managerMenu(username, rights);																			//Return to the managerMenu by calling the function.
fclose(suppart);																						//Close the ascii art file.
}																										//
