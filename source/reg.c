#include "../headers/reg.h"
#include "../headers/structs.h"
#define MAX_ACCFNAME_SIZE 25
#define MAX_ACCLNAME_SIZE 25
#define MAX_ACCGENDER_SIZE 6
#define MAX_ACCADDRESS_SIZE 55
#define MAX_ACCCITY_SIZE 15

const char* getfield(char* line, int num);				

int valid_digit(long long int number){																			//Valid_digit function to verify the correct digits of a number.
					
	int counter = 0;																							//Counter variable definition and initialize at 0.
		
	while(number != 0){																							//While loop that lasts until the number is 0.
										
		number = number/10;																						//With each loop divide the number by 10.
		counter++;																								//Each loop increase the counter (digit) variable by one.
	}																											//
	
	return counter;																								//Return once the function ends the counter (number of digits).
	
}																												//Valid_digit function ends.


char* validate_local_address(char* email) {																		//Validate_local_address function to validate email address.

char* ptr;																										//Pointer character ptr.
char* current;																									//Pointer character current.	

    for (ptr = email; *ptr; ptr++) {																			//Found on internet.
        if (*ptr == '@' && ptr != email) {																		//Check that we saw at least one character
            return ptr+1;																						//Return the ptr+1 value.
        } else if (*current == ' ') {																			//Else if the current character point is empty. (no "@" symbol found).
            return 0;																							//return 0.		
        }
    }
    return 0;																									
}																												//Validate_local_address function ends.	


