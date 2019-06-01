#include "../headers/clients.h"
#include "../headers/structs3.h"
#define MAX_CNTNAME_SIZE 40
#define MAX_CNTLNAME_SIZE 40
#define MAX_CNTADDRESS_SIZE 55
#define MAX_CNTCITY_SIZE 15

void edit_clients(char username[], char rights[]){																	//Edit clients function.
																													//Variables definition start.
char *editclntsart = "art/border1.dat"; 
FILE *art = NULL, *clnts, *clnts_co, *notes;
char cha, last = '\n', line[1024], turnname[10], cname[40], *dirname = username;
char *tmp_cname, *tmp_clname, *tmp_caddress, *tmp_ccity, *tmp_cemail;
int count = 0, j =0, l = 3, y = 36, counta = 0, id, tmp_cid, tmp_cpostal;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
long long int tmp_ctel;
float tmp_cdiscount;
long long int tmp_tel1;
																													//Variables definition ends.
strcpy(turnname, username);																							//Saving username string in temporary turnname.
clnts=fopen("data/clients.csv","rb+");																				//Open clients.csv file in binary, read and append mode.	
clnts_co=fopen("data/clients_copy.csv", "w");																		//Open clients_copy.csv file in write mode. Rewrite is ok.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);							
system("CLS");																										//Clear Screen.
if((art = fopen(editclntsart,"r")) == NULL)                                 										//----------------------------------------------------------------
	{                                                                      											//
        fprintf(stderr,"error opening %s\n",editclntsart);                          								//	If condition in case of ascii art file is missing.
        return;                                                                  									//	
    }                                                                           									//----------------------------------------------------------------
print_title(art);																									//Print the ascii art file.

gotoxy(62,2);
printf("Welcome Back: ");																							//----------------------------------------------------------------
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//							Top Menu beggins.
printf("%s", username);																								//
gotoxy(62,3);																										//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
printf("Date: ");																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);													//
gotoxy(62,4);																										//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
printf("Notes: ");																									//
sprintf(dirname, "%s.txt", username);																				//
notes = fopen(dirname, "rb");																						//
	for(cha = getc(notes); cha != EOF; cha = getc(notes)){															//For loop to get all characters found inside the notes file.
		if(cha == '\n' && last != '\n')																				//If condition a new line is found
			count++;																								//Increase the count variable by 1 which means a new note is found.
		last = cha;																									//
	}																												//	
