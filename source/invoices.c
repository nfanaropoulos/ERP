#include "../headers/invoices.h"
void calculator(int prods[], int amounts[], int counti){									//Calculator function begin. Function used to update products file when invoice is issued.
																							//Variables definition begin.
	FILE *proda, *prod_cp;
	char line[1024], *tmp_desc, *tmp_supp, *tmp_prddd, *tmp_cat, *tmp_pack, *tmp_prname;
	int i, j, tmp, tmp1, flag = 0, tmp_prid, tmp_wquantity, tmp_tq;
	float tmp_price, tmp_tax;
																							//Variables definition ends.	
	proda=fopen("data/products.csv", "r");													//Open the products.csv file in read mode.
	prod_cp=fopen("data/products_copy.csv", "w");											//Open the products_copy.csv file in write mode. Rewrite is ok since it's temp file.						
	
for(i = 0;i < counti - 1; i++)																//For loop for bubble sort algorithm needed to place products and sales in order.
{																							//
	for(j = 0; j < counti - i - 1; j++)														//
	{																						//	
		if(prods[j] > prods[j+1])															//	
		{																					//
	    	tmp = prods[j];																	//------------------------------------------------------------------------------------------
			prods[j] = prods[j+1];															//Swap method in descending order.
			prods[j+1] = tmp;																//------------------------------------------------------------------------------------------
																							//Bubble sort algorithm, sorts also the amounts array (amount of items sold of that product).
			tmp1 = amounts[j];																//
			amounts[j] = amounts[j+1];														//
			amounts[j+1] = tmp1;															//
		}																					//
	}																						//	
}																							//End of bubble sort algorithm.
	
while(fgets(line, 1024, proda) != NULL)														//While loop to read entries of the products.csv file and update it with the new data of the
{																							//Products that have been sold in the invoice.
	sscanf(line, "%d,%s,%s,%s,%s,%s,%f,%f,%lu,%s,%lu[^\n]", &p.pid, p.pname, p.pdesc, p.psupp, p.pdd, p.pcategory, &p.unit_price, &p.tax, &p.warehouse_quantity, p.packaging, &p.total_quantity);
											
	tmp_prid = atoi(strtok(line, ","));														//tmp_prid taken as char string from strtok function. First part of line string. Converted to int.		
	tmp_prname = strtok(NULL, ",");															//tmp_prname taken as char string from strtok function. Second part of line string. 		
	tmp_desc = strtok(NULL, ",");															//tmp_desc taken as char string from strtok function. Third part of line string.
	tmp_supp = strtok(NULL, ",");															//tmp_supp taken as char string from strtok function. Forth part of line string.
	tmp_prddd = strtok(NULL, ","); 															//tmp_prddd taken as char string from strtok function. Fifth part of line string.
	tmp_cat = strtok(NULL, ",");															//tmp_cat taken as char string from strtok function. Sixth part of line string.
	tmp_price = atof(strtok(NULL, ","));  													//tmp_price taken as char string from strtok function. Seventh part of line string. Converted to float.
	tmp_tax = atof(strtok(NULL, ","));														//tmp_tax taken as char string from strtok function. Eighth part of line string. Converted to float.
	tmp_wquantity = atoi(strtok(NULL, ","));												//tmp_wquantity taken as char string from strtok function. Ninth part of line string. Converted to int.
	tmp_pack = strtok(NULL, ",");															//tmp_pack taken as char string from strtok function. Tenth part of line string.
	tmp_tq = atoi(strtok(NULL, ","));														//tmp_tq taken as char string from strtok function. Eleventh part of line string. Converted to int.
	for(i=0;i<=counti;i++)																	//For loop which is needed to check if the product id sold is located in the list of products. 
	{																						//
		if(prods[i] == p.pid)																//If the product is found.
		{																					//
			tmp_wquantity = tmp_wquantity - amounts[i];										//Set the current warehouse quantity to be equal with the old one minus the amount sold. 		

			fseek(prod_cp, 0, SEEK_END);													//Go to the end of the file and save the new entry with the updated warehouse quantity.
			fprintf(prod_cp, "%d,%s,%s,%s,%s,%s,%.2f,%.2f,%lu,%s,%lu\n", tmp_prid, tmp_prname, tmp_desc, tmp_supp, tmp_prddd, tmp_cat, tmp_price, tmp_tax, tmp_wquantity, tmp_pack, tmp_tq);
			flag = 1;																		//Set the flag variable to 1.	
		}																					//
	}
	if(flag != 1)																			//If the flag is not 1, which means that the product has not been found yet.
	{																						//
		fseek(prod_cp, 0, SEEK_END);														//Go to the end of the file.	
		fputs(line, prod_cp);																//Place the line (entry of product) untouched as it is.
	}																						//
}
fclose(proda);																				//Close the file products.csv.
fclose(prod_cp);																			//Close the file products_copy.csv.
sleep(8);																					//Sleep function needed to give the necessary time for files to close safely.			
gotoxy(0,38);																				//	
printf("Wait while Files are being updated...");											//Print on screen the message to inform the user of the delay.
sleep(8);																					//Sleep function needed to give the necessary time for files to rename safely.		
gotoxy(0,39);																				//
printf("Wait while Files are being updated...");											//
rename("data/products.csv", "data/products-backup.csv");									//Rename function to change name of the products.csv into backup file.
sleep(8);																					//Sleep function needed to give the necessary time for files to rename safely.
gotoxy(0,40);																				//
printf("Files updated. Press any key...");													//
rename("data/products_copy.csv", "data/products.csv");										//Rename function to change name of products_copy.csv to products.csv.
getch();																					//Wait for any user input.
	
}																							//Calculation function ends.
int lowquantity(){																			//Lowquantity function needed to calculated products that are below 500 in warehouse.
																							//Variables definition starts.
	FILE *prod, *low;																
	int counter=0, quantity, tmp_prid, tmp_wquantity, tmp_tq;
	prod=fopen("data/products.csv", "r");													//Open the products.csv file in read mode.
	low=fopen("data/low.csv", "w+");														//Open the low.csv file in a write and append mode.
	float tmp_price, tmp_tax;
	char *tmp_desc, *tmp_supp, *tmp_prddd, *tmp_cat, *tmp_pack, *tmp_prname, line2[1024];	
																							//Variables definition ends.
while (fgets(line2, 1024, prod) != NULL)													//While loop needed to get the content of the products.csv file line by line saved in line2 array.																			
{																							//the while loop ends when the file ends. Each line is formated by the sscanf function.
	sscanf(line2, "%d,%s,%s,%s,%s,%s,%f,%f,%d,%s,%d[^\n]", &p.pid, p.pname, p.pdesc, p.psupp, p.pdd, p.pcategory, &p.unit_price, &p.tax, &p.warehouse_quantity, p.packaging, &p.total_quantity);
	
	tmp_prid = atoi(strtok(line2, ","));													//Strtok function devide each whole line into smaller parts seperated by the ",". First is converted in int.
	tmp_prname = strtok(NULL, ",");															//Strtok function takes the second smaller string of line2 (second "," found).	
	tmp_desc = strtok(NULL, ",");															//Strtok function takes the third smaller string of line2 (third "," found).	
	tmp_supp = strtok(NULL, ",");															//Strtok function takes the fourth smaller string of line2 (fourth "," found).
	tmp_prddd = strtok(NULL, ","); 															//Strtok function takes the fifth smaller string of line2 (fifth "," found).
	tmp_cat = strtok(NULL, ",");															//Strtok function takes the sixth smaller string of line2 (sixth "," found).
	tmp_price = atof(strtok(NULL, ","));  													//Strtok function takes the seventh smaller string of line2 (seventh "," found). Converted into float.
	tmp_tax = atof(strtok(NULL, ","));														//Strtok function takes the eighth smaller string of line2 (eighth "," found). Converted into float.
	tmp_wquantity = atoi(strtok(NULL, ","));												//Strtok function takes the ninth smaller string of line2 (ninth "," found). Converted into int.
	tmp_pack = strtok(NULL, ",");															//Strtok function takes the tenth smaller string of line2 (stenth "," found).
	tmp_tq = atoi(strtok(NULL, ","));														//Strtok function takes the eleventh smaller string of line2 (eleventh "," found). Converted into int.
	
	if(tmp_wquantity <= 500)																//If condition the current warehouse quantity is below or equal to 500 units.
	{																						//
		fseek(low, 0, SEEK_END);															//Move to the end of the low.csv file (which is the one holding the products that are low in stock.
		fprintf(low, "%s,%d\n", tmp_prname, tmp_wquantity);									//Print into the file the product name and current quantity that needs to be ordered.
		counter++;																			//Increase the counter variable which count how many products are low, needed to show to the 	
	}																						//user in the top menu.
}
fclose(prod);																				//Close the products.csv file.
fclose(low);																				//Close the low.csv file.		
return counter;																				//Return once the function ends the total amount of products that are low in stock.
}																							//Lowquantity function ends.

