/*
Program - Quiz Game
Author - Nikos Fanaropoulos
Institute - IIEK AKMI THESSALONIKI
Language - C Language
Date - 2nd Semester 2019
*/
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include "source/fullscreen.c"
# include "source/gotoxy.c"
# include "source/mainMenu.c"
# include "source/reg.c"
# include "source/login.c"
# include "source/managermenu.c"
# include "source/employeemenu.c"
# define MAX_LEN 128

// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);     								  (Green)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);	   				 				  (Blue)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);	    			  				  (Red)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);			      				  (Gray)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	   			      (Magenta)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);       			  (CYAN)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);          		  (YELLOW)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); (WHITE)

void print_title(FILE *art){                                                                                                                                                              
    char read_string[MAX_LEN];                                                                    
    while(fgets(read_string,sizeof(read_string),art) != NULL)                                                                                                                                
        printf("%s",read_string);  
}
/*

void addEmployee(){														//Add Employee Menu

	printf("Employee Registration Page");
	printf("\nID: ");
	printf("\nFirst Name: ");
	printf("\nLast Name: ");
	printf("\nGender: ");
	printf("\nDate of Joining: ");
	printf("\nDepartment: ");
	printf("\nAddress: ");
	printf("\nCity: ");
	printf("\nTel 1: ");
	printf("\nTel 2: ");
	printf("\nEmail: ");
	printf("\nSSN: ");
	printf("\nBirthday: ");

}
*/
int main(int argc, char *argv[]) {
SetConsoleOutputCP(CP_UTF8); 
fullscreen();
mainMenu();
}