fclose(notes);																										//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//Print on screen the count variable which is the amount of notes.
printf("%d", count);																								//				
gotoxy(175, 2);																										//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//	
printf("Low Quantity: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//		
printf("%d", lowquantity());																						//Print on screen the low quantity products found from the function.
gotoxy(105,14);																										//							Top Menu beggins.
printf("Clients Edit Page");																						//-----------------------------------------------------------------


gotoxy(74,14);																										//
printf("ID: ");																										//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
scanf("%d", &id);																									//Get user input for the Client ID to edit.

while (fgets(line, 1024, clnts) != NULL)                                          									//While loop to retrieve all lines from clients.csv file one by one.
{																													//Each line get retrieved with a specific format defined by sscanf.	
	sscanf(line, "%d,%s,%s,%s,%s,%lu,%s,%d,%f,%d[^\n]", &cl.cid, cl.cname, cl.clname, cl.caddress, cl.ccity, &cl.ctel, cl.cemail, &cl.cpostal, &cl.cdiscount, &cl.ctotal);
	if(id == cl.cid)																								//If condition a match between user input and cl.cid is found.
	{ 																												//Strtok function used to split the long string into smaller ones.
		tmp_cid = atoi(strtok(line, ","));																			//Atoi function to convert the char string to integer.
		tmp_cname = strtok(NULL, ",");																				//	
		tmp_clname = strtok(NULL, ",");																				//
		tmp_caddress = strtok(NULL, ",");																			//
		tmp_ccity = strtok(NULL, ","); 																				//	
		tmp_ctel = atoll(strtok(NULL, ","));																		//Atoll function to convert char string to long long int.			
		tmp_cemail = strtok(NULL, ","); 																			//
		tmp_cpostal = atoi(strtok(NULL, ","));																		//Atoi function to convert the char string to integer.
		tmp_cdiscount = atof(strtok(NULL, ","));  																	//Atof function to convert the char string to float.	
		                           
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//----------------------------------------------------------------
		gotoxy(74,16); 																								//		Client registries field to be edited by the user.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);									//flushing the standart input is used to clear the input file to avoid
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//having trash data saved by mistake in the file when receiving the
		printf("Client First Name: ");																				//string values needed to be added to the proper field.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//In some cases where the fields require maybe more than 1 word, it is	
		fflush(stdin);																								//required to have the string measured and if the string is longer than 0
		scanf("%s", &cname);																						//and the last character of the string is the new line "\n" then replace
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//that character with the end string character "\0".
		gotoxy(74,18);																								//
		printf("Client Last Name: ");																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//	
		fflush(stdin);																								//
		fgets(tmp_clname, MAX_CNTLNAME_SIZE, stdin);																//	
		if ((strlen(tmp_clname) > 0) && (tmp_clname[strlen (tmp_clname) - 1] == '\n'))								//
    		tmp_clname[strlen (tmp_clname) - 1] = '\0';																//											
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
		gotoxy(74,20);																								//
		printf("Client Address: ");																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
		fflush(stdin);																								//
		fgets(tmp_caddress, MAX_CNTADDRESS_SIZE, stdin);															//
		if ((strlen(tmp_caddress) > 0) && (tmp_caddress[strlen (tmp_caddress) - 1] == '\n'))						//	
    		tmp_caddress[strlen (tmp_caddress) - 1] = '\0';															//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
		gotoxy(74,22);																								//		
		printf("Client's City': ");																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
		fflush(stdin);																								//
		fgets(tmp_ccity, MAX_CNTCITY_SIZE, stdin);																	//
		if ((strlen(tmp_ccity) > 0) && (tmp_ccity[strlen (tmp_ccity) - 1] == '\n'))									//
    		tmp_ccity[strlen (tmp_ccity) - 1] = '\0';													           	//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//			
		gotoxy(74,24);																								//
		printf("Client's Phone: ");																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
		fflush(stdin);																								//			
		do{																											//Do while loop to verify if phone entry has 10 or 11 digits.			
			fflush(stdin);																							//
			gotoxy(90, 24);																							//			
			scanf("%lu", &cl.ctel);																					//Receive the long unsigned integer value given by the user.	
			tmp_tel1 = cl.ctel;																						//Save temporarily the value given to tmp_tel1.
			while(tmp_tel1 != 0)																					//While loop to identify how many digits the given integer has.
   			{																										//
       			tmp_tel1 /= 10;																						//divide the number by 10 to get the digits.		
        		counta++;																							//With each division raise up the integer value counta.	
    		}																										//
    		if(counta <  10 || counta > 10)																			//If condition to verify if the given number has the correct values.			
    		{																										//
				if(y == 45)																							//If condition to verify if the log area is full.
				{																									//
					gotoxy(0,46);																					//Go to the end of the log area.
					printf("Press any key to continue...");															//Print on screen the message.	
					getch();																						//Waiting for user input.
					gotoxy(0,36);																					//----------------------------------------------------------------			
					for(j=36;j<=49; j++)																			//
					{																								//
						gotoxy(0,j);																				//For loop that is used to simulate the clear screen when the log
						for(l=0;l<=170; l++)																		//area is full. The simulation is possible through filling up the
							printf(" ");																			//whole area with empty space.
					}																								//----------------------------------------------------------------
					y = 36;																							//Once the log area is cleared, reset the y axis variable to 36.
					gotoxy(0,y);																					//Move cursor to 0,y which is 0,36.
				}																									//
    			gotoxy(0,y);																						//
    			printf("Error: Please give me a valid 10 digit number as phone number.");							//Error message print.
    			counta = 0 ;																						//reset the counta variable to 0.
    			y++;																								//Increase y (y axis) by one each time a new log line is added.			
     		}																										//
    																												//Keep lopping while the number is below 10 and more than 11.
		}while(counta < 10 || counta >= 11);																		//The reason I decided to have 10 and 11 digits if for phone numbers
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//with 11 digits (for example phone numbers located in Athens).
		gotoxy(74,26);																								//
		printf("Email: ");																							//			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
		do{																											//Do while loop to verify the correct email input.	
			gotoxy(81,26);																							//	
			scanf("%s", &cl.cemail);																				//Read user input for email.	
			if(validate_local_address(cl.cemail) == 0)															 	//If condition, the return of the function validate_local_address is 0.		
			{																										//
				if(y == 45)																							//If y axis is 45 which means that the log area is full.		
				{																									//
					gotoxy(0,46);																					//Go to the end of the log area.	
					printf("Press any key to continue...");															//Print on screen the message for any user input to continue.			
					getch();																						//Read the user input.
					gotoxy(0,36);																					//Move to the start of the log area.
					for(j=36;j<=49; j++)																			//For loop that clears the whole log area by simulating a clear screen.
					{																								//
						gotoxy(0,j);																				//
						for(l=0;l<=170; l++)																		//	
						printf(" ");																				//
					}																								//
					y = 36;																							//Set the y axis to 36.
					gotoxy(0,y);																					//Go to the beggining of the log area.
				}																									//	
				gotoxy(0, y);																						//
				printf("Error: Please use proper Email Address.");													//Print on screen the error message when wrong email input is given.
				counta = 0;																							//Set counta variable back to 0.
				y++;																								//Each time a wrong entry is given the y axis increase for new line.
			}																										//
		}while(validate_local_address(cl.cemail) == 0);																//Keep looping while the email has the proper input (including the "@"		
		gotoxy(116,16);																								//Character which is required in any email address.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
		printf("Postal Code: ");																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
		fflush(stdin);																								//Flush the standart input file.
		scanf("%d", &cl.cpostal);																					//Receive the user input for postal code.	
		gotoxy(116,18);																								//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
		printf("Discount: ");																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
		fflush(stdin);																								//Flush the standart input file.	
		scanf("%f", &cl.cdiscount);																					//Receive the user input for the discount.
		gotoxy(116,20);																								//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
		printf("Total: ");																							//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
		fflush(stdin);																								//Flush the standart input file.
		scanf("%d", &cl.ctotal);																					//Receive the user input for the total buys.			

		fseek(clnts_co, 0, SEEK_END);																				//Go to the end of the clnts_co file.	
		fprintf(clnts_co, "%d,%s,%s,%s,%s,%lu,%s,%d,%.2f,%d\n", cl.cid, cname, tmp_clname, tmp_caddress, tmp_ccity, cl.ctel, cl.cemail, cl.cpostal, cl.cdiscount, cl.ctotal);		
	}																												//And print into the new line the formated data received by the user as a new entry.
	else																											//
	{																												//Else if the ID is not found (entries that do not match the user input.	
		fseek(clnts_co, 0, SEEK_END);																				//Go to the end of the clnts_co file. 	
		fputs(line, clnts_co);																						//And place the line received as it is.	
	}																												//
} 																													//	
fclose(clnts);																										//Close the file clients.csv.
fclose(clnts_co);																									//Close the file clients_copy.csv.
gotoxy(2,36);																										//----------------------------------------------------------------
printf("Wait while files are being updated....                                                ");					//
sleep(7);																											//					Saving changes to the files Proccess
rename("data/clients.csv", "data/clients-backup.csv");																//Since it's not possible to edit .csv files while they are open,
gotoxy(2,37);																										//it is neccessary to have the changes saved in other temporary files
printf("Wait while files are being updated....                                                ");					//which then have to replace the original file. I realised after many
sleep(7);																											//tests, that in C (not sure about other languages / compilers) the
rename("data/clients_copy.csv", "data/clients.csv");																//proccess of closing / renaming / copying / removing files, require 
sleep(7);																											//some time in order to proceed and complete. After many tests,  
remove("data/clients-backup.csv");																					//running the functions without delay (or sleep) it ends up files not 
gotoxy(2,39);																										//being copied or renamed. Delay functions also some times seem not
printf("Files updated....                                                                     ");					//to be effective because the time needed to perform these changes
gotoxy(77,36);																										//vary depending on computer / file sizes and overall system load.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);											//
printf("Update Successful. Please Press any key to go back to Manager Menu.");										//-----------------------------------------------------------------	
strcpy(username, turnname);																							//Returning the saved username string.
getch();																											//Waiting for user input.
registries(username, rights);																						//Calling registries function once the job is done.
fclose(editclntsart);																								//Close the ascii art file.
}																													//End of function.

