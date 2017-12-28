/*
 * File:        appMenu.c
 * Description: Contains the user interface functionality for the UOCCar App application
 * 				Basically, it implements the different menus that will be displayed on the screen
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "appMenu.h"
#include "helpers.h"
#include "operations.h"
#include "cars.h"
#include "offices.h"

/* 
 * Function:    appMenu_mainMenu
 * Description: Displays the UOCCar App application main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char appMenu_mainMenu()
{
	int version;
	char option;
	
	helpers_clearScreen();
	
	version = ops_getVersion();
	
	printf("\nWelcome to the UOCCar App application!\n");
	printf("\n------------------------------------\n\n");
	printf("Library version: %d\n\n", version);
	
	printf("Please, select a menu option:\n\n");
	printf("1. List all available cars \n");
	printf("2. List cars filtered by type \n");
	printf("3. List cars filtered by brand \n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}

/*
 * Function:    appMenu_requestType
 * Description: Display the menu where the user selects which car type he wants to filter
 * Arguments:   ---
 * Returns:     The selected option by the user.
 */
char appMenu_requestType()
{
	char option;
	
	helpers_clearScreen();
	helpers_pressAnyKey();
	
	printf("\nFilter by Car Type\n");
	printf("\n------------------------------------\n\n");
		
	printf("\n   1 - ECONOMY \n");
	printf("\n   2 - SEDAN \n");
	printf("\n   3 - VAGON \n");
	printf("\n   4 - SPORT \n\n");
	
	printf("\n Select the Car Type to filter. (0 to exit)\n");
	
	option = helpers_getOption();
	
	return option;
}

/*
 * Function:    appMenu_requestBrand
 * Description: Display the menu where the user selects which car brand he wants to filter
 * Arguments:   ---
 * Returns:     The selected string.
 */
char * appMenu_requestBrand()
{
	char * retValue = "";
	///
	/// EX.5.1: Display the list of available car brands and request the user to select an option.
	///
	tBrands brands;
	int option;
	
	helpers_clearScreen();
	helpers_pressAnyKey();
	
	car_initBrandTable(&brands);
	appMenu_populateBrandTable(&brands);
	appMenu_showBrandMenu(&brands);
	helpers_scanInt(&option);

	if (option != 0) {
		retValue = brands.table[option-1].brand;
	}
	///
	/// END OF EX.5.1.
	///
	return retValue;
}

/*
 * Function:    appMenu_populateBrandTable
 * Description: Populate a brand table
 * Arguments:   brands: The pointer to brand table
 * Returns:     A brand table with all the current brands
 */
void appMenu_populateBrandTable(tBrands * brands) {
	tCar * currentCar;
	currentCar = cars_firstCar;
	
	// get first car
	if (cars_firstCar != NULL) {
		car_addBrand(brands, currentCar->brand);
	}
	
	// get next ones
	while (currentCar->nextCar != NULL)
	{
		currentCar = currentCar->nextCar;
		car_addBrand(brands, currentCar->brand);
	}
}

/*
 * Function:    appMenu_showBrandMenu
 * Description: Show brand menu
 * Arguments:   brands: The pointer to brand table
 * Returns:     ---
 */
void appMenu_showBrandMenu(tBrands * brands) {
	int i;

	printf("\nFilter by Car Brand\n");
	printf("\n------------------------------------\n\n");
	
	for (i = 0; i < brands->size; i++) {
		printf("%03d - %s\n", i+1, brands->table[i].brand);
	}
	
	printf("\n Select the Brand to filter. (0 to exit)\n");
}


/*
 * Function:    appMenu_listAllCars
 * Description: Display the list of available cars. 
 * Arguments:   ---
 * Returns:     ---
 */
void appMenu_listAllCars()
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
 * Function:    appMenu_listCarsByType
 * Description: Display the list of available cars filtered by type. 
 * Arguments:   filter: The Car type to filter
 * Returns:     ---
 */
void appMenu_listCarsByType(carType filter)
{
	///
	/// EX.4.2: List only the cars that match with the filtered car type.
	///
	tCar * currentCar;
	int i;
	char * type[] = {"ECONOMY", "SEDAN", "VAGON", "SPORT"};
	
	helpers_clearScreen();
	helpers_pressAnyKey();

	printf("\nList of %s registered cars\n", type[filter]);
	printf("\n-----------------------\n\n");

	currentCar = cars_firstCar;
	i = 0;

	if (cars_firstCar == NULL) {
		printf("\nThere are no cars registered yet.\n");
		helpers_pressAnyKey();
		return;
	}

	if (currentCar->type == filter) {
		i++;
		printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
	}

	while (currentCar->nextCar != NULL) {
		currentCar = currentCar->nextCar;

		if (currentCar->type == filter) {
			i++;
			printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
		}
	}
	
	if (i == 0) {
		printf("\nThere are no %s cars registered yet.\n", type[filter]);
		helpers_pressAnyKey();
		return;
	}

	helpers_pressAnyKey();
	///
	/// END OF EX.4.2.
	///
}

/*
 * Function:    appMenu_listCarsByBrand
 * Description: Display the list of available cars filtered by brand. 
 * Arguments:   filter: The string with the brand to filter
 * Returns:     ---
 */
void appMenu_listCarsByBrand(char * filter)
{
	///
	/// EX.5.2: List only the cars that match with the filtered car brand.
	///
	tCar * currentCar;
	int i;
	char * type[] = {"ECONOMY", "SEDAN", "VAGON", "SPORT"};
	
	helpers_clearScreen();
	helpers_pressAnyKey();

	printf("\nList of %s registered cars\n", filter);
	printf("\n-----------------------\n\n");

	currentCar = cars_firstCar;
	i = 0;

	if (cars_firstCar == NULL) {
		printf("\nThere are no cars registered yet.\n");
		helpers_pressAnyKey();
		return;
	}

	if (strcmp(currentCar->brand, filter) == 0) {
		i++;
		printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
	}

	while (currentCar->nextCar != NULL) {
		currentCar = currentCar->nextCar;

		if (strcmp(currentCar->brand, filter) == 0) {
			i++;
			printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
		}
	}
	helpers_pressAnyKey();
	///
	/// END OF EX.5.2.
	///
}