void prodinfo(int prodid, int yi, float prodtax[], float prodprice[], int counti){			//Prodinfo function to retrieve the product information data shown on screen depending on user input.	
																							//Variables definition begin.	
FILE *prod;
int tmp_prid, tmp_wquantity, tmp_tq;
float tmp_price, tmp_tax;
char *tmp_desc, *tmp_supp, *tmp_prddd, *tmp_cat, *tmp_pack, *tmp_prname, line2[1024];
																							//Variables definition ends.
prod=fopen("data/products.csv", "rb");														//Open the file products.csv in read and binary mode.
while(fgets(line2, 1024, prod) != NULL)														//While loop to get the entries of products.csv file line by line and saved ina single line array.
{																							//Each line taken from the file is formated as sscanf function shows below.	
	sscanf(line2, "%d,%s,%s,%s,%s,%s,%f,%f,%d,%s,%d[^\n]", &p.pid, p.pname, p.pdesc, p.psupp, p.pdd, p.pcategory, &p.unit_price, &p.tax, &p.warehouse_quantity, p.packaging, &p.total_quantity);

	if(prodid == p.pid)																		//If condition the prodid variable given by the user matches the id of the product found in the line.
	{
		tmp_prid = atoi(strtok(line2, ","));												//Strtok function devide each whole line into smaller parts seperated by the ",". Converted in int.
		tmp_prname = strtok(NULL, ",");														//Strtok function to receive the second smaller part seperated by the next ",".	
		tmp_desc = strtok(NULL, ",");														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_supp = strtok(NULL, ",");														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_prddd = strtok(NULL, ","); 														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_cat = strtok(NULL, ",");														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_price = atof(strtok(NULL, ","));  												//Strtok function to receive the second smaller part seperated by the next ",". Converted in float.	
		tmp_tax = atof(strtok(NULL, ","));													//Strtok function to receive the second smaller part seperated by the next ",". Converted in float.
		tmp_wquantity = atoi(strtok(NULL, ","));											//Strtok function to receive the second smaller part seperated by the next ",". Converted in int.
		tmp_pack = strtok(NULL, ",");														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_tq = atoi(strtok(NULL, ","));													//Strtok function to receive the second smaller part seperated by the next ",". Converted in int.
		gotoxy(15,yi);																		//Set the apropriate position on screen to begin printing data for each product, line by line.
		printf("%s", tmp_prname);															//Print the product name.
		gotoxy(44,yi);																		//Move across the line.
		printf("%s", tmp_desc);																//Print the description of the product.	
		gotoxy(114,yi);																		//Move across the line.		
		printf("%s", tmp_pack);																//Print the packaging of the product.	
		prodtax[counti] = tmp_tax;															//Set the product tax and the product price in the proper position of prodtax and prodprice arrays.
		prodprice[counti] = tmp_price;														//These information are needed to calculate the total product price, taxes, discounts of each invoice.			
		tmp_prname = '\0';																	
	}
}
fclose(prod);																				//Close the product.csv file.
}

