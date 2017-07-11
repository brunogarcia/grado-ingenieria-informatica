#include <stdio.h>
#include "menu.h"
#include "sections.h"
#include "books.h"
#include "info.h"

tError readBook(tBook *book);

int getOption(int numOptions) {
	int option=0;
	
	while(option<1 || option>numOptions) {
		/* Read the input */
		printf(">> ");
		scanf("%u", &option);
		getchar();
		
		/* Check the user input */
		if(option<1 || option>numOptions) {
			printf("Incorrect option.\n");
		}
	}
	 return option;
}

tError readBook(tBook *book) {	

	tError retVal = OK;
	unsigned short int tmpAvail;

	/* Request information from user */
	printf("ISBN (13 digits):\n>> ");
	scanf("%s",book->ISBN);
 
	printf("Publication year:\n>> ");
	scanf("%hu",&(book->year));
	getchar();
	
	printf("Is it available?:\n(1 yes, 0 no) >> ");
	scanf("%hu",&tmpAvail);
	book->avail = (tmpAvail==1);
	getchar();
 
	printf("Section (1 digit):\n>> ");
	scanf("%c",&(book->clas.secId));
	getchar();
	
	printf("Subsection (1 digit):\n>> ");
	scanf("%c",&(book->clas.subId));
	getchar();
	   
    printf("Author code (3 char):\n>> ");
	scanf("%s",book->author);

    printf("Title (no whitespaces):\n>> ");
	scanf("%s",book->title);

	return retVal;
}

tError readSection(tSection *section) {	

	tError retVal = OK;
		
	printf("Section ID:\n>> ");
	scanf("%c", &section->id);
	getchar();
	
	printf("Name:\n>> ");
	scanf("%s", section->name);
	getchar();
	
	return retVal;
}

void printSectionsTable(tSectionTable table) {
	int i;	
	char secStr[MAX_LINE];
	
	if(table.size==0) {
		printf("No sections.\n");
	} else {
		for(i=0;i<table.size;i++) {
			getSectionStr(table.table[i], MAX_LINE, secStr);
			printf("[%d] - %s\n", i+1, secStr);
		}		
	}
}

void printBookTable(tBookTable table) {
	int i;	
	char bookStr[MAX_LINE];
	
	if(table.size==0) {
		printf("No books.\n");
	} else {
		for(i=0;i<table.size;i++) {
			getBookStr(table.table[i], MAX_LINE, bookStr);
			printf("[%d] - %s\n", i+1, bookStr);
		}		
	}
}


/*****************
 **   MAIN MENU **
*****************/
void printMainMenuOptions() {
	/* Show menu options */
	printf("=======================\n");
	printf(" Main Menu \n");
	printf("=======================\n");
	printf("1) Load data from file\n");
	printf("2) Save data to file\n");
	printf("3) Manage books\n");
	printf("4) Manage sections\n");
	printf("5) View statistics\n");
	printf("6) Exit\n");	
}

tMainMenuOptions getMainMenuOption() {
	/* Convert to the correct type */
	return (tMainMenuOptions)(getOption(6)-1);
}

void mainMenu(tAppData *appData) 
{
	tMainMenuOptions option;
		
	/* Assign the data path */
	appData_setPath(appData,"../");
		
	/* Start the menu */
	do {
		/* Show list of options and ask the user for an option */
		printMainMenuOptions();
		option=getMainMenuOption();
		
		/* Do the action for the given option */
		switch(option) {
		case MAIN_MENU_LOAD:
			if(appData_load(appData)==OK) {
				printf("Data loaded\n");
			} else {	
				printf("No previous data loaded\n");
			}
			break;
		case MAIN_MENU_SAVE:
			if(appData_save(*appData)==OK) {
				printf("Data saved\n");
			} else {	
				printf("Cannot save the data\n");
			}
			break;
		case MAIN_MENU_BOOKS:
			bookMenu(appData);
			break;
		case MAIN_MENU_SECTIONS:
			secMenu(appData);
			break;
		case MAIN_MENU_STATS:
			statsMenu(*appData);
			break;		
		case MAIN_MENU_EXIT:
			break;
		}	
	} while(option!=MAIN_MENU_EXIT);
}

/*********************************
 **   BOOKS MANAGEMENT MENU **
*********************************/
void printBookMenuOptions() {
	/* Show menu options */
	printf("=======================\n");
	printf(" Manage Books\n");
	printf("=======================\n");
	printf("1) List books\n");	
	printf("2) Add book\n");
	printf("3) Delete book\n");	
	printf("4) Sort books\n");	
	printf("5) Exit\n");	
}

tBookMenuOptions getBooksMenuOption() {
	/* Convert to the correct type */
	return (tBookMenuOptions)(getOption(5)-1);
}

