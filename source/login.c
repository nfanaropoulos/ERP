#include "../headers/login.h"

const char* getfield(char* line, int num)																		//Getfield function found on internet to retrieve the .csv file fields.
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
        	return tok;
    }
    return NULL;
}

void login(void){																								//Login function	
																												//Variables definition begin.
char *loginart = "art/border1.dat"; 
FILE *art = NULL, *acc;
char username[10], userpass[10], line[1024], rights[1];
int digs = 0;
long int recsize = sizeof(a);
char *chk_username, *chk_password, *chk_rights;
																												//Variables definition ends.	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//	
acc=fopen("data/employees.csv","rb");																			//Open the file employees.csv in read and binary mode.
system("CLS");																									//Clear screen.
if((art = fopen(loginart,"r")) == NULL)																			//----------------------------------------------------------------------	
    {                                                                               							//	
        fprintf(stderr,"error opening %s\n",loginart);                               							//If condition to check wether the ascii art file exists or not.
        return 1;                                                                    							//		
}                                                                              									//----------------------------------------------------------------------
print_title(art);                                                                   							//Print on screen the ascii art file.	
gotoxy(105,15);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("~~Login Menu~~");																						//
gotoxy(105,18);																									//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
printf("USERNAME:->");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);                     // 	                              
scanf("%s", &username); 																						//User input for username.
gotoxy(105,19);        																							//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);                   //	                               
printf("PASSWORD:->");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE); 					//
scanf("%s", &userpass); 																						//USer input for password.
                                                                                                
while (fgets(line, 1024, acc))                                          										//While loop to read the employees.csv file line by line.
{      	
	char* tmp = strdup(line);																					//Dynamically save the line in tmp.				
	char* tmp1 = strdup(line);																					//Dynamically save the line in tmp1.
	char* tmp2 = strdup(line);																					//Dynamically save the line in tmp2.
	chk_username = getfield(tmp,14); 																			//Set chk_username to be the 14th field of the tmp.
	chk_password = getfield(tmp1,15);																			//Set chk_password to be the 15th field of the tmp1.
	chk_rights = getfield(tmp2,16);																				//Set chk_rights to be the 16th field of the tmp2.	
	rights[0] = chk_rights;																						//Set rights array first element to be the chk_rights.
		                                                             
    if(strcmp(username,chk_username)==0)                                      									//If the result of comparing the strings username and chk_username is 0.	
        {      	                                                												//		
           if(strcmp(userpass,chk_password)==0)                                  								//And if the result of comparing the strings password and chk_password is 0 too.	
            { 																									//
            	if(chk_rights[0] == 'y')																		//If the chk_rights[0] is the character "y".	
				{																								//
					fclose(acc);                                 												//Close the employees.csv file.
					managerMenu(username, chk_rights);															//Call the managerMenu function (administrator rights login).
				}																								//
				else																							//Else if the rights is not administrator but simple user.
				{																								//
					fclose(acc);																				//Close the employees.csv file.
					employeeMenu(username, chk_rights); 														//Call the employeeMenu function (simple user rights login).		
				}                                              													//		
            }                                                                   								//
            else 																								//If password strings do not match.
			{                                                                                                   //
                printf("Wrong Password Please Try Again!Press any key");     									//Print error message.
                getch();                                                     									//Wait for any user input.
                mainMenu();                                                                                     //Go back to the mainMenu function.   
            }                                                             										//
        }                                                               										//	
}    																											//
printf("Account not found! Please press any key");                 												//If username strings do not match. Print the error message.	
fclose(acc);																									//Close the employees.csv file.
getch();   																										//Wait for any user input.
mainMenu();																										//Call mainMenu function.	
}
