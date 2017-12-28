/*
 * File:        cars.c
 * Description: Contains the functionality related to the cars management.
 */

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "cars.h"
#include "operations.h"
 
/*
 * Function:    cars_initStruct
 * Description: Initializes contents of a car struct
 * Arguments:   car: Upon return, the car struct ready to be filled
 * Returns:     ---
 */
void cars_initStruct(tCar * car)
{
	memset(car->plate, 0, PLATE_LENGTH);
	memset(car->brand, 0, MAX_BRAND_LENGTH);
	memset(car->model, 0, MAX_BRAND_LENGTH);
	car->kilometers = 0;
	car->type = CAR_ECONOMY;
	car->nextCar = NULL;
}


/*
 * Function: 	cars_getLastCar
 * Description: Gets the latest stored car.
 * Arguments:   ---
 * Returns: 	The pointer to the latest stored car
 */
tCar * cars_getLastCar()
{
	tCar * retValue = cars_firstCar;
	
	if (retValue == NULL)
	{
		return cars_firstCar;
	}
	
	while (retValue->nextCar != NULL)
	{
		retValue = retValue->nextCar;
	}
	
	return retValue;
}

/*
 * Function:    cars_registerNewCar
 * Description: Creates a new car struct and requests for the information
 * Arguments:   ---
 * Returns:     An enum with the error code according to the validation of the data.
 */
carError cars_registerNewCar(tCar * car)
{
	carError err;
	
	err = cars_checkCar(car);
	if (err != CAR_NOERR)
	{
		return err;
	}
	
	if (cars_firstCar == NULL)
	{
		cars_firstCar = car;
	}
	else
	{
		cars_getLastCar()->nextCar = car;
	}
	
	ops_saveCarsList();
	
	return CAR_NOERR;
}


/*
 * Function:    cars_checkCar
 * Description: Verifies the introduced information is valid
 * Arguments:   car: The car struct to be validated
 * Returns:     The error message
 */ 
carError cars_checkCar(tCar * car)
{	
	int i;
	
	if (strlen(car->plate) != 7)	
	{
		// The car plate must have 4 numbers followed by 3 uppercase letters.
		return CAR_INVALIDPLATE;
	}
	for (i = 0; i < 4; i++)
	{
		if ((car->plate[i] < '0') || (car->plate[i] > '9'))
		{
			// The car plate must have 4 numbers followed by 3 uppercase letters.
			return CAR_INVALIDPLATE;
		}
	}
	for (i = 4; i < 7; i++)
	{
		if ((car->plate[i] < 'A') || (car->plate[i] > 'Z'))
		{
			// The car plate must have 4 numbers followed by 3 uppercase letters.
			return CAR_INVALIDPLATE;
		}
	}
	if ((strlen(car->brand) < 2) || (strlen(car->brand) > 32)) 
	{
		// The brand must have between 2 & 32 letters.
		return CAR_INVALIDBRAND;
	}
	if ((strlen(car->model) < 2) || (strlen(car->model) > 32)) 
	{
		// The model must have between 2 & 32 letters.
		return CAR_INVALIDMODEL;
	}

	return CAR_NOERR;
}

/*
 * Function:    cars_errMsg
 * Description: Transforms the error value enumerate into a string
 * Arguments:   The error value
 * Returns:     The string to display to the user
 */ 
char * cars_errMsg(carError err)
{
	switch(err)
	{
		case CAR_INVALIDPLATE:
		    return "The Plate is invalid. It must have 4 digits followed by 3 letters.\n";
			
		case CAR_INVALIDBRAND:
			return "The Brand is invalid. It must have between 2 & 32 letters.\n";
			
		case CAR_INVALIDMODEL:
			return "The Model is invalid. It must have between 2 & 32 letters.\n";
			
		case CAR_INVALIDTYPE:
			return "The car type is invalid. It must be a number between 1 to 4.\n";
			
		default:
			return "";
	}
}

/*
 * Function:    car_getCarStr
 * Description: Get a textual representation of an car
 * Arguments:   car: The car struct
 * 				str: string pointer to save textual representation
 * Returns:     ---
 */ 
void car_getCarStr(tCar * car, char *str)
{
	int length;
	
	length = snprintf(str, MAX_LINE-1, "%s;%s;%s;%d;%d", car->plate, car->brand, car->model, car->kilometers, (int)car->type);
	
	if (length > 0) {
		str[length] = '\0';
	}
}

/* Init a brand table */
void car_initBrandTable(tBrands * brands) {
	/* Check PRE conditions */
	assert(brands != NULL);
	
	/* Init attributes */
	brands->table = NULL;
	brands->size = 0;
}

/*
 * Function:    car_addBrand
 * Description: Add a new brand into a brand table
 * Arguments:   brands: The pointer to brand table
 * 				str: The brand to add
 * Returns:     A brand table with a new brand
 */ 
void car_addBrand(tBrands * brands, char *str) {
	int check;
	
	// Check if a brand already exists into brand table
	check = car_isBrandExists(brands, str);

	// Only if doesn't exists yet
	if (check != 0) {
		// Update dinamic memory
		if(brands->size == 0) {
			brands->table = (tBrand*)malloc(sizeof(tBrand));
		} else {
			brands->table = (tBrand*)realloc(brands->table, (brands->size + 1) * sizeof(tBrand));
		}
		
		// Check memory error
		if(brands->table == NULL) {
			printf("Memory error on brand table");
		} 

		// Add brand
		strcpy(brands->table[brands->size].brand, str);
		
		// Update table size
		brands->size++;
	}
}

/*
 * Function:    car_isBrandExists
 * Description: Check if a brand already exists into a brand table
 * Arguments:   brands: The pointer to brand table
 * 				str: The brand to check
 * Returns:     An integer that could be: 1 (doesn't exist) or 0 (exists)
 */ 
int car_isBrandExists(tBrands * brands, char *str) {
	int i;
	int result;
	
	result = 1;
	
	for (i = 0; i < brands->size; i++) {
		if (strcmp(brands->table[i].brand, str) == 0) {
			result = 0;
		}
	}
	
	return result;
}