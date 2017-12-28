#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hospital.h"

int main(int argc, char **argv) {
	// First, set up a hospital
	tHospital hospital;
	init_hospital(&hospital);
	
	// Then, add medicines to hospital's pharmacy
	new_medicine(&hospital, 100, "Aspirina", "Bayer");
	new_medicine(&hospital, 200, "Gelocatil", "Gelos");
	new_medicine(&hospital, 100, "Ibuprofeno", "Cinfa");
	new_medicine(&hospital, 150, "Amoxicilina", "Genfar");
	
	// And update medicine stock
	add_units_medicine(&hospital, 200, 50);
	add_units_medicine(&hospital, 300, 160);
	add_units_medicine(&hospital, 150, 10);
	add_units_medicine(&hospital, 200, 20);

	// Finally, print pharmacy data
	print_pharmacy(&hospital);

	return 0;
}


/* Set up a hospital.
 * Patients, Pharmacy and Admissions must be created on empty state.
 * @hospital: a tHospital struct
 * */
void init_hospital(tHospital *hospital) {
	/* Check PRE conditions */
	assert(hospital != NULL);
	
	// Init patients
	hospital->patients.table = NULL;
	hospital->patients.size = 0;
	
	// Init pharmacy
	hospital->pharmacy.table = NULL;
	hospital->pharmacy.size = 0;
	
	// Init admissions
	hospital->admissions.size = 0;
}

/* Add a new medicine to the pharmacy.
 * The medicine's identification must be unique.
 * Otherwise, show an error message.
 * 
 * @hospital: a tHospital struct
 * @id: medicine identification (unsigned int)
 * @name: medicine name (string)
 * @laboratory: laboratory name (string)
 * */
void new_medicine(tHospital *hospital, unsigned int id, char name[MAX_STRING],  char laboratory[MAX_STRING]) {
	/* Check PRE conditions */
	assert(hospital != NULL);
	assert(id >= 0);
	
	unsigned int searchIndex = 0;
	tBoolean medicineFounded = FALSE;
	
	// Update dinamic memory
	if(hospital->pharmacy.size == 0) {
		hospital->pharmacy.table = (tMedicine*)malloc(sizeof(tMedicine));
	} else {
		hospital->pharmacy.table = (tMedicine*)realloc(hospital->pharmacy.table, (hospital->pharmacy.size + 1) * sizeof(tMedicine));
	}
	
	// Check memory error
	if(hospital->pharmacy.table == NULL) {
		printf("Memory error on pharmacy table");
	}

	// Check if already exist a medicine with the same id on pharmacy table	
	while (searchIndex <= hospital->pharmacy.size && medicineFounded == FALSE) {
		// Search on table
		if (hospital->pharmacy.table[searchIndex].id == id) {
			// Cancel search, because there is a match
			medicineFounded = TRUE;
		}
		
		// If there is not a match yet, update search index
		searchIndex++;
	}
	
	if (medicineFounded) {
		// Show an error message
		printf("ERROR: Medicine with code %u already stored \n", id);
	} else {
		// Only must adds a new medicine when it was not found yet on pharmacy
		tMedicine medicine;
		unsigned int availableIndex = hospital->pharmacy.size;
		
		// Creates a medicine struct and fills it with received data
		medicine.units = 0;
		medicine.id = id;
		strcpy(medicine.name, name);
		strcpy(medicine.laboratory, laboratory);
		
		// Add medicine to pharmacy
		hospital->pharmacy.table[availableIndex] = medicine;
		hospital->pharmacy.size++;
	}
}

/* Add units to a medicine.
 * The medicine must be exist on pharmacy.
 * Otherwise, show an error message.
 * 
 * @hospital: a tHospital struct
 * @id: medicine identification (unsigned int)
 * @units: number of units (unsigned int)
 * */
void add_units_medicine(tHospital *hospital, unsigned int id, unsigned int units) {
	/* Check PRE conditions */
	assert(hospital != NULL);
	assert(id >= 0);

	int searchIndex = 0;
	int medicineIndex = -1;
	tBoolean medicineFounded = FALSE;
	
	// Get the index of this medicine on pharmacy table
	while (searchIndex <= hospital->pharmacy.size && medicineFounded == FALSE) {

		// Check if both ids are equals
		if (hospital->pharmacy.table[searchIndex].id == id) {
			// update medicine index
			medicineIndex = searchIndex;
			
			// updated medicine founded flag
			// this allow us to exit of search on the next iteration
			medicineFounded = TRUE;
		}
		
		// Update search index
		searchIndex++;
	}
	
	if (medicineIndex == -1) {
		// Show an error message
		printf("ERROR: Medicine %u is not stored in the pharmacy \n", id);
	} else {
		// Only update units when medicine identification received is valid
		hospital->pharmacy.table[medicineIndex].units += units;
	}
}


/* Print all the medicines that exist on hospital's pharmacy
 * @hospital: a tHospital struct
 * */
void print_pharmacy(tHospital *hospital) {
	/* Check PRE conditions */
	assert(hospital != NULL);

	unsigned int i;
	unsigned int id;
	unsigned int units;
	char name[MAX_STRING];
	char laboratory[MAX_STRING];

	/* Print a medicine by line */
	for(i = 0; i < hospital->pharmacy.size; i++) {
		id = hospital->pharmacy.table[i].id;
		strcpy(name, hospital->pharmacy.table[i].name);
		strcpy(laboratory, hospital->pharmacy.table[i].laboratory);
		units = hospital->pharmacy.table[i].units;

		printf("Code: %u \t Name: %s (%s) \t Units: %u \n", id, name, laboratory, units);
	}
}
