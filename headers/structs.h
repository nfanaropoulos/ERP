#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#endif

struct accounts {
   int id;
   char fname[25];
   char lname[25];
   char gender[6];
   int dd;
   int mm;
   int yyyy;
   char address[55];
   char city[15];
   unsigned long tel1;
   unsigned long tel2;
   char email[35];
   long int ssn;
   int ddjoin;
   int mmjoin;
   int yyyyjoin;
   char department[20];
   char administrator;
   char user[10];
   char password[10];
};

struct accounts a;