void bookMenu(tAppData *appData) {
	tBookMenuOptions option;
	tBook newBook;
	tBookTable bookTable;
	tBookTable sortedTable;
	char bookStr[MAX_LINE];
	int pos=0;
			
	/* Start the menu */
	do {
		/* Show list of options and ask the user for an option */
		printBookMenuOptions();
		option=getBooksMenuOption();
		
		/* Do the action for the given option */
		switch(option) {
		case BOOK_MENU_LIST:
			/* Get the books between two dates*/
			
			if(getBooks(*appData, &bookTable)==OK) {			
				/* Print the books */			
				printBookTable(bookTable);				
			}
			break;
		case BOOK_MENU_ADD:
			printf("Enter the information for the new book:\n");
			if(readBook(&newBook)==OK) {
				addBook(appData, newBook);
			}
			getBookStr(newBook, MAX_LINE, bookStr);
			printf("Book added: %s\n", bookStr);
			break;
		case BOOK_MENU_DEL:
			if(getBooks(*appData, &bookTable)==OK) {			
				/* Print the books */			
				printBookTable(bookTable);				
				/* Ask the number of the register to be removed */
				pos=getOption(bookTable.size);
				/* Remove the selected book */				
				removeBook(appData, bookTable.table[pos-1]);
			}
			break;		
		case BOOK_MENU_SORT:
			if(getBooks(*appData, &bookTable)==OK) {			
				/* Print the books */			
				bookTable_sort(bookTable,&sortedTable);
				printBookTable(sortedTable);				
			}
			break;
		case BOOK_MENU_EXIT:
			break;
		}	
	} while(option!=BOOK_MENU_EXIT);
}

/********************************
 **   SECTION MANAGEMENT MENU **
********************************/
void printSectionMenuOptions() {
	/* Show menu options */
	printf("=======================\n");
	printf(" Manage sections\n");
	printf("=======================\n");
	printf("1) List sections\n");	
	printf("2) Add section\n");
    printf("3) Section info\n");
	printf("4) Exit\n");	
}

tSectionMenuOptions getSectionMenuOption() {
	/* Convert to the correct type */
	return (tSectionMenuOptions)(getOption(4)-1);
}

void secMenu(tAppData *appData) {
	tSectionMenuOptions option;
	tSectionTable sections;
	tSection newSection;
    tSectionInfo secInfo;
    tBookTable books;
	tError retVal = OK;
			
	/* Start the menu */
	do {
		/* Show list of options and ask the user for an option */
		printSectionMenuOptions();
		option=getSectionMenuOption();
		
		/* Do the action for the given option */
		switch(option) {
		case SEC_MENU_LIST:
			getSections(*appData, &sections);
			printSectionsTable(sections);
			break;
		case SEC_MENU_ADD:
			if(readSection(&newSection)==OK) {
				retVal=addSection(appData, newSection);
				if(retVal==ERR_DUPLICATED_ENTRY) {
					printf("ERROR: A section with the same ID already exists\n");
				}
			}			
			break;
		case SEC_MENU_INFO:
			getBooks(*appData, &books);
			getSections(*appData, &sections);
            printf("Section Id:\n>> ");
            scanf("%c", &newSection.id);
            getchar();
            retVal=si_getSectionInfo(books, sections, newSection.id, &secInfo); 
             if(retVal==ERR_INVALID_DATA) {
                printf("ERROR: Invalid section.\n");
            } else if(retVal==ERR_ENTRY_NOT_FOUND) {
                printf("ERROR: No books in this section.\n");
            } else {
				si_listSectionInfo(books, secInfo);
			}
			break;
		case SEC_MENU_EXIT:
			break;
		}	
	} while(option!=SEC_MENU_EXIT);	
}


/******************
 **   STATS MENU **
******************/
void printStatsMenuOptions() {
	/* Show menu options */
	printf("=======================\n");
	printf(" Stats \n");
	printf("=======================\n");
	printf("1) Get number of books on loan \n");	
	printf("2) Get number of books from an author\n");	
	printf("3) Get number of books in a section\n");	
	printf("4) Exit\n");	
}


tStatsMenuOptions getStatusMenuOption() {
	/* Convert to the correct type */
	return (tStatsMenuOptions)(getOption(4)-1);
}

void statsMenu(tAppData appData) {
	tStatsMenuOptions option;
	tBookTable bookTable;
	tBookTable bookTableFilt;
	char author[MAX_BOOK_AUTHOR_CODE];
    char sectionId;
	
	/* Start the menu */
	do {
		/* Show list of options and ask the user for an option */
		printStatsMenuOptions();
		option=getStatusMenuOption();
		
		getBooks(appData, &bookTable);

		/* Do the action for the given option */
		switch(option) {
        case STAT_MENU_ON_LOAN:
			printf("Number of books on loan: %d\n", bookTable_getOnLoanNumber(bookTable));
			break;
		case STAT_MENU_AUTHOR:
			printf("Introduce author key:\n >> ");
			scanf("%s",author);
			printf("Number of books from %s: %d\n", author, bookTable_getAuthorNumber(bookTable, author));
			break;
		case STAT_MENU_SECTION:
			printf("Introduce section ID:\n >> ");
			scanf("%c",&sectionId);
            bookTable_filterBySection(bookTable,sectionId,&bookTableFilt);
			printf("Number of books in %c: %d\n", sectionId, bookTableFilt.size);
			break;
		case STAT_MENU_EXIT:
			break;	
		}	
	} while(option!=STAT_MENU_EXIT);	
}
