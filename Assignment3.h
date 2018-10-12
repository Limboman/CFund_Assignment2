/*******************************************************************************
 * Preprocessing directives
*******************************************************************************/

#define MAX_STR_LEN 60

/*******************************************************************************
 * Author: Cameron
 * This function encrypts a single string
 * inputs:
 * - string, key
 * outputs:
 * - encrypted string
*******************************************************************************/
char* encrypt_line (char line[], char key[], int debug_mode)
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
char* decrypt_line (char line[], char key[], int debug_mode)
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
 * Author: Daniel
 * This function checks to see if the char input only contains valid chars
 * inputs:
 * - char array
 * outputs:
 * - 1 for valid 0 for invalid
*******************************************************************************/

int valid_input (char input[], int debug_mode)
{
    int length = strlen(input);
    int i = 0;
    int flag = 0;
    /* Here we iterate through the string making sure each char is between the
    ascii values of 32 and 126 */
    for(i=0;i<=length-1;i++)
    {
        if (input[i] < 31 || input[i] > 127)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Invalid input\n");
        if(debug_mode == 1)
        {
            printf("DEBUG\nUser Entered ASCII: %d\n", (int)input[i]);
        }
    }
    return flag;
}