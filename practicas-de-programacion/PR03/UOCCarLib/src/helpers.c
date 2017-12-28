/*
 * File:        helpers.c
 * Description: Contains some auxilliar common functions.
 * 
 * IMPORTANT NOTE: ¡¡¡¡Do not add new methods in this file!!!!
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"

/*
 * Function:    helpers_clearScreen
 * Description: Used to clear the output screen
 * Arguments:   ---
 * Returns:     ---
 */
void helpers_clearScreen()
{
	// Windows users: please, use system("cls");
	// system("cls");
	
	// Linux users: please, comment previous line and use system("clear");
	system("clear");
}

/*
 * Function:    helpers_getOption
 * Description: reads a key input from the user.
 * Arguments:   ---
 * Returns:     The character pressed by the user
 */
char helpers_getOption()
{
	char retValue;

	retValue = getchar();
	fflush(stdin);

	return retValue;
}


/*
 * Function:    helpers_pressAnyKey
 * Description: waits until user presses any key
 * Arguments:   ---
 * Returns:     ---
 */
void helpers_pressAnyKey()
{
	printf("\nPress any key to continue.\n");

	getchar();
	fflush(stdin);
}

/*
 * Function:    helpers_scanText
 * Description: Parses and gets an string manually introduced by the user until it presses the Enter.
 * Arguments:   property: Upon return, the pointer to the captured string
 * 			    maxValue: The maximum string length to parse.
 * Returns:     ---
 */
void helpers_scanText(char * property, int maxValue)
{
	int i;
	char c;
	
	i = 0;
	c = getchar();
	while ((i < maxValue - 1) && (c != '\n'))
	{
		// Concatenate the characters until 'Enter' or string maximum length
		property[i] = c;
		i++;
		c = getchar();
	}
	
	fflush(stdin);
}

/*
 * Function:    helpers_scanInt
 * Description: Parses and gets an integer value manually introduced by the user.
 * Arguments:   retValue: Upon return, the captured integer value
 * Returns:     ---
 */
void helpers_scanInt(int * retValue)
{
	scanf("%d", retValue);
	fflush(stdin);
}


/*
 * Function:    helpers_scanDateTime
 * Description: Parses and gets a datetime in format yyyy/mm/dd hh:mm
 * Arguments:   retValue: Upon return, the captured datetime
 * Returns:     ---
 */
void helpers_scanDateTime(tDateTime * retValue)
{
	scanf("%d/%d/%d %d:%d", &retValue->year, &retValue->month, &retValue->day, &retValue->hour, &retValue->minute);
	fflush(stdin);
}


/*
 * Function:    helpers_scanFromFile
 * Description: Parses and gets an string written on a file until finding a new line split by delimiter.
 * Arguments:   inputFile: The file pointer
 * 				delimiter: The delimeter to split the string
 * 			    maxValue: The maximum string length to parse.
 * Returns:     The pointer to the captured string
 */
char * helpers_scanFromFile(FILE * inputFile, char delimiter, int maxValue)
{
	int i;
	char c;
	char * retValue;
	
	retValue = (char *)malloc(maxValue);
	memset(retValue, 0, maxValue);
	
	i = 0;
	c = fgetc(inputFile);
	
	while ((i < maxValue) && (c != delimiter) && (c != '\n') && (c != EOF))
	{
		// Concatenate the characters until finding a new line, string maximum length or no more data in the file
		retValue[i] = c;
		i++;
		c = getc(inputFile);
	}
	
	return retValue;
}


/*
 * Function:    helpers_copyFile
 * Description: Copies the content of a file into another file
 * Arguments:   inFile: The file with the contents to copy
 *              outFile: The destination file pointer
 * Returns:     ---
 */
void helpers_copyFile(FILE * inFile, FILE * outFile)
{
	char c;
	
	c = fgetc(inFile);
	while (c != EOF)
	{
		fputc(c, outFile);
		c = fgetc(inFile);
	}
}
