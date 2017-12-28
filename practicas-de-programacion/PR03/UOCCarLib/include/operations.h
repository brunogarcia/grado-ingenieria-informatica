#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#define UOCCAR_LIB_VERSION 3

#define OPS_CARS_FILE "Logs/cars.txt"
#define OPS_OFFICES_FILE "Logs/offices.txt"

#include "cars.h"
#include "offices.h"

#include <stdio.h>

// Gets the library version
int ops_getVersion();

// Appends the contents of an office struct to the offices file
void ops_saveOffice(tOffice * office);

// Retrieves the information of the offices previously stored on the file
void ops_loadOfficesInformation();

// Saves the list of cars with their information into a file.
void ops_saveCarsList();

// Retrieves the information of the cars previously stored on the file
void ops_loadCarsInformation();

#endif