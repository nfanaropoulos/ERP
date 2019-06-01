#include "../headers/loading.h"

void delay(int number_of_milseconds) 																		//Known delay function used but instead of seconds I left the miliseconds.
{ 
    clock_t start_time = clock();																			//Stroing start time.   
    while (clock() < start_time + number_of_milseconds) 													//looping till required time is not acheived.
        ; 
}

void loading(){																								//Loading function begin.
	
system("CLS");																								//Clear screen.
																											//Variables definition begin.	
int k = 35, i;
FILE *art;
char *loadingart = "art/loading.dat";
																											//Variables definition ends.
if((art = fopen(loadingart,"r")) == NULL)                                 									//-------------------------------------------------------------------------	
{                                                                      										//	
    fprintf(stderr,"error opening %s\n",loadingart);                          								//If condition in case the ascii art file does not exist.
    return;                                                                  								//
}																											//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);                                  //------------------------------------------------------------------------- 
print_title(art); 																							//Print on screen the ascii art file.	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 15);
gotoxy(92,35);																								//--------------------------------------------------------------------------
printf("Loading Data Files...");																			//
gotoxy(85,34);																								//Fixed (non movable) parts of the loading screen.
printf("[");																								//
gotoxy(123,34);																								//
printf("]");																								//
gotoxy(86,34);																								//--------------------------------------------------------------------------
 
for (i=0; i<=10;i++)																						//For loop for the first part (fast one) of the loading screen.
{
	delay(100);																								//The delay of each printing is 100 miliseconds.
	printf("=");																							//The printed character that is added each time is the "=".
}																											//		
gotoxy(92,35);																								//
printf("Loading Menu Artwork...");																			//Message printed on screen when the first part of the loading ends.
gotoxy(97,34);																								//			
for (i=0; i<=3;i++)																							//For loop for the second (slower) part of the loading screen.
{																											//
	delay(1000);																						    //The delay of each printing now is 1000 miliseconds.				
	printf("=");																							//The printed character that is added each time is again the "=".		
}																											//	
for (i=0; i<=10;i++)																						//For loop for the pre-last part (fast again) of the loading screen.
{																											//
	delay(100);																								//The delay again is 100 miliseconds.
	printf("=");																							//Same printing character.
}																											//
gotoxy(92,35);																								//
printf("Removing temporary files...");																		//Fake printing message to simulate that a job is done.		
gotoxy(112,34);																								//	
for (i=0; i<=10;i++)																						//For loop for the last part of the loading screen.
{																											//
	delay(100);																								//Delay is again 100 miliseconds.
	printf("=");																							//Same printing character.	
}																											//
gotoxy(92,35);																								//	
printf("Loading has been Completed...");																	//Message on screen.
gotoxy(92,36);																								//
printf("Press Any key to continue...");																		//Message on screen.
getch();																									//Wait for any user input.
mainMenu();																									//Call the mainMenu function to begin the program.			
fclose(loadingart);																							//Close the ascii art file.
}																											//Loading function ends.	
