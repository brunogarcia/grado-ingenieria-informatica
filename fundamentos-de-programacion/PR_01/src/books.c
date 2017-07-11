#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"


/******************** PR1 - EX 2C ********************/
void getBookStr(tBook book, int maxSize, char *str) {
	int length;

	length = snprintf(str, maxSize-1, "%s %hu %hu %c %c %s %s", book.isbn, book.publicationYear, book.isAvailable, book.classification.section, book.classification.subSection, book.authorCode, book.title);

	str[length] = '\0';
}


/******************** PR1 - EX 2D ********************/
tError getBookObject(const char *str, tBook *book) {

	tError retVal = OK;
	
	sscanf(str, "%s %hu %hu %c %c %s %s", book->isbn, &book->publicationYear, &book->isAvailable, &book->classification.section, &book->classification.subSection, book->authorCode, book->title);
	
	return retVal;
}


void bookTable_init(tBookTable *bookTable) {
	
	bookTable->size = 0;

}

/******************** PR1 - EX 3A ********************/
int book_cmp(tBook b1, tBook b2) {

	int retVal = 0;

	// Compare by section
	if (b1.classification.section > b2.classification.section) {
		retVal = 1;
	} else if (b1.classification.section < b2.classification.section) {
		retVal = -1;
	}

	// If they're still equals, compare by sub section
	if (retVal == 0) {
		if (b1.classification.subSection > b2.classification.subSection) {
			retVal = 1;
		} else if (b1.classification.subSection < b2.classification.subSection) {
			retVal = -1;
		}
	}

	// If they're still equals, compare by author code
	if (retVal == 0) {
		retVal = strcmp(b1.authorCode, b2.authorCode);
	}

	// If they're still equals, compare by title
	if (retVal == 0) {
		retVal = strcmp(b1.title, b2.title);
	}

	// If they're still equals, compare by isbn
	if (retVal == 0) {
		retVal = strcmp(b1.isbn, b2.isbn);
	}

	return retVal;
}

/******************** PR1 - EX 3B ********************/
void book_cpy(tBook *dst, tBook src) {

	// Copy isbn
	strcpy(dst->isbn, src.isbn);

	// Copy publication year
	dst->publicationYear = src.publicationYear;

	// Copy availability
	dst->isAvailable = src.isAvailable;

	// Copy section
	dst->classification.section = src.classification.section;

	// Copy sub section
	dst->classification.subSection = src.classification.subSection;

	// Copy author code
	strcpy(dst->authorCode, src.authorCode);
	
	// Copy title
	strcpy(dst->title, src.title);
}

/******************** PR1 - EX 4A ********************/
tError bookTable_add(tBookTable *tabBook, tBook book) {

	tError retVal = OK;
	
	/* Check if there enough space for the new book */
	if(tabBook->size >= MAX_BOOKS) {
		retVal = ERR_MEMORY;
	}

	if (retVal == OK) {
		/* Add the new book to the end of the table */
		book_cpy(&tabBook->table[tabBook->size], book);
		
		/* Update size of tabBook */
		tabBook->size++;
	}
	
	return retVal;
}

/******************** PR1 - EX 4B ********************/
int bookTable_find(tBookTable tabBook, char *ISBN) {

	unsigned int i = 0;
	int idx = -1;
	
	while(i < tabBook.size && idx == -1) {
		// Check if the isbn is the same
		if(strcmp(tabBook.table[i].isbn, ISBN) == 0) {
			idx = i;
		}
		
		// Update search index
		i++;
	}
	
	return idx;
}

/******************** PR1 - EX 4C ********************/
void bookTable_del(tBookTable *tabBook, tBook book) {
	unsigned int i;
	unsigned int pos;

	pos = bookTable_find(*tabBook, book.isbn);

	if (pos != -1) {
	/* If the book is found, all the rest of the elements are displaced one position */
		for(i = pos; i < tabBook->size - 1; i++) {
			book_cpy(&tabBook->table[i], tabBook->table[i + 1]);
		}

		/* Update size of tabBook */
		tabBook->size = tabBook->size - 1;
	}
}

/******************** PR1 - EX 5A ********************/
tError bookTable_save(tBookTable tabBook, const char* filename) {

	tError retVal = OK;
	FILE *fout = 0;
	unsigned int i;
	char str[MAX_LINE];

	/* Open the output file */
	if((fout = fopen(filename, "w")) == 0) {
		retVal = ERR_CANNOT_WRITE;
	} else {
		/* Save all books to the file */
		for(i = 0; i < tabBook.size; i++) {
			getBookStr(tabBook.table[i], MAX_LINE, str);
			fprintf(fout, "%s\n", str);
		}

		/* Close the file */
		fclose(fout);
	}

	return retVal;
}

/******************** PR1 - EX 5B ********************/
tError bookTable_load(tBookTable *tabBook, const char* filename) {

	tError retVal = OK;
	FILE *fin = 0;
	char line[MAX_LINE];
	tBook newBook;

	/* Initialize the output table */
	bookTable_init(tabBook);

	/* Open the input file */
	if((fin = fopen(filename, "r")) != NULL) {

		/* Read all the sections */
		while(!feof(fin) && tabBook->size < MAX_BOOKS) {
			/* Remove any content from the line */
			line[0] = '\0';
			
			/* Read one line (maximum 511 chars) and store it in "line" variable */
			fgets(line, MAX_LINE - 1, fin);

			/* Ensure that the string is ended by 0*/
			line[MAX_LINE-1] = '\0';

			if(strlen(line) > 0) {
				/* Obtain the object */
				getBookObject(line, &newBook);

				/* Add the new book to the output table */
				bookTable_add(tabBook, newBook);
			}
		}

		/* Close the file */
		fclose(fin);

	} else {
		retVal = ERR_CANNOT_READ;
	}

	return retVal;
}

/******************** PR1 - EX 6 ********************/
void bookTable_filterBySection(tBookTable tabBook, char sectionId, tBookTable *result) {

	unsigned int i;

	// Initialize the output table
	bookTable_init(result);

	// Search in books table
	for(i = 0; i < tabBook.size; i++) {
		// Add to result table only the books that matched by section id
		if (tabBook.table[i].classification.section == sectionId) {
			bookTable_add(result, tabBook.table[i]);
		}
	}
}

/******************** PR1 - EX 7A ********************/
unsigned int bookTable_getOnLoanNumber(tBookTable tabBook){

	unsigned int i;
	int numBooks = 0;
	
	// Search in books table
	for(i = 0; i < tabBook.size; i++) {
		// If have found any book not available
		if (tabBook.table[i].isAvailable == 0) {
			// Update number of books
			numBooks++;
		}
	}

	return numBooks;
}

/******************** PR1 - EX 7B ********************/
unsigned int bookTable_getAuthorNumber(tBookTable tabBook, char *author){

	unsigned int i;
	int numBooks = 0;

	// Search in books table
	for(i = 0; i < tabBook.size; i++) {
		// If has found an author code that coincides
		if (strcmp(tabBook.table[i].authorCode, author) == 0) {
			// Update number of books
			numBooks++;
		}
	}

	return numBooks;
}
