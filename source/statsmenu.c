#include "../headers/statsmenu.h"

void forecasting(int i, int years, float r, int q, int flag, int real_sales){										//Void Function for sales forecasting.
	
	int forecast[100], accumulative[100], xi = 3, yi = 36;															//definition of the 2 integer arrays forecast and accumulative.

	for(i=0; i<years; i++)																							//For loop to fill up the forecast array from 0 until years-1.
    	forecast[i]=r*q*pow(1-r,i);																					//Forecast algorithm, Forecast[i] is the estimated sales for i year.
	if(flag == 1)																									//Condition if in case of real data input from user.
	{																												//			
		forecast[0]= real_sales;																				    //First (0) place of the array gets the real data sales given.
		for(i=1; i<years; i++)																					    //For loop to add the rest (1)-(years-1) entries.
			forecast[i] = r*q*pow(1-r,i);																		    //Forecast algorithm.	
	}																											    //End of If condition.
	gotoxy(3,36);																									//
	printf("***********************");																				//
	for(i=0; i<years; i++)																						    //For loop to show up the forecast array from 0 until years-1.
	{																												//
		gotoxy(xi,yi);																								//	
		printf("Prediction for Year %d: %d", i+1, forecast[i]);													    //Showing the prediction results for each year.
		yi++;																										//Increase the yi variable by one. 
	}																												//
	gotoxy(xi,yi);																									//	
	printf("***********************");																				//	
																							
	accumulative[0] = forecast[0];																					//Setting the first place of accumulative array to be equal with the sales of that year.
	for (i=1; i<years; i++)																							//For loop to fill up the accumulative array from (1)-(years-1) places.
		accumulative[i] = accumulative[i-1] + forecast[i];															//Equation for the appropriate value of each place.
	yi += 1;																										//Add one to the yi variable.
	gotoxy(xi,yi);																									//			
	printf("***********************");																				//
	for(i=0; i<years; i++)																							//For loop to show up the values of the accumulative array.
	{																												//				
		gotoxy(xi,yi);																								//
		printf("Accumulated Sales for year %d : %d", i+1, accumulative[i]);										    //Showing up the values of accumulative array to the user.
		yi++;																										//Increase yi by one.
	}																												//
}																													//End of sales forecasting function.	

void statsmenu(char username[], char rights[]){																		//Stats menu function begin.
				
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);						//
																													//Variables definition area begin.	
char *statsart = "art/border1.dat";
FILE *art = NULL, *notes11;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int q, years, forecast[100], accumulative[100], i, choice2, real_sales =0, flag=0, first_year, second_year, choice, j, l, xi, yi;		 
float r, data;																									  
char choice1 = "Y", choice3 = "A";
																													//Variables definition area ends.

