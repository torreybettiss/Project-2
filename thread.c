/* 
 * @File:   thread.c
 * @authors Ashley Miller / Torrey Bettis
 * @date 9/25/2016
 * @info Course COP4634 Project 2
 */

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "thread.h"
#include "collatz.h"



void threadCreate(char** argv, long counter)
{
    struct timespec start, stop;
    int i,j;
    float totalTime = 0;
    char buffer[50];
    long maxRange;
    void * param;
    long tArray;
   
    //copying the character value for the max range to buffer
    strcpy(buffer, argv[1]);
    
    //converting the string value to a long
    maxRange = strtol(buffer, NULL, 10);
    param = (void*)(long)maxRange;

    //copying the thread count character value to buffer
    strcpy(buffer, argv[2]);

    //converting the string value to a long
    tArray = strtol(buffer, NULL, 10);

    //declaring the array for the thread with the tArray size
    pthread_t thread[tArray];

    //getting the start time for the clock
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start);

    for(i=0; i<tArray; i++)
    {
       //creating the thread to be ran
       pthread_create(&thread[i], NULL, &collatz,&param);
       
       //getting the time the thread finished running the collatz functiion
       clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&stop);

       //The total time the thread ran the collatz function
       totalTime= ((stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec));
    }
    
    for(j=0; j<tArray; j++)
    {
        //suspends execution of the calling thread until the target thread terminates
        pthread_join(thread[j],NULL);
        
    }
    
    totalTime/=1000000;
    
    printHistogram(histogram);    
    fprintf(stderr,"%ld, %ld, %.9f\n",maxRange, tArray,totalTime);
    

    pthread_exit(NULL);
}