int empid(char turnname[]){																	//Empid function needed to retrieve the employee Id that is logged in the program.
																							//Variable definition begin.	
FILE *acc;
int chk_id;
char *chk_username, line1[1024];
																							//Variable definition ends.
acc=fopen("data/employees.csv","rb");														//Open the file employees.csv in read and binary mode.
while (fgets(line1, 1024, acc) != NULL)														//While loop needed to retrieve all entries of the employees.csv file line by line.	
	{
	char* tmp = strdup(line1);																//Saved the line string in the tmp.
	char* tmp1 = strdup(line1);																//Saved the line string in the tmp1.
	chk_username = getfield(tmp,14);														//Retrieve the chk_username (username of the employee) by getting the 14th field of tmp.
	chk_id = getfield(tmp1,1);																//Retrieve the chk_id (id of the employee) by getting the 1st field of tmp1.		
	
	if(strcmp(turnname, chk_username) == 0)													//If condition the compare of the two strings turnname and username is 0 (the same).
	{
		return chk_id;																		//Return at the end of the function the chk_id (employee id).
	}
}
		
}																							//Empid function ends.

void retail(char username[], char rights[]){												//Retail function for invoices begin.
																							//Variables definition begin.
char *retailart = "art/border2.dat"; 
FILE *acc, *prod, *notes, *retail, *client, *art = NULL;
int count = 0, counti = 0, employID, id, j, prodid, realdisc, tmp_cid, tmp_cpostal, yi = 15, prodamount[17], amounts[17], prods[17];
char* dirname = username, *tmp_cname, *tmp_clname, *tmp_cemail, *tmp_caddress, *tmp_ccity, last = '\n', cha, more = 'Y', line[1024], line2[1024], turnname[10];
time_t t = time(NULL);
struct tm tm = *localtime(&t);
long long tmp_ctel;
float tmp_cdiscount, subtotal = 0.0, total = 0.0, prodfinal, prodprice[17], prodtax[17], totprod[17];
																							//Variables definition ends.
strcpy(turnname, username);																	//Save in a temporary string the username.
acc=fopen("data/employees.csv","rb");														//Open employees.csv file in read and binary mode.	
client=fopen("data/clients.csv", "rb");														//Open the clients.csv file in read and binary mode.			
retail=fopen("data/retail/retail_invoices.csv", "rb+");										//Open the retail_invoices.csv file in read binary and append mode.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
system("CLS");																				//Clear Screen.
if((art = fopen(retailart,"r")) == NULL)                                 					//------------------------------------------------------------------------------------------
	{                                                                      					//	
        fprintf(stderr,"error opening %s\n",retailart);                          			//If condition in case of the ascii art file missing.
        return;                                                                  			//
    }                                                                           			//------------------------------------------------------------------------------------------
print_title(art);																			//Print the ascii art file on screen.

gotoxy(62,2);																				//------------------------------------------------------------------------------------------			
printf("Welcome Back: ");																	//									Top Menu begin.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	//
printf("%s", username);																		//Print username.
gotoxy(62,3);																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Date: ");																			//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	//
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);							//Print current date / hour.		
gotoxy(62,4);																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Notes: ");																			//
sprintf(dirname, "%s.txt", username);														//
notes = fopen(dirname, "rb");																//Open the text file titled as the username in read and binary mode, file includes notes.	
	for(cha = getc(notes); cha != EOF; cha = getc(notes)){									//For loop that read all characters received from the notes file one by one until end of file.
		if(cha == '\n' && last != '\n')														//If condition character new line is found ("\n") and the last character isn't the new line.
			count++;																		//Increase the count variable which counts the number of notes.
		last = cha;																			//Set the last character retrieved to be the new line character.
	}																						//

