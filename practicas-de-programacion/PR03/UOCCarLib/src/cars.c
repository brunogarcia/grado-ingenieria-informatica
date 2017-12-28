/*
 * File:        cars.c
 * Description: Contains the functionality related to the cars management.
 */

#include <string.h>

#include "cars.h"
#include "operations.h"
#include "helpers.h"
 
/*
 * Function:    cars_initStruct
 * Description: Initializes contents of a car struct
 * Arguments:   car: Upon return, the car struct ready to be filled
 * Returns:     ---
 */
void cars_initStruct(tCar * car)
{
	///
	/// EX.2.1: Adapt the function according to the changes in the struct.
	///
	
	memset(car->plate, 0, PLATE_LENGTH);
	memset(car->brand, 0, MAX_BRAND_LENGTH);
	memset(car->model, 0, MAX_BRAND_LENGTH);
	car->kilometers = 0;
	car->officeIndex = 0;
	car->isBooked = 0;
	car->type = CAR_ECONOMY;
	car->nextCar = NULL;
	
	///
	/// END OF EX.2.1.
	///
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
 * Function:    cars_listCars
 * Description: Display the list of cars
 * Arguments:   ---
 * Returns:     ---
 */
void cars_listCars()
{
	tCar * currentCar;
	int i;
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
}

/*
 * Function:    cars_listBookedCars
 * Description: Display the list of booked cars
 * Arguments:   ---
 * Returns:     Number of booked cars
 */
int cars_listBookedCars()
{
	int i;
	int counter = 0;
	tCar * currentCar;
	char * type[] = {"ECONOMY", "SEDAN", "VAGON", "SPORT"};
	
	helpers_clearScreen();
	
	printf("\nList of booked cars\n");
	printf("\n-------------------\n\n");
	
	currentCar = cars_firstCar;
	i = 1;
	
	// Show only booked cars
	if (currentCar->isBooked == 1)
	{
		counter++;
		printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
	}
	
	while (currentCar->nextCar != NULL)
	{
		i++;
		currentCar = currentCar->nextCar;
		
		// Show only booked cars
		if (currentCar->isBooked == 1)
		{
			counter++;
			printf("%03d - %s - %s - %s (%s)\n", i, currentCar->plate, currentCar->brand, currentCar->model, type[currentCar->type]);
		}
	}
	
	if (counter == 0)
	{
		printf("\nThere are no cars booked.\n");
		helpers_pressAnyKey();
	}
	
	return counter;
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
 * Function:    cars_displayCar
 * Description: Displays the detailed information of a car.
 * Arguments:   car: The pointer to the car struct to display its information
 * Returns:     ---
 */ 
void cars_displayCar(tCar * car)
{

	///
	/// EX.3.1: Implement the function to display the information of a car including its plate, brand, model, type and kilometers made.
	///
	char * type[] = {"ECONOMY", "SEDAN", "VAGON", "SPORT"};
	
	if (car == NULL)
	{
		return;
	} else {
		printf("Plate: %s\n", car->plate);
		printf("Brand: %s\n", car->brand);
		printf("Model: %s\n", car->model);
		printf("Type:  %s\n", type[car->type]);
		printf("Kms:   %d\n\n", car->kilometers);
	}
	///
	/// END OF EX.3.1
	///
}


/*
 * Function:    cars_bookCar
 * Description: Reserves a car.
 * Arguments:   car: The pointer to the car to be booked
 * Returns:     ---
 */ 
void cars_bookCar(tCar * car)
{
	if (car == NULL)
	{
		return;
	}
	
	if (car->isBooked == 1)
	{
		printf("This car is currently in use. Please select another\n");
	}
	else
	{
		car->isBooked = 1;
		ops_saveCarsList();
		printf("Car correctly booked.\n");
	}

	helpers_pressAnyKey();
}