void edit_reg(char username[], char rights[]){																	//Edit_reg function begin.		
																												//Variables definition begin.
char *editregart = "art/border1.dat"; 
FILE *art = NULL, *acc, *acc_co, *notes;
int o, count = 0, j=0, l=3, y=36, counta = 0, counter = 1, temp_id, id;
char acc_id[4], characteri = 'a', cha, last = '\n', c, line[1024], turnname[10], fname[25], check = '/', check1 = '/';
char *dirname = username, *temp_fname, *temp_lname, *temp_gender, *temp_pdd, *temp_address, *temp_city, *temp_jdd, *temp_depart, *temp_user, *temp_password, *temp_admin;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
long long int temp_tel1, temp_tel2, temp_snn;
																												//Variables definition ends.
strcpy(turnname, username);																						//Save the username string into turnname.	
acc=fopen("data/employees.csv","rb+");																			//Open the employees.csv file in read, binary and append mode.
acc_co=fopen("data/employees_copy.csv", "w");																	//Open the employees_copy.csv file in write mode. Rewrite is ok.	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
system("CLS");																									//Clear screen.	
if((art = fopen(editregart,"r")) == NULL)                                 										//--------------------------------------------------------------------
	{                                                                      										//
        fprintf(stderr,"error opening %s\n",editregart);                          								//If condition in case the ascii art file does not exists.
        return;                                                                  								//
    }                                                                           								//--------------------------------------------------------------------	
print_title(art);																								//Print on screen the ascii art file.

gotoxy(62,2);																									//---------------------------------------------------------------------
printf("Welcome Back: ");																						//								Top Menu begin.
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
notes = fopen(dirname, "rb");																					//Open the notes file titled with the active username.	
for(cha = getc(notes); cha != EOF; cha = getc(notes)){															//For loop which takes all contents of the notes file character by character
	if(cha == '\n' && last != '\n')																				//until end of file and if the character taken is the new line charavter
		count++;																								//"\n" and the last variable character isn't the new line then increase
	last = cha;																									//the count variable by one. Count is the number of notes.
}																												//Finally set the last char variable to be the same as cha variable.
											
fclose(notes);																									//Close the notes file.

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
printf("%d", count);																							//Show up on screen the amount of notes found in the file.	
gotoxy(175, 2);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("Low Quantity: ");																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
printf("%d", lowquantity());																					//								Top Menu ends.
gotoxy(105,14);																									//---------------------------------------------------------------------
printf("Employee Edit Page");

gotoxy(74,14);																									//
printf("ID: ");																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
scanf("%d", &id);																								//Read the user input for the employee id to edit.

while (fgets(line, 1024, acc) != NULL)                                          								//While loop that gets the content of the employees.csv file line by line.
{																												//Each line is saved in line[1024] with the specific format given by sscanf.
	sscanf(line, "%d,%s,%s,%s,%s,%s,%s,%lu,%lu,%s,%d,%s,%s,%s,%s,%s[^\n]", &a.id, a.fname, a.lname, a.gender, a.dd, a.address, a.city, &a.tel1, &a.tel2, a.email, &a.ssn, a.ddjoin, a.department, a.user, a.password, a.administrator);
	if(id == a.id)																								//If condition the id given by user and the id taken from the current line match.
	{  
		temp_id = atoi(strtok(line, ","));																		//Set temp_id to be the first string of the line (before comma found) and convert into int.
		temp_fname = strtok(NULL, ",");																			//Set temp_fname to be the next string between comma's.
		temp_lname = strtok(NULL, ",");																			//Set temp_lname to be the next string between comma's.
		temp_gender = strtok(NULL, ",");																		//Set temp_gender to be the next string between comma's.
		temp_pdd = strtok(NULL, ","); 																			//Set temp_pdd to be the next string between comma's.	
		temp_address = strtok(NULL, ",");																		//Set temp_address to be the next string between comma's.
		temp_city = strtok(NULL, ",");  																		//Set temp_city to be the next string between comma's.
		temp_tel1 = atoll(strtok(NULL, ","));																	//Set temp_tel1 to be the next string between comma's. Converted to long long int.
		temp_tel2 = atoll(strtok(NULL, ","));																	//Set temp_tel2 to be the next string between comma's. Converted to long long int.				
		temp_snn = atoll(strtok(NULL, ","));																	//Set temp_snn to be the next string between comma's. Converted to long long int.	
		temp_jdd = strtok(NULL, ","); 																			//Set temp_jdd to be the next string between comma's.
		temp_depart = strtok(NULL, ","); 																		//Set temp_depart to be the next string between comma's.
		temp_user = strtok(NULL, ","); 																			//Set temp_user to be the next string between comma's.
		temp_password = strtok(NULL, ","); 																		//Set temp_password to be the next string between comma's.
		temp_admin = strtok(NULL, ",");                       													//Set temp_admin to be the next string between comma's.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//---------------------------------------------------------------------
		gotoxy(74,16); 																							//						Edit area of the employee entry.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);								//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		printf("Employee Name: ");																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//
		scanf("%s", &fname);																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		gotoxy(74,18);																							//
		printf("Employee Last Name: ");																			//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//	
		fflush(stdin);																							//
		fgets(temp_lname, MAX_ACCLNAME_SIZE, stdin);															//
		if ((strlen(temp_lname) > 0) && (temp_lname[strlen (temp_lname) - 1] == '\n'))							//
    		temp_lname[strlen (temp_lname) - 1] = '\0';															//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		gotoxy(74,20);																							//
		printf("Employee Gender: ");																			//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//
		fgets(temp_gender, MAX_ACCGENDER_SIZE, stdin);															//
		if ((strlen(temp_gender) > 0) && (temp_gender[strlen (temp_gender) - 1] == '\n'))						//
    		temp_gender[strlen (temp_gender) - 1] = '\0';														//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		gotoxy(74,22);																							//
		printf("Birthdate (dd/mm/yyyy): ");																		//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		do{																										//Do while loop to validate correct user input for birthdate.
			fflush(stdin);																						//Flush the standard input file.
			gotoxy(97,22);																						//
			scanf("%d%c%d%c%d", &a.dd, &check, &a.mm, &check1, &a.yyyy);										//Read the user input for day, month and year with "/ character" between them.
			if(a.dd < 1)																						//If condition the day given by the user is below 1 (wrong input).
			{																									//
				if(counter == 10)																				//If condition the counter variable is 10. This variable counts the log area lines.
				{																								//
					gotoxy(0,y);																				//Move to the new line of log area.
					printf("Press any key to continue...");														//Send the print message on screen.
					getch();																					//Wait for any user input.
					gotoxy(0,36);																				//Move to the begining of the log entry.
					for(j=36;j<=49; j++)																		//For loop to traverse the whole log area lines.
					{																							//
						gotoxy(0,j);																			//	
						for(l=0;l<=170; l++)																	//Nested for loop to traverse the whole x axis of each line.	
							printf(" ");																		//Fake erase what is written in log area by replacing them with " ".
					}																							//
				gotoxy(0,36);																					//Move cursor again to the begining of the log area.
				counter = 1;																					//Set counter to be 1 (reset).	
				y=36;																							//Set y axis of gotoxy to be 36 (reset log area).
				}																								//
				gotoxy(0,y);																					//Go to the 0,y coords.
				printf("Wrong Input. Day cannot be below 1.");													//Print the error message.
				y++;																							//Increase y axis of gotoxy by one.
				counter++;																						//Increase the counter (lines of wrong messages) by one.	
			}																									//	
			if(a.dd > 31)																						//IF condition the day given is higher than 31.
			{																									//---------------------------------------------------------------------	
				if(counter == 10)																				//							As Above begin.
				{																								//	
					gotoxy(0,y);																				//	
					printf("Press any key to continue...");														//
					getch();																					//
					gotoxy(0,36);																				//
					for(j=36;j<=49; j++)																		//
					{																							//	
						gotoxy(0,j);																			//
						for(l=0;l<=170; l++)																	//
							printf(" ");																		//	
					}																							//	
				gotoxy(0,36);																					//
				counter = 1;																					//	
				y=36;																							//		
				}																								//
				gotoxy(0,y);																					//	
				printf("Wrong Input. Day cannot be bigger than 31.");											//	
				y++;																							//
				counter++;																						//
			}																									//
			if(a.mm < 1)																						//If condition the month given is below 1 (wrong input).	
			{																									//
				if(counter == 10)																				//		
				{																								//
					gotoxy(0,y);																				//
					printf("Press any key to continue...");														//
					getch();																					//
					gotoxy(0,36);																				//	
					for(j=36;j<=49; j++)																		//	
					{																							//
						gotoxy(0,j);																			//
						for(l=0;l<=170; l++)																	//	
							printf(" ");																		//			
					}																							//
				gotoxy(0,36);																					//
				counter = 1;																					//
				y=36;																							//
				}																								//
				gotoxy(0,y);																					//
				printf("Wrong Input. Month cannot be below 1.");												//					
				y++;																							//
				counter++;																						//
			}																									//		
			if(a.mm > 12)																						//If condition the month given is higher than 12 (wrong input).
			{																									//	
				if(counter == 10)																				//	
				{																								//
					gotoxy(0,y);																				//
					printf("Press any key to continue...");														//	
					getch();																					//
					gotoxy(0,36);																				//
					for(j=36;j<=49; j++)																		//
					{																							//
						gotoxy(0,j);																			//
						for(l=0;l<=170; l++)																	//
							printf(" ");																		//
					}																							//
				gotoxy(0,36);																					//					
				counter = 1;																					//	
				y=36;																							//
				}																								//
				gotoxy(0,y);																					//
				printf("Wrong Input. Month cannot be bigger than 12.");											//
				y++;																							//
				counter++;																						//
			}																									//
			if(a.yyyy > 2002)																					//If condition the year given is higher than 2002 (minor age).
			{																									//
				if(counter == 10)																				//	
				{																								//
					gotoxy(0,y);																				//
					printf("Press any key to continue...");														//
					getch();																					//	
					gotoxy(0,36);																				//
					for(j=36;j<=49; j++)																		//
					{																							//
						gotoxy(0,j);																			//
						for(l=0;l<=170; l++)																	//
							printf(" ");																		//
					}																							//	
				gotoxy(0,36);																					//
				counter = 1;																					//	
				y=36;																							//
				}																								//
				gotoxy(0,y);																					//
				printf("Wrong Input. Years above 2002 should not work by law.");								//
				y++;																							//	
				counter++;																						//
			}																									//
			if(a.yyyy < 1950)																					//If condition the year given is below 1950 (pension age).
			{																									//
				if(counter == 10)																				//
				{																								//
					gotoxy(0,y);																				//
					printf("Press any key to continue...");														//		
					getch();																					//	
					gotoxy(0,36);																				//	
					for(j=36;j<=49; j++)																		//
					{																							//
						gotoxy(0,j);																			//
						for(l=0;l<=170; l++)																	//
							printf(" ");																		//
					}																							//
				gotoxy(0,36);																					//	
				counter = 1;																					//
				y=36;																							//
				}																								//
				gotoxy(0,y);																					//	
				printf("Wrong Input. Years below 1950 should not work by law.");								//
				y++;																							//
				counter++;																						//
			}																									//
			if(check != '/')																					//If condition seperator character is not "/".
			{																									//
				if(counter == 10)																				//
				{																								//
					gotoxy(0,y);																				//
					printf("Press any key to continue...");														//	
					getch();																					//
					gotoxy(0,36);																				//	
					for(j=36;j<=49; j++)																		//
					{																							//
						gotoxy(0,j);																			//
						for(l=0;l<=170; l++)																	//
							printf(" ");																		//
					}																							//
				gotoxy(0,36);																					//
				counter = 1;																					//	
				y=36;																							//
				}																								//		
				gotoxy(0,y);																					//	
				printf("Wrong Input. Please use '/' as date seperator.");										//
				y++;																							//
				counter++;																						//							As Above ends.
			}																									//---------------------------------------------------------------------
		}while(a.dd < 1 || a.dd > 31 || check != '/' || check1 != '/' || a.mm < 1 || a.mm > 12 || a.yyyy < 1950 || a.yyyy > 2002); //Conditions.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		gotoxy(74,24);																							//
		printf("Address: ");																					//		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//
		fgets(temp_address, MAX_ACCADDRESS_SIZE, stdin);														//
		if ((strlen(temp_address) > 0) && (temp_address[strlen (temp_address) - 1] == '\n'))					//
    		temp_address[strlen (temp_address) - 1] = '\0';														//			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		gotoxy(74,26);																							//
		printf("City: ");																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//
		fgets(temp_city, MAX_ACCCITY_SIZE, stdin);																//
		if ((strlen(temp_city) > 0) && (temp_city[strlen (temp_city) - 1] == '\n'))								//
    		temp_city[strlen (temp_city) - 1] = '\0';															//		
		gotoxy(116,16);																							//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//	
		printf("Tel 1: ");																						//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//		
		do{																										//Do while loop for user input validation of phone number.	
			fflush(stdin);																						//
			gotoxy(123, 16);																					//
			scanf("%lu", &a.tel1);																				//Read the user input for the phone number.
			temp_tel1 = a.tel1;																					//Copy the phone number into a temp variable for checking.
			while(temp_tel1 != 0)																				//While loop the temporary variable isn't 0.
   			{																									//
       			temp_tel1 /= 10;																				//Devide the temporary phone number variable by 10 (to count digits).
        		counta++;																						//Increase digit variable (counta) by one.	
    		}																									//
    		if(counta <  10 || counta > 10)																		//If condition the counta is below 10 or above 10.	
    		{																									//
				if(y == 45)																						//If condition to check if the log area is full.	
				{																								//	
					gotoxy(5,46);																				//
					printf("Press any key to continue...");														//Print on screen the message.		
					getch();																					//Wait for any user input.
					gotoxy(0,36);																				//
					for(j=36;j<=49; j++)																		//For loop to traverse all lines of the log area one by one.
					{																							//
						gotoxy(0,j);																			//Move to the begining of each line.
						for(l=0;l<=170; l++)																	//Nested for loop to traverse the x axis of each line.
							printf(" ");																		//Fake clear screen the whole line by replacing text with " ".		
					}																							//
					y = 36;																						//	
					gotoxy(0,y);																				//
				}																								//
    			gotoxy(0,y);																					//
    			printf("Error: Please give me a valid 10 digit number as phone number.");						//Print on screen error message.
    			counta = 0 ;																					//Set back the counta variable to 0.
    			y++;																							//Increase with each error given the y axis of the log area.
     		}																									//
		}while(counta < 10 || counta >= 11);																	//Conditions.	
		counta = 0;																								//Set counta variable to 0. (reseting).
		gotoxy(116,18);																							//												
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//	
		printf("Tel 2: ");																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//
		do{																										//Do while loop for validation user input for second telephone.
			fflush(stdin);																						//---------------------------------------------------------------------
			gotoxy(123, 18);																					//							As above begin.			
			scanf("%lu", &a.tel2);																				//	
			temp_tel2 = a.tel2;																					//
			while(temp_tel2 != 0)																				//
    		{																									//
      			temp_tel2 /= 10;																				//	
        		counta++;																						//
    		}																									//	
   			if(counta <  10 || counta > 10)																		//
    		{																									//
				if(y == 45)																						//	
				{																								//	
					gotoxy(5,46);																				//
					printf("Press any key to continue...");														//
					getch();																					//
					gotoxy(0,36);																				//
					for(j=36;j<=49; j++)																		//
					{																							//
						gotoxy(0,j);																			//	
						for(l=0;l<=170; l++)																	//	
							printf(" ");																		//
					}																							//
					y = 36;																						//
					gotoxy(0,y);																				//			
				}																								//
    			gotoxy(5,y);																					//
    			printf("Error: Please give me a valid 10 digit number as phone number.");						//	
    			counta = 0;																						//
    			y++;																							//
     		}																									//
		}while(counta < 10 || counta >= 11);																	//							As above ends.			
		gotoxy(116,20);																							//---------------------------------------------------------------------
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		printf("Email: ");																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		do{																										//Do while loop for validation user input of email address.
			gotoxy(123,20);																						//
			scanf("%s", &a.email);																				//Read the user input for the email address.
			if(validate_local_address(a.email) == 0)															//If the return of the validate_local_address() is 0.	
			{																									//	
				if(y == 45)																						//If the log area line is the last one.
				{																								//
					gotoxy(0,46);																				//
					printf("Press any key to continue...");														//Print message on screen.	
					getch();																					//Wait for any user input.
					gotoxy(0,36);																				//Go to the begining of the log area.	
					for(j=36;j<=49; j++)																		//For loop to traverse the all log area lines one by one.
					{																							//
						gotoxy(0,j);																			//Move to each line one by one.					
						for(l=0;l<=170; l++)																	//Nested for loop to traverse the x axis of the log area line.	
							printf(" ");																		//Fake clear screen by replacing what is written with " ".
					}																							//
					y = 36;																						//Set y (y axis, line) to be the first one in log area.
					gotoxy(0,y);																				//Go to the begining of the next line in log area.
				}
				gotoxy(0, y);																					//Go to the 0 x and y value y axis of gotoxy.	
				printf("Error: Please use proper Email Address.");												//Print the error message.
				counta = 0;																						//Set the counta (lines of log area) to be 0 again (Reset).
				y++;																							//Increase the y axis each time by one.
			}																									//
		}while(validate_local_address(a.email) == 0);															//While condition is when the return of the function is 0 (wrong input).	
		gotoxy(116,22);																							//			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//	
		printf("SSN: ");																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//
		scanf("%d", &a.ssn);																					//
		gotoxy(116,24);																							//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//	
		printf("Join Date: ");																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//		
		scanf("%d/%d/%d", &a.ddjoin, &a.mmjoin, &a.yyyyjoin);													//
		gotoxy(116,26);																							//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		printf("Department: ");																					//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//	
		scanf("%s", &a.department);																				//
		gotoxy(116,28);																							//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		printf("Administration: ");																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//	
		a.administrator = getch();																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		gotoxy(74,29);																							//
		printf("Username (max 10 char): ");																		//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//	
		scanf("%s", &a.user);																					//	
		gotoxy(116,29);																							//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);			//
		printf("Password (max 10 char): ");																		//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);				//
		fflush(stdin);																							//						Edit area of the employee entry ends.
		scanf("%s", &a.password);																				//----------------------------------------------------------------------
		
		fseek(acc_co, 0, SEEK_END);																				//Go to the end of the employees_copy.csv file and print the edited line.	
		fprintf(acc_co, "%d,%s,%s,%s,%d/%d/%d,%s,%s,%lu,%lu,%s,%d,%d/%d/%d,%s,%s,%s,%c\n", a.id, fname, temp_lname, temp_gender, a.dd, a.mm, a.yyyy, temp_address, temp_city, a.tel1, a.tel2, a.email, a.ssn, a.ddjoin, a.mmjoin, a.yyyyjoin, a.department, a.user, a.password, a.administrator);		
	}																											//		
	else																										//Else, in case of the id given by user and the line employee id does not match.
	{																											//
		fseek(acc_co, 0, SEEK_END);																				//Go to the end of the employees_copy.csv file.			
		fputs(line, acc_co);																					//And place the line untouched as taken.
	}																											//
} 																												//	
fclose(acc);																									//Close employees.csv file.
fclose(acc_co);																									//Close employees_copy.csv file.
gotoxy(2,36);																									//	
printf("Wait while files are being updated....                                                              ");	//Print message.
sleep(7);																										//Sleep function to give time for the files to be saved properly.	
rename("data/employees.csv", "data/employees-backup.csv");														//Rename the employees.csv file to employees-backup.csv file.
gotoxy(2,37);																									//	
printf("Wait while files are being updated....                                                              "); //Print message.
sleep(7);																										//Sleep function.	
rename("data/employees_copy.csv", "data/employees.csv");														//Rename the employees_copy.csv to employees.csv.
sleep(7);																										//Sleep function.
remove("data/employees-backup.csv");																			//Remove the backup file.
gotoxy(2,39);																									//
printf("Files updated....                                                                                    ");//Print message.
gotoxy(77,36);																									//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);										//
printf("Update Successful. Please Press any key to go back to Manager Menu.");									//Print message.
strcpy(username, turnname);																						//Replace the previously saved username saved in turnname.	
getch();																										//Wait for any user input.
registries(username, rights);																					//Go back to the registries menu by calling the function.
fclose(editregart);																								//Close the ascii art file.
}																												//End of the edit employee function.

