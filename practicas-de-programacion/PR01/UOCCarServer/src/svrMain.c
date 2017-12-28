/*
 * File:        svrMain.c
 * Description: Contains the main functionality for the application
 */

#include <stdio.h>
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
	
	///
	/// EX.2.1: Manage the option introduced by the user
	///
	
	// Call proper action for each option selected
	// 1: Manage cars
	// 2: Manage offices
	// 0: exit program
	do {
		option = svrMenu_mainMenu();

		switch(option) {
		case '1':
			svrMain_manageCars();
			break;
		case '2':
			svrMain_manageOffices();
			break;
		default:
			break;
		}
	} while(option!='0');
	/// END OF EX.2.1
}


/* 
 * Function:    svrMain_manageCars
 * Description: Displays the Cars Management sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_manageCars()
{
	///
	/// EX.2.2: Implement the Cars Management sub-menu
	///
	char option;

	
	// Call proper action for each option selected
	// 1: Register new car
	// 2: List cars
	// 3: Go up one nivel
	do {
		option = svrMenu_carsMenu();

		switch(option) {
		case '1':
			svrMenu_registerNewCar();
			break;
		case '2':
			svrMenu_listCars();
			break;
		case '0':
			svrMain_displayMenu();
			break;
		}
	} while(option!='0');
	/// END OF EX.2.2
}


/* 
 * Function:    svrMain_manageOffices
 * Description: Displays the Offices Management sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_manageOffices()
{
	///
	/// EX.2.3: Implement the Offices management sub-menu
	///
	char option;

	// Call proper action for each option selected
	// 1: Register new office
	// 2: List offices
	// 0: Go up one nivel
	do {
		option = svrMenu_officesMenu();

		switch(option) {
		case '1':
			svrMenu_registerNewOffice();
			break;
		case '2':
			svrMenu_listOffices();
			break;
		case '0':
			svrMain_displayMenu();
			break;
		}
	} while(option!='0');
	
	
	/// END OF EX.2.3
}