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
	tCar * currentCar;
	int i;
	char * type[] = {"ECONOMY", "SEDAN", "VAGON", "SPORT"};
	
	helpers_clearScreen();
	
	printf("\nList of registered cars\n");
	printf("\n-----------------------\n\n");
	
	currentCar = cars_firstCar;
	i = 1;
	
	if (cars_firstCar == NULL)
	{
		printf("\nThere are no cars registered yet.\n");
		helpers_pressAnyKey();
		return;
	}
	
	printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
	
	while (currentCar->nextCar != NULL)
	{
		i++;
		currentCar = currentCar->nextCar;
		printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
	}
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
	tOffice * currentOffice;
	int i;
	
	helpers_clearScreen();
	
	printf("\nList of registered offices\n");
	printf("\n--------------------------\n\n");
	
	currentOffice = offices_firstOffice;
	i = 1;
	
	if (offices_firstOffice == NULL)
	{
		printf("\nThere are no offices registered yet.\n");
		helpers_pressAnyKey();
		return;
	}
	
	printf("%03d - %s \n", i, currentOffice->address);
	printf("      %s \n", currentOffice->city);
	printf("      %s - %s \n\n", currentOffice->postalCode, currentOffice->country);
	
	while (currentOffice->nextOffice != NULL)
	{
		i++;
		currentOffice = currentOffice->nextOffice;
		printf("%03d - %s \n", i, currentOffice->address);
	    printf("      %s \n", currentOffice->city);
	    printf("      %s - %s \n\n", currentOffice->postalCode, currentOffice->country);
	}
	helpers_pressAnyKey();
	
}

