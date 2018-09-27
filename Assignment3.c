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
 * List structs
*******************************************************************************/
struct login
{
    char name[];
    char desc[];
    char login[];
    char pw[];
    
}; typedef struct login login_t;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
char ** user_initialisation (char mast_pw[], char db_location[]);
void print_main_menu ();
login_t add_login ();
login_t modify_login (login_t mod_login);
void delete_login (login_t del_login);
void find_login(char seach[]);
void display_login (login_t del_login);
char ** encrypt_line (char line[], char key[]);
char ** decrypt_line (char line[], char key[]);
void compress_db (char db_location[]);
void decompres_db (char db_location[]);
void save_db (char db_location[], login_t del_login[]);
login_t load_db (char db_location[], login_t del_login[]);

/*******************************************************************************
 * Author: Bennett
 * This function has the user enter a database location and master password
 * inputs:
 * - master password
 * - database location
 hello
 * outputs:
 * - pointer to char array of first line of DB
*******************************************************************************/

char * user_initialisation (char mast_pw[], char db_location[])
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

}

/*******************************************************************************
 * Author: Daniel
 * This function has the user enter a new login to be saved in the database
 * inputs:
 * - 
 * outputs:
 * - login structure variable
*******************************************************************************/
login_t add_login ()
{
	
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
login_t modify_login (login_t mod_login[])
{
	
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
 * - search parameter
 * outputs:
 * - none
*******************************************************************************/
void find_login(char seach[])
{
	
}

/*******************************************************************************
 * Author: Daniel
 * This function displays a single login on the console
 * inputs:
 * - login structure variable
 * outputs:
 * - none
*******************************************************************************/
void display_login (login_t del_login[])
{
	
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
void save_db (char db_location[], login_t del_login[])
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
login_t load_db (char db_location[], login_t del_login[])
{
	
}
