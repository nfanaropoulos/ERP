#include "../headers/addproduct.h"
#include "../headers/structs1.h"
#define MAX_PRODNAME_SIZE 40
#define MAX_PRODDESC_SIZE 100
#define MAX_PRODSUPP_SIZE 35
#define MAX_PRODCAT_SIZE 15
#define MAX_PRODPACK_SIZE 10

void returns(char username[], char rights[]){																//Return product function.												

																											//Variables definition.
	
char *returnsart = "art/border1.dat", *dirname = username, *tmp_name, *tmp_desc, *tmp_supp, *tmp_pdd, *tmp_cat, *tmp_pack;  
FILE *art = NULL, *prod, *prod_co, *notesa;
int tmp_id;
char acc_id[4], cha, last = '\n', c, line[1024], turnname[10]; 
int count = 0, returns, ret_id;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
float tmp_price, tmp_tax;
unsigned long tmp_wquantity, tmp_tq;

																											//Variables definition end.

strcpy(turnname, username);																					//Keeping a copy of username to not mess with it when changing files.
prod=fopen("data/products.csv","rb+");																		//Open products.csv in read, append mode (binary).
prod_co=fopen("data/products_copy.csv", "w");															    //Open products_copy.csv in write mode (over right is ok in this case).
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//Changing foreground colour.
system("CLS");
if((art = fopen(returnsart,"r")) == NULL)                                 								 	//Validate if the ascii art file exists.	
	{                                                                      
        fprintf(stderr,"error opening %s\n",returnsart);                          
        return;                                                                  
    }                                                                           
print_title(art);																							//Print on screen the ascii art.		
																											//Top Menu start.
gotoxy(62,2);																								//
printf("Welcome Back: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//	
printf("%s", username);																						//			
gotoxy(62,3);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Date: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);											//	
gotoxy(62,4);																							 	//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Notes: ");																							//
sprintf(dirname, "%s.txt", username);																		//Retrieve the file named username.txt
notesa = fopen(dirname, "rb");																				//Open the file.
	for(cha = getc(notesa); cha != EOF; cha = getc(notesa)){												//For loop to get char by char until the end of the file .
		if(cha == '\n' && last != '\n')																		//If condition when the character reach a new line and last isn't new line.
			count++;																						//Increase the number of count variable (lines = entries).	
		last = cha;																							//Set last to be current char.
	}																										//
fclose(notesa);																								//Close notes file.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", count);																						//Print on screen the amount of notes exist in the personal file.
gotoxy(175, 2);																								//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Low Quantity: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", lowquantity());																				//	
																											//Top Menu ends.
gotoxy(105,14);
printf("Product Returns Page");

gotoxy(74,14);
printf("ID: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%d", &ret_id);

while (fgets(line, 1024, prod) != NULL)                                          							//While loop to get each line of products.csv and save it in line[1024].					
{																											//Sscanf to read formated input from each line collected by while.
	sscanf(line, "%d,%s,%s,%s,%s,%s,%f,%f,%lu,%s,%lu[^\n]", &p.pid, p.pname, p.pdesc, p.psupp, p.pdd, p.pcategory, &p.unit_price, &p.tax, &p.warehouse_quantity, p.packaging, &p.total_quantity);
	if(ret_id == p.pid)																						//If the return_id given by user matches the product_id found on a line.
	{   																									//Follows strtok Function to split the line string into comma seperated strings.
		tmp_id = atoi(strtok(line, ","));																	//Atoi function used to convert the char string into integer, for IDs.
		tmp_name = strtok(NULL, ",");																		//
		tmp_desc = strtok(NULL, ",");																		//
		tmp_supp = strtok(NULL, ",");																		//
		tmp_pdd = strtok(NULL, ","); 																		//		
		tmp_cat = strtok(NULL, ",");																		//			
		tmp_price = atof(strtok(NULL, ","));  																//Atof Function used to convert the char string into float, for prod.price.	
		tmp_tax = atof(strtok(NULL, ","));																	//
		tmp_wquantity = atoll(strtok(NULL, ","));															//Atoll Function used to convert the char string into long long int for quantities.	
		tmp_pack = strtok(NULL, ",");																		//---------------------------------------------------------------------------------
		tmp_tq = atoll(strtok(NULL, ","));                       											//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,16); 																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);							//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		printf("Product Name: ");																			//						Retrieved Product Information start.	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		printf("%s", tmp_name);																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,18); 																						//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//						Retrieved Product Information ends.
		printf("Return Amount: ");																			//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//	--------------------------------------------------------------------------------
		scanf("%d", &returns);																				//Read returns value given by the user.
		
		tmp_wquantity += returns;																			//Add the returned product to the total quantity exist in warehouse.
		
		fseek(prod_co, 0, SEEK_END);																		//Seek the end of line of products_copy.csv and save the new entry with fprintf below.
		fprintf(prod_co, "%d,%s,%s,%s,%s,%s,%.2f,%.2f,%lu,%s,%lu\n", tmp_id, tmp_name, tmp_desc, tmp_supp, tmp_pdd, tmp_cat, tmp_price, tmp_tax, tmp_wquantity, tmp_pack, tmp_tq);		
	}																										
	else																									//If the line read from the file is not the matched one.	
	{																										//
		fseek(prod_co, 0, SEEK_END);																		//Go to the end of the file.				
		fputs(line, prod_co);																				//Put the non match entry to the end of the file.
	}																										//****NOTE . We need a copy of products.csv file , named products_copy.csv	
} 																											//****		 Because .csv files cannot be edited while open.	
fclose(prod);																								//Close products.csv file.
fclose(prod_co);																							//Close products_copy.csv file.
gotoxy(2,36);	
printf("Wait while files are being updated....                                                                ");
sleep(7);																									//Seems like sleep function is needed when copying/renaming/deleting files.
rename("data/products.csv", "data/products-backup.csv");													//Rename products.csv -> products-backup.csv.		
gotoxy(2,37);
printf("Wait while files are being updated....                                                                ");
sleep(7);																									//Seems like sleep function is needed when copying/renaming/deleting files.
rename("data/products_copy.csv", "data/products.csv");														//Rename products_copy.csv -> products.csv. 
sleep(7);																									//Seems like sleep function is needed when copying/renaming/deleting files.
remove("data/products-backup.csv");																			//Delete products-backup.csv.
gotoxy(2,39);
printf("Files updated....                                                                                     ");
gotoxy(77,36);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
printf("Update Successful. Please Press any key to go back to Manager Menu.");
strcpy(username, turnname);																					//Reset username string to the saved turnname.	
getch();
warehousemenu(username, rights);																			//Calling warehousemenu function.
fclose(returnsart);																							//Close file of ascii art.
}																											//End of return product function.