void clients(char username[], char rights[]){																		//Add clients function.
																													//Variables definition area begin.		
char *borderart = "art/border1.dat"; 
FILE *art = NULL, *clnts, *notes, *clnts_cp;
char* dirname = username;
cl.cid = 0;
int id = 0, counta = 0, count = 0, j, k, l, counter = 1, y = 36, ids = 0;
char c, ch, cha, last = '\n';   
long int recsize = sizeof(c);
time_t t = time(NULL);
struct tm tm = *localtime(&t);
char line[1024], turnname[10], cname[40];
long long int tmp_tel1;
																													//Variables definition area ends.			
strcpy(turnname, username);																							//Saving the username string into a temporary string named turnname.
system("copy data\\clients.csv data\\clients.txt"); 																//Copying the clients.csv file to clients.txt file.
clnts_cp=fopen("data/clients.txt", "r");																			//Open clients.txt file in read mode.
clnts=fopen("data/clients.csv","rb+");																				//Open clients.csv file in read mode.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
system("CLS");																										//Clear screen.
if((art = fopen(borderart,"r")) == NULL)                                 											//-----------------------------------------------------------------
	{                                                                      											//				
        fprintf(stderr,"error opening %s\n",borderart);                          									//If condition in case of the ascii art file is missing.
        return;                                                                  									//
    }                                                                           									//-----------------------------------------------------------------
print_title(art);																									//Print on screen the ascii art.
	gotoxy(62,2);																									//-----------------------------------------------------------------
	printf("Welcome Back: ");																						//					Top menu and shortcuts beggin.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("%s", username);																							//
	gotoxy(62,3);																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("Date: ");																								//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);												//
	gotoxy(62,4);																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("Notes: ");																								//
	sprintf(dirname, "%s.txt", username);																			//
	notes = fopen(dirname, "rb");																					//Open the notes menu.
	for(cha = getc(notes); cha != EOF; cha = getc(notes)){															//For loop to get all characters from the personal notes file.
		if(cha == '\n' && last != '\n')																				//If condition the character taken is the new line character '\n'.
			count++;																								//Increase the count variable by one. Count is the number of notes.
		last = cha;																									//Set the last variable (last character taken) to be the same as cha.
	}																												//
	fclose(notes);																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("%d", count);																							//Print the amount of notes found inside the personal notes file.
	gotoxy(62,5);																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("View Clients List : ");																					//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("~");																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("   Print Clients List : ");																				//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("^");																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("   View Notes : ");																						//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("#");																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("   Print Notes : ");																					//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf(">");																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("   Back : ");																							//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("!");																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);										//
	gotoxy(90,6);																									//
	printf("   NOTE!! : Shortcuts work only at the Client Name Entry!");											//
	gotoxy(175, 2);																									//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("Low Quantity: ");																						//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
	printf("%d", lowquantity());																					//Print on screen the result of the lowquantity function.
gotoxy(105,14);																										//						Top menu and shortcuts ends.
printf("Client Registration Page");																					//------------------------------------------------------------------
gotoxy(43,14);																										//
for (c = getc(clnts); c != EOF; c = getc(clnts)){																	//For loop that gets all characters from the clients.csv file.
	if (c == '\n')																									//Each time a new line character is found.
		ids++;																										//Increase by one the ids variable, which is the number of clients.
}																													//the last entry (last client) will be counted and then the ids will
gotoxy(74,14);																										//get another one increment (++ before ids) to get the new client id.
printf("ID: ");																										//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
printf("%d", ids);																									//Print on screen the new client id to be added.	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//	
gotoxy(74,16);																										//
printf("First Name: ");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
fclose(notes);																										//Close the notes file.
do																													//Do while loop for the shortcuts options.
{																													//
	fflush(stdin);																									//Flush the stdin file.		
	fgets(cname, MAX_CNTNAME_SIZE, stdin);																			//Get from the input file the cname given by the player with the max
	if ((strlen(cname) > 0) && (cname[strlen (cname) - 1] == '\n'))													//allowed size and if the string is not 0 size, and the prelast char
    	cname[strlen (cname) - 1] = '\0';																			//is new line '\n', change it to the end string character '\0'.
    if(cname[0] == '!')																								//! Shortcut for going back to previous menu.
    	managerMenu(username, rights);																				//Calling the previous menu managerMenu.
	if(cname[0] == '^')																								//^ Shortcut to print the clients list in log area.
	{																												//
		gotoxy(0,36);																								//
																													
		while(fgets(line, 1024, clnts_cp)) 																			//While loop to retrieve all entries from the copied clients file.
		{																											//
			if(counter == 10)																						//If condition the counter variable (end of log area) is 10.
			{																										//
				printf("\n Press any key to continue...");															//Print on screen the message.	
				getch();																							//Wait for the user input any key.
				gotoxy(0,36);																						//Go to the begining of the log area.
				for(j=36;j<=49; j++)																			 	//For loop that goes through each line in the log area.						
				{																									//	
					gotoxy(0,j);																					//Gotoxy function that goes line by line in log area.
					for(l=0;l<=150; l++)																			//Nested for loop to traverse the whole line in log area.
					printf(" ");																					//Replace all line characters with empty space (simulation of local CLS.			
				}																									//
			gotoxy(0,36);																							//Go back to the begining of the log area.
			counter = 1;																							//Set the start counter to 1 (first line of log area).
			}																										//
			printf("%s\n", line);																					//Print the whole line taken from the clients file.	
			counter++;																								//Each line printed will increase the counter of the log area lines.
		}																											//
	gotoxy(86,16);																									//
	}																												//
	if(cname[0] == '~')																								//~ shortcut to open the clients txt file.	
	{																												//
		system("data\\clients.txt");																				//Open the copy .txt file of clients.
		gotoxy(86,16);																								//
	}																												//	
	if(cname[0] == '#')																								//# shortcut to open the notes file.
	{																												//
		system(dirname);																							//Open the personal notes file named as the username.
		gotoxy(86,16);																								//
	}																												//
	if(cname[0] == '>')																								//> shortcut to print the notes on screen in log area.
	{																												//	
		notes = fopen(dirname, "rb");																				//Open the personal notes file in read and binary mode.
		gotoxy(0,36);																								//Go to the beggining of the log area. 
		for(j=36;j<=49; j++)																						//For loop that counts and moves cursor to all lines in log area.
		{																											//	
			gotoxy(0,j);																							//Move to each line one by one.
			for(l=0;l<=150; l++)																					//Nested for loop that traverse whole line one by one.
				printf(" ");																						//Replace all line characters with empty space (simulation of local CLS.		
		}																											//
		gotoxy(0,36);																								//	
		k = fgetc(notes);																							//Set k to be the first character taken from the personal notes file.
		while (k != EOF)																							//While loop to get all characters from personal notes file one by one.	
		{																											//Until it reach the end of the file.		
			printf ("%c", k);																						//Print on screen the character taken.		
			k = fgetc(notes); 																						//Set the k character to be the next character taken from personal notes file.
		}																											//
	gotoxy(86,16);																									//
	cname[0] = '^';																									//Set the first [0] charactar of the cname string to be ^ (randomly taken).
	}																												//This is needed to return at the beggining of the do while loop.
}while(cname[0] == '>' || cname[0] == '~' || cname[0] == '^' || cname[0] == '#');									//Keep the loop as long as the cname[0] is > or ~ or ^ or #.
fclose(clnts_cp);																									//Close the copy (txt) file of clients.	
fclose(notes);																										//Close the personal notes file.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
gotoxy(74,18);																										//
printf("Last Name: ");																								//				
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
fflush(stdin);																										//Flush the stdin file.
fgets(cl.clname, MAX_CNTLNAME_SIZE, stdin);																			//Get the user input from stdin and save it in cl.clname struct variable
if ((strlen(cl.clname) > 0) && (cl.clname[strlen (cl.clname) - 1] == '\n'))											//with the specific MAX_CNTLNAME_SIZE size and if the string taken is	
    cl.clname[strlen (cl.clname) - 1] = '\0';																		//bigger than 0 and the prelast character of the string is the new line
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//then replace the prelast character with the end string character.
gotoxy(74,20);																										//
printf("Address: ");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
fflush(stdin);																										//Flush the stdin file.			
fgets(cl.caddress, MAX_CNTADDRESS_SIZE, stdin);																		//Get the user input from stdin and save it in cl.caddress struct variable				
if ((strlen(cl.caddress) > 0) && (cl.caddress[strlen (cl.caddress) - 1] == '\n'))									//with the specific MAX_CNTADDRESS_SIZE size and if the string taken is 
    cl.caddress[strlen (cl.caddress) - 1] = '\0';																	//bigger than 0 and the prelast character of the string is the new line		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//then replace the prelast character with the end string character.
gotoxy(74,22);																										//
printf("City: ");																									//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//		
fflush(stdin);																										//Flush the stdin file.
fgets(cl.ccity, MAX_CNTCITY_SIZE, stdin);																			//Get the user input from stdin and save it in cl.ccity struct variable
if ((strlen(cl.ccity) > 0) && (cl.ccity[strlen (cl.ccity) - 1] == '\n'))											//with the specific MAX_CNTCITY_SIZE size and if the string taken is 
    cl.ccity[strlen (cl.ccity) - 1] = '\0';																			//bigger than 0 and the prelast character of the string is the new line
gotoxy(116,16);																										//then replace the prelast character with the end string character.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
printf("Tel 1: ");																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
fflush(stdin);																										//Flush the stdin file.
do{																													//-----------------------------------------------------------------				
	fflush(stdin);																									//	   Do while loop for telephone number validation check begin.
	gotoxy(123, 16);																								//			
	scanf("%lu", &cl.ctel);																							//Read user input for the telephone number saved as long unsigned.	
	tmp_tel1 = cl.ctel;																								//Save the number given into a temporary variable.	
	while(tmp_tel1 != 0)																							//While loop to check how many digits the number given has.		
   	{																												//
       	tmp_tel1 /= 10;																								//Divide the temporary variable with the phone number each time by 10.		
        counta++;																									//Each time the number is being divided in the loop increase counta.
    }																												//
    if(counta <  10 || counta > 10)																					//If the total counta is below 10 (digits) or higher than 10.				
    {																												//
		if(y == 45)																									//If the y axis reach the end of the log area.
		{																											//
			gotoxy(0,46);																							//Go to the last line of the log area.
			printf("Press any key to continue...");																	//Print on screen the message.
			getch();																								//Wait for any user input.
			gotoxy(0,36);																							//Go back to the begining of the log area.
			for(j=36;j<=49; j++)																					//For loop that goes through each log area line.	
			{																										//
				gotoxy(0,j);																						//Traverse each line one by one.
				for(l=0;l<=170; l++)																				//Nested for loop that traverse the x axis of each log area line.
					printf(" ");																					//Replace all line characters with empty space (simulation of local CLS.
			}																										//
			y = 36;																									//Set the y axis to the beggining of the log area.	
			gotoxy(0,y);																							//Go to the begining of the log area.	
		}																											//
    	gotoxy(0,y);																								//
    	printf("Error: Please give me a valid 10 digit number as phone number.");									//Print on screen the error message in case of wrong input.
    	counta = 0 ;																								//Set back the counta (counting phone digits) to 0.		
    	y++;																										//increase each time an error is given the y axis variable.
    }																												//
}while(counta < 10 || counta >= 11);																				//	   Do while loop for telephone number validation check ends.
gotoxy(116,18);																										//-----------------------------------------------------------------
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
printf("Email: ");																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//-----------------------------------------------------------------
do{																													//Do while loop for email validation beggin (require "@" character).
	gotoxy(123,18);																									//		
	scanf("%s", &cl.cemail);																						//Receive the user input for cl.cemail struct variable.			
	if(validate_local_address(cl.cemail) == 0)																		//If condition the return of validate_local_address(cl.cemail) is 0.
	{																												//Which means that the email address is not correct.
		if(y == 45)																									//If the y axis of the log area is 45 which is the end of log area.
		{																											//
			gotoxy(0,46);																							//Go to the end of the log area.
			printf("Press any key to continue...");																	//Print the error message.
			getch();																								//Wait for any user input.
			gotoxy(0,36);																							//Go to the beggining of the log area.
			for(j=36;j<=49; j++)																					//For loop that goes through each log area line one by one.	
			{																										//
				gotoxy(0,j);																						//Go with each repeat of the loop in the next line.
				for(l=0;l<=170; l++)																				//Nested for loop to traverse the whole line (x axis).
				printf(" ");																						//Replace all line characters with empty space (simulation of local CLS.
			}																										//
			y = 36;																									//Set y axis to be 36 which is the beggining of the log area.
			gotoxy(0,y);																							//Move to the beggining of the log area.		
		}																											//
		gotoxy(0, y);																								//
		printf("Error: Please use proper Email Address.");															//Print on screen the error message.
		y++;																										//Each time the user gives a wrong email increase the y axis by one.	
		counta++;																									//Increase with each wrong user input the counta variable by one.
	}																												//
}while(validate_local_address(cl.cemail) == 0);																		//Do while loop for email validation ends (require "@" character).			
gotoxy(116,20);																										//----------------------------------------------------------------
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
printf("Postal Code: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
fflush(stdin);																										//Flush the stdin file.
scanf("%d", &cl.cpostal);																							//Receive the user input for the cl.cpostal struct variable.
gotoxy(116,22);																										//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
printf("Discount: ");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);							//
fflush(stdin);																										//Flush the stdin file.		
scanf("%f", &cl.cdiscount);																							//Receive the user input for the cl.cdiscount struct variable.
gotoxy(116,26);																										//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
cl.ctotal = 0;																										//Set the total client spents for new clients to be 0.

fseek(clnts, 0, SEEK_END);																							//Move to the end of the clients file and print the new entry.
fprintf(clnts, "%d,%s,%s,%s,%s,%lu,%s,%d,%.2f,%d\n", ids, cname, cl.clname, cl.caddress, cl.ccity, cl.ctel, cl.cemail, cl.cpostal, cl.cdiscount, cl.ctotal);

fclose(clnts);																										//Close the clients.csv file.

gotoxy(77,36);																										//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);											//
printf("Registration Successful. Please Press any key to go back to main menu.");									//Print on screen the message for succesfull registry.
strcpy(username, turnname);																							//Replace the saved username string from turnname.
getch();																											//Wait for any user input.
system("copy data\\clients.csv data\\clients.txt");																	//Copy the clients.csv file into a new clients.txt file.				
managerMenu(username, rights);																						//Call the managerMenu function.
fclose(borderart);																									//Close the ascii art file.
}																													//End of add client function.
