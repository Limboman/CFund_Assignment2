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
#include <stdio.h> /* printf, fopen, fclose, fprintf, fscanf */
#include <string.h> /* strcmp,  strlen, strcpy, strcat*/
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
login_t* modify_login (login_t* logins_LL,login_t* mod_login);
login_t* delete_login (login_t* logins_LL, login_t* del_login);
login_t* find_login(char seach[], login_t* logins_LL);
void display_login (login_t del_login, int header, int order);
char* encrypt_line (char line[], char key[]);
char* decrypt_line (char line[], char key[]);
void compress_db (char db_location[]);
void decompres_db (char db_location[]);
void save_db (char db_location[], login_t* logins_LL, char key[]);
login_t* load_db (char db_location[], char key[]);
int valid_input (char input[]);
login_t* add_to_LL (login_t* logins_LL, char name[MAX_STR_LEN], 
    char desc[MAX_STR_LEN], char user[MAX_STR_LEN], char pw[MAX_STR_LEN]);

/*******************************************************************************
 * Main
 * Author: Cameron & Daniel
*******************************************************************************/

int main(int argc,char* argv[])
{
    login_t* temp_login;
    temp_login = (login_t *) malloc(sizeof(login_t));
    int quit = 0, selection, ii = 0, debug_mode = 0, j=0, database_exists =0;
    char master_key[256] = {"A"}, usr_input[256], db_location[256];
    char usr_key_input[256], confirmation[MAX_STR_LEN];
    login_t* logins_LL;
    logins_LL = (login_t *) malloc(sizeof(login_t));
    /* Here we check to see if any arguments were passed to the program from
    the command line, we only accept two arguments, -db for the database
    location and -debug to enable debug mode */
    if(argc >= 2)
    {
        for(ii=0;ii<argc;ii++)
        {
            if(strcmp(argv[ii], "-db") == 0)
            {
                strcpy(db_location, argv[ii+1]);
            }
            if(strcmp(argv[ii], "-debug") == 0)
            {
                debug_mode = 1;
            }

        }
    }

    /* Here we check to see if the database provided (if provided) exists */
    FILE* fp = NULL;
    fp = fopen(db_location, "r");
    if (fp == NULL)
    {
            printf("Database selected doesn't exist, ");
            printf("or there was no database selected\n");
    }
    else
    {
        database_exists = 1;
        fclose(fp);
    }
    
    /* if an existing database was provided this section asks the user for the
    master password of the datbase and the attempts to decrypt the first line
    if the first line decrypts to DATABASE_DECRYPTED then we know that the 
    correct password was supplied and the entire database is loaded into
    memory */
    if (database_exists == 1)
    {
        printf("The database selected is %s \n", db_location);
        

        while (j < MAX_TRIES)
        {
            printf("Please enter the master password for this database >");
            fgets(usr_key_input, MAX_STR_LEN, stdin);
            sscanf(usr_key_input, "%s", usr_key_input);

            fp = fopen(db_location, "r");

            fscanf(fp, "%s", confirmation);
            fclose(fp);

            strcpy(confirmation, decrypt_line(confirmation, usr_key_input));

            if (strcmp(confirmation, "DATABASE_DECRYPTED") == 0)
            {
                printf("Correct password\n");
                /* decrypt */
                logins_LL = load_db(db_location, usr_key_input);
                break;
            }
            else
            {
                printf("Incorrect password\n");
                j++;
            }

        }
        if (j == MAX_TRIES)
        {
            printf("Too many incorrect attempts, exiting program.\n");
            exit(0);
        }
    }
    /* If no database is provided then the user is asked for a database name
    and a password for that database, these are stored for later use when the
    user wishes to save their database */
    else
    {
        j = 0;
        while (j < MAX_TRIES)
        {
            printf("Enter new database name >");
            /* database name */
            fgets(db_location, MAX_STR_LEN, stdin);
            sscanf(db_location, "%s", db_location);
            /* create a database for given name */
            fp = fopen(db_location, "r");
            if ( fp == NULL)
            {
                /************************************/

                printf("Enter master password for database >");
                /* entered master password */
                fgets(master_key, MAX_STR_LEN, stdin);
                sscanf(master_key, "%s", master_key);
                
                break;
            }
            else
            {
                printf("File already exists in location.\n");
                j++;
            }
        }
        
    }

    /* if debug mode is enabled then it is printed for the user to see */
    if(debug_mode == 1)
    {
        printf("DEBUG MODE ON \n");
        login_t* logins_LL2;
        logins_LL2 = (login_t *) malloc(sizeof(login_t));
        login_t* logins_LL3;
        logins_LL3 = (login_t *) malloc(sizeof(login_t));
        login_t* logins_LL4;
        logins_LL4 = (login_t *) malloc(sizeof(login_t));

        strcpy(logins_LL->name, "G1");
        strcpy(logins_LL->desc, "www.google.com");
        strcpy(logins_LL->user, "cam");
        strcpy(logins_LL->pw, "1234");
        
        logins_LL->login_n = logins_LL2;
        strcpy(logins_LL2->name, "G2");
        strcpy(logins_LL2->desc, "www.google.com");
        strcpy(logins_LL2->user, "cam");
        strcpy(logins_LL2->pw, "1234");
        
        logins_LL2->login_n = logins_LL3;
        strcpy(logins_LL3->name, "G3");
        strcpy(logins_LL3->desc, "www.google.com");
        strcpy(logins_LL3->user, "MACCAM");
        strcpy(logins_LL3->pw, "4321");
        
        logins_LL3->login_n = logins_LL4;
        strcpy(logins_LL4->name, "G4");
        strcpy(logins_LL4->desc, "www.google.com");
        strcpy(logins_LL4->user, "mac");
        strcpy(logins_LL4->pw, "qwerty");

        logins_LL4->login_n = NULL;
    }

    printf("\033[2J\033[H");
    /* This is the main while loop that the program will stay in untill they
    choose to exit the program */
    while(quit == 0)
    {

        print_main_menu();
        fgets(usr_input, MAX_STR_LEN, stdin);
        sscanf(usr_input, "%d", &selection);
        /* This is the switch statement for the main menu */
        switch(selection)
        {
            case 1:
                temp_login = add_login();
                if(temp_login->login_n == NULL)
                {
                    if(strcmp(logins_LL->name, "") == 0)
                    {
                        strcpy(logins_LL->name, temp_login->name);
                        strcpy(logins_LL->desc, temp_login->desc);
                        strcpy(logins_LL->user, temp_login->user);
                        strcpy(logins_LL->pw, temp_login->pw);
                    }
                    else
                    {
                    logins_LL = add_to_LL(logins_LL, temp_login->name,
                        temp_login->desc, temp_login->user, temp_login->pw);
                    }
                    
                }
                break;
            case 2:
                if(strcmp(logins_LL->name, "") == 0)
                {
                    printf("Database is empty.\n");
                }
                else
                {
                    printf("Please enter search paramater or * for all>");
                    fgets(usr_input, MAX_STR_LEN, stdin);
                    sscanf(usr_input, "%s", usr_input);
                    printf("\033[2J\033[H");
                    logins_LL = find_login(usr_input, logins_LL);
                }
                break;
            case 3:
                save_db(db_location, logins_LL, master_key);
                break;
            case 4:
                save_db(db_location, logins_LL, master_key);
                quit = 1;
                break;
            case 5:
                quit = 1;
                break;
            default:
            printf("\033[2J\033[H");
            printf("Invalid choice\n");
            break;

        }
    }
    free(logins_LL);
    logins_LL = NULL;
    return 0;
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
    printf("1: Add password\n");
    printf("2: Search password\n");
    printf("3: Save database\n");
    printf("4: Save and Quit\n");
    printf("5: Quit\n");
    printf("Enter choice (number between 1-5)> ");
}

