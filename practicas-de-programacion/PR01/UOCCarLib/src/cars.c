/*
 * File:        cars.c
 * Description: Contains the functionality related to the cars management.
 */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

#include "cars.h"
 
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
 * Function: 	cars_listCars
 * Description: Display the list of cars
 * Arguments:   ---
 * Returns:		---
 */
void cars_listCars() {
	unsigned int counter;
	struct sCar * tmpCar;
	char index[MAX_INDEX_CAR];
	char buffer[MAX_LINE_CAR];
	
	counter = 0;
	tmpCar = cars_firstCar;

	while (tmpCar != NULL) {
		// Get index
		counter++;
		helpers_getCarIndex(index, counter);
		
		// Print car data
		snprintf(buffer, MAX_LINE_CAR, "%s%u %s - %s - %s (%s) \n", index, counter, tmpCar->plate, tmpCar->brand, tmpCar->model, cars_carTypeMsg(tmpCar->type));
		puts (buffer);
		
		// Get new car
		tmpCar = tmpCar->nextCar;
	}
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

	// Temp car data
	char plate[PLATE_LENGTH];
	char brand[MAX_BRAND_LENGTH];
	char model[MAX_BRAND_LENGTH];
	carType type;

	// Request car data
	cars_requestCarPlate(plate);
	cars_requestCarBrand(brand);
	cars_requestCarModel(model);
	type = cars_requestCarType();

	// Fill car data
	strncpy(car->plate, plate, PLATE_LENGTH);
	strncpy(car->brand, brand, MAX_BRAND_LENGTH);
	strncpy(car->model, model, MAX_BRAND_LENGTH);
	car->type = type;
	
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
	
	return CAR_NOERR;
}

// Request car plate
void cars_requestCarPlate(char *plate) {
	printf("Plate ID:\n");
	scanf ("%[^\n]%*c", plate);
}

// Request car brand
void cars_requestCarBrand(char *brand) {
	printf("Brand:\n");
	scanf ("%[^\n]%*c", brand);
}

// Request car model
void cars_requestCarModel(char *model) {
	printf("Model:\n");
	scanf ("%[^\n]%*c", model);
}

// Request car type
carType cars_requestCarType() {
	char tmpType;
	carType type;
	
	do {
		printf("Car type:\n");
		printf("1. Economy\n");
		printf("2. Sedan\n");
		printf("3. Vagon\n");
		printf("4. Sport\n");

		tmpType = helpers_getOption();
		
		switch(tmpType) {
		case '1':
			type = 	CAR_ECONOMY;
			break;
		case '2':
			type = CAR_SEDAN;
			break;
		case '3':
			type = 	CAR_VAGON;
			break;
		case '4':
			type = CAR_SPORT;
			break;
		default:
			helpers_clearScreen();
			printf("Error: please select a valid car type. \n");
			break;
		}

	} while (!cars_validCarType(type));
	
	return type;
}

/*
 * Function:    cars_validCarType
 * Description: Validate a car type
 * Arguments:   type: a carType to validate
 * Returns:     An tBoolean with the validation of the data
 */
tBoolean cars_validCarType(carType type) {
	tBoolean result = FALSE;

	switch(type) {
		case CAR_ECONOMY:
		case CAR_SEDAN:
		case CAR_VAGON:
		case CAR_SPORT:
			result = TRUE;
	};
	
	return result;
}

/*
 * Function:    cars_checkCar
 * Description: Verifies the introduced information is valid
 * Arguments:   car: The car struct to be validated
 * Returns:     The error message
 */ 
carError cars_checkCar(tCar * car)
{	
	///
	/// EX.3.2: Validate the contents of the struct and return the correct error message.
	///
	if (!cars_validCarPlate(car->plate)) {
		return CAR_INVALIDPLATE;
	}
	
	if (!cars_validCarBrand(car->brand)) {
		return CAR_INVALIDBRAND;
	}

	if (!cars_validCarModel(car->model)) {
		return CAR_INVALIDMODEL;
	}
	/// END OF EX.3.2
	
	return CAR_NOERR;
}

/*
 * Function:    cars_validCarPlate
 * Description: Verifies that a car plate is valid
 * Arguments:   plate: The car plate to be validated
 * Returns:     tBoolean
 */ 
