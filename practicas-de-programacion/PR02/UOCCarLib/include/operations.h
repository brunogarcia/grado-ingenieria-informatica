#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#define UOCCAR_LIB_VERSION 2

#define OPS_CARS_FILE "Logs/cars.txt"
#define OPS_OFFICES_FILE "Logs/offices.txt"
#define MAX_LINE 200

#include "cars.h"
#include "offices.h"

#include <stdio.h>

// Gets the library version
int ops_getVersion();

// Appends the contents of an office struct to the offices file
void ops_saveOffice(tOffice * office);

// Retrieves the information of the offices previously stored on the file
void ops_loadOfficesInformation();

// Set the information of the offices into memory
void ops_setOfficesInformation(FILE * inputFile);

// Saves the list of cars with their information into a file.
void ops_saveCarsList();

// Saves a car into a file.
void ops_saveCar(FILE * inputFile, tCar * car);

// Retrieves the information of the cars previously stored on the file
void ops_loadCarsInformation();

// Set the information of the cars into memory
void ops_setCarsInformation(FILE * inputFile);

#endif