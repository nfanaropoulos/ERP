#ifndef STRUCTS1_H_INCLUDED
#define STRUCTS1_H_INCLUDED
#endif

struct products {
   int pid;
   char pname[40];
   char pdesc[100];
   char psupp[35];
   int pdd;
   int pmm;
   int pyyyy;
   char pcategory[15];
   float unit_price;
   float tax;
   unsigned long warehouse_quantity;
   char packaging[10];
   unsigned long total_quantity;
};

struct products p;