tBoolean cars_validCarPlate(char *plate) {
	tBoolean validation = FALSE;
	tBoolean validChar0;
	tBoolean validChar1;
	tBoolean validChar2;
	tBoolean validChar3;
	tBoolean validChar4;
	tBoolean validChar5;
	tBoolean validChar6;
	
	// A plate must start with 4 numbers
	validChar0 = helpers_checkCharIsNumber(plate[0]);
	validChar1 = helpers_checkCharIsNumber(plate[1]);
	validChar2 = helpers_checkCharIsNumber(plate[2]);
	validChar3 = helpers_checkCharIsNumber(plate[3]);
	
	// A plate must finish with 3 uppercase letters
	validChar4 = helpers_checkCharIsUppercaseLetter(plate[4]);
	validChar5 = helpers_checkCharIsUppercaseLetter(plate[5]);
	validChar6 = helpers_checkCharIsUppercaseLetter(plate[6]);
	
	// Check if all chars are valid
	if (validChar0 == TRUE && 
		validChar1 == TRUE && 
		validChar2 == TRUE && 
		validChar3 == TRUE &&
		validChar4 == TRUE &&
		validChar5 == TRUE &&
		validChar6 == TRUE) {
		validation = TRUE;
	}
	
	return validation;
}

/*
 * Function:    cars_validCarBrand
 * Description: Verifies that a car brand is valid
 * Arguments:   brand: The car brand to be validated
 * Returns:     tBoolean
 */ 
tBoolean cars_validCarBrand(char *brand) {
	return cars_helpers_validStringLength(brand, MIN_MESSAGE_LENGTH, MAX_BRAND_LENGTH);
}

/*
 * Function:    cars_validCarModel
 * Description: Verifies that a car model is valid
 * Arguments:   model: The car model to be validated
 * Returns:     tBoolean
 */ 
tBoolean cars_validCarModel(char *model) {
	return cars_helpers_validStringLength(model, MIN_MESSAGE_LENGTH, MAX_BRAND_LENGTH);
}

// Validate a string length
tBoolean cars_helpers_validStringLength(char *message, unsigned int minLength, unsigned int maxLength) {
	unsigned int messageLength;
	tBoolean validation = FALSE;
	
	messageLength = strlen(message);

	if (messageLength >= minLength && 
	    messageLength <= maxLength) {
		validation = TRUE;
	}
	
	return validation;
}

/*
 * Function:    helpers_checkCharIsNumber
 * Description: Check that a char type is a number representation on ASCII table
 * Arguments:   value: The char type to be validated
 * Returns:     tBoolean
 */ 
tBoolean helpers_checkCharIsNumber(char value) {
	tBoolean validation = FALSE;
	unsigned int number = (int)value;
	
	// ASCII code: 48 is equal to number 0 (zero)
	// ASCII code: 57 is equal to number 9 (nine)
	if (number >= 48 && number <= 57) {
		validation = TRUE;
	}
	
	return validation;
}

/*
 * Function:    helpers_checkCharIsUppercaseLetter
 * Description: Check that a char type is an uppercase letter representation on ASCII table
 * Arguments:   value: The char type to be validated
 * Returns:     tBoolean
 */ 
tBoolean helpers_checkCharIsUppercaseLetter(char value) {
	tBoolean validation = FALSE;
	unsigned int number = (int)value;

	// ASCII code: 65 is equal to uppercase letter A
	// ASCII code: 90 is equal to uppercase letter Z
	if (number >= 65 && number <= 90) {
		validation = TRUE;
	}
	
	return validation;
}

/*
 * Function: 	helpers_getCarIndex
 * Description: Get car index
 * Arguments:   index: char pointer that represents the zeros values
 *              counter: numeric value that represents the current counter of the list
 * Returns:		a single string that is the result of combine index and counter
 */
void helpers_getCarIndex(char *index, unsigned int counter) {
	// counter has 1 digit
	// add 2 zeros
	if (counter >= 1 && counter <= 9) {
		strcpy(index, "00");
	}
	
	// counter has 2 digits
	// add 1 zero
	if (counter >= 10 && counter <= 99) {
		strcpy(index, "0");
	}

	// counter has 3 or more digits
	// return an empty string
	if (counter >= 100) {
		strcpy(index, "");
	}
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
 * Function:    cars_carTypeMsg
 * Description: Transforms a carType value enumerate into a string
 * Arguments:   The car type
 * Returns:     The string to display to the user
 */
char * cars_carTypeMsg(carType type) {
	switch(type) 
	{
		case CAR_ECONOMY:
			return "ECONOMY";

		case CAR_SEDAN:
			return "SEDAN";

		case CAR_VAGON:
			return "VAGON";

		case CAR_SPORT:
			return "SPORT";

		default:
			return "";
	}
}