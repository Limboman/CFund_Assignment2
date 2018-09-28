#include <stdio.h> /* printf, scanf, fopen, fclose, fprintf, fscanf */
#include <string.h> /* strcmp,  strlen*/
#include <stdlib.h>

struct login
{
    char name[200];
    char desc[200];
    char user[200];
    char pw[200];
    struct login* login_n;

}; typedef struct login login_t;



/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void display_login (login_t del_login, int header);

/*******************************************************************************
 * Main
*******************************************************************************/

int main(void)
{
    login_t* logins_LL;
    logins_LL = (login_t *) malloc(sizeof(login_t));
    login_t* logins_LL2;
    logins_LL2 = (login_t *) malloc(sizeof(login_t));
    login_t* logins_LL3;
    logins_LL3 = (login_t *) malloc(sizeof(login_t));
    login_t* logins_LL4;
    logins_LL4 = (login_t *) malloc(sizeof(login_t));
    int exit = 0;

    strcpy(logins_LL->name, "Google");
    strcpy(logins_LL->desc, "www.google.com");
    strcpy(logins_LL->user, "cam");
    strcpy(logins_LL->pw, "1234");
    
    logins_LL->login_n = logins_LL2;
    strcpy(logins_LL2->name, "Apple");
    strcpy(logins_LL2->desc, "www.google.com");
    strcpy(logins_LL2->user, "cam");
    strcpy(logins_LL2->pw, "1234");
    
    logins_LL2->login_n = logins_LL3;
    strcpy(logins_LL3->name, "Apple");
    strcpy(logins_LL3->desc, "www.google.com");
    strcpy(logins_LL3->user, "mac");
    strcpy(logins_LL3->pw, "4321");
    
    logins_LL3->login_n = logins_LL4;
    strcpy(logins_LL4->name, "Google");
    strcpy(logins_LL4->desc, "www.google.com");
    strcpy(logins_LL4->user, "mac");
    strcpy(logins_LL4->pw, "4321");

    logins_LL4->login_n = NULL;



    while(exit == 0)
    {
        exit = 1;
    }

    free(logins_LL);
    logins_LL = NULL;
    return 0;
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
