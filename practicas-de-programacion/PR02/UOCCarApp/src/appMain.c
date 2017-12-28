/*
 * File:        appMain.c
 * Description: Contains the main functionality for the application
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "appMain.h"
#include "appMenu.h"

#include "cars.h"
#include "offices.h"

/* 
 * Function:    appMain_displayMenu
 * Description: Displays the UOCCar App application main menu
 * Arguments:   ---
 * Returns:     ---
 */
void appMain_displayMenu()
{
	char option;

	option = appMenu_mainMenu();
	
	while (option != '0')
	{
		switch(option)
		{
			case '1':   // List all Cars
				appMenu_listAllCars();
				break;
				
			case '2':   // List Cars filtered by type
				appMain_filterCarsByType();
				break;
				
			case '3':   // List Cars filtered by brand
				appMain_filterCarsByBrand();
				break;
				
			default:
				break;
		}
		option = appMenu_mainMenu();
	}
}


/* 
 * Function:    appMain_filterCarsByType
 * Description: Displays the List cars filtered by type sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void appMain_filterCarsByType()
{
	///
	/// EX.4.1: Request the type to filter and display the list of filtered cars on screen.
	///
	char option;

	option = appMenu_requestType();
	
	while (option != '0')
	{
		switch(option)
		{
			case '1': 
				appMenu_listCarsByType(CAR_ECONOMY);
				break;
				
			case '2':
				appMenu_listCarsByType(CAR_SEDAN);
				break;
				
			case '3':
				appMenu_listCarsByType(CAR_VAGON);
				break;
				
			case '4':
				appMenu_listCarsByType(CAR_SPORT);
				break;
				
			default:
				break;
		}

		option = appMenu_requestType();
	}
	///
	/// END OF EX.4.1
	///
}


/* 
 * Function:    appMain_filterCarsByBrand
 * Description: Displays the List cars filtered by brand sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void appMain_filterCarsByBrand()
{
	char * retValue;

	retValue = appMenu_requestBrand();
	
	while (strcmp(retValue,""))
	{
		appMenu_listCarsByBrand(retValue);
		retValue = appMenu_requestBrand();
	}
}
