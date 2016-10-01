/* version 1.2
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

