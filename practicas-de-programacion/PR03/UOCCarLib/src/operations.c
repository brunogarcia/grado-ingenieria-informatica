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
	FILE * outputFile;

	outputFile = fopen(OPS_OFFICES_FILE, "a");
	if (outputFile == NULL)
	{
		return;
	}
	
	fprintf(outputFile, "%s;%s;%s;%s\n", office->address, office->city, office->country, office->postalCode);

	fclose(outputFile);
}

/*
 * Function:    ops_loadOfficesInformation
 * Description: Retrieves the information of the offices previously stored on the file
 * Arguments:   ---
 * Returns:     The list of offices is retrieved upon offices_firstOffice variable.
 */ 
void ops_loadOfficesInformation()
{

	FILE * inputFile;
	tOffice * newOffice;
	tOffice * currentOffice;
	char * auxAddress, * auxCity, * auxCountry, * auxPostalCode;
	
	inputFile = fopen(OPS_OFFICES_FILE, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	// First, we read the contents of the line
	auxAddress = helpers_scanFromFile(inputFile, ';', ADDRESS_LENGTH );
	auxCity = helpers_scanFromFile(inputFile, ';', CITY_LENGTH );
	auxCountry = helpers_scanFromFile(inputFile, ';', COUNTRY_LENGTH );
	auxPostalCode = helpers_scanFromFile(inputFile, ';', POSTAL_CODE_LENGTH );
	
	// If there was something written, we can copy the contents into the struct.
	if (strcmp(auxAddress, ""))
	{
		offices_firstOffice = (tOffice *)malloc(sizeof(tOffice));
		offices_initStruct(offices_firstOffice);
			
		strcpy(offices_firstOffice->address, auxAddress);
		strcpy(offices_firstOffice->city, auxCity);
		strcpy(offices_firstOffice->country, auxCountry);
		strcpy(offices_firstOffice->postalCode, auxPostalCode);
		
		currentOffice = offices_firstOffice;
	}
	while (strcmp(auxAddress, ""))
	{
		// We keep on reading the file line by line until the end
		auxAddress = helpers_scanFromFile(inputFile, ';', ADDRESS_LENGTH );
		auxCity = helpers_scanFromFile(inputFile, ';', CITY_LENGTH );
		auxCountry = helpers_scanFromFile(inputFile, ';', COUNTRY_LENGTH );
		auxPostalCode = helpers_scanFromFile(inputFile, ';', POSTAL_CODE_LENGTH );
		if (strcmp(auxAddress, ""))
		{
			// We have a new register, so append it to the list.
			newOffice = (tOffice *)malloc(sizeof(tOffice));
			offices_initStruct(newOffice);
		
			strcpy(newOffice->address, auxAddress);
			strcpy(newOffice->city, auxCity);
			strcpy(newOffice->country, auxCountry);
			strcpy(newOffice->postalCode, auxPostalCode);
			
			currentOffice->nextOffice = newOffice;
			currentOffice = newOffice;
		}
	}
	
	fclose(inputFile);

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
	/// EX.2.1: Adapt the function according to the changes in the struct.
	///
	
	FILE * outputFile;
	tCar * car;

	outputFile = fopen(OPS_CARS_FILE, "w");
	if (outputFile == NULL)
	{
		return;
	}
	car = cars_firstCar;
	
	while (car != NULL)
	{
		fprintf(outputFile, "%s;%s;%s;%d;%d;%d;%d\n", car->plate, car->brand, car->model, car->kilometers, car->officeIndex, car->isBooked, car->type);
		car = car->nextCar;
	}
	
	fclose(outputFile);

	///
	/// END OF EX.2.1.
	///
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
	/// EX.2.1: Adapt the function according to the changes in the struct.
	///
	
	FILE * inputFile;
	tCar * newCar;
	tCar * currentCar;
	char * auxPlate, * auxBrand, * auxModel, * auxKilometer, *auxOfficeIndex, *auxIsBooked, * auxType;
	
	inputFile = fopen(OPS_CARS_FILE, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	// First, we read the contents of the line
	auxPlate = helpers_scanFromFile(inputFile, ';', PLATE_LENGTH );
	auxBrand = helpers_scanFromFile(inputFile, ';', MAX_BRAND_LENGTH );
	auxModel = helpers_scanFromFile(inputFile, ';', MAX_BRAND_LENGTH );
	auxKilometer = helpers_scanFromFile(inputFile, ';', 7 );
	auxOfficeIndex = helpers_scanFromFile(inputFile, ';', 2 );
	auxIsBooked = helpers_scanFromFile(inputFile, ';', 1 );
	auxType = helpers_scanFromFile(inputFile, ';', 1 );
	
	// If there was something written, we can copy the contents into the struct.
	if (strcmp(auxPlate, ""))
	{
		cars_firstCar = (tCar *)malloc(sizeof(tCar));
		cars_initStruct(cars_firstCar);
			
		strcpy(cars_firstCar->plate, auxPlate);
		strcpy(cars_firstCar->brand, auxBrand);
		strcpy(cars_firstCar->model, auxModel);
		cars_firstCar->kilometers = atoi(auxKilometer);
		cars_firstCar->officeIndex = atoi(auxOfficeIndex);
		cars_firstCar->isBooked = atoi(auxIsBooked);
		cars_firstCar->type = atoi(auxType);
		
		currentCar = cars_firstCar;
	}

	while (strcmp(auxPlate, ""))
	{
		// We keep on reading the file line by line until the end
		auxPlate = helpers_scanFromFile(inputFile, ';', PLATE_LENGTH );
		auxBrand = helpers_scanFromFile(inputFile, ';', MAX_BRAND_LENGTH );
		auxModel = helpers_scanFromFile(inputFile, ';', MAX_BRAND_LENGTH );
		auxKilometer = helpers_scanFromFile(inputFile, ';', 7 );
		auxOfficeIndex = helpers_scanFromFile(inputFile, ';', 2 );
		auxIsBooked = helpers_scanFromFile(inputFile, ';', 1 );
		auxType = helpers_scanFromFile(inputFile, ';', 1 );
		
		if (strcmp(auxPlate, ""))
		{
			// We have a new register, so append it to the list.
			newCar = (tCar *)malloc(sizeof(tCar));
			cars_initStruct(newCar);
				
			strcpy(newCar->plate, auxPlate);
			strcpy(newCar->brand, auxBrand);
			strcpy(newCar->model, auxModel);
			newCar->kilometers = atoi(auxKilometer);
			newCar->officeIndex = atoi(auxOfficeIndex);
			newCar->isBooked = atoi(auxIsBooked);
			newCar->type = atoi(auxType);
			
			currentCar->nextCar = newCar;
			currentCar = newCar;
		}
	}
	
	fclose(inputFile);

	///	
	/// END OF EX.2.1
	///
}