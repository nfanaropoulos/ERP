#include "../headers/addproduct.h"
#include "../headers/structs1.h"

void editproduct(char username[], char rights[]){
char *editproductart = "art/border1.dat"; 
FILE *art = NULL;
FILE *prod;
int i;
char prod_id[4];
char charac = 'a'; 
char c;                                                                     //warehouse
//long int recsize = sizeof(line);
time_t t = time(NULL);
struct tm tm = *localtime(&t);
char line[3072];
char *chk_pid;
char *chk_pname;
char *chk_pdesc;
char *chk_psupp;
char *chk_pdd;
char *chk_pmm;
char *chk_pyyyy;
char *chk_pcategory;
float *chk_unit_price;
float *chk_tax;
char *chk_warehouse_quantity;
char *chk_packaging;
int *chk_total_quantity;
int j=0;
int l=3;

prod=fopen("data/products.csv","rb+");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
system("CLS");
if((art = fopen(editproductart,"r")) == NULL)                                 
	{                                                                      
        fprintf(stderr,"error opening %s\n",editproductart);                          
        return;                                                                  
    }                                                                           
print_title(art);
gotoxy(62,2);
printf("Welcome Back: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%s", username);
gotoxy(62,3);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Date: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
gotoxy(62,4);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Notes: ");
gotoxy(200, 2);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Low Quantity: ");
gotoxy(105,11);
printf("Product Edit Page");


gotoxy(74,14);
printf("ID: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
getchar();
for(i=0; i<=4;i++)
{
	charac = getchar();
	if(charac == '\n')
		break;
	prod_id[i] = charac;
}
prod_id[i] = '\0';

while (fgets(line, 1024, prod))                                          
{  
	char* tmp0 = strdup(line);
	char* tmp1 = strdup(line);
	char* tmp2 = strdup(line);
	char* tmp3 = strdup(line);
	char* tmp4 = strdup(line);
	char* tmp5 = strdup(line);
	char* tmp6 = strdup(line);
	char* tmp7 = strdup(line);
	char* tmp8 = strdup(line);
	char* tmp9 = strdup(line);
	char* tmp10 = strdup(line);
	chk_pid = getfield(tmp0,1); 
	chk_pname = getfield(tmp1,2);
	chk_pdesc = getfield(tmp2,3);
	chk_psupp = getfield(tmp3,4); 
	chk_pdd = getfield(tmp4,5); 
	chk_pcategory = getfield(tmp5,6);
	chk_unit_price = getfield(tmp6,7);
	chk_tax = getfield(tmp7,8);
	chk_warehouse_quantity = getfield(tmp8,9);
	chk_packaging = getfield(tmp9,10);
	chk_total_quantity = getfield(tmp10,11);
	
int j=0;
int l=3;	

	for(i=0;i<4;i++)
	{
		if(chk_pid[l] == prod_id[i])
		{
			l++;
			j++;	
		}
	}    

sscanf(line, "%d,%s,%s,%s,%s,%s,%f,%f,%d,%s,%[^\n]", &chk_pid, &chk_pname, &chk_pdesc, &chk_psupp, &chk_pdd, &chk_pcategory, &chk_unit_price, &chk_tax, &chk_warehouse_quantity, &chk_packaging, &chk_total_quantity);                                   
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(77,40); 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
printf("Values: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", chk_pid, chk_pname, chk_pdesc, chk_psupp, chk_pdd, chk_pcategory, chk_unit_price, chk_tax, chk_warehouse_quantity, chk_packaging, chk_total_quantity);
gotoxy(74,16);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);

printf("Product Name: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
gets(p.pname);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,18);
printf("Product Description: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
gets(p.pdesc);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,20);
printf("Supplier: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
gets(p.psupp);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,22);
printf("Registration Date (dd/mm/yyyy): ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%s", chk_pdd);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,24);
printf("Product Category: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", p.pcategory);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,26);
printf("Unit Price: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%f", &p.unit_price);
gotoxy(116,14);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Tax: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%f", &p.tax);
gotoxy(116,16);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Product Quantity: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%s", chk_warehouse_quantity);
gotoxy(116,18);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Packaging: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &p.packaging);
gotoxy(116,20);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Total Quantity: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%s", chk_total_quantity);

fclose(prod);

prod=fopen("data/products.csv","rb+");
fseek(prod, -sizeof(line), SEEK_CUR);
fprintf(prod, "%s,%s,%s,%s,%s,%s,%.2f,%.2f,%s,%s,%s\n", chk_pid, p.pname, p.pdesc, p.psupp, chk_pdd, p.pcategory, p.unit_price, p.tax, chk_warehouse_quantity, p.packaging, chk_total_quantity);
fclose(prod);
} 

gotoxy(77,33);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
printf("Update Successful. Please Press any key to go back to Manager Menu.");
getch();
managerMenu(username, rights);
fclose(editproductart);
	
}


void addproduct(char username[], char rights[]){
char *addproductart = "art/border1.dat"; 
FILE *art = NULL;
FILE *prod; 
p.pid = 0;
p.total_quantity = 0;
char c;                                                                     //warehouse
long int recsize = sizeof(p);
time_t t = time(NULL);
struct tm tm = *localtime(&t);

prod=fopen("data/products.csv","rb+");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
system("CLS");
if((art = fopen(addproductart,"r")) == NULL)                                 
	{                                                                      
        fprintf(stderr,"error opening %s\n",addproductart);                          
        return;                                                                  
    }                                                                           
print_title(art);
gotoxy(62,2);
printf("Welcome Back: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%s", username);
gotoxy(62,3);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Date: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
gotoxy(62,4);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Notes: ");
gotoxy(200, 2);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Low Quantity: ");
gotoxy(105,11);
printf("Product Registration Page");
gotoxy(43,14);
for (c = getc(prod); c != EOF; c = getc(prod)){
	if (c == '\n')
	p.pid = p.pid + 1;
}
gotoxy(74,14);
printf("ID: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%d", p.pid);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,16);
printf("Product Name: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
getchar();
gets(p.pname);
//scanf("%s", &p.pname);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,18);
printf("Product Description: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
gets(p.pdesc);
//scanf("%s", &p.pdesc);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,20);
printf("Supplier: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
gets(p.psupp);
//scanf("%s", &p.psupp);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,22);
printf("Registration Date (dd/mm/yyyy): ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%d-%d-%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
p.pdd = tm.tm_mday;
p.pmm = tm.tm_mon + 1;
p.pyyyy = tm.tm_year + 1900;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,24);
printf("Product Category: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &p.pcategory);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,26);
printf("Unit Price: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%f", &p.unit_price);
gotoxy(116,14);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Tax: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%f", &p.tax);
gotoxy(116,16);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Product Quantity: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%d", &p.warehouse_quantity);
gotoxy(116,18);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Packaging: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &p.packaging);
gotoxy(116,20);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Total Quantity: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
p.total_quantity = p.warehouse_quantity;
printf("%d", p.total_quantity);

fseek(prod, 0, SEEK_END);
fprintf(prod, "%d,%s,%s,%s,%d/%d/%d,%s,%.2f,%.2f,%d,%s,%d\n", p.pid, p.pname, p.pdesc, p.psupp, p.pdd, p.pmm, p.pyyyy, p.pcategory, p.unit_price, p.tax, p.warehouse_quantity, p.packaging, p.total_quantity);

fclose(prod);

gotoxy(77,33);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
printf("Registration Successful. Please Press any key to go back to Manager Menu.");
getch();
managerMenu(username, rights);
fclose(addproductart);
}