void orders(char username[], char rights[]){																//Order product function.
																											//Variables definition start.
char *editprodart = "art/border1.dat", *dirname = username, line[1024], turnname[10]; 
FILE *art = NULL, *prod, *prod_co, *notesa;
char cha, last = '\n';
int count = 0, order, ord_id, tmp_id;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
float tmp_price, tmp_tax;
char *tmp_name, *tmp_desc, *tmp_supp, *tmp_pdd, *tmp_cat, *tmp_pack;
unsigned long tmp_wquantity, tmp_tq;
																											//Variables definition end.
strcpy(turnname, username);																					//Saving username string to turnname to avoid issues when leaving function.
prod=fopen("data/products.csv","rb+");																		//open products.csv in read, binary and append mode.
prod_co=fopen("data/products_copy.csv", "w");																//open products_copy.csv in write mode, rewritting data is ok.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	
system("CLS");	
if((art = fopen(editprodart,"r")) == NULL)																	//If condition in case ascii art file does not exist.				                                 
	{                                                                      									//
        fprintf(stderr,"error opening %s\n",editprodart);                          							//
        return;                                                                  							//		
    }                                                                           							//
print_title(art);																							//Start printing the ascii art.	

gotoxy(62,2);
printf("Welcome Back: ");																					//Top menu starts.
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
sprintf(dirname, "%s.txt", username);																		//Retrieve the file named username.txt	
notesa = fopen(dirname, "rb");																				//Open the file.
	for(cha = getc(notesa); cha != EOF; cha = getc(notesa)){												//For loop to get char by char until the end of the file.		
		if(cha == '\n' && last != '\n')																		//If condition when the character reach a new line.
			count++;																						//Increase the number of count variable (lines = entries).
		last = cha;																							//Set last to be current char.	
	}																										//
																											//
fclose(notesa);																								//Close notes file.	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", count);																						//Print on screen the amount of notes exist in the personal file.		
gotoxy(175, 2);																								//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Low Quantity: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", lowquantity());																				//
gotoxy(105,14);																								//Top menu ends.
printf("Product Order Page");

gotoxy(74,14);
printf("ID: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%d", &ord_id);

while (fgets(line, 1024, prod) != NULL) 																	//While loop to get each line of products.csv and save it in line[1024].                                         
{																											//Sscanf to read formated input from each line collected by while.
	sscanf(line, "%d,%s,%s,%s,%s,%s,%f,%f,%lu,%s,%lu[^\n]", &p.pid, p.pname, p.pdesc, p.psupp, p.pdd, p.pcategory, &p.unit_price, &p.tax, &p.warehouse_quantity, p.packaging, &p.total_quantity);
	if(ord_id == p.pid)																						//If the ord_id given by user matches the product_id found on a line.
	{   																									//Follows strtok Function to split the line string into comma seperated strings.
		tmp_id = atoi(strtok(line, ","));																	//Atoi function used to convert the char string into integer, for IDs.
		tmp_name = strtok(NULL, ",");																		//
		tmp_desc = strtok(NULL, ",");																		//		
		tmp_supp = strtok(NULL, ",");																		//	
		tmp_pdd = strtok(NULL, ","); 																		//
		tmp_cat = strtok(NULL, ",");																		//
		tmp_price = atof(strtok(NULL, ","));  																//Atof Function used to convert the char string into float, for prod.price.
		tmp_tax = atof(strtok(NULL, ","));																	//Atof Function used to convert the char string into float, for prod.price.
		tmp_wquantity = atoll(strtok(NULL, ","));															//Atoll Function used to convert the char string into long long int for quantities.
		tmp_pack = strtok(NULL, ",");																		//		
		tmp_tq = atoll(strtok(NULL, ","));                       											//Atoll Function used to convert the char string into long long int for quantities.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//---------------------------------------------------------------------------------
		gotoxy(74,16); 																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);							//			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//	
		printf("Product Name: ");																			//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//					Retrieving Product Information
		printf("%s", tmp_name);																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,18); 																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		printf("Order Amount: ");																			//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//---------------------------------------------------------------------------------
		scanf("%d", &order);																				//Reading user input for product order amount.
		
		tmp_wquantity += order;																				//Adding the product order amount to the current warehouse quantities.
		tmp_tq += order;																					//Adding the product order amount to the total quantities so far. For stats.

		fseek(prod_co, 0, SEEK_END);																		//Going to the end of the products_copy.csv file to add the new modified entry.
		fprintf(prod_co, "%d,%s,%s,%s,%s,%s,%.2f,%.2f,%lu,%s,%lu\n", tmp_id, tmp_name, tmp_desc, tmp_supp, tmp_pdd, tmp_cat, tmp_price, tmp_tax, tmp_wquantity, tmp_pack, tmp_tq);		
	}
	else																									//In case of products that do not match the order id.
	{
		fseek(prod_co, 0, SEEK_END);																		//Going to the end of the products_copy.csv file.
		fputs(line, prod_co);																				//Add the line untouched.		
	}
} 
fclose(prod);																								//Close the file products.csv.	
fclose(prod_co);																							//Close the file products_copy.csv.
gotoxy(2,36);
printf("Wait while files are being updated....");
sleep(5);																									//Seems like sleep function is needed when copying/renaming/deleting files.
rename("data/products.csv", "data/products-backup.csv");													//Change products.csv -> products-backup.csv.
gotoxy(2,37);
printf("Wait while files are being updated....");
sleep(5);																									//Seems like sleep function is needed when copying/renaming/deleting files.
rename("data/products_copy.csv", "data/products.csv");														//Change products_copy.csv -> products.csv.
sleep(5);																									//Seems like sleep function is needed when copying/renaming/deleting files.
remove("data/products-backup.csv");																			//Delete products-backup.csv.
gotoxy(2,39);
printf("Files updated....");
gotoxy(77,36);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
printf("Update Successful. Please Press any key to go back to Manager Menu.");
strcpy(username, turnname);																					//Repositioning the original username string from turnname.
getch();
warehousemenu(username, rights);																			//Calling warehousemenu function.
fclose(editprodart);																						//Close the ascii art file.
}																											//End of Order product function.