fclose(notes);																				//Close the notes file.

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	//
printf("%d", count);																		//
gotoxy(175, 2);																				//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Low Quantity: ");																	//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	//
printf("%d", lowquantity());																//									Top Menu ends.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	//------------------------------------------------------------------------------------------

do{																							//Do while loop for user input.
	gotoxy(52,9);																			//	
	scanf("%d", &id);																		//Receive the user input.
	fflush(stdin);																			//With each loop flush the input file.			
	if(id == 9999)																			//If the id given by the user is 9999 (code for clients view file can be anything).
		system("data\\clients.txt");														//open the file clients.txt.
}while(id == 9999);																			//Keep looping as long as the id given is 9999.		
for(j=53;j<56;j++)																			//For loop that is needed to clear the line 8 of screen so each time the user entry clears.	
{					
	gotoxy(j,8);																			//Move along the 8th line.
	printf(" ");																			//And print empty character for 4 characters
}																							//


while (fgets(line, 1024, client) != NULL)                									//While loop that read the entries of clients.csv file line by line and saved in line array.                          
{																							//Each line is received in a formated way by sscanf function as below.	
	sscanf(line, "%d,%s,%s,%s,%s,%lu,%s,%d,%f,%d[^\n]", &cl.cid, cl.cname, cl.clname, cl.caddress, cl.ccity, &cl.ctel, cl.cemail, &cl.cpostal, &cl.cdiscount, &cl.ctotal);	

	if(id == cl.cid)																		//If condition a match is found between the user input and client id taken from a line.
	{    
		tmp_cid = atoi(strtok(line, ","));													//Strtok function to receive the second smaller part seperated by the next ",". Converted in int.	
		tmp_cname = strtok(NULL, ",");														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_clname = strtok(NULL, ",");														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_caddress = strtok(NULL, ",");													//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_ccity = strtok(NULL, ","); 														//Strtok function to receive the second smaller part seperated by the next ",".
		tmp_ctel = atoll(strtok(NULL, ","));												//Strtok function to receive the second smaller part seperated by the next ",". Converted in long long int.
		tmp_cemail = strtok(NULL, ","); 													//Strtok function to receive the second smaller part seperated by the next ",".		
		tmp_cpostal = atoi(strtok(NULL, ","));												//Strtok function to receive the second smaller part seperated by the next ",". Converted in int.
		tmp_cdiscount = atof(strtok(NULL, ","));											//Strtok function to receive the second smaller part seperated by the next ",". Converted in float.
        
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(53,10);																		//
		printf("%s", tmp_cname);															//Print on screen the client's name.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(51,11);																		//
		printf("%s", tmp_clname);															//Print on screen the client's last name.
		gotoxy(85,9);																		//
		printf("%s", tmp_caddress);															//Print on screen the client's address.		
		gotoxy(89,10);																		//
		printf("%d", tmp_cpostal);															//Print on screen the client's postal code.
		gotoxy(81,11);																		//
		printf("%s", tmp_ccity);															//Print on screen the client's city. 
		gotoxy(128,9);																		//
		printf("%s", tmp_cemail);															//Print on screen the client's email address.
		gotoxy(126,10);																		//	
		printf("%lld", tmp_ctel);															//Print on screen the client's phone number.
		gotoxy(172,33);																		//
		realdisc = tmp_cdiscount * 100;														//Calculate the discount as percentage (x%).
		printf("%d%%", realdisc);															//Print on screen the discount with the symbol % at the end.
		gotoxy(130,11);																		//
		printf("%.2f", tmp_cdiscount);														//Print on screen the client discount as float number.				
		empid(turnname);																	//Call the empid function to receive the employee ID.	
		employID = empid(turnname);															//Set the variable employeId to be the return value of the function.			
		gotoxy(168,9);																		//	
		printf("%s", employID);																//Print the employee Id.
		do{																					//Do while loop needed for the user option to keep adding products or leave the invoice.
			if(more == 'n')																	//If condition, user gives "n", then break the loop of adding more items.
				break;																		//
			do																				//Do while nested loop to read the user input for the product id each time a new product	
			{																				//is added to the invoice.
				gotoxy(7,yi);																//Each product added in the invoice it will be added to the new line.
				fflush(stdin);																//Flush the input file.
				scanf("%d", &prodid);														//Read the user input for the product id.
				fflush(stdin);																//Flush the input file.
				if(prodid == 9999)															//If condition the product id given by the user is 9999 (code input).
					system("data\\products.txt");											//Open the products.txt file for the user to see.
			}while(prodid == 9999);															//Do while loop when prodid is 9999.
			for(j=8;j<12;j++)																//For loop needed to replace the "_" characters (line graphic of invoice graphs).
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
				gotoxy(j,yi);																//Coords.
				printf("_");																//Replace what is written with the original _ character.
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);

			prodinfo(prodid, yi, prodtax, prodprice, counti);								//Call the prodinfo function to retrieve the information of the product id given by the user.
			gotoxy(128, yi);																//	
			printf("%.2f", prodtax[counti]);												//Print on screen the tax of the counti-nth product.
			gotoxy(138, yi);																//
			printf("%.2f", prodprice[counti]);												//Print on screen the price of the counti-nth product.
			gotoxy(155,yi);																	//
			scanf("%d", &prodamount[counti]);												//Read the user input for the amount of the client buys of the specific product (counti).	
			fflush(stdin);																	//Flush the input file.	
			
			totprod[counti] = prodprice[counti] * (float) prodamount[counti];				//Calculate the total product cost (counti-nth product).	
			
			gotoxy(171,yi);
			printf("%.2f", totprod[counti]);												//Print the result of the previous calculation.					
			subtotal += totprod[counti];													//Calculate the subtotal to be equal the previous subtotal plus the new product addition cost.
						
			total = subtotal - (subtotal*tmp_cdiscount);                                    //Calculate the total cost of the invoice by subtracting the disconut.
			gotoxy(172,32);																	//
			printf("%.2f", subtotal);														//Print on screen the subtotal.
			gotoxy(172,34);																	//
			printf("%.2f", total);															//Print on screen the total cost of the invoice.	
			gotoxy(185,yi);																	//	
			prods[counti] = prodid;															//Add in the counti-nth position of prods the product id. Needed for subtracting quantities from warehouse.
			amounts[counti] = prodamount[counti];											//Add in the counti-nth position of amounts the amount of products bought. Needed for subtracting quantities from warehouse.
			printf("Add more products? (Y/N)");												//Ask user if he wish to add more products to the invoice.
			more = getch();																	//Set the user input to be the more variable.
			fflush(stdin);																	//Flush the input file.
			yi++;																			//Increase the y axis of gotoxy.
			counti++;																		//Increase counti variable (which counts the products of the specific invoice).
			
		}while(counti < 18 && more != 'n');													//While keeps running until 18th product (end of invoice page) or until user doesn't wish to add more.
		fseek(retail, 0, SEEK_END);															//Go to the end of the retail_invoices.csv file.
		fprintf(retail, "%s,%d,%.2f\n", employID, tmp_cid, total);							//Add as new entry (line) the details shown as a new invoice.			
		fclose(retail);																		//Close the retail_invoices.csv file.
		strcpy(username, turnname);															//Placing username string to be the same as turnname.		
		calculator(prods, amounts, counti);													//Call the calculator function to calculate and subtract the amounts of the invoice from the products.csv file.
		if(rights[0] == 'y')																//At the end of the invoice, if the rights[0] (rights) is admin.
			managerMenu(username, rights);													//Call the managerMenu function.
		else																				//	
			employeeMenu(username, rights);													//If not call the employeeMenu function.	
	}		
}
fclose(acc);																				//Close the employees.csv file.
fclose(retail);																				//Close the retail_invoices.csv file.
fclose(prod); 																				//Close the products.csv file.		
strcpy(username, turnname);																	//Placing username string to be the same as turnname.
if(rights[0] == 'y')																		//At the end of the invoice, if the rights[0] (rights) is admin.
	managerMenu(username, rights);															//Call the managerMenu function.
