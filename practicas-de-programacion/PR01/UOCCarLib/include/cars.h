#ifndef _CARS_H_
#define _CARS_H_

#define MIN_MESSAGE_LENGTH 2
#define MAX_INDEX_CAR 3
#define PLATE_LENGTH 8
#define MAX_TYPE_LENGTH 32
#define MAX_BRAND_LENGTH 32
#define MAX_LINE_CAR 300

typedef enum {FALSE, TRUE} tBoolean;

typedef enum
{
	CAR_ECONOMY,
	CAR_SEDAN,
	CAR_VAGON,
	CAR_SPORT
} carType;

typedef enum
{
	CAR_NOERR,
	CAR_INVALIDPLATE,
	CAR_INVALIDBRAND,
	CAR_INVALIDMODEL,
	CAR_INVALIDTYPE
} carError;

typedef struct sCar
{
	char plate[PLATE_LENGTH];
	char brand[MAX_BRAND_LENGTH];
	char model[MAX_BRAND_LENGTH];
	int kilometers;
	carType type;
	struct sCar * nextCar;
} tCar;


tCar * cars_firstCar;

// Initializes contents of a car struct
void cars_initStruct(tCar * car);

// Gets the latest stored car.
tCar * cars_getLastCar();

// Request car plate
void cars_requestCarPlate(char *plate);

// Request car brand
void cars_requestCarBrand(char *brand);

// Request car model
void cars_requestCarModel(char *model);

// Request car type
carType cars_requestCarType();

// Print list cars on screen
void cars_listCars();

// Register a new car
carError cars_registerNewCar();

// Transforms the error value enumerate into a string
char * cars_errMsg(carError err);

// Transforms a carType value enumerate into a string
char * cars_carTypeMsg(carType type);

// Verifies the introduced information is valid
carError cars_checkCar(tCar * car);

// Validate car plate
tBoolean cars_validCarPlate(char *plate);

// Validate car brand
tBoolean cars_validCarBrand(char *brand);

// Validate car model
tBoolean cars_validCarModel(char *model);

// Validate car type
tBoolean cars_validCarType(carType type);

// Valite a string length
tBoolean cars_helpers_validStringLength(char *message, unsigned int minLength, unsigned int maxLength);

// Get car index
void helpers_getCarIndex(char *index, unsigned int counter);

// Check if char is a number representation on ascii table
tBoolean helpers_checkCharIsNumber(char value);

// Check if char is an uppercase letter representation on ascii table
tBoolean helpers_checkCharIsUppercaseLetter(char value);

#endif
