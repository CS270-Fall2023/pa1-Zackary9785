/**
 * @file token.c
 * @author Zackary Morrow
 * @brief implementation file
 * @version 0.1
 * @date 2023-09-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "token.h"

#define MAX_TOKENS 100

/**
 * @brief split the string into tokens and add them to an array
 * 
 * @param s is the string to be tokenized
 * @param args is the array that will hold the tokens
 * @return the number of tokens
 */
int getTokens(char* s, char**args[]) 
{
    int tokenCount = 0;
    char* copy = strdup(s); // Create a copy of the input string so we don't change the original

    if (copy == NULL) 
    {
        perror("Memory allocation error");
        return -1; // Error
    }

    char* token_start = copy;
    char* token_end = strstr(token_start, " "); //says end of token is the space after characters

    while (token_start != NULL) 
    {
        if (tokenCount >= MAX_TOKENS) 
        {
            // Error, more tokens than space allocated
            return -1;
        }

        if (token_end != NULL) 
        {
            *token_end = '\0'; // Null terminate the token
            if (strlen(token_start) > 0) 
            {
                (*args)[tokenCount] = strdup(token_start);
                tokenCount++;
            }

            token_start = token_end + strlen(" "); // Move to the next token
            while (*token_start == ' ') 
            {
                token_start++; // Skip additional spaces
            }
            token_end = strstr(token_start, " ");   //searching for " " substring to end the token
        } 
        else 
        {
            // Last token or no more tokens
            if (strlen(token_start) > 0) 
            {
                (*args)[tokenCount] = strdup(token_start);

                if ((*args)[tokenCount] == NULL) 
                {
                    perror("Memory allocation error");
                    return -1; // Error: Unable to allocate memory for the last token
                }

                tokenCount++;
            }

            break;
        }
    }

    free(copy); // Free the copy of the input string
    //printf("Number of tokens: %d\n", tokenCount);
    return tokenCount;
}