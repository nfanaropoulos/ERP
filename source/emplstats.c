#include "../headers/emplstats.h"
struct invoice{																					//Struct invoice begin.
																								//Struct variables definition begin.
	int emplid;
	int clientid;
	float sale;
																								//Struct variables definition ends.	
};
struct invoice invi;																			//Struct invoice ends.

void emplstats(char username[], char rights[]){													//Emplstats function begin.
																								//Variables definition begin.
	FILE *invoice, *emp;
	int tmp1, tmp2, i, employees[100] = {}, counter=0, j, k, l, count=1, chk_id, yi = 36, tmp;
	float tmp3, sales[100] = {};
	char line[1024], line2[1024], *names[100], timp_name[25], *chk_lname, *temporary;
	float timp_sales;
	char * ( *ptr)[100] = &names;
																								//Variables definition ends.	
	invoice=fopen("data/retail/retail_invoices.csv", "r");										//Open the file retail_invoices.csv in read mode.

while (fgets(line, 1024, invoice))																//While loop to read line by line the entries of retail_invoices.csv.
{
	sscanf(line, "%d,%d,%d[^\n]", &invi.emplid, &invi.clientid, &invi.sale);					//read each line in a specific formated string.
	tmp1 = atoi(strtok(line, ","));																//Split the string at the first ',' and convert that string taken into int.
	tmp2 = atoi(strtok(NULL, ","));																//Split the next string at the second ',' and convert that string taken into int.
	tmp3 = atof(strtok(NULL, ","));																//Split the next string at the third ',' and convert that string taken into float.	
	for(i=0;i<100;i++)																			//For loop that runs for 100 times. This is needed to get the 100 employees that have
	{																							//made sales and place their sales in the same 'i' position as the employees id.
		if(employees[i] == NULL)																//If the current 'i' position of employees is empty.
		{																						//Basically each i rapresents an employee and his corresponding sales in sales array
			employees[i] = tmp1;																//Place the employee id of this line taken to the current 'i' employee place.
			sales[i] = tmp3;																	//Place in the same position of sales array the sales this employee has made.
			counter++;																			//Increase the counter.
			break;																				//
		}																						//
		if(employees[i] == tmp1)																//If the 'i' position is occupied by the current employee, which means that the employee
		{																						//Id has been registred already with a previous sale he made.	
			sales[i] += tmp3;																	//Then add the current sales to the previous ones the employee has made.
			break;																				//
		}																						//
	}																							//End of foor loop.
	
}																								//End of while loop.	
fclose(invoice);																				//Close the retail_invoices.csv file.

	emp=fopen("data/employees.csv", "r");														//Open the employees.csv file in read mode.
	
while (fgets(line2, 1024, emp) != NULL)															//While loop to read line by line the entries of employees.csv. This while is required
{																								//in order to assign the employees id with their last names.
	char* temp = strdup(line2);																	//Duplicate the line taken each time and save it in temp.	
	char* temp1 = strdup(line2);																//Diplicate the line taken each time and save it in temp1.
	chk_lname = getfield(temp,3);																//Assign in chk_lname the third field taken from the temp string.
	chk_id = getfield(temp1,1);																	//Assign in chk_id the 1st field taken from the temp1 string.

 
	for(i=0;i<counter-1;i++)																	//For loop that last for counter-1 (we need only the actuall employee numbers that made
	{																							//sales and not all 100 positions of the employee array.
		if(employees[i] == atoi(chk_id))														//If the 'i' position of employees is the same as the chk_id number (converted the string
		{																						//into an int for making the compare).

			(*ptr)[i] = chk_lname;																//Found on internet a way of assignining the chk_lname to the id of the employee.	
		}																						//
	}																							//

}																								//
for(k=0; k < counter-1; k++)																	//For loop that will begin the bubble sort of the employees and sale arrays.
	for(l = 0 ; l < counter - 1 - k; l++)														//Nested for loop that compares each 'k' with all 'l' entries.
	{
		if(sales[l]<sales[l+1])																	//If the sales of the 'l' employee are lower than the sales of the next employee.				
		{																						//Perform a swap to get next employee before current one.		
			tmp = sales[l];																		//Save current employee's sales to tmp variable.
			sales[l] = sales[l+1];																//Now set the current employee sales to be the same as the next ones.
			sales[l+1] = tmp;																	//Set the next employee's sales to be the same as the saved tmp sales.
			strcpy(temporary, (*ptr)[l]);														//Now swap by copying the string name of lower sales employee to a temporary string.
			strcpy((*ptr)[l],(*ptr)[l+1]);														//And place the string name of the higher sales employee to the current employee name.
			strcpy((*ptr)[l+1], temporary);														//And place the lower sales employee string name to the next employee string name.	
		}																						//Basically swaped the position of both names and sales in ascending order.
	}
for(i=0;i< counter-2; i++)																		//Another for loop needed to show the sorted list of both sales and employees to the 
{																								//Screen. This loop runs for exactly the amount of registered employees that made sales.	
	gotoxy(0,yi);																				//Print the current employee and his total sales at the yi line of the log area.
	if(count == 14)																				//If the count variable (which counts the lines of the log area), read 14.
	{																							//
		printf("\n Press any key to continue...");												//Print on screen the message to press any key.
		getch();																				//Wait for the user input.		
		gotoxy(0,35);																			//Go to the begining of the log area.
		for(j=35;j<=62; j++)																	//For loop that run through all log area lines.
		{																						//
			gotoxy(0,j);																		//Go to the begining of each line.			
			for(l=0;l<=200; l++)																//Nested for loop to run across the whole line.	
				printf(" ");																	//Simulate a clear line by replacing everything that is written with empty character.
		}																						//
		gotoxy(0,35);																			//Return cursor to the start of the log area.
		count = 1;																			 	//Set count (line of log area) to be the 1 (first).			
	}
	printf("Salesman : %s", (*ptr)[i]);															//Print in each linie the salesman name.
	printf("	Total sales: %.2f\n", sales[i]);												//Followed by his total sales.
	yi++;																						//Increase yi (next y axis position).
	count++;																					//Increase count (lines of log area).
}	
fclose(emp);																					//Close the employees.csv file.
gotoxy(77,36);																					//
printf("Please press any key...");																//Print the message for any user input.				
getch();																						//Wait for any user input.
managerMenu(username,rights);																	//Call managerMenu function (return to previous menu).
}																								//Emplstats function ends.
