/*
 * File:        svrMain.c
 * Description: Contains the main functionality for the application
 */

#include "svrMain.h"
#include "svrMenu.h"

#include "cars.h"
#include "offices.h"

/* 
 * Function:    svrMain_displayMenu
 * Description: Displays the UOCCar Server application main menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_displayMenu()
{
	char option;

	option = svrMenu_mainMenu();
	
	while (option != '0')
	{
		switch(option)
		{
			case '1':   // Manage Cars
				svrMain_manageCars();
				break;
				
			case '2':   // Manage Offices
				svrMain_manageOffices();
				break;
				
			default:
				break;
		}
		option = svrMenu_mainMenu();
	}
	
}


/* 
 * Function:    svrMain_manageCars
 * Description: Displays the Cars Management sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_manageCars()
{
	char option;

	option = svrMenu_carsMenu();
	
	
	while (option != '0')
	{
		switch(option)
		{
			case '1':   // Register a new car
				svrMenu_registerNewCar();
				break;
				
			case '2':   // Display the list of cars
				svrMenu_listCars();
				break;
				
			default:
				break;
		}
		option = svrMenu_carsMenu();
	}
	
}


/* 
 * Function:    svrMain_manageOffices
 * Description: Displays the Offices Management sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_manageOffices()
{
	char option;

	option = svrMenu_officesMenu();
	
	
	while (option != '0')
	{
		switch(option)
		{
			case '1':   // Register a new car
				svrMenu_registerNewOffice();
				break;
				
			case '2':   // Display the list of offices
				svrMenu_listOffices();
				break;
				
			default:
				break;
		}
		option = svrMenu_officesMenu();
	}
	
}