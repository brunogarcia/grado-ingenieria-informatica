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
	printf("4. Return a car\n");
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
 * Function:    appMenu_requestType
 * Description: Display the menu where the user selects which car brand he wants to filter
 * Arguments:   ---
 * Returns:     The selected string.
 */
char * appMenu_requestBrand()
{	
	int i, counter;
	tCar * currentCar;
	char * retValue;
	char ** brandList;
	char ** brand;
	
	helpers_clearScreen();
	
	printf("\nFilter by Car Brand\n");
	printf("\n-------------------\n\n");
	
	retValue = (char *)malloc(MAX_BRAND_LENGTH);
	
	counter = 0;
	brandList = (char **)malloc(MAX_BRAND_LENGTH);
	currentCar = cars_firstCar;
	
	if (cars_firstCar == NULL)
	{
		printf("\nThere are no cars registered yet.\n");
		helpers_pressAnyKey();
		return "";
	}
	
	while (currentCar != NULL)
	{
		for (i = 0; i < counter; i++)
		{
			if (!strcmp(currentCar->brand, brandList[i]))
			{
				// We already detected this brand, so there is no need to add it again.
				break;
			}
			
		}
		if (i == counter)
		{
			// This means the brand has not been added yet to the list of available brands.
			counter++;
			brand = (char **)realloc(brandList, counter * sizeof(char *));
			brandList = brand;
			brandList[i] = (char *)malloc(MAX_BRAND_LENGTH);
			strcpy(brandList[i], currentCar->brand);
		}
		currentCar = currentCar->nextCar;
	}
	
	// Print the list of available brands on screen.
	for (i = 0; (i < counter) && (strcmp(brandList[i], "")); i++)
	{
		printf("\n%03d - %s\n", i + 1, brandList[i]);
	}
	
	printf("\n Select the Brand to filter. (0 to exit)\n");
	
	scanf("%d", &i);
	fflush(stdin);
	
	if ((i == 0) || (i > counter))
	{
		// It is not a valid value. Return an empty string
		strcpy(retValue, "");
	}
	else 
	{
		// Return the brand according to the item selected by the user.
		strcpy(retValue, brandList[i-1]);
	}
	
	// Finally, free all previously allocated memory.
	for (i = 0; i < counter; i++)
	{
		free(brandList[i]);
	}
	free(brandList);
	
	return retValue;
}

/*
 * Function:    appMenu_findCarByIndex
 * Description: Find a car by its index and book it.
 * Arguments:   Index: the selected index of the car
 * Returns:     ---
 */
void appMenu_findAndBookCar(int index)
{
	int i;
	int carFounded = 0;
	tCar * tempCar;
	tCar * car = NULL;
	
	i = 1;
	tempCar = cars_firstCar;
	
	if (cars_firstCar != NULL && i == index)
	{
		carFounded = 1;
		car = tempCar;
	}
	
	while (tempCar->nextCar != NULL && carFounded == 0)
	{
		i++;
		tempCar = tempCar->nextCar;

		if (i == index) {
			carFounded = 1;
			car = tempCar;
		}
	}
	
	if (car != NULL)
	{
		cars_bookCar(car);
	}
}

/*
 * Function:    appMenu_listCars
 * Description: Display the list of available cars. 
 * Arguments:   ---
 * Returns:     ---
 */
void appMenu_listAllCars()
{
	tCar * currentCar;
	int i, selectedCar;
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
	
	printf("\nSelect a car to book. Press 0 to  Exit.\n");
	helpers_scanInt(&selectedCar);
	
	helpers_clearScreen();
	
	///
	/// EX.4.1: Determine the car the user selected in order to book it.
	///
	appMenu_findAndBookCar(selectedCar);
	///
	/// END OF EX.4.1
	///
}

/*
 * Function:    appMenu_listCarsByType
 * Description: Display the list of available cars filtered by type. 
 * Arguments:   filter: The Car type to filter
 * Returns:     ---
 */