else																						//
	employeeMenu(username, rights);															//If not call the employeeMenu function.
gotoxy(2,41);																				//
printf("Wait while files are being updated....");											//
sleep(5);																					//
//rename("data/employees.csv", "data/employees-backup.csv");								//	
gotoxy(2,42);																				//
printf("Wait while files are being updated....");											//		
sleep(5);																					//
//rename("data/employees_copy.csv", "data/employees.csv");									//
sleep(5);																					//
//remove("data/employees-backup.csv");														//	
gotoxy(2,43);																				//
printf("Files updated....");																//
gotoxy(77,41);																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);					//		
printf("Update Successful. Please Press any key to go back.");								//
strcpy(username, turnname);																	//	
getch();																					//Wait for user input.	
if(rights[0] == 'y')																		//At the end of the invoice, if the rights[0] (rights) is admin.
	managerMenu(username, rights);															//Call the managerMenu function.	
else																						//
	employeeMenu(username, rights);															//If not call the employeeMenu function.
//registries(username, rights);
fclose(retailart);																			//Close the retail_invoice.csv file.
}																							//Retail function ends.

void invoices(char username[], char rights[]){												//Invoices function begin.			

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
																							//Variables definition begin.
char *invoicesart = "art/border1.dat";
FILE *art = NULL, *notes;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int choice, count = 0;
char turnname[10], cha, last = '\n';
strcpy(turnname, username);
char *dirname = username;
																							//Variables definition ends.

system("CLS");																				//Clear screen.
if((art = fopen(invoicesart,"r")) == NULL)													//------------------------------------------------------------------------------------------
    {																						//
        fprintf(stderr,"error opening %s\n",invoicesart);									//If condition the ascii art file does not exist, print the error message.
        return 1;																			//
}																							//------------------------------------------------------------------------------------------		
print_title(art);																			//Print on screen the ascii art file.		

gotoxy(62,2);																				//------------------------------------------------------------------------------------------
printf("Welcome Back: ");																	//										Top Menu begins.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE); //
printf("%s", username);																		//
gotoxy(62,3);																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Date: ");																			//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE); //
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);							//
gotoxy(62,4);																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Notes: ");																			//
sprintf(dirname, "%s.txt", username);														//
notes = fopen(dirname, "rb");																//Open the notes file with the tile of the active username.
for(cha = getc(notes); cha != EOF; cha = getc(notes)){										//For loop that takes character by character the contents of the notes file until end of file.		
	if(cha == '\n' && last != '\n')															//If condition a new line character ("\n") is found and the last variable isn't the new line.
		count++;																			//Increase the count variable (variable that counts the number of notes available (1 line = 1 note).
	last = cha;																				//
}																							//
fclose(notes);																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	//
printf("%d", count);																		//
gotoxy(175, 2);																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Low Quantity: ");																	//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	//
printf("%d", lowquantity());																//										Top Menu ends.	
gotoxy(105, 15);																			//------------------------------------------------------------------------------------------
printf("~~Invoices Menu~~");																//Invoices Menu and user options.
gotoxy(105, 17);																			//
printf("1. Retail Invoice");																//	
gotoxy(105, 18);																			//
printf("2. Back");																			//
gotoxy(105, 20);																			//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);					//
strcpy(username, turnname);																	//
printf("Enter your Choice: ");																//
scanf("%d", &choice);																		//User input saved in the choice variable.
switch(choice)																				//Switch for user input.
{
	case 1:																					//For case 1 call the retail function.
		retail(username, rights);
		break;	
	case 2:																					//For case 2 call the managerMenu function.
		if(rights[0] == 'y')																//At the end of the invoice, if the rights[0] (rights) is admin.
			managerMenu(username, rights);													//Call the managerMenu function.	
		else																				//
			employeeMenu(username, rights);													//If not call the employeeMenu function.
		break;
}
fclose(invoicesart);																		//Close the ascii art file.
}
