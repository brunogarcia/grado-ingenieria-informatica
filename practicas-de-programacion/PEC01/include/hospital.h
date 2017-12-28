#define MAX_DOSES 20
#define MAX_STRING 256
#define MAX_HOSPITAL_BEDS 200

typedef enum {FALSE, TRUE} tBoolean;

typedef struct {
	unsigned char day;
	unsigned char month;
	unsigned short year;
} tDate;

typedef struct {
	unsigned int id;
	char name[MAX_STRING];
	unsigned char age;
} tPatient;

typedef struct {
	tPatient* table;
	unsigned int size;
} tPatients;

typedef struct {
	unsigned int idMedicine;
	unsigned int units;
	unsigned char frequency;
} tDose;

typedef struct {
	tDose doses[MAX_DOSES];
	unsigned int size;
} tTreatment;

typedef struct {
	tDate date;
	unsigned char room;
	unsigned int idPatient;
	tTreatment treatment;
} tAdmission;

typedef struct {
	tAdmission table[MAX_HOSPITAL_BEDS];
	unsigned int size;
} tAdmissions;

typedef struct {
	unsigned int id;
	unsigned int units;
	char name[MAX_STRING];
	char laboratory[MAX_STRING];
} tMedicine;

typedef struct {
	tMedicine* table;
	unsigned int size;
} tPharmacy;

typedef struct {
	tPatients patients;
	tPharmacy pharmacy;
	tAdmissions admissions;
} tHospital;

/* Set up a Hospital
 * Patients, Pharmacy and Admissions must be created on empty state.
 * */
void init_hospital(tHospital *hospital);

/* Add a new medicine to the pharmacy.
 * The medicine's identification must be unique.
 * Otherwise, show an error message.
 * 
 * @hospital: a tHospital struct
 * @id: medicine identification (unsigned int)
 * @name: medicine name (string)
 * @laboratory: laboratory name (string)
 * */
void new_medicine(tHospital *hospital, unsigned int id, char name[MAX_STRING],  char laboratory[MAX_STRING]);

/* Add units to a medicine.
 * The medicine must be exist on pharmacy.
 * Otherwise, show an error message.
 * 
 * @hospital: a tHospital struct
 * @id: medicine identification (unsigned int)
 * @units: number of units (unsigned int)
 * */
void add_units_medicine(tHospital *hospital, unsigned int id, unsigned int units);

/* Print all the medicines that exist on hospital's pharmacy
 * @hospital: a tHospital struct
 * */
void print_pharmacy(tHospital *hospital);