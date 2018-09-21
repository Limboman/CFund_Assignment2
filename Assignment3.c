/*******************************************************************************
 * Function prototypes
*******************************************************************************/
char * user_initialisation (char mast_pw[], char db_location[]);
void print_main_menu ();
login_t add_login ();
login_t modify_login (login_t mod_login);
void delete_login (login_t del_login);
void find_login(char seach[]);
void display_login (login_t del_login);
void encrypt_line ();
void decrypt_line ();
void compress_db ();
void decompres_db ():
void save_db ();
void load_db ();

/*******************************************************************************
 * Author: Bennett
 * This function has the user enter a database location and master password
 * inputs:
 * - master password
 * - database location
 * outputs:
 * - pointer to char array of first line of DB
*******************************************************************************/

char * user_initialisation (char mast_pw[], char db_location[])
{

}

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
login_t modify_login (login_t mod_login)
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
void delete_login (login_t del_login)
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
void display_login (login_t del_login)
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
void encrypt_line ()
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
void decrypt_line ()
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
void compress_db ()
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
void decompres_db ()
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
void save_db ()
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
void load_db ()
{
	
}
