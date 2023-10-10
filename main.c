/**
 * @file main.c
 * @author Zackary Morrow
 * @brief The purpose of this assignment is to write a function that will parse a 
 *        string into tokens (or words), similar to what the shell is required to do.
 * @version 0.1
 * @date 2023-09-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

int main() 
{
    char str[256];

    printf("Please, enter the string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline from user input
    size_t str_len = strlen(str);
    if (str_len > 0 && str[str_len - 1] == '\n') 
    {
        str[str_len - 1] = '\0';
    }

    // Allocate memory for an array of pointers to store tokens
    char** arrayOfTokens = (char**)malloc(sizeof(char*) * 100);
    if (arrayOfTokens == NULL) 
    {
        perror("Memory allocation error");
        return 1;
    }

    int tokenCount = getTokens(str, &arrayOfTokens);
    arrayOfTokens[tokenCount+1] = NULL; 
    
    for (int i = 0; i < tokenCount; i++) 
    {
        printf("Token %d: %s\n", i+1, arrayOfTokens[i]);
        free(arrayOfTokens[i]);
    }
    if(arrayOfTokens[tokenCount+1]==NULL)
        printf("Token %d: (null)\n", tokenCount+1);

    free(arrayOfTokens);

    return 0;
}
