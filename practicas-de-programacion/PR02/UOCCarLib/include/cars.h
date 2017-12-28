#ifndef _CARS_H_
#define _CARS_H_

#define PLATE_LENGTH 8
#define MAX_BRAND_LENGTH 33
#define MAX_VEHICLES 64

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

typedef struct {
	char brand[MAX_BRAND_LENGTH];
} tBrand;

typedef struct sBrands
{
	tBrand* table;
	int size;
} tBrands;


tCar * cars_firstCar;

// Initializes contents of a car struct
void cars_initStruct(tCar * car);

// Gets the latest stored car.
tCar * cars_getLastCar();

// Register a new car
carError cars_registerNewCar(tCar * car);

// Display the list of cars
void cars_listCars();

// Transforms the error value enumerate into a string
char * cars_errMsg(carError err);

// Verifies the introduced information is valid
carError cars_checkCar(tCar * car);

/* Get a textual representation of a car */
void car_getCarStr(tCar * car, char *str);

/* Init a brand table */
void car_initBrandTable(tBrands * brands);

/* Add a new brand into a brand table */
void car_addBrand(tBrands * brands, char *str);

/* Check if a brand already exists into a brand table */
int car_isBrandExists(tBrands * brands, char *str);
#endif
