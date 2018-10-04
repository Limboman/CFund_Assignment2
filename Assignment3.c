/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 * Name: Cameron Leedman
 * Student ID: 10460285
 * Date of submission: 
 * 
*******************************************************************************/

/*******************************************************************************
 * List header files
*******************************************************************************/
#include <stdio.h> /* printf, scanf, fopen, fclose, fprintf, fscanf */
#include <string.h> /* strcmp,  strlen*/
#include <stdlib.h>

/*******************************************************************************
 * Preprocessing directives
*******************************************************************************/

#define MAX_STR_LEN 60
#define MAX_TRIES 4

/*******************************************************************************
 * List structs
*******************************************************************************/
struct login
{
    char name[MAX_STR_LEN];
    char desc[MAX_STR_LEN];
    char user[MAX_STR_LEN];
    char pw[MAX_STR_LEN];
    struct login* login_n;

}; typedef struct login login_t;


/*******************************************************************************
 * Function prototypes
*******************************************************************************/
char* user_initialisation (char mast_pw[], char db_location[]);
void print_main_menu ();
void print_find_menu ();
login_t* add_login ();
login_t modify_login (login_t mod_login);
void delete_login (login_t del_login);
void find_login(char seach[]);
void display_login (login_t disp_login, int header);
char* encrypt_line (char line[], char key[]);
char* decrypt_line (char line[], char key[]);
void compress_db (char db_location[]);
void decompres_db (char db_location[]);
void save_db (char db_location[], char master_pw[], login_t* logins_LL);
login_t* load_db (char db_location[], char master_pw[]);
int valid_input (char input[]);
void add_to_LL (login_t* logins_LL, login_t* login_add);

/*******************************************************************************
 * Main
*******************************************************************************/

int main(void)
{
    int selection, exit =0;
    char usr_input[256];

    while(exit == 0)
    {

        print_main_menu();
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%d", &selection);

        switch(selection)
        {
            case 1:

            break;
            case 2:
                printf("Please enter search paramater>");
                fgets(usr_input, 10000, stdin);
                sscanf(usr_input, "%s", usr_input);
                printf("\033[2J\033[H");
                find_login(usr_input, logins_LL);
            break;
            case 3:
            
            break;
            case 4:
                exit = 1;
            break;
            default:
            printf("Invalid choice\n");
            break;

        }
    }

}

/*******************************************************************************
 * Author: Bennett
 * This function has the user enter a database location and master password
 * inputs:
 * - master password
 * - database location
 * outputs:
 * - pointer to char array of first line of DB
*******************************************************************************/

char* user_initialisation (char mast_pw[], char db_location[])
{ 
int utpyold,utypnew;	
printf("1.Old user\n2.New user");
scanf("%d %d",&utpyold,&utypnew);
/**/
if(utpyold==1){
/* if databases for storing user data exist print these*/
	printf("1.Enter a database location");
	printf("2.Enter the master password");
    /*check if inut matches stored data*/
	scanf("%c",[]);
	scanf("%c",[]);
}
else {
	printf("Incorrect input try again!") 
	/* add option to try again, until the user selects the right option.*/;}
}
if(utypnew==2){ 
	/*take them to create a login stage*/
	;}
else {/*stay on intial menu and ask for correct input.*/;}	


/*******************************************************************************
 * Author: Daniel
 * This function prints the main menu
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void print_main_menu ()
{
	printf("1: Add password\n");
	printf("2: Search password\n");
	printf("3: Save database\n");
	printf("4: Quit\n");
    printf("Enter choice (number between 1-4)> ");
}

void print_find_menu ()
{
    printf("1: Modify Login\n");
    printf("2: Delete Login\n");
    printf("3: Back to main menu\n");
    printf("Enter choice (number between 1-3)> ");  
}

/*******************************************************************************
 * Author: Daniel
 * This function has the user enter a new login to be saved in the database
 * inputs:
 * - 
 * outputs:
 * - login structure variable
*******************************************************************************/
login_t* add_login ()
{
    login_t* add;
    char usr_input[MAX_STR_LEN];
    add = (login_t *) malloc(sizeof(login_t));
    int i = 0;

    printf("Enter name for where password will be used\n");
    while (i < MAX_TRIES)
    {
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%s", usr_input);
        if (valid_input(usr_input) == 0)
        {
            strcpy(add->name, usr_input);
            break;
        }
        else
        {
            i++;
        }
    }
    i = 0;

    printf("Enter description for password\n");
    while (i < MAX_TRIES)
    {
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%s", usr_input);
        if (valid_input(usr_input) == 0)
        {
            strcpy(add->desc, usr_input);
            break;
        }
        else
        {
            i++;
        }
    }

    printf("Enter Username\n");
    while (i < MAX_TRIES)
    {
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%s", usr_input);
        if (valid_input(usr_input) == 0)
        {
            strcpy(add->user, usr_input);
            break;
        }
        else
        {
            i++;
        }
    }

    printf("Enter password\n");
    while (i < MAX_TRIES)
    {
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%s", usr_input);
        if (valid_input(usr_input) == 0)
        {
            strcpy(add->pw, usr_input);
            break;
        }
        else
        {
            i++;
        }
    }

    add->login_n = NULL;
    return add;

}


