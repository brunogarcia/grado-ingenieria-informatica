#ifndef _SVRMENU_H_
#define _SVRMENU_H_


// Displays the UOCCar Server main menu with the available operations
char svrMenu_mainMenu();

// Displays the Cars Management sub-menu with the available operations
char svrMenu_carsMenu();

// Displays the Offices Management sub-menu with the available operations
char svrMenu_officesMenu();

// Register a new car
void svrMenu_registerNewCar();

// Display the list of cars
void svrMenu_listCars();

// Register a new office
void svrMenu_registerNewOffice();

// Display the list of offices
void svrMenu_listOffices();

#endif