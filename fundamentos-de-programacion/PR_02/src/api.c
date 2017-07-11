#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <api.h>
#include "books.h"
#include "sections.h"

void appData_init(tAppData *object) {
	/* Set parent folder as the default path */
	strcpy(object->path, "../");
	
	/* Initialize the books table */
	bookTable_init(&(object->books));
	
	/* Initialize the sections table */
	secTable_init(&(object->sections));

}

tError appData_load(tAppData *object) {
	char path[MAX_LINE];
	tError retVal = OK;
		
	/* Load the table of sections */
	sprintf(path,"%ssections.txt", object->path);
	retVal=secTable_load(&(object->sections), path);
	if(retVal!=OK) {
		printf("ERROR: Error reading the file of sections\n");
	}

	/* Load the table of books */
	sprintf(path,"%sbooks.txt", object->path);
	retVal=bookTable_load(&(object->books), path);
	if(retVal!=OK) {
		printf("ERROR: Error reading the file of books\n");
	}
	
	return retVal;
}

tError appData_save(tAppData object)  {
	char path[MAX_LINE];
	tError retVal = OK;
	
	/* Save the table of sections */
	sprintf(path,"%ssections.txt", object.path);
	retVal=secTable_save(object.sections, path);
	if(retVal!=OK) {
		printf("ERROR: Error saving the file of sections\n");
	}
	
	/* Save the table of books */
	sprintf(path,"%sbooks.txt", object.path);
	retVal=bookTable_save(object.books, path);
	if(retVal!=OK) {
		printf("ERROR: Error saving the file of books\n");
	}
	
	return retVal;
}

void appData_setPath(tAppData *object, const char *path)  {		
	strncpy(object->path, path, 255);	
}


/*********************** 
 *        API
 **********************/
tError getSections(tAppData object, tSectionTable *result) {
	tError retVal = OK;
	*result = object.sections;	
	return retVal;
}

tError getSection(tAppData object, char sectionId, tSection *section) {
	
	tError retVal = OK;
	tBoolean found;
	int i;
	
	found = FALSE;
	/* Check if there is another section with this ID */
	for(i=0; i<object.sections.size; i++) {
		if(object.sections.table[i].id==sectionId) {
			section_cpy(section,object.sections.table[i]);
		}
	}
	if (!found) retVal = ERR_ENTRY_NOT_FOUND;
	
	return retVal;
}

tError addSection(tAppData *object, tSection section) {
	tError retVal = OK;
	tSection tmp;
	
	/* Check if there is another section with this ID */
	if(getSection(*object, section.id, &tmp)==OK) {
		retVal = ERR_DUPLICATED_ENTRY;
	} else {
		/* Add the new section using the section table method */
		retVal =secTable_add(&(object->sections), section);
	}
	return retVal;
}

tError getBooks(tAppData object, tBookTable *result) {
	tError retVal = OK;
	*result = object.books;	
	return retVal;
}

tError getBook(tAppData object, char *ISBN, tBook *book) {
	
	int i;
	tError retVal = OK;
	
	/* Check if there is a book with this ISBN */
	i = bookTable_find(object.books, ISBN);
	if (i!=-1) {
		book_cpy(book,object.books.table[i]);
	} else {
		retVal = ERR_ENTRY_NOT_FOUND;
	}
	
	return retVal;
}


tError addBook(tAppData *object, tBook book) {
	tError retVal = OK;
	
	/* Add the new book using the book table method */
	retVal=bookTable_add(&(object->books), book);	
	
	return retVal;
}

tError removeBook(tAppData *object, tBook book) {
	/* Call the method from the book table*/
	bookTable_del(&(object->books), book);
	return OK;
}

/* Release the allocated memory */
void appData_release (tAppData *object) {
#ifdef COMPLETE_VERSION
/******************** PR2 - EX6F ********************/
	if(object->books.table != NULL) {
		object->books.size = 0;
		free(object->books.table);
		object->books.table = NULL;
	}
#endif
}