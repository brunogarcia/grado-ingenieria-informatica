/*
 * File:        offices.c
 * Description: Contains the functionality related to the offices management.
 */

#include <string.h>

#include "offices.h"
#include "operations.h"
 
/*
 * Function:    offices_initStruct
 * Description: Initializes contents of an office struct
 * Arguments:   office: Upon return, the office struct ready to be filled
 * Returns:     ---
 */
void offices_initStruct(tOffice * office)
{
	memset(office->address, 0, ADDRESS_LENGTH);
	memset(office->city, 0, CITY_LENGTH);
	memset(office->country, 0, COUNTRY_LENGTH);
	memset(office->postalCode, 0, POSTAL_CODE_LENGTH);
	office->nextOffice = NULL;
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
	
	if (retValue == NULL)
	{
		return offices_firstOffice;
	}
	
	while (retValue->nextOffice != NULL)
	{
		retValue = retValue->nextOffice;
	}
		
	return retValue;
}

/*
 * Function:    offices_registerNewOffice
 * Description: Creates a new office struct and requests for the information
 * Arguments:   ---
 * Returns:     An enum with the error code according to the validation of the data.
 */
officeError offices_registerNewOffice(tOffice * office)
{
	officeError err;
	
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
	
	ops_saveOffice(office);
		
	return OFFICE_NOERR;
}

/*
 * Function:    offices_listOffices
 * Description: Display the list of offices
 * Arguments:   ---
 * Returns:     ---
 */
void offices_listOffices()
{
	tOffice * currentOffice;
	int i;
	
	printf("\nList of registered offices\n");
	printf("\n-----------------------\n\n");
	
	currentOffice = offices_firstOffice;
	i = 1;
	
	if (currentOffice == NULL)
	{
		printf("\nThere are no offices registered yet.\n");
		return;
	}
	
	printf("%03d - %s - %s - %s - %s\n", i, currentOffice->address, currentOffice->city, currentOffice->country, currentOffice->postalCode);
	
	while (currentOffice->nextOffice != NULL)
	{
		i++;
		currentOffice = currentOffice->nextOffice;
		printf("%03d - %s - %s - %s - %s\n", i, currentOffice->address, currentOffice->city, currentOffice->country, currentOffice->postalCode);
	}
}

/*
 * Function:    offices_checkOffice
 * Description: Verifies the introduced information is valid
 * Arguments:   office: The office struct to be validated
 * Returns:     The error message
 */ 
officeError offices_checkOffice(tOffice * office)
{	
	if ((strlen(office->address) < 2) || (strlen(office->address) > 64)) 
	{
		// The address must have between 2 & 64 letters.
		return OFFICE_INVALIDADDRESS;
	}
	if ((strlen(office->city) < 2) || (strlen(office->city) > 32)) 
	{
		// The city must have between 2 & 32 letters.
		return OFFICE_INVALIDCITY;
	}
	if ((strlen(office->country) < 2) || (strlen(office->country) > 32)) 
	{
		// The country must have between 2 & 32 letters.
		return OFFICE_INVALIDCOUNTRY;
	}
	if ((strlen(office->postalCode) < 2) || (strlen(office->postalCode) > 16)) 
	{
		// The postal code must have between 2 & 16 letters.
		return OFFICE_INVALIDPOSTALCODE;
	}

	return OFFICE_NOERR;
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

/*
 * Function:    offices_displayOffice
 * Description: Common function to display the information of an office
 * Arguments:   officeIndex: The index of the office to display its information
 * Returns:     ---
 */ 
void offices_displayOffice(int officeIndex)
{
	///
	/// EX.3.1: Implement the function to display the information of an office including address, city, country and postal code.
	///
	tOffice * office = NULL;
	tOffice * tempOffice;
	int i;
	int founded = 0;
	
	printf("\nOFFICE\n");
	printf("\n-----------------------\n\n");

	// Find the office selected
	i = 0;
	tempOffice = offices_firstOffice;
	
	if (offices_firstOffice != NULL && i == (officeIndex-1))
	{
		founded = 1;
		office = tempOffice;
	}
	
	while (tempOffice->nextOffice != NULL && founded == 0)
	{
		i++;
		tempOffice = tempOffice->nextOffice;

		if (i == (officeIndex-1)) {
			founded = 1;
			office = tempOffice;
		}
	}
	
	if (office != NULL)
	{
		// Print office details
		printf("Address:     %s\n", office->address);
		printf("City:        %s\n", office->city);
		printf("Country:     %s\n", office->country);
		printf("Postal Code: %s\n\n", office->postalCode);
	}
	///
	/// END OF EX.3.1
	///
}