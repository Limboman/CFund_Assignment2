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
login_t* find_login(char seach[], login_t* logins_LL);
void display_login (login_t del_login, int header, int order);
void print_main_menu ();
int valid_input (char input[]);
login_t* add_login ();
login_t* delete_login (login_t* logins_LL, login_t* del_login);
void add_to_LL (login_t* logins_LL, login_t* login_add);
void print_find_menu ();
login_t* modify_login (login_t* logins_LL,login_t* mod_login);

/*******************************************************************************
 * Main
*******************************************************************************/

int main(void)
{
    login_t* temp_login;
    temp_login = (login_t *) malloc(sizeof(login_t));
    int exit = 0;
    int selection;
    char usr_input[256];

    login_t* logins_LL;
    logins_LL = (login_t *) malloc(sizeof(login_t));
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

    printf("\033[2J\033[H");

    while(exit == 0)
    {

        print_main_menu();
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%d", &selection);

        switch(selection)
        {
            case 1:
                temp_login = add_login();
                if(temp_login->login_n == NULL)
                {
                    add_to_LL(logins_LL, temp_login);
                }
            break;
            case 2:
                printf("Please enter search paramater or * for all>");
                fgets(usr_input, 10000, stdin);
                sscanf(usr_input, "%s", usr_input);
                printf("\033[2J\033[H");
                logins_LL = find_login(usr_input, logins_LL);
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

    free(logins_LL);
    logins_LL = NULL;
    return 0;
}


/*******************************************************************************
 * Author: Cameron
 * This function returns any number of logins that match a search paramater
 * inputs:
 * - search parameter
 * outputs:
 * - none
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
    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
        
        
        if(strcmp("*", seach) == 0)
        {
            display_login(*temp_login, 0, num_results + 1);
            search_results[num_results] = *temp_login;
            num_results++;
        }
        else
        {
            if(strcmp(temp_login->name, seach) == 0)
            {
                display_login(*temp_login, 0, num_results + 1);
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
    

    exit = 0;
    print_find_menu();
    while(exit == 0)
    {
        fgets(usr_input, 10000, stdin);
        sscanf(usr_input, "%d", &selection);

        switch(selection)
        {
            case 1:
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

    for(temp_login=logins_LL;temp_login!=NULL; temp_login=temp_login->login_n)
    {
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

        if(temp_login->login_n == del_login->login_n)
        {
            if(prev_login == prev_login_temp)
            {

                login_t* temp = logins_LL;
                temp = temp->login_n;
                logins_LL = temp;
                break;
            }
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
 * Author: Daniel
 * This function displays a single login on the console
 * inputs:
 * - login structure variable
 * outputs:
 * - none
*******************************************************************************/
void display_login (login_t disp_login, int header, int order)
{
    char name_spaces[(11) - strlen(disp_login.name)];
    char desc_spaces[(19) - strlen(disp_login.desc)];
    char user_spaces[(17) - strlen(disp_login.user)];
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
    
    for(ii=0;ii<((16) - strlen(disp_login.user));ii++)
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
        printf("#   Name      # Desc              # Username        # Password"
        "                #\n");
        printf("###############################################################"
        "################\n");

    }
    else
    {
        printf("# %d.", order);
        printf("%s", disp_login.name);
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


login_t* add_login ()
{
    login_t* add;
    char usr_input[MAX_STR_LEN];
    add = (login_t *) malloc(sizeof(login_t));
    int i = 0, too_many_tries = 0;

    while(too_many_tries == 0)
    {

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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
        }
        i = 0;

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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
        }
        i = 0;

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
        if(i >= MAX_TRIES)
        {
            too_many_tries = 1;
            break;
        }
        break;

    }

    printf("\033[2J\033[H");

    if(too_many_tries == 1)
    {
        printf("Too many incorrect entries\n");
        add->login_n = add;
    }
    else
    {
        add->login_n = NULL;
    }

    return add;

}

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


login_t* modify_login (login_t* logins_LL, login_t* mod_login)
{
    int i=0, select;
    char input[100];
    
    login_t* tmp_login;
    tmp_login = (login_t *) malloc(sizeof(login_t));
    
    
    printf("\n");
    printf("What would you like to modify?\n");
    printf("1. Name\n");
    printf("2. Description\n");
    printf("3. Username\n");
    printf("4. Password\n");
    printf("5. Back\n");
    fgets(input, 10000, stdin);
    sscanf(input, "%d", &select);

    

    for(tmp_login=logins_LL;tmp_login!=NULL; tmp_login=tmp_login->login_n)
    {
        if(mod_login->login_n == tmp_login->login_n)
        {
            while(i == 0)
            {
             switch(select)
             {
             case 1:
                 printf("Enter new Name\n");
                 fgets(input, 10000, stdin);
                 sscanf(input, "%s", input);
                 if (valid_input(input) == 0)
                 {
                     strcpy(tmp_login->name, input);
                     strcpy(mod_login->name, input);
                 }
                 i = 1;
                 break;

             case 2:
                 printf("Enter new Description\n");
                 fgets(input, 10000, stdin);
                 sscanf(input, "%s", input);
                 if (valid_input(input) == 0)
                 {
                     strcpy(tmp_login->desc, input);
                     strcpy(mod_login->desc, input);
                 }
                 i = 1;
                 break;

             case 3:
                 printf("Enter new Username\n");
                 fgets(input, 10000, stdin);
                 sscanf(input, "%s", input);
                 if (valid_input(input) == 0)
                 {
                     strcpy(tmp_login->user, input);
                     strcpy(mod_login->user, input);
                 }
                 i = 1;
                 break;

             case 4:
                 printf("Enter new Password\n");
                 fgets(input, 10000, stdin);
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