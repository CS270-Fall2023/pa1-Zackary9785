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

int getTokens(char *s, char **args[])
{
    int numberOfTokens = 0;
    char test[100];
    (*args) = malloc(sizeof(char*)*100);
    //strncpy((*args)[numberoftokens-1], s+stringstart, stringend-stringstart) //copy current token
    int lenOfSubString;
    int j=0;
    int stringStart = 0;
    int stringEnd = 0;
    
    for(int i=0; i<strlen(s)+1; i++)
    {
        if(s[i]!=' ')
        {
            j++;
            stringEnd++;
            //printf("%d\n stringEnd is: ", stringEnd);
        }
        else
        {
            stringEnd = 0;
            stringStart++;
        }
            
        
        //printf("%s\n", str+i);
        if((s[i] == ' ' && s[i+1] != ' ') || s[i] == '\0')
        {
            // if(s[i] == ' ')
            // {
            //     stringStart++;
            // }
            if(s[i]=='\0')
                j--;
            lenOfSubString = j;
            //printf("%s\n", s+stringStart);
            //strncpy(test, s+stringStart, lenOfSubString);
            (*args)[0]=malloc(sizeof(char)*lenOfSubString+1);
            strncpy(*args[0], s, lenOfSubString);
            printf("Length of substring is: %i\n", lenOfSubString);
            printf("found space or null\n");
            //copy length lenOfSubString substring of str into array
            j=0;
            numberOfTokens++;
            //printf("%s", test[0]);
        }    
    }
    return numberOfTokens;
}