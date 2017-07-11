#include "data.h"

/* 
 * Methods for application data management 
 */

/* Initialize the application data */
void appData_init(tAppData *object);

/* Load the application data from file */
tError appData_load(tAppData *object);

/* Save the application data to a file */
tError appData_save(tAppData object);

/* Allow to assign a path to the application data */
void appData_setPath(tAppData *object, const char *path);

/* 
 * API
 */

/* Return a table with the books */
tError getBooks(tAppData object, tBookTable *result);

/* Get the section information */
tError getBook(tAppData object, char *ISBN, tBook *book);

/* Add a new book */
tError addBook(tAppData *object, tBook book);

/* Remove a certain book */
tError removeBook(tAppData *object, tBook book);

/* Return the table of sections */
tError getSections(tAppData object, tSectionTable *result);

/* Get the section information */
tError getSection(tAppData object, char C1, tSection *section);

/* Add a new section */
tError addSection(tAppData *object, tSection section);