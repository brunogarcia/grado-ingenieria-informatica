/*
 * File:        main.c
 * Description: Initialization point
 * IMPORTANT NOTE: ¡¡¡¡Do not add modify this file!!!!.
 * 				   It will be used for the automated validation.
 */

#include "appMain.h"
#include "cars.h"
#include "offices.h"
#include "operations.h"

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
	
	// Load the saved information
	ops_loadOfficesInformation();
	ops_loadCarsInformation();
	
	// Display the main application menu
	appMain_displayMenu();
	
	return 0;
}