/*******************************************************************************
 * Author: Daniel
 * This function takes a already exisiting login and allows the user to change
 * it and then saves the changed login.
 * inputs:
 * - login structure variable
 * outputs:
 * - login structure variable
*******************************************************************************/
login_t modify_login (login_t mod_login)
{

    display_login(mod_login)
    printf("5: Quit\n");

    printf("Select number to modify details\n");
    scanf("%d", &select);

    char input[100]
    int i=0;
    while(i != 0);
    {
   	 switch(select)
   	 {
   	 case 1:
   		 printf("Enter new Name\n");
   		 fgets(input, 10000, stdin);
   		 if (valid_input == 0)
   		 {
   			 strcpy(mod_login.name, input);
   		 }
   		 break;

   	 case 2:
   		 printf("Enter new Description\n");
   		 fgets(input, 10000, stdin);
   		 if (valid_input == 0)
   		 {
   			 strcpy(mod_login.desc, input);
   		 }
   		 break;

   	 case 3:
   		 printf("Enter new Username\n");
   		 fgets(input, 10000, stdin);
   		 if (valid_input == 0)
   		 {
   			 strcpy(mod_login.user, input);
   		 }
   		 break;

   	 case 4:
   		 printf("Enter new Password\n");
   		 fgets(input, 10000, stdin);
   		 if (valid_input == 0)
   		 {
   			 strcpy(mod_login.pw, input);
   		 }
   		 break;

   	 case 5:
   		 i = 1;
   		 break;
   	 }
    }
    return mod_login;
    
}


/*******************************************************************************
 * Author: Bennett
 * This function deletes a login from the main array
 * inputs:
 * - login structure variable
 * outputs:
 * - none
*******************************************************************************/
void delete_login (login_t del_login[])
{
	
}

/*******************************************************************************
 * Author: Cameron
 * This function returns any number of logins that match a search paramater
 * inputs:
 * - search parameter, pointer to logins link list
 * outputs:
 * - none
*******************************************************************************/
void find_login(char seach[], login_t* logins_LL)
{
    login_t* temp_login;
    login_t search_results[256];
    temp_login = (login_t *) malloc(sizeof(login_t));
    int selection, exit = 0, num_results = 0;
    char usr_input[256];

    strcpy(search_results[0].name, "");

    display_login(*temp_login, 1);
    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
        if(strcmp("*", seach) == 0)
        {
            display_login(*temp_login, 0);
            search_results[num_results] = *temp_login;
            num_results++;
        }
        else
        {
            if(strcmp(temp_login->name, seach) == 0)
            {
            display_login(*temp_login, 0);
            search_results[num_results] = *temp_login;
            num_results++;
            }
        }
    }

    printf("\n");

    if(num_results > 1)
    {
        while(exit == 0)
        {
            printf("Please enter the number of the login you want> ");
            fgets(usr_input, 10000, stdin);
            sscanf(usr_input, "%d", &selection);
            if(selection <= num_results && selection > 0)
            {
                printf("\033[2J\033[H");
                display_login(search_results[selection-1], 1);
                display_login(search_results[selection-1], 0);
                printf("\n");
                exit = 1;
            }
            else
            {
                printf("Invalid selection\n");
            }
        }
    }
    

    exit = 0;
    print_find_menu();
    while(exit == 0)
    {
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%d", &selection);

        switch(selection)
        {
            case 1:
            
            break;
            case 2:
            
            break;
            case 3:
                printf("\033[2J\033[H");
                exit = 1;
            break;
            default:
                printf("Invalid choice\n");
                printf("Enter choice (number between 1-3)> ");
            break;

        }


    }

    
    free(temp_login);
    temp_login = NULL;
    return;

}

