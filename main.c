/**
 * @file main.c
 * @author Zackary Morrow
 * @brief write a program that accepts a string and tells the user the number of tokens in it
 * @version 0.1
 * @date 2023-09-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "token.h"
#include <string.h>

int main()
{
    char **arrayOfTokens, str[] = "ls -l file";
    printf("%s\n", str);
    //printf("Please enter a string: ");
    printf("The length of the string is: %d\n", strlen(str));
    //strncpy((*arrayOfTokens), str, 2);
    int lenOfSubString;
    int j=0;
    for(int i=0; i<strlen(str)+1; i++)
    {
        j++;
        //printf("%s\n", str+i);
        if(str[i] == ' ' || str[i] == '\0')
        {
            lenOfSubString = j-1;
            printf("Length of substring is: %i\n", lenOfSubString);
            printf("found space or null\n");
            //copy length lenOfSubString substring of str into array
            j=0;
        }    
    }
    //int numberOfTokens;
    //numberOfTokens = getTokens(str, &arrayOfTokens);

    return 0;
}