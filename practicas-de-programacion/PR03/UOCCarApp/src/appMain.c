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
				
			case '4':   // Return a currently reserved car
				appMenu_returnCar();
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
	char option;
	int retValue;
	
	option = appMenu_requestType();
	
	while (option != '0')
	{
		retValue = option - 49;
		if ((retValue >= 0) && (retValue < 4))
		{
			appMenu_listCarsByType(retValue);
		}
		option = appMenu_requestType();
	}
}


/* 
 * Function:    appMain_filterCarsByType
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
