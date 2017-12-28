/*
 * File:        offices.c
 * Description: Contains the functionality related to the offices management.
 */

#include <string.h>
#include <stdio.h>

#include "offices.h"
#include "helpers.h"
 
/*
 * Function:    offices_initStruct
 * Description: Initializes contents of an office struct
 * Arguments:   office: Upon return, the office struct ready to be filled
 * Returns:     ---
 */
void offices_initStruct(tOffice * office)
{
	///
	/// EX.5.1. Initialize all properties of an office struct to 0
	///
	memset(office->address, 0, ADDRESS_LENGTH);
	memset(office->city, 0, CITY_LENGTH);
	memset(office->country, 0, COUNTRY_LENGTH);
	memset(office->postalCode, 0, POSTAL_CODE_LENGTH);
	office->nextOffice = NULL;;
	///
	/// END OF EX.5.1.
	///
}


/*
 * Function: 	offices_getLastOffice
 * Description: Gets the latest stored office.
 * Arguments:   ---
 * Returns: 	The pointer to the latest stored office
 */
tOffice * offices_getLastOffice()
{
	tOffice * retValue = offices_firstOffice;
	
	///
	/// EX.5.1. Initialize all properties of an office struct to 0
	///
	if (retValue == NULL)
	{
		return offices_firstOffice;
	}
	
	while (retValue->nextOffice != NULL)
	{
		retValue = retValue->nextOffice;
	}
	/// END OF EX.5.1.
	
	return retValue;
}

/*
 * Function: 	offices_listOffices
 * Description: Display the list of offices
 * Arguments:   ---
 * Returns:		---
 */
void offices_listOffices() {
	char buffer[MAX_LINE_OFFICE];
	unsigned int counter;
	struct sOffice * tmpOffice;
	char index[MAX_INDEX_OFFICE];
	
	counter = 0;
	tmpOffice = offices_firstOffice;

	while (tmpOffice != NULL) {
		// Get index 
		counter++;
		helpers_getOfficeIndex(index, counter);
		
		// Print office data
		snprintf(buffer, MAX_LINE_OFFICE, "%s%u \n %s\n %s\n %s - %s \n\n", index, counter, tmpOffice->address, tmpOffice->city, tmpOffice->postalCode, tmpOffice->country);
		puts (buffer);
		
		// Get new office
		tmpOffice = tmpOffice->nextOffice;
	}
}

/*
 * Function: 	helpers_getOfficeIndex
 * Description: Get car index
 * Arguments:   index: char pointer that represents the zeros values
 *              counter: numeric value that represents the current counter of the list
 * Returns:		a single string that is the result of combine index and counter
 */
void helpers_getOfficeIndex(char *index, unsigned int counter) {
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
 * Function:    offices_registerNewOffice
 * Description: Creates a new office struct and requests for the information
 * Arguments:   ---
 * Returns:     An enum with the error code according to the validation of the data.
 */
officeError offices_registerNewOffice(tOffice * office)
{
	///
	/// EX.5.1. Validate the contents of the struct, and add it to the list if everything is correct.
	///         Return the error code in case of any error in the data.
	///
	officeError err;

	// Temp office data
	char address[ADDRESS_LENGTH];
	char city[CITY_LENGTH];
	char country[COUNTRY_LENGTH];
	char postalCode[POSTAL_CODE_LENGTH];
	
	// Request office data
	offices_requestDataString(address, "Address");
	offices_requestDataString(city, "City");
	offices_requestDataString(country, "Country");
	offices_requestDataString(postalCode, "Postal code");

	// Fill office data
	strncpy(office->address, address, ADDRESS_LENGTH);
	strncpy(office->city, city, CITY_LENGTH);
	strncpy(office->country, country, COUNTRY_LENGTH);
	strncpy(office->postalCode, postalCode, POSTAL_CODE_LENGTH);
	
	err = offices_checkOffice(office);
	if (err != OFFICE_NOERR)
	{
		return err;
	}
	
	if (offices_firstOffice == NULL)
	{
		offices_firstOffice = office;
	}
	else
	{
		offices_getLastOffice()->nextOffice = office;
	}
	/// END OF EX.5.1.
		
	return OFFICE_NOERR;
}

/*
 * Function:    offices_requestDataString
 * Description: Request data string for an office
 * Arguments:   data: Upon return, the pointer to the captured string
 *              message: text that will be show to the user
 * 			    maxValue: The maximum string length to parse.
 * Returns:     ---
 */
void offices_requestDataString(char *data, char *message) {
	printf("%s: \t", message);
	scanf ("%[^\n]%*c", data);
}

/*
 * Function:    offices_checkOffice
 * Description: Verifies the introduced information is valid
 * Arguments:   office: The office struct to be validated
 * Returns:     The error message
 */ 
officeError offices_checkOffice(tOffice * office)
{	
	///
	/// EX.5.1: Validate the contents of the struct and return the correct error message.
	///
	if(offices_validOfficeAddress(office->address) != VALID) {
		return OFFICE_INVALIDADDRESS;
	}
	
	if(offices_validOfficeCity(office->city) != VALID) {
		return OFFICE_INVALIDCITY;
	}
	
	if(offices_validOfficeCountry(office->country) != VALID) {
		return OFFICE_INVALIDCOUNTRY;
	}
	
	if(offices_validOfficePostalCode(office->postalCode) != VALID) {
		return OFFICE_INVALIDPOSTALCODE;
	}
	/// END OF EX.5.1
		
	return OFFICE_NOERR;
}

// Validate office address
int offices_validOfficeAddress(char *address) {
	return offices_helpers_validStringLength(address, MIN_MESSAGE_LENGTH, ADDRESS_LENGTH);
}

// Validate office city
int offices_validOfficeCity(char *city) {
	return offices_helpers_validStringLength(city, MIN_MESSAGE_LENGTH, CITY_LENGTH);
}


// Validate office country
int offices_validOfficeCountry(char *country) {
	return offices_helpers_validStringLength(country, MIN_MESSAGE_LENGTH, COUNTRY_LENGTH);
}

// Validate office postal code
int offices_validOfficePostalCode(char *postalCode) {
	return offices_helpers_validStringLength(postalCode, MIN_MESSAGE_LENGTH, POSTAL_CODE_LENGTH);
}


/*
 * Function:    offices_errMsg
 * Description: Transforms the error value enumerate into a string
 * Arguments:   The error value
 * Returns:     The string to display to the user
 */ 
char * offices_errMsg(officeError err)
{
	switch(err)
	{
		case OFFICE_INVALIDADDRESS:
		    return "The Address is invalid. It must have between 2 & 64 characters.\n";
			
		case OFFICE_INVALIDCITY:
			return "The City is invalid. It must have between 2 & 32 characters.\n";
			
		case OFFICE_INVALIDCOUNTRY:
			return "The Country is invalid. It must have between 2 & 32 characters.\n";
			
		case OFFICE_INVALIDPOSTALCODE:
			return "The Postal Code is invalid. It must have between 2 & 16 characters.\n";
			
		default:
			return "";
	}
}

// Valite a string length
int offices_helpers_validStringLength(char *message, unsigned int minLength, unsigned int maxLength) {
	int validation = INVALID;
	unsigned int messageLength;
	
	messageLength = strlen(message);

	if (messageLength >= minLength && 
	    messageLength <= maxLength) {
		validation = VALID;
	}

	return validation;
}