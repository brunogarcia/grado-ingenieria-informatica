#ifndef _APPMENU_H_
#define _APPMENU_H_

#include "cars.h"

// Displays the UOCCar App main menu with the available operations
char appMenu_mainMenu();

// Display the list of available cars. 
void appMenu_listAllCars();

// Display the menu where the user selects which car type he wants to filter
char appMenu_requestType();

// Display the menu where the user selects which car brand he wants to filter
char * appMenu_requestBrand();

// Populate a brand table
void appMenu_populateBrandTable(tBrands * brands);

// Show brand menu
void appMenu_showBrandMenu(tBrands * brands);

// Display the list of available cars. 
void appMenu_listAllCars();

// Display the list of available cars filtered by type. 
void appMenu_listCarsByType(carType filter);

// Display the list of available cars filtered by brand. 
void appMenu_listCarsByBrand(char * filter);

#endif