/*******************************************************************************
 * Author: Cameron
 * This function prints the find menu
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/

void print_find_menu ()
{
    printf("1: Modify Login\n");
    printf("2: Delete Login\n");
    printf("3: Back to main menu\n");
    printf("Enter choice (number between 1-3)> ");  
}

/*******************************************************************************
 * Author: Daniel & Cameron
 * This function has the user enter a new login to be saved in the database
 * inputs:
 * - 
 * outputs:
 * - pointer to a login structure variable
*******************************************************************************/
login_t* add_login ()
{
    login_t* add;
    char usr_input[MAX_STR_LEN];
    add = (login_t *) malloc(sizeof(login_t));
    int i = 0, too_many_tries = 0;
    /* We decided that we would limit the number of attempts a user has to
    enter correct data, the max number of tries is defined at the beginning
    of the program using MAX_TRIES */
    while(too_many_tries == 0)
    {

        printf("Enter name for where password will be used\n");
        while (i < MAX_TRIES)
        {
            fgets(usr_input, MAX_STR_LEN, stdin);
            sscanf(usr_input, "%s", usr_input);
            /* Each time the user enters some data it is checked to see if it
            is within our alowable range for ascii characters */
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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
        }
        i = 0;

        printf("Enter description for password\n");
        while (i < MAX_TRIES)
        {
            fgets(usr_input, MAX_STR_LEN, stdin);
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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
        }
        i = 0;

        printf("Enter Username\n");
        while (i < MAX_TRIES)
        {
            fgets(usr_input, MAX_STR_LEN, stdin);
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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
        }
        i = 0;

        printf("Enter password\n");
        while (i < MAX_TRIES)
        {
            fgets(usr_input, MAX_STR_LEN, stdin);
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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
        }
        break;
    }

    /* Once the user has finished entering data we clear the screen */
    printf("\033[2J\033[H");

    if(too_many_tries == 1)
    {
    	/* if too many incorrect attempts were made to enter data we set the
    	value of the "next" node equal to itself, we use this as a flag to
    	know that we don't want to add it to the linked list */
        printf("Too many incorrect entries\n");
        add->login_n = add;
    }
    else
    {
        add->login_n = NULL;
    }
    return add;
}


