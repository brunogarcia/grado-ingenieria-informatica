#ifndef _HELPERS_H_
#define _HELPERS_H_


/*
 * 
 * IMPORTANT NOTE: ¡¡¡¡Do not add new methods in this file!!!!
 *
 */
 
#include <stdio.h>
#include "operations.h"

typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
} tDateTime;

// Used to clear the output screen
void helpers_clearScreen();

// reads a key input from the user.
char helpers_getOption();

// waits until user presses any key
void helpers_pressAnyKey();

// Parses and gets an string manually introduced by the user until it presses the Enter.
void helpers_scanText(char * property, int maxValue);

// Parses and gets an integer value manually introduced by the user.
void helpers_scanInt(int * retValue);

// Parses and gets a datetime in format yyyy/mm/dd hh:mm
void helpers_scanDateTime(tDateTime * retValue);

// Parses and gets an string written on a file until finding a new line.
char * helpers_scanFromFile(FILE * inputFile, int maxValue);

// Copies the content of a file into another file
void helpers_copyFile(FILE * inFile, FILE * outFile);

#endif
