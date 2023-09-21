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
    char **arrayOfTokens, str[256] = "ls -l file";
    //strncat(*arrayOfTokens[1], str, 2);
    //printf("%s\n", &arrayOfTokens);
    //printf("%s\n", arrayOfTokens);
    ////printf("%s\n", str);
    printf("Please enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("The length of the string is: %d\n", (int)strlen(str));
    //strncpy(*arrayOfTokens, str, 2);
    // int lenOfSubString;
    // int j=0;
    int numberOfTokens = 0;
    // for(int i=0; i<strlen(str)+1; i++)
    // {
    //     if(str[i]!=' ')
    //         j++;
        
    //     //printf("%s\n", str+i);
    //     if((str[i] == ' ' && str[i+1] != ' ') || str[i] == '\0')
    //     {
    //         if(str[i]=='\0')
    //             j--;
    //         lenOfSubString = j;
    //         printf("Length of substring is: %i\n", lenOfSubString);
    //         printf("found space or null\n");
    //         //copy length lenOfSubString substring of str into array
    //         j=0;
    //         numberOfTokens++;
    //     }    
    // }
    numberOfTokens = getTokens(str, &arrayOfTokens);    //we pass the empty array so that we can fill it
    printf("The number of tokens is %d\n", numberOfTokens);
    printf("Value of array is %s\n", arrayOfTokens[0]);

    // char * test = "hello everyone";
    // char * duplicate;
    // duplicate = "small";
    // strncpy(&duplicate, &test, 5);   //why is this copying the whole string rather than 5 characters or hello
    // printf("%s\n", duplicate);
    //strcat();

    return 0;
}