/*******************************************************************************
 * Author: Daniel & Cameron
 * This function takes a already exisiting login and allows the user to change
 * it and then saves the changed login.
 * inputs:
 * - login structure variable
 * outputs:
 * - login structure variable
*******************************************************************************/
login_t* modify_login (login_t* logins_LL, login_t* mod_login)
{
    int i=0, select;
    char input[100];
    
    login_t* tmp_login;
    tmp_login = (login_t *) malloc(sizeof(login_t));
    
    /* Here we allow the user to modify a part of an existing login */
    printf("\n");
    printf("What would you like to modify?\n");
    printf("1. Name\n");
    printf("2. Description\n");
    printf("3. Username\n");
    printf("4. Password\n");
    printf("5. Back\n");

    fgets(input, MAX_STR_LEN, stdin);
    sscanf(input, "%d", &select);

    /* Here we iterate through the linked list untill we find the login
    that we want to modify and then based on the user choice allow them to
    modify that value */
    for(tmp_login=logins_LL;tmp_login!=NULL; tmp_login=tmp_login->login_n)
    {
        if(mod_login->login_n == tmp_login->login_n)
        {
            while(i == 0)
            {
             switch(select)
             {
             case 1:
                 printf("Enter new Name >");
                 fgets(input, MAX_STR_LEN, stdin);
                 sscanf(input, "%s", input);
                 if (valid_input(input) == 0)
                 {
                     strcpy(tmp_login->name, input);
                     strcpy(mod_login->name, input);
                 }
                 i = 1;
                 break;

             case 2:
                 printf("Enter new Description >");
                 fgets(input, MAX_STR_LEN, stdin);
                 sscanf(input, "%s", input);
                 if (valid_input(input) == 0)
                 {
                     strcpy(tmp_login->desc, input);
                     strcpy(mod_login->desc, input);
                 }
                 i = 1;
                 break;

             case 3:
                 printf("Enter new Username >");
                 fgets(input, MAX_STR_LEN, stdin);
                 sscanf(input, "%s", input);
                 if (valid_input(input) == 0)
                 {
                     strcpy(tmp_login->user, input);
                     strcpy(mod_login->user, input);
                 }
                 i = 1;
                 break;

             case 4:
                 printf("Enter new Password >");
                 fgets(input, MAX_STR_LEN, stdin);
                 sscanf(input, "%s", input);
                 if (valid_input(input) == 0)
                 {
                     strcpy(tmp_login->pw, input);
                     strcpy(mod_login->pw, input);
                 }
                 i = 1;
                 break;

             case 5:
                 i = 1;
                 break;
             }
            }
        }
    }
    return mod_login;
}

