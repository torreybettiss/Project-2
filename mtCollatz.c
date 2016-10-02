/* 
 * This program takes the number of threads to create
 * amd the max range value and computes the collatz
 * sequence. the amount of time it takes the threads to 
 * run the collatz function is calculated.
 *
 * @authors Ashley Miller / Torrey Bettis
 * @date 9/25/2016
 * @info Course COP4634 Project 2
 */


#include <stdio.h>
#include <stdlib.h>
#include "collatz.h"
#include "thread.h"





/*
 * 
 */
int main(int argc, char** argv)
{
    checkArguments(argv);
    initializeHistogram(histogram);
    threadCreate(argv, counter);
    return (EXIT_SUCCESS);
}

