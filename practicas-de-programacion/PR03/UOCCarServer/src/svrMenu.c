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
	
	helpers_clearScreen();
	
	printf("\nCars Management\n");
	printf("\n---------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. Register new car \n");
    printf("2. Display the list of cars \n");
	printf("3. Assign car to office \n") ;
	printf("\n");
	printf("0. Exit\n\n");
	
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
	
	helpers_clearScreen();
	
	printf("\nOffices Management\n");
	printf("\n------------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. Register new office \n");
    printf("2. Display the list of offices \n");
	printf("\n");
	printf("0. Exit\n\n");
		
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
	tCar * newCar;
	carError err = CAR_NOERR;
	char * errMsg;
	int type; 
	
	helpers_clearScreen();
	helpers_pressAnyKey();

	// Allocate memory and initialize the contents for the new struct
	newCar = (tCar *)malloc(sizeof(tCar));
	cars_initStruct(newCar);
	
	printf("\nRegister a new car\n");
	printf("\n-----------------\n\n");
	
	// The parameters we need are the plate id, the brand and model of the car
    // and its type (economy, sedan, vagon or sport)
		
	printf("\nPlate ID:        ");
	helpers_scanText(newCar->plate, PLATE_LENGTH);
	
	printf("\nBrand:           ");
	helpers_scanText(newCar->brand, MAX_BRAND_LENGTH);
	
	printf("\nModel:           ");
	helpers_scanText(newCar->model, MAX_BRAND_LENGTH);
	
	printf("\nCar Type : \n");
	printf("\n   1 - ECONOMY \n");
	printf("\n   2 - SEDAN \n");
	printf("\n   3 - VAGON \n");
	printf("\n   4 - SPORT \n\n");
	helpers_scanInt(&type);
	if ((type > 0) && (type < 5))
	{
		newCar->type = (carType)(type - 1);
		err = cars_registerNewCar(newCar);
	}
	else
	{
		err = CAR_INVALIDTYPE;
	}	
	
	// Display the result on screen.
	if (err == CAR_NOERR)
	{
		helpers_clearScreen();
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
	int selectedCar;
	int tempIndexCar;
	int carFounded = 0;
	tCar * tempCar;
	tCar * currentCar = NULL;
	
	// Print on screen the cars
	cars_listCars();
	
	printf("\nSelect a car to display. Press 0 to  Exit.\n");
	helpers_scanInt(&selectedCar);
	
	if (selectedCar == 0)
	{
		return;
	}
	
	helpers_clearScreen();

	///
	/// EX.3.2: Display the car information followed by the detailed information of the office where the car is assigned.
	///

	// Find car by index
	tempIndexCar = 1;
	tempCar = cars_firstCar;
	
	if (cars_firstCar != NULL && tempIndexCar == selectedCar)
	{
		carFounded = 1;
		currentCar = tempCar;
	}
	
	while (tempCar->nextCar != NULL && carFounded == 0)
	{
		tempIndexCar++;
		tempCar = tempCar->nextCar;

		if (tempIndexCar == selectedCar) {
			carFounded = 1;
			currentCar = tempCar;
		}
	}
	
	if (currentCar != NULL)
	{
		// Print car details
		cars_displayCar(currentCar);
		
		// Print office details
		offices_displayOffice(currentCar->officeIndex + 1);
	}
	///
	/// END OF EX.3.2
	///
	
	helpers_pressAnyKey();

}


/*
 * Function:    svrMenu_registerNewOffice
 * Description: Creates a new office struct and requests for the information
 * Arguments:   ---
 * Returns:     ---
 */