system("CLS");																										//Clear screen.
if((art = fopen(statsart,"r")) == NULL)																				//------------------------------------------------------------------	
    {																												//	
        fprintf(stderr,"error opening %s\n",statsart);																//If condition in case the ascii art file does not exist.	
        return 1;																									//
}																													//------------------------------------------------------------------
print_title(art);																									//Print on screen the ascii art file.

	gotoxy(62,2);																									//------------------------------------------------------------------
	printf("Welcome Back: ");																						//							Top menu begin.
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
	gotoxy(200, 2);																									//			
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);					//
	printf("Low Quantity: ");																						//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);						//	
	printf("%d", lowquantity());																					//							Top menu ends.
	gotoxy(105, 15);																								//------------------------------------------------------------------
	printf("~~Statistics Menu Menu~~");																				//Statistics Menu.
	gotoxy(105, 17);																								//	
	printf("1. Sales Prediction.");																					//Sales Prediction. 				
	gotoxy(105, 18);																								//
	printf("2. Employees Sales.");																					//Employee sales stats.	
	gotoxy(105, 19);																								//
	printf("3. Back.");																								//Back.
	gotoxy(105, 21);																								//	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);										//		
	printf("Enter your Choice: ");																					//		
	scanf("%d", &choice);																							//Receive user input of his choice.
	switch(choice)																									//Switch function.
	{																												//
		case 1:																										//Case 1.
			gotoxy(74,21);																							//	
			printf("***********************************************************************************");			//
			gotoxy(74,22);																							//	
			printf("Give me the amount of the untapped market: ");													//
			scanf("%d", &q);																						//Receive the untapped market entry from the user and save it in q.			
			gotoxy(74,23);																							//	
			printf("Give me the penetration rate value: ");															//
			scanf("%f", &r);																						//Receive the penetration rate entry given by the user and save in r.			
			gotoxy(74,24);																							//
			printf("How many years you want me to forecast: ");														//			
			scanf("%d", &years);																					//Receive the years which the user wants to run the prediction.
			
			forecasting(i, years, r, q, flag, real_sales);															//call forecasting function and transfer the neccessary data.	
			gotoxy(74,25);																							//
			printf("Do you have valid data? (Y/N): ");																//Print message to ask the user if he has valid data from sales.			
			choice1 = getch();																						//Receive the user input and save it in choice1 variable.
			switch(choice1)																							//Switch function for choice1.
			{																										//
				case 'y':																							//Case y or Y (Removing case sensitive).	
				case 'Y':																							//
				xi = 74;																							//Set x axis to be 74.
				yi = 22;																							//Set y axis to be 22.
				gotoxy(xi,yi);																						//Move to the x/y coordinates.	
				for(j=22;j<=25; j++)																				//For loop to traverse the y axis of the log area .		
				{																									//
  					gotoxy(xi,j);																					//
  					for(l=0;l<=65; l++)																				//Nested for loop to traverse the x axis of the log area for each line.		
  						printf(" ");																				//Replace all line characters with empty space (simulation of local CLS.
				}																									//
				gotoxy(74,22);																						//
				printf("You have valid data for 1 or more years?");													//Asking the user if he has data for 1 or more years.		
				gotoxy(74,23);																						//
				printf("1. 1 year");																				//Option 1 ( 1 year data ).	
				gotoxy(74,24);																						//	
				printf("2. 2 years");																				//Option 2 ( 2 year data ).
				scanf("%d", &choice2);																				//Receive the user input.
				switch(choice2)																						//Switch for choice2.			
				{																										
					case 1:																							//Case 1.
						gotoxy(74,25);																				//
						printf("How many years you want me to forecast?");											//
						scanf("%d", &years);																		//Receiving from user input how many years he wish to run forecast.
						gotoxy(74,26);																				//		
						printf("Give me the Real Sales data you have: ");											//
						scanf("%d", &real_sales);																	//Asking for the real sales value for 1 year.		
						gotoxy(74,27);																				//
						printf("Choose which value you want to keep");												//Asking the user which variable he wish to keep (q or r).
						gotoxy(74,28);																				//
						printf("r: penetration rage");																//Option 1 (keep r).		
						gotoxy(74,29);																				//
						printf("q: untapped market");																//Option 2 (keep q).	
						choice3 = getch();																			//Receive user input.
						switch(choice3)																				//Switch for choice3.	
						{
							case 'r':																				//Case r or R (removing case sensitive).		
							case 'R':
								q = real_sales/r;																	//In case of keeping the r variable, recalculate the q variable.	
								flag = 1;																			//Set the flag to 1.			
								forecasting(i, years, r, q, flag, real_sales);										//Call forecasting function and send the new data.
								gotoxy(74,30);																		//	
								printf("Press Any key to go back.");												//
								getch();																			//Wait for any user input.		
								statsmenu(username, rights);														//Call the statsmenu function (going back).
								break;																				//
							case 'q':																				//Case q or Q (removing the case sensitive).
							case 'Q':	
								r = (float) real_sales/q;															//In case of keeping the q variable,recalculate the r variable.
								flag = 1;																			//Set flag to 1.
								forecasting(i, years, r, q, flag, real_sales);										//Call forecasting function and send the new data.				
								gotoxy(74,30);																		//	
								printf("Press Any key to go back.");												//	
								getch();																			//Wait for any user input.	
								statsmenu(username, rights);														//Call the statsmenu function (going back).
								break;																				//				
						}																							//
						break;																						//
					case 2:																							//Case 2 (2 years sales data).
						gotoxy(74,25);																				//
						printf("How many years you want me to forecast?");											//				
						scanf("%d", &years);																		//Receive the user input for how many years  to run the forecast.
						gotoxy(74,26);																				//
						printf("Give me the amount of the first year sales: ");										//
						scanf("%d", &first_year);																	//Receiving the first year real sales.	
						gotoxy(74,27);																				//
						printf("Give me the amount of the second year sales: ");									//
						scanf("%d", &second_year);																	//Receiving the second year real sales.	
															
						data = (float) second_year/first_year;														//Set data variable to be second_year/first_year. As taken from theory.			
						r = 1.0 - data;																				//Recalculate r based on real data from 2 years as taken from theory.	
						q = first_year/r;																			//Recalculate q  based on first year sales divided by r as taken from theory.	
						forecasting(i, years, r, q, flag, real_sales);												//Call the forecasting function and send the new data.
						gotoxy(74,28);																				//
						printf("Press Any key to go back.");														//
						getch();																					//Wait for any user input.	
						statsmenu(username, rights);																//Call the statsmenu function (going back).
						break;																						//	
				}																									//
					break;																							//
				case 'N':																							//Case n or N (removing case sensitive). 
				case 'n':																							//
					managerMenu(username,rights);																	//Go back to managerMenu function.
					break;																							//			
			}																										//
										
			break;																									//
		case 2:																										//Case 2.
			emplstats(username, rights);																			//Call emplstats function (going back).
			break;																									//
		case 3:																										//Case 3.	
			managerMenu(username, rights);																			//Calling managerMenu function (going back).		
	}
fclose(statsart);																									//Close the ascii art file.
}																													//End of stats menu function.
