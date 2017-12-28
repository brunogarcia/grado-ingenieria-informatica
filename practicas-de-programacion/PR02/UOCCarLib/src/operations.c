/*
 * File:        operations.c
 * Description: Contains miscellaneous operations provided by the library.
 */
 
 #include "operations.h"
 #include "helpers.h"
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 /* 
 * Function:    ops_getVersion
 * Description: Gets the library version
 * Arguments:   ---
 * Returns:     The library version
 */
int ops_getVersion()
{
	return UOCCAR_LIB_VERSION;
}



/*
 * Function:    ops_saveOffice
 * Description: Appends the current office information into offices file.
 * Arguments:   office: Pointer to the office to save its information.
 * Returns:     ---
 */ 
void ops_saveOffice(tOffice * office)
{
	///
	/// EX.2.1. Append the offices struct contents into the Offices file.
	///
    FILE *inputFile = 0;
    char str[MAX_LINE];

	/* Open the output file */
    inputFile = fopen(OPS_OFFICES_FILE, "a");
    
	if(inputFile != 0) {
		offices_getOfficeStr(office, str);
        fprintf(inputFile, "%s\n", str);
	}
	
	/* Close the file */
	fclose(inputFile);

	/// END OF EX.2.1.
}

/*
 * Function:    ops_loadOfficesInformation
 * Description: Retrieves the information of the offices previously stored on the file
 * Arguments:   ---
 * Returns:     The list of offices is retrieved upon offices_firstOffice variable.
 */ 
void ops_loadOfficesInformation()
{
	///
	/// EX: 2.2 Implement the function that loads the Offices list from the file.
	///
    FILE *inputFile = 0;

	/* Open the output file */
    inputFile = fopen(OPS_OFFICES_FILE, "r");
    
	if(inputFile != 0) {
		ops_setOfficesInformation(inputFile);
	}

	/* Close the file */
	fclose(inputFile);
	
	/// END OF EX.2.2
}

/*
 * Function:    ops_setOfficesInformation
 * Description: Set the information of stored offices into memory
 * Arguments:   inputFile: The file pointer
 * Returns:     ---
 */ 
void ops_setOfficesInformation(FILE * inputFile) {
	// Instance helper vars
	tOffice * office;
	char delimiter = ';';
	
	// Init an office
	office = (tOffice *)malloc(sizeof(tOffice));
	offices_initStruct(office);

	/* Gets each attribute of one stored office and 
	 * then save all of them in an office struct */
	strcpy(office->address, helpers_scanFromFile(inputFile, delimiter, ADDRESS_LENGTH));
	strcpy(office->city, helpers_scanFromFile(inputFile, delimiter, CITY_LENGTH));
	strcpy(office->country, helpers_scanFromFile(inputFile, delimiter, COUNTRY_LENGTH));
	strcpy(office->postalCode, helpers_scanFromFile(inputFile, delimiter, POSTAL_CODE_LENGTH));
		
	// Base case
	if (!feof(inputFile)) {
		// Save first office
		if (offices_firstOffice == NULL) {
			offices_firstOffice = office;
		} else {
			// Save next ones
			offices_getLastOffice()->nextOffice = office;
		}
		
		// Recursive case
		ops_setOfficesInformation(inputFile);
	}
}


/*
 * Function:    ops_saveCarsList
 * Description: Saves the list of cars with their information into a file.
 * Arguments:   ---
 * Returns:     ---
 */ 
void ops_saveCarsList()
{
	///
	/// EX.3.1. Saves the list of cars with their information into the Cars file.
	///
    FILE *inputFile = 0;
	tCar * car = cars_firstCar;

	/* Open the output file */
    inputFile = fopen(OPS_CARS_FILE, "w");
    
	if(inputFile != 0) {
	
		// Saves first car
		ops_saveCar(inputFile, car);
		
		// Saves next ones
		while (car->nextCar != NULL) {
			car = car->nextCar;
			ops_saveCar(inputFile, car);
		}
	}
	
	/* Close the file */
	fclose(inputFile);
	/// END OF EX.3.1.
}

/*
 * Function:    ops_saveCar
 * Description: Saves a car into a file.
 * Arguments:   inputFile: The file pointer
 *              car: Pointer to the car to save its information.
 * Returns:     ---
 */ 
void ops_saveCar(FILE * inputFile, tCar * car) {
	char str[MAX_LINE];

	car_getCarStr(car, str);
	fprintf(inputFile, "%s\n", str);
}


/*
 * Function:    ops_loadCarsInformation
 * Description: Retrieves the information of the cars previously stored on the file
 * Arguments:   ---
 * Returns:     The list of cars is retrieved upon cars_firstCar variable.
 */ 
void ops_loadCarsInformation()
{
	///
	/// EX: 3.2 Implement the function that loads the Cars list from the file.
	///
    FILE *inputFile = 0;

	/* Open the output file */
    inputFile = fopen(OPS_CARS_FILE, "r");
    
	if(inputFile != 0) {
		ops_setCarsInformation(inputFile);
	}

	/* Close the file */
	fclose(inputFile);
	/// END OF EX.3.2
}

/*
 * Function:    ops_setCarsInformation
 * Description: Set the information of stored cars into memory
 * Arguments:   inputFile: The file pointer
 * Returns:     ---
 */ 
void ops_setCarsInformation(FILE * inputFile) {
	// Instance helper vars
	tCar * car;
	char delimiter = ';';
	int max_kilometers_length = 5;
	int max_type_length = 1;
	int temp_kilometers;
	int temp_type;
	
	// Init a car
	car = (tCar *)malloc(sizeof(tCar));
	cars_initStruct(car);

	/* Gets each attribute of one stored car and 
	 * then save all of them in an car struct */
	strcpy(car->plate, helpers_scanFromFile(inputFile, delimiter, PLATE_LENGTH));
	strcpy(car->brand, helpers_scanFromFile(inputFile, delimiter, MAX_BRAND_LENGTH));
	strcpy(car->model, helpers_scanFromFile(inputFile, delimiter, MAX_BRAND_LENGTH));

	// Save car kilometers: convert it to integer
	temp_kilometers = atoi(helpers_scanFromFile(inputFile, delimiter, max_kilometers_length));
	car->kilometers = temp_kilometers;
	
	// Save car type: first convert char to integer and then to carType
	temp_type = atoi(helpers_scanFromFile(inputFile, delimiter, max_type_length));
	car->type = (carType)temp_type;
		
	// Base case
	if (!feof(inputFile)) {
		// Save first car
		if (cars_firstCar == NULL) {
			cars_firstCar = car;
		} else {
			// Save next ones
			cars_getLastCar()->nextCar = car;
		}
		
		// Recursive case
		ops_setCarsInformation(inputFile);
	}
}