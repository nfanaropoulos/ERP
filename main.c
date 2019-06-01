/*
Program - ERP Software
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
# include <time.h>
# include "source/fullscreen.c"
# include "source/gotoxy.c"
# include "source/mainMenu.c"
# include "source/reg.c"
# include "source/login.c"
# include "source/managermenu.c"
# include "source/employeemenu.c"
# include "source/warehousemenu.c"
# include "source/addproduct.c"
# include "source/notes.c"
# include "source/registries.c"
# include "source/supplier.c"
# include "source/clients.c"
# include "source/statsmenu.c"
# include "source/invoices.c"
# include "source/emplstats.c"
# include "source/loading.c"
# define MAX_LEN 128

//gotoxy(3,35) - gotoxy(3,62);
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);     								  (Green)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);	   				 				  (Blue)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);	    			  				  (Red)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);			      				  (Gray)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);	   			      (Magenta)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);       			  (CYAN)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);          		  (YELLOW)
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); (WHITE)

void print_title(FILE *art){         										//Function to print Ascii Art found on Internet.                                                                                                                                                     
    char read_string[MAX_LEN];                                              //Definition of the string to print.                      
    while(fgets(read_string,sizeof(read_string),art) != NULL)               //While loop to read line by line the file containing the art, until it reach the end of file.                                                                                                                 
        printf("%s",read_string);  										    //Print the line string to the monitor.
}

int main(int argc, char *argv[]) {
SetConsoleOutputCP(CP_UTF8); 												
fullscreen();																//Initialize the program in fullscreen.		
loading();																	//Call the loading Function which is the first function the user interact with.
}