void edit_prod(char username[], char rights[]){																//Edit product function.
																											//Variables definition start.
char *editprodart = "art/border1.dat", *dirname = username; 
FILE *art = NULL, *prod, *prod_co, *notesa;
char cha, last = '\n', line[1024], turnname[10];
int count = 0, tmp_id, id;
time_t t = time(NULL);
struct tm tm = *localtime(&t);
float tmp_price, tmp_tax;
char *tmp_name, *tmp_desc, *tmp_supp, *tmp_pdd, *tmp_cat, *tmp_pack;
unsigned long tmp_wquantity, tmp_tq;
																											//Variables definition ends.
strcpy(turnname, username);																					//Saving username string in turnname.
prod=fopen("data/products.csv","rb+");																		//Open products.csv in binary, read and append mode.
prod_co=fopen("data/products_copy.csv", "w");																//Open products_copy.csv in write mode. Rewritting is ok.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
system("CLS");																								//
if((art = fopen(editprodart,"r")) == NULL)                                 									//-------------------------------------------------------------------
	{                                                                      									//
        fprintf(stderr,"error opening %s\n",editprodart);                          							//			If condition in case ascii art file is missing.
        return;                                                                  							//
    }                                                                           							//-------------------------------------------------------------------	
print_title(art);																							//Print ascii art.

gotoxy(62,2);
printf("Welcome Back: ");																					//--------------------------------------------------------------------		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//							Top Menu Start.
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
notesa = fopen(dirname, "rb");																				//
	for(cha = getc(notesa); cha != EOF; cha = getc(notesa)){												//
		if(cha == '\n' && last != '\n')																		//			
			count++;																						//
		last = cha;																							//
	}																										//			
																											
fclose(notesa);																								//

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", count);																						//					
gotoxy(175, 2);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//			
printf("Low Quantity: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", lowquantity());																				//							Top Menu Sends.
gotoxy(105,14);																								//-------------------------------------------------------------------
printf("Product Edit Page");

gotoxy(74,14);
printf("ID: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%d", &id);																							//Receive the user input the id of the product to edit.

while (fgets(line, 1024, prod) != NULL)                														//While loop to get each line of products.csv and save it in line[1024].                          
{																											//Sscanf to read formated input from each line collected by while.
	sscanf(line, "%d,%s,%s,%s,%s,%s,%f,%f,%lu,%s,%lu[^\n]", &p.pid, p.pname, p.pdesc, p.psupp, p.pdd, p.pcategory, &p.unit_price, &p.tax, &p.warehouse_quantity, p.packaging, &p.total_quantity);
	if(id == p.pid)																							//If the id given by user matches the product_id found in a line.
	{      																									//Follows strtok Function to split the line string into comma seperated strings.
		tmp_id = atoi(strtok(line, ","));																	//Atoi function used to convert the char string into integer, for IDs.
		tmp_name = strtok(NULL, ",");																		//
		tmp_desc = strtok(NULL, ",");																		//
		tmp_supp = strtok(NULL, ",");																		//
		tmp_pdd = strtok(NULL, ","); 																		//
		tmp_cat = strtok(NULL, ",");																		//
		tmp_price = atof(strtok(NULL, ","));  																//Atof function used to convert the char string into float.	
		tmp_tax = atof(strtok(NULL, ","));																	//Atof function used to convert the char string into float.
		tmp_wquantity = atoll(strtok(NULL, ","));															//Atoll function used to convert the char string into long long int.
		tmp_pack = strtok(NULL, ",");																		//
		tmp_tq = atoll(strtok(NULL, ",")); 																	//Atoll function used to convert the char string into long long int.			
		                       
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,16); 																						//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);							//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		printf("Product Name: ");																			//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.	
		fgets(p.pname, MAX_PRODNAME_SIZE, stdin);															//Receiving user input and saving data to struct variable p.name with specific max size.
		if ((strlen(p.pname) > 0) && (p.pname[strlen (p.pname) - 1] == '\n'))								//If condition the length of p.pname is bigger than 0 and it ends with new line \n.	
    		p.pname[strlen (p.pname) - 1] = '\0';															//Then replace the \n with \0. Replace new line with end of string.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,18);																						//
		printf("Product Description: ");																	//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.
		fgets(p.pdesc, MAX_PRODDESC_SIZE, stdin);															//
		if ((strlen(p.pdesc) > 0) && (p.pdesc[strlen (p.pdesc) - 1] == '\n'))								//Receiving user input and saving data to struct variable p.pdesc with specific max size.		
    		p.pdesc[strlen (p.pdesc) - 1] = '\0';															//If condition the length of p.pdesc is bigger than 0 and it ends with new line \n.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//Then replace the \n with \0. Replace new line with end of string.
		gotoxy(74,20);																						//			
		printf("Product Supplier: ");																		//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.
		fgets(p.psupp, MAX_PRODSUPP_SIZE, stdin);															//Receiving user input and saving data to struct variable p.psupp with specific max size.
		if ((strlen(p.psupp) > 0) && (p.psupp[strlen (p.psupp) - 1] == '\n'))								//If condition the length of p.psupp is bigger than 0 and it ends with new line \n.
    		p.psupp[strlen (p.psupp) - 1] = '\0';															//Then replace the \n with \0. Replace new line with end of string.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,22);																						//
		printf("Registration Date (dd/mm/yyyy): ");															//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		printf("%s", tmp_pdd);																				//Printing the registration date that was taken by the sscanf function.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,24);																						//	
		printf("Category: ");																				//	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.
		fgets(p.pcategory, MAX_PRODCAT_SIZE, stdin);														//Receiving user input and saving data to struct variable p.pcategory with specific max size.
		if ((strlen(p.pcategory) > 0) && (p.pcategory[strlen (p.pcategory) - 1] == '\n'))					//If condition the length of p.pcategory is bigger than 0 and it ends with new line \n.
    		p.pcategory[strlen (p.pcategory) - 1] = '\0';													//Then replace the \n with \0. Replace new line with end of string.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		gotoxy(74,26);																						//
		printf("Unit Price: ");																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.
		scanf("%f", &p.unit_price);																			//Receiving the user input for the new price. Saved in struct variable p.unit_price.
		gotoxy(116,16);																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		printf("Tax: ");																					//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.
		scanf("%f", &p.tax);																				//Receiving the user input for the new tax. Saved in struct variable p.tax.
		gotoxy(116,18);																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		printf("Warehouse Quantity: ");																		//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.
		scanf("%lu", &p.warehouse_quantity);																//Receiving the user input for the warehouse quantity. Saved in struct variable p.warehouse_quantity.
		gotoxy(116,20);																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//	
		printf("Packaging: ");																				//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		fflush(stdin);																						//Flushing the input file to clear trash data.
		fgets(p.packaging, MAX_PRODPACK_SIZE, stdin);														//Receiving user input and saving data to struct variable p.packaging with specific max size.
		if ((strlen(p.packaging) > 0) && (p.packaging[strlen (p.packaging) - 1] == '\n'))					//If condition the length of p.packaging is bigger than 0 and it ends with new line \n.
    		p.packaging[strlen (p.packaging) - 1] = '\0';													//Then replace the \n with \0. Replace new line with end of string.
		gotoxy(116,22);																						//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);		//
		printf("Total Quantity: ");																			//
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);			//
		printf("%lu", tmp_tq);																				//Printing the total quality received from sscanf. %lu is used for long unsigned int.
		p.total_quantity = tmp_tq;																			//Calculating the new struct variable p.total_quantity by making it equal to tmp_tq.
		fseek(prod_co, 0, SEEK_END);																		//Go to the end of product_copy.csv file. And fprintf the new edited line for the specific product.
		fprintf(prod_co, "%d,%s,%s,%s,%s,%s,%.2f,%.2f,%lu,%s,%lu\n", p.pid, p.pname, p.pdesc, p.psupp, tmp_pdd, p.pcategory, p.unit_price, p.tax, p.warehouse_quantity, p.packaging, p.total_quantity);		
	}
	else																									//In case of not a match id.
	{
		fseek(prod_co, 0, SEEK_END);																		//Go to the end of product_copy.csv file.
		fputs(line, prod_co);																				//And place the untouched line taken by sscanf.		
	}
} 
fclose(prod);																								//Close products.csv file.
fclose(prod_co);																							//Close products_copy.csv file.
gotoxy(2,36);
printf("Wait while files are being updated....");
sleep(5);																									//Seems like sleep delay is needed when copying/renaming/deleting files.
rename("data/products.csv", "data/products-backup.csv");													//Rename products.csv -> products-backup.csv.		
gotoxy(2,37);	
printf("Wait while files are being updated....");
sleep(5);																									//Seems like sleep delay is needed when copying/renaming/deleting files.	
rename("data/products_copy.csv", "data/products.csv");														//Rename products_copy.csv -> products.csv.
sleep(5);																									//Seems like sleep delay is needed when copying/renaming/deleting files.
remove("data/products-backup.csv");																			//Remove products-backup.csv file.
gotoxy(2,39);
printf("Files updated....");
gotoxy(77,36);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
printf("Update Successful. Please Press any key to go back to Manager Menu.");
strcpy(username, turnname);																					//Returning the username string from turnname.
getch();
warehousemenu(username, rights);																			//Calling the warehousemenu function.
fclose(editprodart);																						//Close the ascii art file.
}																											//End of edit product function.

