/*
 * File:        main.c
 * Description: Initialization point
 * IMPORTANT NOTE: ¡¡¡¡Do not add modify this file!!!!.
 * 				   It will be used for the automated validation.
 */

#include "svrMain.h"
#include "cars.h"
#include "offices.h"

#include <stdlib.h>

/* 
 * Function:    main
 * Description: Application entry method
 * Arguments:   ---
 * Returns:     0 always.
 */
int main(int argc, char **argv)
{
	// Initialize the first entry of the list
	cars_firstCar = NULL;
	offices_firstOffice = NULL;
		
	// Display the main application menu
	svrMain_displayMenu();
	return 0;
}