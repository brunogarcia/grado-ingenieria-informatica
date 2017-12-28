#ifndef _OFFICES_H_
#define _OFFICES_H_

#define MIN_MESSAGE_LENGTH 2
#define ADDRESS_LENGTH 64
#define CITY_LENGTH 32
#define COUNTRY_LENGTH 32
#define POSTAL_CODE_LENGTH 16
#define VALID 1
#define INVALID 0
#define MAX_INDEX_OFFICE 3
#define MAX_LINE_OFFICE 200

typedef enum
{
	OFFICE_NOERR,
	OFFICE_INVALIDADDRESS,
	OFFICE_INVALIDCITY,
	OFFICE_INVALIDCOUNTRY,
	OFFICE_INVALIDPOSTALCODE
} officeError;

typedef struct sOffice
{
	char address[ADDRESS_LENGTH];
	char city[CITY_LENGTH];
	char country[COUNTRY_LENGTH];
	char postalCode[POSTAL_CODE_LENGTH];
	struct sOffice * nextOffice;
} tOffice;

tOffice * offices_firstOffice;

// Initializes contents of an office struct
void offices_initStruct(tOffice * office);

// Gets the latest stored office.
tOffice * offices_getLastOffice();

// Register a new office
officeError offices_registerNewOffice();

// Display the list of offices
void offices_listOffices();

// Request data string
void offices_requestDataString(char *data, char *message);

// Transforms the error value enumerate into a string
char * offices_errMsg(officeError err);

// Verifies the introduced information is valid
officeError offices_checkOffice(tOffice * office);

// Validate office address
int offices_validOfficeAddress(char *address);

// Validate office city
int offices_validOfficeCity(char *city);

// Validate office country
int offices_validOfficeCountry(char *country);

// Validate office postal code
int offices_validOfficePostalCode(char *postalCode);

// Get office index
void helpers_getOfficeIndex(char *index, unsigned int counter);

// Valite a string length
int offices_helpers_validStringLength(char *message, unsigned int minLength, unsigned int maxLength);

#endif