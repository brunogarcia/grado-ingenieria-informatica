#include "data.h"

/* Get a textual representation of a book */
void getBookStr(tBook book, int maxSize, char *str);
	
/* Get a book object from its textual representation */
tError getBookObject(const char *str, tBook *book);

/* Compare two books by author name*/
int book_cmp(tBook t1, tBook t2);

/* Copy the book data in src to dst*/
void book_cpy(tBook *dst, tBook src);

/* Initialize the table of books */
void bookTable_init(tBookTable *bookTable);

/* Add a new book to the table of books */
tError bookTable_add(tBookTable *table, tBook book);

/* Find a book in the table */
int bookTable_find(tBookTable table, char *ISBN);

/* Remove the first occurence of a book in the table */
void bookTable_del(tBookTable *table, tBook book);

/* Load the table of books from a file */
tError bookTable_load(tBookTable *table, const char* filename);

/* Save a table of books to a file */
tError bookTable_save(tBookTable table, const char* filename);

void bookTable_filterBySection(tBookTable tabBook, char sectionID, tBookTable *result);

unsigned int bookTable_getOnLoanNumber(tBookTable tabBook);

unsigned int bookTable_getAuthorNumber(tBookTable tabBook, char *author);

tError bookTable_sortedAdd(tBookTable *tabBook, tBook book);

void bookTable_sort(tBookTable tabBook, tBookTable *result);

/* Release a books table */
void bookTable_release(tBookTable *table); 