void reg(char username[], char rights[]){																		//Reg function to register employees.
																												//Variables definition begin.		
char *borderart = "art/border1.dat"; 	
FILE *art = NULL, *acc, *acc_cp, *notes;
char* dirname = username;
a.id = 0;
a.fname[0] = '^';        
char text[78] = "[SYSTEM]: Welcome to the Company's manpower. This is the first automatic Note.";
long int recsize = sizeof(a);
time_t t = time(NULL);
struct tm tm = *localtime(&t);
char p, last = 'n', cha, ch, c, line[1024], turnname[10], check = '/', check1 = '/';                  
int k, j, l, counter = 1, count = 0, id = 0, y =36, counta = 0, tmp_tel1, tmp_tel2, countemps=0;
																												//Variables definition end.
strcpy(turnname, username);																						//Save the username string to the temporary turnname.
system("copy data\\employees.csv data\\employees.txt");                                                   	    //System Command that copy employees.csv to employees.txt
acc=fopen("data/employees.csv","rb+");																			//Open the file employees.csv file in read, binary and append mode.
acc_cp=fopen("data/employees.txt", "r");																		//Open the file employees.txt in read mode.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
system("CLS");																									//Clear screen.
if((art = fopen(borderart,"r")) == NULL)                                 										//---------------------------------------------------------------------
	{                                                                      										//
        fprintf(stderr,"error opening %s\n",borderart);                          								//If condition in case the ascii art file does not exist.
        return;                                                                  								//
    }                                                                           								//---------------------------------------------------------------------
print_title(art);																								//Print ascii art on screen.
gotoxy(62,2);																									//-------------------------------------------------------------------------
printf("Welcome Back: ");																						//							Top Menu begin.
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
notes = fopen(dirname, "rb");																					//Open the notes file titled as the active user in read and binary mode.
for(cha = getc(notes); cha != EOF; cha = getc(notes)){															//For loop to read the notes file character by character until end of file.
	if(cha == '\n' && last != '\n')																				//If condition the character found is the new line "\n" and last isn't "\n".	
		count++;																								//Increase the count variable by one (count is the number of personal notes).
	last = cha;																									//Set last to be the current character.
}																												//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//		
printf("%d", count);																							//
gotoxy(62,5);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("View Employee's List : ");																				//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
printf("~");																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("   Print Employee List : ");																			//
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
printf("   NOTE!! : Shortcuts work only at the First Name Entry!");												//
gotoxy(175, 2);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("Low Quantity: ");																						//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
printf("%d", lowquantity());																					//Call lowquantity() function to check the amount of low products in warehouse.
gotoxy(102,14);																									//							Top Menu ends.
printf("Employee Registration Page");																			//-------------------------------------------------------------------------
gotoxy(43,14);																									//
for (c = getc(acc); c != EOF; c = getc(acc)){																	//For loop to read the whole employees file char by char until end of file.
	if (c == '\n')																								//If the character found is the new line "\n". 
		countemps++;								  															//Increase the counting employees variables by one.
}																												//
gotoxy(74,14);																									//
printf("ID: ");																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
printf("%d", countemps);																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
gotoxy(74,16);																									//
printf("First Name(max 25): ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
fclose(notes);																									//Close the personal notes file.
do																												//Do while loop for shortcuts.
{																												//	
	fflush(stdin);																								//Flush the standard input file.	
	fgets(a.fname, MAX_ACCFNAME_SIZE, stdin);																	//Get from the input file the fname variable with max_accfname_size size.
	if ((strlen(a.fname) > 0) && (a.fname[strlen (a.fname) - 1] == '\n'))										//If condition the length of the string taken is bigger than 0 and the 
    	a.fname[strlen (a.fname) - 1] = '\0';																	//Prelast character of the string is the new line "\n", then replace that with end string.
    if(a.fname[0] == '!')																						//Shortcut !.
    	managerMenu(username, rights);																			//Go back by calling the managerMenu function.
	if(a.fname[0] == '^')																						//Shortcut ^.
	{																											//
		gotoxy(0,y);																							//
	
		while(fgets(line, 1024, acc_cp))																		//While loop that receives the entries of employees.txt line by line.	 
		{																										//
			if(counter == 10)																					//If condition counter variable (which counts lines of log area) is 10.		
			{																									//	
				printf("\n Press any key to continue...");														//Print message.
				getch();																						//Wait for any user input.
				gotoxy(0,36);																					//
				for(j=36;j<=49; j++)																			//For loop to traverse all the log area lines.
				{																								//
					gotoxy(0,j);																				//Move to each line one by one.
					for(l=0;l<=170; l++)																		//Nested for loop to traverse each line in their x axis.
					printf(" ");																				//Fake clear log area by replacing all characters with " ".
				}																								//	
			gotoxy(0,36);																						//
			counter = 1;																						//Set the counter (log area lines) to 1.
			}																									//
			printf("%s\n", line);																				//Print on screen the line received from the .txt file.
			counter++;																							//Increse counter variable by one (line of log area).
			y= y+2;																								//Increase the y axis by 2 (it prints a blank line also from txt file).						
		}																										//
		gotoxy(94,16);																							//
	}																											//	
	if(a.fname[0] == '~')																						//Shortcut ~.
		system("data\\employees.txt");																			//Open for the user the employees.txt file.
	if(a.fname[0] == '#')																						//Shortcut #.
		system(dirname);																						//Open the personal notes file (dirname has notes.txt string) for the user.
	if(a.fname[0] == '>')																						//Shortcut >.
	{																											//
		notes = fopen(dirname, "rb");																			//Open the personal notes file in read and binary mode.	
		gotoxy(0,y);																							//
		for(j=36;j<=49; j++)																					//For loop to traverse all log area lines.	
		{																										//
			gotoxy(0,j);																						//Move to each line one by one.		
			for(l=0;l<=170; l++)																				//Nested for loop to traverse in x axis all lines of log area.				
				printf(" ");																					//Fake clear screen for log area by replacing all characters with " ".
		}																										//	
		gotoxy(0,y);																							//
		k = fgetc(notes);																						//Set k to be the next character received from personal notes file.
		while (k != EOF)																						//While loop to read all characters from personal notes file 1 by 1.
		{																										//			
			printf ("%c", k);																					//Print on screen all characters received.	
			k = fgetc(notes);																					//Set k to be the next character received from personal notes file.
			if(k == '\n')																						//If the k variable is the new line character "\n".
			{																									//
				counter++;																						//Increase the counter (log area lines counter) by one.	
				y++;																							//Increase the y axis of the log area by one (new line for each note).
			} 																									//
		}																										//
		gotoxy(94,16);																							//
	}																											//	
}while(a.fname[0] == '>' || a.fname[0] == '^' || a.fname[0] == '~' || a.fname[0] == '#' );						//While conditions.
fclose(acc_cp);																									//Close the employees.txt file.
fclose(notes);																									//Close the active's user personal notes file.		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
gotoxy(74,18);																									//				
printf("Last Name(max 25): ");																					//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
fflush(stdin);																									//
fgets(a.lname, MAX_ACCLNAME_SIZE, stdin);																		//Get the user input for lastname from stdin with size = MAX_ACCLNAME_SIZE
if ((strlen(a.lname) > 0) && (a.lname[strlen (a.lname) - 1] == '\n'))											//If the length of the string is bigger than 0 and the prelast character is			
    a.lname[strlen (a.lname) - 1] = '\0';																		//the new line "\n" then replace that character with the end string "\0".
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
gotoxy(74,20);																									//
printf("Gender(Male/Female): ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
fflush(stdin);																									//
fgets(a.gender, MAX_ACCGENDER_SIZE, stdin);																		//Get the user input for gender from stdin with size = MAX_ACCGENDER_SIZE
if ((strlen(a.gender) > 0) && (a.gender[strlen (a.gender) - 1] == '\n'))										//If the length of the string is bigger than 0 and the prelast character is
    a.gender[strlen (a.gender) - 1] = '\0';																		//the new line "\n" then replace that character with the end string "\0".
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
gotoxy(74,22);																									//			
printf("Birthday (dd/mm/yyyy): ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
do{																												//Do while loop for birthday input verification.		
	fflush(stdin);																								//Flush the standard input file.
	gotoxy(98,22);																								//
	scanf("%d%c%d%c%d", &a.dd, &check, &a.mm, &check1, &a.yyyy);												//Receive the user input for the birthday of the employee.
	if(a.dd < 1)																								//If condition the day given is below 1 (wrong input).
	{																											//
		if(counter == 10)																						//If condition the counter variable (log area lines) is 10 (full).	
		{																										//
			gotoxy(0,y);																						//
			printf("Press any key to continue...");																//Print message.
			getch();																							//Wait for any user input.
			gotoxy(0,36);																						//
			for(j=36;j<=49; j++)																				//For loop to traverse the log area line by line.
			{																									//	
				gotoxy(0,j);																					//
				for(l=0;l<=170; l++)																			//For loop to traverse the log area x axis.	
				printf(" ");																					//Fake clear screen of log area by replacing all written with " ".
			}																									//
		gotoxy(0,36);																							//
		counter = 1;																							//Set counter (log area lines) back to 1.
		y=36;																									//Set the y axis of cursor to be 36 (initial log area).
		}																										//
		gotoxy(0,y);																							//	
		printf("Wrong Input. Day cannot be below 1.");															//Print error message.
		y++;																									//Increase y axis by one each time a log message is post.
		counter++;																								//Increase counter (log area lines) with each error message.
	}																											//
	if(a.dd > 31)																								//If condition in case of user input for day is above 31.
	{																											//As above.
		if(counter == 10)																						//
		{																										//
			gotoxy(0,y);																						//
			printf("Press any key to continue...");																//
			getch();																							//
			gotoxy(0,36);																						//			
			for(j=36;j<=49; j++)																				//
			{																									//	
				gotoxy(0,j);																					//
				for(l=0;l<=170; l++)																			//
				printf(" ");																					//	
			}																									//
		gotoxy(0,36);																							//
		counter = 1;																							//
		y=36;																									//
		}																										//
		gotoxy(0,y);																							//
		printf("Wrong Input. Day cannot be bigger than 31.");													//	
		y++;																									//
		counter++;																								//
	}																											//
	if(a.mm < 1)																								//If condition in case of user input for month below 1 (wrong input).
	{																											//As above.
		if(counter == 10)																						//
		{																										//
			gotoxy(0,y);																						//		
			printf("Press any key to continue...");																//
			getch();																							//
			gotoxy(0,36);																						//
			for(j=36;j<=49; j++)																				//		
			{																									//
				gotoxy(0,j);																					//
				for(l=0;l<=170; l++)																			//
					printf(" ");																				//
			}																									//
		gotoxy(0,36);																							//
		counter = 1;																							//
		y=36;																									//
		}																										//
		gotoxy(0,y);																							//
		printf("Wrong Input. Month cannot be below 1.");														//
		y++;																									//
		counter++;																								//		
	}																											//
	if(a.mm > 12)																								//If condition in case of user input for month above 12 (wrong input).
	{																											//
		if(counter == 10)																						//
		{																										//	
			gotoxy(0,y);																						//
			printf("Press any key to continue...");																//
			getch();																							//
			gotoxy(0,36);																						//	
			for(j=36;j<=49; j++)																				//
			{																									//
				gotoxy(0,j);																					//	
				for(l=0;l<=170; l++)																			//	
				printf(" ");																					//		
			}																									//
		gotoxy(0,36);																							//
		counter = 1;																							//	
		y=36;																									//	
		}																										//
		gotoxy(0,y);																							//
		printf("Wrong Input. Month cannot be bigger than 12.");													//
		y++;																									//
		counter++;																								//		
	}																											//
	if(a.yyyy > 2002)																							//If condition in case of user input for year above 2002 (minor).
	{																											//As above.	
		if(counter == 10)																						//
		{																										//
			gotoxy(0,y);																						//
			printf("Press any key to continue...");																//		
			getch();																							//
			gotoxy(0,36);																						//	
			for(j=36;j<=49; j++)																				//
			{																									//
				gotoxy(0,j);																					//
				for(l=0;l<=170; l++)																			//
				printf(" ");																					//
			}																									//	
		gotoxy(0,36);																							//
		counter = 1;																							//
		y=36;																									//
		}																										//
		gotoxy(0,y);																							//	
		printf("Wrong Input. Years above 2002 should not work by law.");										//
		y++;																									//
		counter++;																								//
	}																											//
	if(a.yyyy < 1950)																							//If condition in case of user input for year below 1950 (pension).
	{																											//
		if(counter == 10)																						//
		{																										//
			gotoxy(0,y);																						//
			printf("Press any key to continue...");																//
			getch();																							//
			gotoxy(0,36);																						//
			for(j=36;j<=49; j++)																				//	
			{																									//	
				gotoxy(0,j);																					//
				for(l=0;l<=170; l++)																			//
				printf(" ");																					//
			}																									//	
		gotoxy(0,36);																							//
		counter = 1;																							//
		y=36;																									//
		}																										//
		gotoxy(0,y);																							//
		printf("Wrong Input. Years below 1950 should not work by law.");										//
		y++;																									//
		counter++;																								//
	}																											//
	if(check != '/')																							//If condition to check the date/month/year seperation character.
	{																											//	
		if(counter == 10)																						//
		{																										//
			gotoxy(0,y);																						//
			printf("Press any key to continue...");																//	
			getch();																							//
			gotoxy(0,36);																						//
			for(j=36;j<=49; j++)																				//
			{																									//	
				gotoxy(0,j);																					//	
				for(l=0;l<=170; l++)																			//
				printf(" ");																					//	
			}																									//	
		gotoxy(0,36);																							//
		counter = 1;																							//
		y=36;																									//
		}																										//
		gotoxy(0,y);																							//
		printf("Wrong Input. Please use '/' as date seperator.");												//			
		y++;																									//
		counter++;																								//
	}																											//
}while(a.dd < 1 || a.dd > 31 || check != '/' || check1 != '/' || a.mm < 1 || a.mm > 12 || a.yyyy < 1950 || a.yyyy > 2002); // While loop conditions.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
gotoxy(74,24);																									//	
printf("Address: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
fflush(stdin);																									//
fgets(a.address, MAX_ACCADDRESS_SIZE, stdin);																	//User input for address, taken from stdin with size = MAX_ACCADDRESS_Size.
if ((strlen(a.address) > 0) && (a.address[strlen (a.address) - 1] == '\n'))										//If the length of the address is bigger than 0 and the prelast character is
    a.address[strlen (a.address) - 1] = '\0';																	//the new line "\n" then set the end of the string "\0" to be in that place.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
gotoxy(74,26);																									//
printf("City: ");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
fflush(stdin);																									//
fgets(a.city, MAX_ACCCITY_SIZE, stdin);																			//User input for city taken from stdin with size = MAX_ACCCITY_SIZE.
if ((strlen(a.city) > 0) && (a.city[strlen (a.city) - 1] == '\n'))												//If the length of the city is bigger than 0 and the prelast character is
    a.city[strlen (a.city) - 1] = '\0';																			//the new line "\n" then set the end of the string "\0" to be in that place.
gotoxy(121,16);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//	
printf("Tel 1: ");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//

do{																												//Do while loop to validate correct user input for phone number.
	fflush(stdin);																								//Flush the standard input file.	
	gotoxy(129, 16);																							//
	scanf("%lu", &a.tel1);																						//Read the user input for phone number saved as long unsigned int variable.	
	tmp_tel1 = a.tel1;																							//Save the phone number given in a temp variable for the calculations.	
	while(tmp_tel1 != 0)																						//While the temp variable (phone number) is not 0.
    {																											//
       tmp_tel1 /= 10;																							//Divide the number by 10 at each loop.
        counta++;																								//With each division increase the counta variable (digits).		
    }																											//
    if(counta <  10 || counta > 10)																				//If counta is below 10 or above 10.
    {																											//	
		if(y == 45)																								//If y axis variable is 45 (end of log area).
		{																										//	
			gotoxy(0,46);																						//
			printf("Press any key to continue...");																//Print message on screen.
			getch();																							//Wait for any user input.
			gotoxy(0,36);																						//
			for(j=36;j<=49; j++)																				//For loop to traverse all lines of the log area one by one.	
			{																									//	
				gotoxy(0,j);																					//
				for(l=0;l<=170; l++)																			//For loop to traverse all x axis of the log area of each line.
					printf(" ");																				//Fake clear screen by replacing everything that is written with " ".
			}																									//	
			y = 36;																								//
			gotoxy(0,y);																						//
		}																										//
    	gotoxy(0,y);																							//
    	printf("Error: Please give me a valid 10 digit number as phone number.");								//Print error message.		
    	counta = 0 ;																							//Set the counta (log area lines) to be 0.	
    	y++;																									//Increase the y axis (line) by one with each wrong message.
     }																											//
    																								
}while(counta < 10 || counta >= 11);																			//While loop conditions.
counta = 0;																										//Set counta to be 0 (log area lines).			
gotoxy(121,18);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//			
printf("Tel 2: ");																								//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
do{																												//Do while loop for telephone 2.
	fflush(stdin);																								//As above.	
	gotoxy(129, 18);																							//
	scanf("%lu", &a.tel2);																						//	
	tmp_tel2 = a.tel2;																							//
	while(tmp_tel2 != 0)																						//
    {																											//
       tmp_tel2 /= 10;																							//
        counta++;																								//
    }																											//	
    if(counta <  10 || counta > 10)																				//
    {																											//
		if(y == 45)																								//
		{																										//
			gotoxy(0,46);																						//
			printf("Press any key to continue...");																//
			getch();																							//
			gotoxy(0,36);																						//
			for(j=36;j<=49; j++)																				//	
			{																									//
				gotoxy(0,j);																					//	
				for(l=0;l<=170; l++)																			//
					printf(" ");																				//
			}																									//
			y = 36;																								//
			gotoxy(0,y);																						//
		}																										//
    	gotoxy(0,y);																							//
    	printf("Error: Please give me a valid 10 digit number as phone number.");								//
    	counta = 0;																								//
    	y++;																									//	
     }																											//		
    																										
}while(counta < 10 || counta >= 11);																			//While loop conditions.	
gotoxy(121,20);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("Email: ");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
do{																												//Do while loop for email user input validation.
	fflush(stdin);																								//Flush standard input file.
	gotoxy(128,20);																								//
	scanf("%s", &a.email);																						//Receive the user input for the email address.	
	if(validate_local_address(a.email) == 0)																	//If the return of the function validate_local_address of mail is 0.
	{																											//			
		if(y == 45)																								//If the y axis variable is 45 (end of log area).	
		{																										//
			gotoxy(0,46);																						//
			printf("Press any key to continue...");																//Print message on screen.
			getch();																							//Wait for any user input.
			gotoxy(0,36);																						//	
			for(j=36;j<=49; j++)																				//For loop to traverse the log area line by line.
			{																									//
				gotoxy(0,j);																					//Move to each line with each loop.
				for(l=0;l<=170; l++)																			//Nested for loop to traverse the x axis of the log area.
				printf(" ");																					//Fake clear screen by replacing everything written with " ".		
			}																									//	
			y = 36;																								//Set the y axis to be 36 (begin of the log area).
			gotoxy(0,y);																						//
		}																										//
		gotoxy(0, y);																							//	
		printf("Error: Please use proper Email Address.");														//Print message on screen.
		counta = 0;																								//Set counta (number of lines of log area) to be 0.	
		y++;																									//With each loop increase the log area y axis by one.		
	}																											//
}while(validate_local_address(a.email) == 0);																	//While condition.
gotoxy(121,22);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("SSN(10 digits): ");																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
fflush(stdin);																									//
scanf("%d", &a.ssn);																							//User input for SSN number.
gotoxy(121,24);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("Date of Joining (dd/mm/yyyy): ");																		//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
fflush(stdin);																									//
scanf("%d/%d/%d", &a.ddjoin, &a.mmjoin, &a.yyyyjoin);															//User input for joining date.
gotoxy(121,26);																									//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("Department: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
fflush(stdin);																									//
scanf("%s", &a.department);																						//User input for department assignment.
gotoxy(121,28);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("Administration (Y/N): ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//
fflush(stdin);																									//
a.administrator = getch();																						//User input for administrator rights.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//	
gotoxy(74,29);																									//
printf("Username (max 10 char): ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
fflush(stdin);																									//
scanf("%s", &a.user);																							//User input for username.
gotoxy(121,29);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//	
printf("Password (max 10 char): ");																				//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
fflush(stdin);																									//
scanf("%s", &a.password);																						//User input for password.
																									
fseek(acc, 0, SEEK_END);																						//Go to the end of the employees.csv file and save the data with sscanf format. 
fprintf(acc, "%d,%s,%s,%s,%d/%d/%d,%s,%s,%lu,%lu,%s,%d,%d/%d/%d,%s,%s,%s,%c\n", countemps, a.fname, a.lname, a.gender, a.dd, a.mm, a.yyyy, a.address, a.city, a.tel1, a.tel2, a.email, a.ssn, a.ddjoin, a.mmjoin, a.yyyyjoin, a.department, a.user, a.password, a.administrator);

fclose(acc);																									//Close the employees.csv file.
fclose(notes);																									//Close the personal notes file.

sprintf(dirname, "%s.txt", a.user);																				//At this point a new file is being created for the new employee and the
notes = fopen(dirname, "wb");																					//file has the title of the username of the employee with .txt format.
for (ch = getc(notes); ch != EOF; ch = getc(notes)){															//For loop (Just in case of having the file aready). Read each character
	if (ch == '\n')																								//and with each new line character "\n".
	id = id + 1;																								//Increase the id (number of notes) by one.
}																												//	
fseek(notes, 0, SEEK_END);																						//Go to the end of the username personal notes file.
fprintf(notes, "%d : %s\n", id, text);																			//Print the first welcome note send by the system.
fclose(notes);																									//Close the notes file.	

gotoxy(77,36);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);										//
printf("Registration Successful. Please Press any key to go back to main menu.");								//Print message on screen with each succesfull registration.			
getch();																										//Wait for any user input.
system("copy data\\employees.csv data\\employees.txt");  														//Copy the employees.csv file to employees.txt file.
strcpy(username, turnname);																						//Replace the string saved turnname earlier with the username.
managerMenu(username, rights);																					//Go back by calling the managerMenu function.	
fclose(borderart);																								//Close the ascii art file.
}
