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
   char address1[20];
   char address2[20];
   char address3[10];
   char city[15];
   int tel1c;
   int tel1p1;
   int tel1p2;
   int tel2c;
   int tel2p1;
   int tel2p2;
   char email[35];
   long int ssn;
   int ddjoin;
   int mmjoin;
   int yyyyjoin;
   char department[20];
   char administrator;
   char username[10];
   char password[10];
};

struct accounts a;
