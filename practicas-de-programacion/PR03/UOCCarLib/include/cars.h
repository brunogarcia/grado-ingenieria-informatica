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
	int officeIndex;   // EX.2.1 Manage the office where the car is assigned. 
	int isBooked;      // EX.2.1 Manage whether the vehicle is currently reserved by a customer.
	struct sCar * nextCar;
} tCar;


tCar * cars_firstCar;

// Initializes contents of a car struct
void cars_initStruct(tCar * car);

// Gets the latest stored car.
tCar * cars_getLastCar();

// Register a new car
carError cars_registerNewCar(tCar * car);

// Display the list of cars
void cars_listCars();

// Display the list of booked cars
int cars_listBookedCars();

// Transforms the error value enumerate into a string
char * cars_errMsg(carError err);

// Verifies the introduced information is valid
carError cars_checkCar(tCar * car);

// Displays the detailed information of a car.
void cars_displayCar(tCar * car);

// Reserves a car.
void cars_bookCar(tCar * currentCar);

#endif