void svrMenu_registerNewOffice()
{
	tOffice * newOffice;
	officeError err = OFFICE_NOERR;
	char * errMsg;
	
	helpers_clearScreen();
	helpers_pressAnyKey();

	// Allocate memory and initialize the contents for the new struct
	newOffice = (tOffice *)malloc(sizeof(tOffice));
	offices_initStruct(newOffice);
	
	printf("\nRegister a new office\n");
	printf("\n---------------------\n\n");
	
	// The parameters we need are the address, city, country and postal code
    	
	printf("\nAddress:        ");
	helpers_scanText(newOffice->address, ADDRESS_LENGTH);
	
	printf("\nCity:           ");
	helpers_scanText(newOffice->city, CITY_LENGTH);
	
	printf("\nCountry:        ");
	helpers_scanText(newOffice->country, COUNTRY_LENGTH);
	
	printf("\nPostal Code:    ");
	helpers_scanText(newOffice->postalCode, POSTAL_CODE_LENGTH);
	
	err = offices_registerNewOffice(newOffice);
	
	// Display the result on screen.
	if (err == OFFICE_NOERR)
	{
		helpers_clearScreen();
		printf("\nOffice successfully registered\n\n");
		printf("\n-----------------------------\n\n");
	}
	else
	{
		// Some error ocurred. Display the error.
		free(newOffice);
		printf("\n\n");
		errMsg = offices_errMsg(err);
		printf("\n%s\n", errMsg);
	}
	
	helpers_pressAnyKey();
	
	
}

/*
 * Function:    svrMenu_listOffices
 * Description: Display the list of available offices. 
 * Arguments:   ---
 * Returns:     ---
 */
void svrMenu_listOffices()
{
	tCar * tempCar;
	int selectedOffice;
	
	// Print on screen the offices
	offices_listOffices();
	
	printf("\nSelect an office to display. Press 0 to  Exit.\n");
	helpers_scanInt(&selectedOffice);
	if (selectedOffice == 0)
	{
		return;
	}
	
	helpers_clearScreen();
	
	///
	/// EX.3.1: Display the office information followed by the list of cars assigned to that office.
	///
	offices_displayOffice(selectedOffice);
	
	// Print car information related to this office
	printf("\nCARS IN OFFICE\n");
	printf("\n-----------------------\n\n");
	
	// Find cars
	tempCar = cars_firstCar;
	
	if (cars_firstCar != NULL && tempCar->officeIndex == (selectedOffice-1))
	{
		cars_displayCar(tempCar);
	}
	
	while (tempCar->nextCar != NULL)
	{
		tempCar = tempCar->nextCar;

		if (tempCar->officeIndex == (selectedOffice-1)) {
			cars_displayCar(tempCar);
		}
	}
	///
	/// END OF EX.3.1
	///
	
	helpers_pressAnyKey();
}


/*
 * Function:    svrMenu_assignCarToOffice
 * Description: Requests the user the car to assign, and once selected, prompts the user to select an office.
 * Arguments:   ---
 * Returns:     ---
 */
void svrMenu_assignCarToOffice()
{
	tCar * currentCar = NULL;
	tCar * tempCar;
	int tempIndexCar;
	int carFounded = 0;
	int selectedCar = 0;
	int selectedOffice = 0;
	
	/// 
	/// EX.2.2. Implement the function to assign a car to an office.
	///
	
	// ### (1) Show car list ###
	cars_listCars();
	
	// ### (2) Select and find a car ###
	printf("\nSelect a car to assign. Press 0 to Exit.\n");
	helpers_scanInt(&selectedCar);
	
	// Check that selected car is valid
	if (selectedCar != 0) {
		// Find the car selected
		tempIndexCar = 1;
		tempCar = cars_firstCar;
		
		if (cars_firstCar != NULL && tempIndexCar == selectedCar)
		{
			carFounded = 1;
			currentCar = tempCar;
		}
		
		while (tempCar->nextCar != NULL && carFounded == 0)
		{
			tempIndexCar++;
			tempCar = tempCar->nextCar;

			if (tempIndexCar == selectedCar) {
				carFounded = 1;
				currentCar = tempCar;
			}
		}
	}
	
	// ### (3) Show office list ###
	if (currentCar != NULL) {
		offices_listOffices();
		
		// Select an office
		printf("\nSelect a office to assign. Press 0 to Exit.\n");
		helpers_scanInt(&selectedOffice);
		
		// Check that selected office is valid
		if (selectedCar != 0) {
			// ### (3) Assign office to car ###
			currentCar->officeIndex = selectedOffice - 1;
		}
	}

	///
	/// END OF EX.2.2.
	/// 
	ops_saveCarsList();
	if (currentCar != NULL)
	{
		printf("\n\nThe car %s has been correctly assigned to office %03d\n\n", currentCar->plate, selectedOffice);
		helpers_pressAnyKey();
	}
}