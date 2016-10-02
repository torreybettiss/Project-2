/* 
 * @File:   collatz.h
 * @authors Ashley Miller / Torrey Bettis
 * @date 9/25/2016
 * @info Course COP4634 Project 2
 */

#ifndef COLLATZ_H
#define COLLATZ_H
#define SIZE 1000
long histogram[SIZE];
long counter;

/*
 * Checks that the arguments passed from the command line
 * are correct.Argv[1] should be an integer describing
 * the range for which the Collatz sequence must be 
 * computed and Argv[2] should be an integer describing
 * the total number of threads to be created.If the tests
 * fail the user will be prompted the error and the program
 * will terminate.
 * @param: the argument value array from the command line
 * @returns: nothing
 */
void checkArguments(char **);

/*
 * Checks a string to make sure the input recieved from
 * the command line is an integer by evaluating each
 * character.
 * @param: pointer to the string
 * @returns: 1 if is an integer, 0 if not 
 */
int isIntCheck(char *);

/*
 * Initializes the global histogram array values to 0.
 * @param: pointer to the histogram array
 * @returns: nothing
 */
void initializeHistogram(long *);

/*
 * Computes the Collatz sequence for a number
 * @param: long of the number to be compute, pointer to the histogram
 * @returns: nothing
 */
void * collatz(void *);

/*
 * Increments the value at the given index by 1.
 * @param: long index value
 * @returns: nothing
 */
void incrementHistogram(long, long*);

/*
 * Prints the values in the histogram array
 * to stderr
 * @param: histogram
 * @returns: nothing
*/
void printHistogram(long *);

#endif /* COLLATZ_H */

