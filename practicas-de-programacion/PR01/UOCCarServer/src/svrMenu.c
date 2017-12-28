/*
 * File:        svrMenu.c
 * Description: Contains the user interface functionality for the UOCCar Server application
 * 				Basically, it implements the different menus that will be displayed on the screen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "svrMenu.h"
#include "helpers.h"
#include "operations.h"
#include "cars.h"
#include "offices.h"


/* 
 * Function:    svrMenu_mainMenu
 * Description: Displays the UOCCar Server application main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char svrMenu_mainMenu()
{
	int version;
	char option;
	
	helpers_clearScreen();
	
	version = ops_getVersion();
	
	printf("\nWelcome to the UOCCar Server application!\n");
	printf("\n------------------------------------\n\n");
	printf("Library version: %d\n\n", version);
	
	printf("Please, select a menu option:\n\n");
	printf("1. Manage Cars \n");
    printf("2. Manage Offices \n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}


/* 
 * Function:    svrMenu_carsMenu
 * Description: Displays the Cars Management sub-menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char svrMenu_carsMenu()
{
	char option;
	
	///
	/// EX.2.2: Implement the Cars Management sub-menu
	///
	helpers_clearScreen();
	
	printf("\n Cars managment \n");
	printf("\n------------------------------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. Register new car \n");
    printf("2. Display the list of cars \n");
	printf("\n");
	printf("0. Go up one level\n\n");
	/// END OF EX.2.2
	
	option = helpers_getOption();

	return option;
}

/* 
 * Function:    svrMenu_officesMenu
 * Description: Displays the Offices Management sub-menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char svrMenu_officesMenu()
{
	char option;
	
	///
	/// EX.2.3: Implement the Offices Management sub-menu
	///
	helpers_clearScreen();

	printf("\n Offices management \n");
	printf("\n------------------------------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. Register new office \n");
    printf("2. Display the list of offices \n");
	printf("\n");
	printf("0. Go up one level\n\n");
	
	/// END OF EX.2.3
	
	option = helpers_getOption();
	
	return option;
}


/*
 * Function:    svrMenu_registerNewCar
 * Description: Creates a new car struct and requests for the information
 * Arguments:   ---
 * Returns:     ---
 */
void svrMenu_registerNewCar()
{
	tCar * newCar = NULL;
	carError err = CAR_NOERR;
	char * errMsg;
	
	///
	/// EX.3.1: Fill the fields of the struct with the proper information.
	///
	
	helpers_clearScreen();
	
	// Start register
	printf("\nRegister a new car\n\n");
	printf("\n---------------------------\n\n");
	
	// Set dinamic memory
	newCar = (tCar*)malloc(sizeof(tCar));
	
	// Check memory error
	if(newCar == NULL) {
		printf("Memory error");
	}
	
	// Init car
	cars_initStruct(newCar);
	
	// Clear enter
	while(getchar()!='\n');
	
	// Register new car and saving response
	err = cars_registerNewCar(newCar); 
	
	/// END OF EX.3.1
	
	
	// Display the result on screen.
	if (err == CAR_NOERR)
	{
		printf("\nCar successfully registered\n\n");
		printf("\n---------------------------\n\n");
	}
	else
	{
		// Some error ocurred. Display the error.
		free(newCar);
		printf("\n\n");
		errMsg = cars_errMsg(err);
		printf("\n%s\n", errMsg);
	}
	
	while(getchar()!='\n');
	helpers_pressAnyKey();
}

/*
 * Function:    svrMenu_listCars
 * Description: Display the list of available cars. 
 * Arguments:   ---
 * Returns:     ---
 */
void svrMenu_listCars()
{
	///
	/// EX.4.1. Implement functionality to display the list of cars.
	///
	helpers_clearScreen();

	printf("\n List cars \n\n");
	printf("\n------------------------------------\n\n");
	
	if (cars_firstCar == NULL) {
		printf("There is not any car registered yet.\n");
	} else {
		cars_listCars();
	}
	
	while(getchar()!='\n');
	helpers_pressAnyKey();
	
	/// END OF EX.4.1.
}


/*
 * Function:    svrMenu_registerNewOffice
 * Description: Creates a new office struct and requests for the information
 * Arguments:   ---
 * Returns:     ---
 */
void svrMenu_registerNewOffice()
{
	///
	/// EX.5.2: Implement the office registering functionality
	///
	tOffice * newOffice = NULL;
	officeError err = OFFICE_NOERR;
	char * errMsg;
	
	helpers_clearScreen();
	
	// Start register
	printf("\n Register office \n");
	printf("\n---------------------------\n\n");
	
	// Set dinamic memory
	newOffice = (tOffice*)malloc(sizeof(tOffice));
	
	// Check memory error
	if(newOffice == NULL) {
		printf("Memory error");
	}
	
	// Init car
	offices_initStruct(newOffice);
	
	// Clear enter
	while(getchar()!='\n');
	
	// Register new office and saving response
	err = offices_registerNewOffice(newOffice); 
	
	// Display the result on screen.
	if (err == OFFICE_NOERR)
	{
		printf("\nOffice successfully registered\n\n");
		printf("\n---------------------------\n\n");
	}
	else
	{
		// Some error ocurred. Display the error.
		free(newOffice);
		printf("\n\n");
		errMsg = offices_errMsg(err);
		printf("\n%s\n", errMsg);
	}
	
	while(getchar()!='\n');
	helpers_pressAnyKey();
	/// END OF EX.5.2
	
}

/*
 * Function:    svrMenu_listOffices
 * Description: Display the list of available offices. 
 * Arguments:   ---
 * Returns:     ---
 */
void svrMenu_listOffices()
{
	///
	/// EX.5.3: Implement the office listing functionality
	///
	helpers_clearScreen();

	printf("\n List offices \n\n");
	printf("\n------------------------------------\n\n");
	
	if (offices_firstOffice == NULL) {
		printf("There is not any office registered yet.\n");
	} else {
		offices_listOffices();
	}
	
	while(getchar()!='\n');
	helpers_pressAnyKey();
	/// END OF EX.5.3
	
}