/*******************************************************************************
 * Author: Cameron
 * This function deletes a login from the main array
 * inputs:
 * - two pointers to login_t structures
 * outputs:
 * - pointer to a login_t structure
*******************************************************************************/
login_t* delete_login (login_t* logins_LL, login_t* del_login)
{
    login_t* temp_login;
    temp_login = (login_t *) malloc(sizeof(login_t));
    login_t* prev_login;
    prev_login = (login_t *) malloc(sizeof(login_t));
    login_t* prev_login_temp;
    prev_login_temp = (login_t *) malloc(sizeof(login_t));

    strcpy(prev_login->name, "");
    strcpy(prev_login_temp->name, "");
    prev_login_temp = NULL;
    /* Here we iterate through the linked list to find the node that we want
    to remove */
    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
    	/* Here we keep track of the node previous to the one we are currently
    	examening, if its the first node then the previous node is obviously
    	the same as the currently examened node, otherwise prev_login is 
    	equal to the previous node */
        if(prev_login_temp == NULL)
        {
            prev_login = temp_login;
            prev_login_temp = temp_login;
        }
        else
        {
            prev_login = prev_login_temp;
            prev_login_temp = temp_login;
        }
        /* Here we check to see if the current login being examined is the same
        as the login we want deleted */
        if(temp_login->login_n == del_login->login_n)
        {
        	/* Here we check if the login being examined is the first login in
        	the linked list, if it is we change the first node in the linked 
        	list to the seccond node (effectivly removing the first node) */
            if(prev_login == prev_login_temp)
            {
                login_t* temp = logins_LL;
                temp = temp->login_n;
                logins_LL = temp;
                break;
            }
            /* If the current node is not the first in the linked list then
            we simply set the previous node's "next node" equal to the 
            "next node" of the node currently being examined effectly removing
            the current node */
            else
            {
                prev_login->login_n = del_login->login_n;
                break;
            }    
        }
    }
    return logins_LL;
}

/*******************************************************************************
 * Author: Cameron
 * This function returns any number of logins that match a search paramater
 * inputs:
 * - search parameter, pointer to logins link list
 * outputs:
 * - pointer to logins link list
*******************************************************************************/
login_t* find_login(char seach[], login_t* logins_LL)
{
    login_t search_results[256];
    login_t* temp_login;
    temp_login = (login_t *) malloc(sizeof(login_t));
    int selection, exit = 0, num_results = 0;
    char usr_input[256];

    strcpy(search_results[0].name, "");

    display_login(*temp_login, 1, 0);
    /* Here we itterate through the linked list looking for any logins whos
    name matches the search paramater */
    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
    	/* If the search parameter was * it will simply display all logins
    	in the linked list */
        if(strcmp("*", seach) == 0)
        {
            display_login(*temp_login, 0, num_results + 1);
            search_results[num_results] = *temp_login;
            num_results++;
        }
        else
        {
        	/* Here we check if the search parameter is equal to the name of 
        	the current node */
            if(strcmp(temp_login->name, seach) == 0)
            {
                display_login(*temp_login, 0, num_results + 1);
                search_results[num_results] = *temp_login;
                num_results++;
            }
        }
    }

    printf("\n");

    /* If the search returned more than 1 result we ask the user to select a
    single login that they want to view/edit/delete */
    if(num_results > 1)
    {
        while(exit == 0)
        {
            printf("Please enter the number of the login you want> ");
            fgets(usr_input, MAX_STR_LEN, stdin);
            sscanf(usr_input, "%d", &selection);
            if(selection <= num_results && selection > 0)
            {
            	/* Here we display the login selected by the user */
                printf("\033[2J\033[H");
                display_login(search_results[selection-1], 1, 0);
                display_login(search_results[selection-1], 0, 1);
                temp_login = &search_results[selection-1];
                printf("\n");
                exit = 1;
            }
            else
            {
                printf("Invalid selection\n");
            }
        }
    }
    else
    {
        temp_login = &search_results[0];
    }
    
    /* Once the search has been reduced down to a single login we display 
    the find menu and give the user a choice of what they want to do next */
    exit = 0;
    print_find_menu();
    while(exit == 0)
    {
        fgets(usr_input, MAX_STR_LEN, stdin);
        sscanf(usr_input, "%d", &selection);

        switch(selection)
        {
            case 1:
            	/* Here the user user elects to modify the login and the
            	modify login function is called */
                printf("\033[2J\033[H");
                display_login(*temp_login, 1, 0);
                display_login(*temp_login, 0, 1);
                temp_login = modify_login(logins_LL, temp_login);
                printf("\033[2J\033[H");
                display_login(*temp_login, 1, 0);
                display_login(*temp_login, 0, 1);
                printf("\n");
                print_find_menu();
                break;
            case 2:
            	/* Here the user elects to delete the current login, they are
            	asked for a confirmation and if they confirm then the delete
            	login function is called */
                printf("Are you sure you want to delete this login? (y/n)>");
                fgets(usr_input, 10000, stdin);
                sscanf(usr_input, "%s", usr_input);
                if(strcmp("y", usr_input) == 0)
                {
                    logins_LL = delete_login(logins_LL, temp_login);
                    printf("\033[2J\033[H");
                    printf("Login Deleted \n");
                    exit = 1;
                }
                else
                {
                    printf("Enter choice (number between 1-3)> ");
                }
                break;
            case 3:
                exit = 1;
                printf("\033[2J\033[H");
                break;
            default:
                printf("Invalid choice\n");
                
                break;
        }
    }
    return logins_LL;
}