void addproduct(char username[], char rights[]){															//Add product Function.
																											//Variables definition start.	
char *addproductart = "art/border1.dat"; 
FILE *art = NULL, *prod, *prod_cp, *notes, *low_cp;
char* dirname = username;

p.total_quantity = 0;
char c, cha, last = '\n';
long int recsize = sizeof(p);
time_t t = time(NULL);
struct tm tm = *localtime(&t);
p.pname[0] = '>';
int j, k, l, count = 0, counter =1, counting = 0, ids = 0;
char line[1024], line1[1024], turnname[10], pname[40];
																											//Variables definition end.
strcpy(turnname, username);																					//Saving username string in turnname.
system("copy data\\products.csv data\\products.txt");														//Copy products.csv -> products.txt.
system("copy data\\low.csv data\\low.txt");  																//Copy low.csv -> low.txt.
prod_cp=fopen("data/products.txt", "r");																	//Open products.txt in read mode.
prod=fopen("data/products.csv","rb+");																		//Open products.csv in binary, read and append mode.
low_cp=fopen("data/low.txt", "r");																			//Open low.txt in read mode.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);	
system("CLS");																								//Clear screen.
if((art = fopen(addproductart,"r")) == NULL)                                 								//If condition in case of a missing ascii art file.
	{                                                                      									//	
        fprintf(stderr,"error opening %s\n",addproductart);                          						//
        return;                                                                  							//	
    }                                                                           							//	
print_title(art);																							//Print the ascii art file to the screen.
gotoxy(62,2);
printf("Welcome Back: ");																					//--------------------------------------------------------------------
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%s", username);																						//
gotoxy(62,3);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Date: ");																							//						First part of Top Menu.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);											//
gotoxy(62,4);																								//			
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Notes: ");																							//
sprintf(dirname, "%s.txt", username);																		//---------------------------------------------------------------------
notes = fopen(dirname, "rb");																				//Open the corresponding to the username.txt file for personal notes.
	for(cha = getc(notes); cha != EOF; cha = getc(notes)){													//For loop to read character by character until end of file.
		if(cha == '\n' && last != '\n')																		//If condition the character is the new line (\n).
			count++;																						//Increase the count variable, which means each line is a new note.
		last = cha;																							//Set last to be equal to cha.	
	}																										//			
	
fclose(notes);																								//Close the notes file.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//----------------------------------------------------------------------
printf("%d", count);																						//
gotoxy(62,5);																								//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("View Product List : ");																				//			
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("~");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("   Print Product List : ");																			//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("^");																								//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("   View Notes : ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("#");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//	
printf("   Print Notes : ");																				//						Second Part Top Menu.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf(">");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("   Print Low Products : ");																			//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("@");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("   Back : ");																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("!");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);									//	
gotoxy(90,6);																								//
printf("   NOTE!! : Shortcuts work only at the Product Name Entry!");										//
gotoxy(175, 2);																								//		
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Low Quantity: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//------------------------------------------------------------------------				
printf("%d", lowquantity());																				//Call lowquantity function which returns the amount of products below 500.
gotoxy(105,14);																								//
printf("Product Registration Page");																		//			
gotoxy(43,14);																								//
for (c = getc(prod); c != EOF; c = getc(prod)){																//For loop that read character by character the products file until end of file.
	if (c == '\n')																							//When a new line is found.
		ids++;																								//Increase the counter ids variable which means each line is a new product.
}																											//
gotoxy(74,14);																								//
p.pid = ids;																								//
printf("ID: ");																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d", p.pid);																						//Print on screen the new product ID automatically.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
gotoxy(74,16);																								//
printf("Product Name: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
fclose(notes);																								//Close notes file.
do																											//Do while loop for the shortcuts available to the user.
{
	fflush(stdin);																							//Flush the input file.
	fgets(pname, MAX_PRODNAME_SIZE, stdin);																	//Get from input file the user entry with MAX_PRODNAME_SIZE and save it in pname.
	if ((strlen(pname) > 0) && (pname[strlen (pname) - 1] == '\n'))											//If the length of pname is greater than 0 and the end of the string is new line.
    	pname[strlen (pname) - 1] = '\0';																	//Replace the new line character with the end of string character.
	if(pname[0] == '!')																						//If condition the pname string beggin with the character "!".
		warehousemenu(username, rights);																	//Call the warehousemenu function. (Go back shortcut).
	if(pname[0] == '^')																						//If condition the pname string beggin with the character "^".
	{																										//
		gotoxy(0,36);																						//Go to the beggining of the log area.

		while(fgets(line, 1024, prod_cp)) 																	//While loop to retrieve all lines from the products.txt file.
		{
			if(counter == 10)																				//If condition the counter lines variable reach 10 (log page gets full).
			{
				printf("\n Press any key to continue...");													//Print message.
				getch();																					//Wait for any user input.
				gotoxy(0,36);																				//Go back to the start of the log area.
				for(j=36;j<=49; j++)																		//For loop that increase by one the lines from start to end of log area.
				{																							
					gotoxy(0,j);																			//Go to each line.		
					for(l=0;l<=150; l++)																	//Nested for to set the width of the log area from 0-150.
					printf(" ");																			//Print black space (erase), the whole line.
				}
			gotoxy(0,36);																					//Return to the beggining of the log area.
			counter = 1;																					//Reset the counter to 1.
			}											
			printf("%s\n", line);																			//Print the line string as taken by fgets.
			counter++;																						//With each print on screen increase the counter,to check when log is full.
		}
	gotoxy(88,16);																							//Each time the shortcut prints end, return to the user input area.	
	}
	if(pname[0] == '@')																						//If condition pname string beggin with the character "@".
	{
		gotoxy(0,36);																						//Go to the beggining of the log area.

		while(fgets(line1, 1024, low_cp)) 																	//Retrieve all lines from the low.txt file.
		{
			if(counter == 10)																				//If condition the counter variable reach 10, which is the max log entries.
			{
				printf("\n Press any key to continue...");													//Print message.
				getch();																					//Wait for any user input.		
				gotoxy(0,36);																				//Go to the beggining of the log area.
				for(j=36;j<=49; j++)																		//For loop that increase the log area lines by one each time.
				{
					gotoxy(0,j);																			//Go to each line.
					for(l=0;l<=150; l++)																	//Nested for loop to count the width of the log area to be cleared.
					printf(" ");																			//Replace what has been written with the blank (fake erase).
				}
			gotoxy(0,36);																					//Go back to the beggining of the log area.
			counter = 1;																					//Set the counter back to 1.
			}
			printf("%s\n", line1);																			//Print the new line taken by the fgets.
			counter++;																						//With each new line increase the counter by one.
		}
	gotoxy(88,16);																							//Each time the shortcut prints end, return to the user input area.
	}
	if(pname[0] == '~')																						//If condition pname string beggin with the character "~".
	{
		system("data\\products.txt");																		//Open the file products.txt for the user to see.
		gotoxy(88,16);																						//Move cursor to the previous user input location.
	}
	if(pname[0] == '#')																						//If condition pname string beggin with the character "#".
	{
		system(dirname);																					//Open the file username.txt for the user to see.		
		gotoxy(88,16);																						//Move cursor to the previous user input location.	
	}
	if(pname[0] == '>')																						//If condition pname string beggin with the character ">".
	{
		notes = fopen(dirname, "rb");																		//Open notes file in read and binary mode.
		gotoxy(0,36);																						//Go to the beggining of the log area.
		for(j=36;j<=49; j++)																				//For loop to set the lines of the log area one by one.
		{	
			gotoxy(0,j);																					//Move to each line one by one.
			for(l=0;l<=150; l++)																			//Nested for loop to set the width of each line in the log aera.
				printf(" ");																				//Fake erase the line by entering a black space across the line.
		}
		gotoxy(0,36);																						//Move back to the beggining of the log area.	
		k = fgetc(notes);																					//-----------------------------------------------------------------
		while (k != EOF)																					//	Get all characters, one by one from the personal notes file 			
		{																									//	until the file ends, and print each character taken to the 		
			printf ("%c", k);																				//  screen for the user to see.
			k = fgetc(notes); 																				//
		}																								 	//------------------------------------------------------------------			
	gotoxy(88,16);																							//Get cursor back to the original user input area.
	pname[0] = '^';																							//Finally set the first character of the string pname to be ^ so 
	}																										//that the loop beggins again.
}while(pname[0] == '>' || pname[0] == '~' || pname[0] == '^' || pname[0] == '#' || pname[0] == '@');		//Conditions for the loop to go over and over again.
fclose(prod_cp);																							//Close products.txt file.
fclose(low_cp);																								//Close low.txt file.
fclose(notes);																								//Close the personal notes file.	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//--------------------------------------------------------------------------
gotoxy(74,18);																								//	
printf("Product Description: ");																			//	User input area for the new product entry. Some entries require to count
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//how big is the string and replace the last character of new line "\n" with
fflush(stdin);																								//the end string character "\0", because it causes issues when entering the
fgets(p.pdesc, MAX_PRODDESC_SIZE, stdin);																	//values to the files messing up strings and entries. Also it is important
if ((strlen(p.pdesc) > 0) && (p.pdesc[strlen (p.pdesc) - 1] == '\n'))										//to have the stdin file (standard input file) flushed often to remove any
    p.pdesc[strlen (p.pdesc) - 1] = '\0';																	//trash data found inside when we add the string we want to save into an array.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//Finally, each product have the date of entry to be the date the user register
gotoxy(74,20);																								//the product, meaning that it is being added when the product first arrived in
printf("Supplier: ");																						//warehouse, not before, not after.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
fflush(stdin);																								//
fgets(p.psupp, MAX_PRODSUPP_SIZE, stdin);																	//
if ((strlen(p.psupp) > 0) && (p.psupp[strlen (p.psupp) - 1] == '\n'))										//		
    p.psupp[strlen (p.psupp) - 1] = '\0';																	//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//	
gotoxy(74,22);																								//			
printf("Registration Date (dd/mm/yyyy): ");																	//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);											//
p.pdd = tm.tm_mday;																							//
p.pmm = tm.tm_mon + 1;																						//
p.pyyyy = tm.tm_year + 1900;																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//	
gotoxy(74,24);																								//
printf("Product Category: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
fflush(stdin);																								//
fgets(p.pcategory, MAX_PRODCAT_SIZE, stdin);																//
if ((strlen(p.pcategory) > 0) && (p.pcategory[strlen (p.pcategory) - 1] == '\n'))							//
    p.pcategory[strlen (p.pcategory) - 1] = '\0';															//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
gotoxy(74,26);																								//		
printf("Unit Price: ");																						//			
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
fflush(stdin);																								//			
scanf("%f", &p.unit_price);																					//
gotoxy(116,16);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Tax: ");																							//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
fflush(stdin);																								//
scanf("%f", &p.tax);																						//	
gotoxy(116,18);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Product Quantity: ");																				//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//	
fflush(stdin);																								//
scanf("%lu", &p.warehouse_quantity);																		//
gotoxy(116,20);																								//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Packaging: ");																						//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//
fflush(stdin);																								//	
fgets(p.packaging, MAX_PRODPACK_SIZE, stdin);																//
if ((strlen(p.packaging) > 0) && (p.packaging[strlen (p.packaging) - 1] == '\n'))							//
    p.packaging[strlen (p.packaging) - 1] = '\0';															//
gotoxy(116,22);																								//	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);				//
printf("Total Quantity: ");																					//
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);					//-------------------------------------------------------------------------
p.total_quantity = p.warehouse_quantity;																	//Setting the p.total_quality variable to be originally the same as the 
printf("%lu", p.total_quantity);																			//warehouse quantity since it's a new product,once done print it on screen.
																											//Go to the end of the products.csv file, and add the new product with the
fseek(prod, 0, SEEK_END);																					//apropriate format using the fprintf function.
fprintf(prod, "%d,%s,%s,%s,%d/%d/%d,%s,%.2f,%.2f,%lu,%s,%lu\n", ids, pname, p.pdesc, p.psupp, p.pdd, p.pmm, p.pyyyy, p.pcategory, p.unit_price, p.tax, p.warehouse_quantity, p.packaging, p.total_quantity);

fclose(prod);																								//Close the products.csv file.

gotoxy(77,36);																						
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);				
printf("Registration Successful. Please Press any key to go back to Manager Menu.");						//Once it's all done print the appropriate message to the screen.	
strcpy(username, turnname);																					//Replace the saved turnname string to the username.
getch();																									//Wait for any user input.
system("copy data\\products.csv data\\products.txt"); 														//Copy the file products.csv to the products.txt file as backup.	
managerMenu(username, rights);																				//Function call managerMenu.
fclose(addproductart);																						//Close the ascii art file.
}																											//End of add product function.
