#include "../headers/reg.h"
#include "../headers/structs.h"

void reg(void){
char *borderart = "art/border1.dat"; 
FILE *art = NULL;
FILE *acc; 
a.id = 0;
char c;                                                                     //registries
long int recsize = sizeof(a);


acc=fopen("data/employees.csv","rb+");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
if((art = fopen(borderart,"r")) == NULL)                                 
	{                                                                      
        fprintf(stderr,"error opening %s\n",borderart);                          
        return;                                                                  
    }                                                                           
print_title(art);

gotoxy(105,11);
printf("Registration Page");
gotoxy(43,14);
for (c = getc(acc); c != EOF; c = getc(acc)){
	if (c == '\n')
	a.id = a.id + 1;
}
gotoxy(74,14);
printf("ID: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
printf("%d", a.id);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,16);
printf("First Name: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.fname);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,18);
printf("Last Name: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.lname);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,20);
printf("Gender: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.gender);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,22);
printf("Birthday (dd/mm/yyyy): ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%d/%d/%d", &a.dd, &a.mm, &a.yyyy);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,24);
printf("Address: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s %s %s", &a.address1, &a.address2, &a.address3);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,26);
printf("City: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.city);
gotoxy(116,14);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Tel 1: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%4d%3d%3d", &a.tel1c, &a.tel1p1, &a.tel1p2);
gotoxy(116,16);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Tel 2: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%4d%3d%3d", &a.tel2c, &a.tel2p1, &a.tel2p2);
gotoxy(116,18);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Email: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.email);
gotoxy(116,20);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("SSN: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%d", &a.ssn);
gotoxy(116,22);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Date of Joining (dd/mm/yyyy): ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%d/%d/%d", &a.ddjoin, &a.mmjoin, &a.yyyyjoin);
gotoxy(116,24);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Department: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.department);
gotoxy(116,26);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Administration: ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
a.administrator = getch();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
gotoxy(74,28);
printf("Username (max 10 char): ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.username);
gotoxy(116,28);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
printf("Password (max 10 char): ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
scanf("%s", &a.password);

fseek(acc, 0, SEEK_END);
fprintf(acc, "%d,%s,%s,%s,%d/%d/%d,%s %s %s,%s,%4d%3d%3d,%4d%3d%3d,%s,%d,%d/%d/%d,%s,%s,%s,%c\n", a.id, a.fname, a.lname, a.gender, a.dd, a.mm, a.yyyy, a.address1, a.address2, a.address3, a.city, a.tel1c, a.tel1p1, a.tel1p2, a.tel2c, a.tel2p1, a.tel2p2, a.email, a.ssn, a.ddjoin, a.mmjoin, a.yyyyjoin, a.department, a.username, a.password, a.administrator);

fclose(acc);

gotoxy(77,33);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
printf("Registration Successful. Please Press any key to go back to main menu.");
getch();
mainMenu();
fclose(borderart);

}
