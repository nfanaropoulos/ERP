#include "../headers/login.h"


const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
        	return tok;
    }
    return NULL;
}

void login(void){
char *loginart = "art/border1.dat"; 
FILE *art = NULL;
FILE *acc; 
char username[10], userpass[10];
int digs = 0;
long int recsize = sizeof(a);
char line[3072];
char *chk_username;
char *chk_password;
char *chk_rights;
char rights;

acc=fopen("data/employees.csv","rb");
system("CLS");
if((art = fopen(loginart,"r")) == NULL)
    {                                                                               
        fprintf(stderr,"error opening %s\n",loginart);                               
        return 1;                                                                    
}                                                                              
print_title(art);                                                                   
    
printf("USERNAME:->");                                                     
scanf("%s", &username);                                                             
printf("PASSWORD:->"); 
scanf("%s", &userpass); 
                                                                                                
while (fgets(line, 1024, acc))                                          
{      
	char* tmp = strdup(line);
	char* tmp1 = strdup(line);
	char* tmp2 = strdup(line);
	chk_username = getfield(tmp,14); 
	chk_password = getfield(tmp1,15);
	chk_rights = getfield(tmp2,16);
		                                                             
    if(strcmp(username,chk_username)==0)                                      
        {      	                                                
           if(strcmp(userpass,chk_password)==0)                                  
            { 
            	if(chk_rights[0] == 'y')
					managerMenu();
				else
					employeeMenu();                                               
            }                                                                   
            else 
			{                                                                                                                                                   
                printf("Wrong Password Please Try Again!Press any key");     
                getch();                                                     
                mainMenu();                                                                                                                  
            }                                                             
        }   
	printf("Account not found! Please press any key");                                                               
}                     
fclose(acc);
mainMenu();
}
