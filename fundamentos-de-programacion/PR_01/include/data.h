/* This code ensures that this file is included only once */
#ifndef __DATA_H
#define __DATA_H
/* If the constant DATA_H is not defined (ifndef), the code is added, otherwise, this code is excluded. 
 * When the code is added, the constant is defined, 
 * therefore next time this file will be included it will be defined and no inclusion will be done.
 * */

#define MAX_PATHNAME 256
#define MAX_LINE 512
#define MAX_SECTIONS 10
#define MAX_SECTION_NAME 100
#define MAX_BOOKS 300
#define MAX_SUB 10
#define MAX_BOOK_AUTHOR_CODE 4
#define MAX_ISBN_CODE 14
#define MAX_BOOK_TITLE 100

/* Definition of a boolean type */
typedef enum {FALSE, TRUE} tBoolean;

/* Definition of the error type. */
typedef enum {OK=1, ERROR=0, ERR_CANNOT_READ=-1, ERR_CANNOT_WRITE=-2, ERR_MEMORY=-3, ERR_DUPLICATED_ENTRY=-4, ERR_INVALID_DATA=-5, ERR_ENTRY_NOT_FOUND=-6} tError;

/* Definition of a location */
typedef struct {
    char row;
    char column;
    char shelf;
} tLocation;

/* Definition of a section */
typedef struct {
    char id;
    char name[MAX_SECTION_NAME];
    tLocation init;
} tSection;

/* Definition of a classification */
typedef struct {
    char section;
    char subSection;
} tClassification;

/* Table of sections */
typedef struct {
	tSection table[MAX_SECTIONS];
	unsigned int size;
} tSectionTable;

/******************** PR1 - EX 2A ********************/
/* Definition of the book */
typedef struct {
	char isbn[MAX_ISBN_CODE];
	unsigned short int publicationYear;
	tBoolean isAvailable;
	tClassification classification;
	char authorCode[MAX_BOOK_AUTHOR_CODE];
	char title[MAX_BOOK_TITLE];
} tBook;

/* Table of books */
typedef struct {
	tBook table[MAX_BOOKS];
	unsigned int size;
} tBookTable;


/* Definition of the application data structure */
typedef struct {
	/* Path where data will be stored */
	char path[MAX_PATHNAME];
	
	/* sections table */
	tSectionTable sections;
	
	/* Books table */
	tBookTable books;
	
} tAppData;

#endif /*__DATA_H*/