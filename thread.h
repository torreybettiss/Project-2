/* version 1.2
 * @File:   thread.h
 * @authors Ashley Miller / Torrey Bettis
 * @date 9/25/2016
 * @info Course COP4634 Project 2
 */

#ifndef THREAD_H
#define THREAD_H



/*
 This function will create argv[2] number of threads,
 *and will call the collatz function and pass it argv[1]
 *as a parameter.  Attributes are set to NULL.  
 *@parameter is array of integers argv
 *@returns: nothing
 */
void threadCreate(char**, long);




#endif /* THREAD_H */