/*******************************************************************************
 * Author: Daniel
 * This function displays a single login on the console
 * inputs:
 * - login structure variable
 * outputs:
 * - none
*******************************************************************************/
void display_login (login_t disp_login, int header)
{
    char name_spaces[(11) - strlen(disp_login.name)];
    char desc_spaces[(19) - strlen(disp_login.desc)];
    char user_spaces[(19) - strlen(disp_login.user)];
    char pw_spaces[(25) - strlen(disp_login.pw)];
    int ii;
    
    for(ii=0;ii<((10) - strlen(disp_login.name));ii++)
    {
        name_spaces[ii] = ' ';
    }
    name_spaces[ii] = '\0';
    
    for(ii=0;ii<((18) - strlen(disp_login.desc));ii++)
    {
        desc_spaces[ii] = ' ';
    }
    desc_spaces[ii] = '\0';
    
    for(ii=0;ii<((18) - strlen(disp_login.user));ii++)
    {
        user_spaces[ii] = ' ';
    }
    user_spaces[ii] = '\0';
    
    for(ii=0;ii<((24) - strlen(disp_login.pw));ii++)
    {
        pw_spaces[ii] = ' ';
    }
    pw_spaces[ii] = '\0';
    
    
    if(header == 1)
    {
        printf("\n");
        printf("###############################################################"
        "################\n");
        printf("# Name      # Desc              # Login             # Password"
        "                #\n");
        printf("###############################################################"
        "################\n");

    }
    else
    {
        printf("# %s", disp_login.name);
        printf("%s", name_spaces);
        printf("# %s", disp_login.desc);
        printf("%s", desc_spaces);
        printf("# %s", disp_login.user);
        printf("%s", user_spaces);
        printf("# %s", disp_login.pw);
        printf("%s", pw_spaces);
        printf("#\n");
    }
    
    return;
}


/*******************************************************************************
 * Author: Cameron
 * This function encrypts a single string
 * inputs:
 * - string, key
 * outputs:
 * - encrypted string
*******************************************************************************/
char * encrypt_line (char line[], char key[])
{
	
}

/*******************************************************************************
 * Author: Cameron
 * This function decrypts a single string
 * inputs:
 * - encrypted string, key
 * outputs:
 * - string
*******************************************************************************/
char * decrypt_line (char line[], char key[])
{
	
}

/*******************************************************************************
 * Author: Cameron
 * This function compresses the database
 * inputs:
 * - database location
 * outputs:
 * - none
*******************************************************************************/
void compress_db (char db_location[])
{
	
}

/*******************************************************************************
 * Author: Cameron
 * This function decompresses the database
 * inputs:
 * - database location
 * outputs:
 * - none
*******************************************************************************/
void decompres_db (char db_location[])
{
	
}

/*******************************************************************************
 * Author: Bennett
 * This function saves the encrpted logins array
 * inputs:
 * - database location, login array
 * outputs:
 * - none
*******************************************************************************/
void save_db (char db_location[], char master_pw[], login_t* logins_LL)
{
	
}

/*******************************************************************************
 * Author: Bennett
 * This function 
 * inputs:
 * - database location, login array
 * outputs:
 * - login array
*******************************************************************************/
login_t* load_db (char db_location[], char master_pw[])
{
	
}

/*******************************************************************************
 * Author: Daniel
 * This function checks to see if the char input only contains valid chars
 * inputs:
 * - char array
 * outputs:
 * - 1 for valid 0 for invalid
*******************************************************************************/

int valid_input (char input[])
{
    int length = strlen(input);
    int i = 0;
    int flag = 0;
    while (i < length - 1)
    {
    if (input[i] < 31 || input[i] > 127)
    {
        flag = 1;
        break;
    }
    i++;
    }
    if (flag == 1)
    {
     printf("Invalid input\n");
    }
    return flag;
}



void add_to_LL (login_t* logins_LL, login_t* login_add)
{
    login_t* temp_login;
    temp_login = (login_t *) malloc(sizeof(login_t));

    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
        if(temp_login->login_n == NULL)
        {
            temp_login->login_n = login_add;
            break;
        }

    }
    return;
}