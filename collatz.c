/* 
 * @File:   collatz.c
 * @authors Ashley Miller / Torrey Bettis
 * @date 9/25/2016
 * @info Course COP4634 Project 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "collatz.h"

void checkArguments(char ** argv)
{
    int i = 1;
    
    while(i < 2)
    {
        //If int check fails notify user exit program
        if(isIntCheck(argv[i]) == 0)
        {
            printf("Argument [%i] is not an integer.\n", i);
            printf("*******PROGRAM**TERMINATED*******\n");
            exit(0);
        }
        
        i++;
    }
}

int isIntCheck(char * argv)
{
    int i = 0;
    char temp[50];
    
    //Check if any argument was passed
    if(argv == NULL)
    {
        return 0;
    }    
    strcpy(temp, argv);
    
    //Checks each char if is int (returns 1), else returns 0
    while(i < strlen(temp))
    {
        if(isdigit(temp[i])== 0)
        {
            return 0;
        }
        
        i++;
    }
    
    return 1;
}

void initializeHistogram(long * histogram)
{
    int i =0;
    
    //Setting each value in the array to 0
    while(i < SIZE)
    {
        histogram[i] = 0;
        i++;
    }
}

void * collatz(void * num)
{
    long stoppingTime = 0;
    long  maxRange = *(long*)num;
    long  n = 0;
    counter = 2;   
    
 
    while(counter <= maxRange)
    {   
        stoppingTime = 0;
	n = counter;
        counter++;
               
        while(1)
        {
           //Stopping condition
           if(n == 1)
           {
               incrementHistogram(stoppingTime, histogram);
	       break;
           }
           else if(n % 2 == 0) //If n is even test
           {
               n = n/2;
               stoppingTime++;
           }
           else //Else number is assumed odd
           {
               n = 3 * n + 1;
               stoppingTime++;
           }
       }
    }
    return (void*)NULL; 
}

void incrementHistogram(long index, long * histogram)
{
    //Incrementing value at index by 1
    histogram[index]++;
}

void printHistogram(long * histogram)
{
   int i = 0;

   while(i < SIZE)
   {
      printf("%i, <%ld>\n", i + 1, histogram[i]);
      i++;
   }
}