/*******************************************************************************
 * Author: Cameron & Daniel
 * This function displays a single login on the console
 * inputs:
 * - login structure variable, boolen header variable, int order variable
 * outputs:
 * - none
*******************************************************************************/
void display_login (login_t disp_login, int header, int order)
{
	/* This function displays either a single login or the login header
	depening on if the header variable that is passed to this function is a 0
	or a 1 */
                    
    if(header == 1)
    {
        printf("\n");
        printf("###############################################################"
        "#################\n");
        printf("#    Name      # Desc              # Username        # Password"
        "                #\n");
        printf("###############################################################"
        "#################\n");

    }
    else
    {
        printf("# %2d.", order);
        printf("%-10.9s", disp_login.name);
        printf("# %-18.17s", disp_login.desc);
        printf("# %-16.15s", disp_login.user);
        printf("# %-24.23s", disp_login.pw);
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
char* encrypt_line (char line[], char key[])
{
    char* encrypted_line;
    encrypted_line = (char *) malloc(sizeof(char[MAX_STR_LEN+1]));
    
    int encrypt_key=0;
    int ii;
    
    /* Here we generate a numerical encryption key by simply adding the ascii
    values of each character in the provided key together */
    for(ii=0;key[ii]!='\0';ii++)
    {
        encrypt_key = (int)key[ii] + encrypt_key;
    }
    /* Here we encrypt the string that is passed to the function using the key
    that we just generated,  we used a simple ceasar cipher and simply add the 
    key to each character*/
    for(ii=0;line[ii]!='\0';ii++)
    {
        encrypted_line[ii] = line[ii] + encrypt_key;
    }

    encrypted_line[MAX_STR_LEN+1] = '\0';

    return encrypted_line;
    
}

/*******************************************************************************
 * Author: Cameron
 * This function decrypts a single string
 * inputs:
 * - encrypted string, key
 * outputs:
 * - string
*******************************************************************************/
char* decrypt_line (char line[], char key[])
{
    char* decrypted_line;
    decrypted_line = (char *) malloc(sizeof(char[MAX_STR_LEN+1]));

    int encrypt_key=0;
    int ii;
    /* Here we generate a numerical encryption key by simply adding the ascii
    values of each character in the provided key together */
    for(ii=0;key[ii] != '\0';ii++)
    {
        encrypt_key = (int)key[ii] + encrypt_key;
    }
    /* Here we decrypt the string that is passed to the function using the key
    that we just generated,  we used a simple ceasar cipher and simply subtract
    the key from each character*/
    for(ii=0;line[ii] != '\0';ii++)
    {
        decrypted_line[ii] = line[ii] - encrypt_key;
    }

    decrypted_line[MAX_STR_LEN+1] = '\0';

    return decrypted_line;
    
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
 * Author: Cameron
 * This function saves the encrpted logins array
 * inputs:
 * - database location, login array
 * outputs:
 * - none
*******************************************************************************/
void save_db (char db_location[], login_t* logins_LL, char key[])
{
    char combined[MAX_STR_LEN*4];
    FILE *fp;
    fp = fopen(db_location, "w+");
    login_t* temp_login;
    temp_login = (login_t *) malloc(sizeof(login_t));
    /* Here we save the encrypted linked list to a file */
    /* First we encrypt and save the text DATABASE_DECRYPTED to the file,
    we do this so that when attempting to open a file the first line should
    always be DATABASE_DECRYPTED and if it is we know that the decryption
    was sucsessfull*/
    fprintf(fp, "%s\n", encrypt_line("DATABASE_DECRYPTED", key));
    /* Here we concatanate all the strings from a single linked list node
    into a single string seperated by commas with the word LOGIN at the start
    we then encrypt the combined line and write it to the file */
    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
        strcpy(combined, "LOGIN");
        strcat(combined, ",");
        strcat(combined, temp_login->name);
        strcat(combined, ",");
        strcat(combined, temp_login->desc);
        strcat(combined, ",");
        strcat(combined, temp_login->user);
        strcat(combined, ",");
        strcat(combined, temp_login->pw);

        strcpy(combined, encrypt_line(combined, key));

        fprintf(fp,"%s\n", combined);

    }

    fclose(fp);

    return;
}

/*******************************************************************************
 * Author: Cameron
 * This function 
 * inputs:
 * - database location, login array
 * outputs:
 * - login array
*******************************************************************************/
login_t* load_db (char db_location[], char key[])
{
    char combined[MAX_STR_LEN*4], confirmation[MAX_STR_LEN];
    char * token;
    FILE *fp;
    fp = fopen(db_location, "r");
    login_t* logins_LL;
    logins_LL = (login_t *) malloc(sizeof(login_t));
    int end_of_file =0, ii=0, first_login=0;

    fscanf(fp, "%s", confirmation);
    /* Here we read and decrypt a database of logins and add them to a new 
    linked list */
    while (end_of_file != EOF)
    {
        end_of_file = fscanf(fp, "%s", combined);
        strcpy(combined, decrypt_line(combined, key));
        token = strtok (combined,",");
        /* using strtok to split the decrypted string we first check that the
        line that was decrypted was a login */
        if(strcmp(token, "LOGIN") == 0)
        {
            ii=0;
            login_t* new_login;
            new_login = (login_t *) malloc(sizeof(login_t));
            /* now going token by token we split the string up into its
            individual parts and assign them to the new node */
            while (token != NULL)
            {
                switch(ii)
                {
                    case 1:
                        if(first_login == 0)
                        {
                            strcpy(logins_LL->name, token);
                        }
                        else
                        {
                            strcpy(new_login->name, token);
                        }
                        break;
                    case 2:
                        if(first_login == 0)
                        {
                            strcpy(logins_LL->desc, token);
                        }
                        else
                        {
                            strcpy(new_login->desc, token);
                        }
                        break;
                    case 3:
                        if(first_login == 0)
                        {
                            strcpy(logins_LL->user, token);
                        }
                        else
                        {
                            strcpy(new_login->user, token);
                        }
                        break;
                    case 4:
                        if(first_login == 0)
                        {
                            strcpy(logins_LL->pw, token);
                        }
                        else
                        {
                            strcpy(new_login->pw, token);
                        }
                        break;
                    default:
                        break;
                }
                /* Here we itterate to the next token created by strtok */
                token = strtok (NULL, ",");
                ii++;
            }
            /* Here we check to see if the current node is the first one to be
            added, if it is we don't need to call the add to link list function
            and simply flag that the first node has been filled*/
            if(first_login == 0)
            {
                logins_LL->login_n = NULL;
                first_login = 1;
                free(new_login);
            }
            /* Here we add the newly decrypted login to the linked list by
            calling the add to link list function */
            else
            {
                new_login->login_n = NULL;
                logins_LL = add_to_LL(logins_LL, new_login->name, 
                    new_login->desc, new_login->user, new_login->pw);
                free(new_login);
            }

        }
        
    }

    fclose(fp);
    return logins_LL;
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
    /* Here we iterate through the string making sure each char is between the
    ascii values of 32 and 126 */
    while (i <= length - 1)
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

/*******************************************************************************
 * Author: Cameron
 * This function adds a new login to the linklist
 * inputs:
 * - the main linklist and the name, desc, user and pw of a new login
 * outputs:
 * - the pointer to the first node of the main linklist
*******************************************************************************/

login_t* add_to_LL (login_t* logins_LL, char name[MAX_STR_LEN], 
    char desc[MAX_STR_LEN], char user[MAX_STR_LEN], char pw[MAX_STR_LEN])
{
    login_t* temp_login;
    temp_login = (login_t *) malloc(sizeof(login_t));
    login_t* login_add;
    login_add = (login_t *) malloc(sizeof(login_t));
    
    strcpy(login_add->name, name);
    strcpy(login_add->desc, desc);
    strcpy(login_add->user, user);
    strcpy(login_add->pw, pw);
    login_add->login_n = NULL;
    /* This function simply iterates through the main linked list to find the 
    last node and then appends the new node onto the end */
    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
        if(temp_login->login_n == NULL)
        {
            temp_login->login_n = login_add;
            break;
        }

    }
    return logins_LL;
}