void appMenu_listCarsByType(carType filter)
{	
	tCar * currentCar;
	int i, selectedCar;
	char * type[] = {"ECONOMY", "SEDAN", "VAGON", "SPORT"};
	
	helpers_clearScreen();
	
	printf("\nList of %s registered cars\n", type[filter]);
	printf("\n--------------------------------\n\n");
	
	currentCar = cars_firstCar;
	i = 1;
	
	if (cars_firstCar == NULL)
	{
		printf("\nThere are no cars registered yet.\n");
		helpers_pressAnyKey();
		return;
	}
	
	while (currentCar != NULL)
	{
		if (currentCar->type == filter)
		{
			printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);	
			i++;
		}
		currentCar = currentCar->nextCar;
	}
	
	if (i == 1)
	{
		printf("\nThere are no %s cars registered yet.\n", type[filter]);
		helpers_pressAnyKey();
		return;
	}
	
	printf("\nSelect a car to book. Press 0 to  Exit.\n");
	helpers_scanInt(&selectedCar);
	
	helpers_clearScreen();
	
	///
	/// EX.4.2: Determine the car the user selected in order to book it.
	///
	appMenu_findAndBookCar(selectedCar);
	///
	/// END OF EX.4.2
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
	tCar * currentCar;
	int i, selectedCar;
	char * type[] = {"ECONOMY", "SEDAN", "VAGON", "SPORT"};
	
	helpers_clearScreen();
	
	printf("\nList of %s registered cars\n", filter);
	printf("\n----------------------------------\n\n");
	
	currentCar = cars_firstCar;
	i = 1;
	
	if (cars_firstCar == NULL)
	{
		printf("\nThere are no cars registered yet.\n");
		helpers_pressAnyKey();
		return;
	}
	
	while (currentCar != NULL)
	{
		if (!strcmp(currentCar->brand, filter))
		{
			printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);	
			i++;
		}
		currentCar = currentCar->nextCar;
	}
	
	printf("\nSelect a car to book. Press 0 to  Exit.\n");
	helpers_scanInt(&selectedCar);
	
	helpers_clearScreen();
	
	///
	/// EX.4.3: Determine the car the user selected in order to book it.
	///
	appMenu_findAndBookCar(selectedCar);
	///
	/// END OF EX.4.3
	///
}

/*
 * Function:    appMenu_returnCar
 * Description: Return a car to the rental office, indicating where it has been delivered and how many kilometers 
 * Arguments:   ---
 * Returns:     ---
 */
void appMenu_returnCar()
{
	///
	/// EX.5.1. Implement the functionality to return a car to a rental office.
	///
	int selectedCar;
	int selectedOffice;
	int kmsDoneDuringBooking;
	int numberBookedCars;
	int tempIndexCar;
	int carFounded = 0;
	tCar * tempCar;
	tCar * currentCar = NULL;

	// 1) Show a list with the booked cars
	numberBookedCars = cars_listBookedCars();
	
	if (numberBookedCars == 0)
	{
		return;
	}

	// 2) Select a car to return
	printf("\nSelect a car to return. Press 0 to Exit.\n");
	helpers_scanInt(&selectedCar);
	
	// Check that selected index is valid
	if (selectedCar == 0)
	{
		return;
	}
	
	// 3) Find a car by index
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
	
	// Check that selected car is valid
	if (currentCar != NULL && currentCar->isBooked == 1)
	{
		// 4) Show car details
		printf("------------------\n");
		cars_displayCar(currentCar);
		
		// 5) Show offices list
		offices_listOffices();

		printf("\nSelect a office to return the car. Press 0 to Exit.\n");
		helpers_scanInt(&selectedOffice);
		
		// Check that selected office is valid
		if (selectedOffice == 0)
		{
			return;
		}
		
		// 6) Request kilometers
		printf("\nIndicate the kilometers done during the booking:\n");
		helpers_scanInt(&kmsDoneDuringBooking);
		
		// 7) Save office to return
		currentCar->officeIndex = selectedOffice - 1;

		// 8) Save kilometers done during the booking
		currentCar->kilometers = kmsDoneDuringBooking;
		
		// 9) Make the car available again
		currentCar->isBooked = 0;
		
		// 10) And finally save cars list
		ops_saveCarsList();

		printf("\nCar correctly returned.\n");
	}
	
	/// END OF EX.5.1.
	///
	helpers_pressAnyKey();
}