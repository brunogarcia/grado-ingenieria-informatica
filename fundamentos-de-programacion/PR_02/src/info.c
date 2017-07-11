#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "info.h"
#include "books.h"
#include "sections.h"

tBoolean si_search_subsection(tSectionInfo *si, char subSectionId) {
	int j = 0;
	int previousIdx = -1;
	tBoolean found = FALSE;

	// There is any subsection equal to subSectionId param?
	// And this subsection has at least one book?
	while ((j < si->totSecSubs) & (found == FALSE)) {
		if (si->secSubs[j].id == subSectionId && si->secSubs[j].totSubBooks > 0) {
			// Save the current index
			previousIdx = j;
			// And cancel search, because there is a match
			found = TRUE;
		}
		
		// Keep looking
		j++;
	}
	
	return previousIdx;
}

void si_add_subsection(tSectionInfo *si, char subSectionId, int bookPosition) {
	// Because the subsections could have more than one book
	// We must search into sub-sections table
	int previousIdx = si_search_subsection(si, subSectionId);

	
	#ifdef SIMPLE_VERSION
	/******************** PR2 - EX3A ********************/
	// A) If exist the current subsection into subsections table
	if (previousIdx != -1) {
		// Save a new book position into the index that corresponds it
		si->secSubs[previousIdx].subBooks[si->secSubs[previousIdx].totSubBooks] = bookPosition;
		
		// Increase total books of THIS subsecction
		si->secSubs[previousIdx].totSubBooks++;
	} else {
		// B) Otherwise create a new sub-section
		
		// Init total books in this sub-secction
		si->secSubs[si->totSecSubs].totSubBooks = 0;
		
		// Save sub-section id
		si->secSubs[si->totSecSubs].id = subSectionId;
		
		// Save book position
		si->secSubs[si->totSecSubs].subBooks[si->secSubs[si->totSecSubs].totSubBooks] = bookPosition;
		
		// Increase total books of THIS sub-secction
		si->secSubs[si->totSecSubs].totSubBooks++;

		// Increase total of sub-sections
		si->totSecSubs++;
	}
	#endif

	#ifdef COMPLETE_VERSION
	/******************** PR2 - EX6A ********************/
	// A) If exist the current subsection into subsections table
	if (previousIdx != -1) {
		// Update dinamic memory
		si->secSubs[previousIdx].subBooks = (int*)realloc(si->secSubs[previousIdx].subBooks, (si->secSubs[previousIdx].totSubBooks + 1) * sizeof(int));
		
		// Save a new book position into the index that corresponds it
		si->secSubs[previousIdx].subBooks[si->secSubs[previousIdx].totSubBooks] = bookPosition;
		
		// Increase total books of THIS subsecction
		si->secSubs[previousIdx].totSubBooks++;
	} else {
		// B) Otherwise create a new sub-section
		
		// Init dinamic memory
		si->secSubs[si->totSecSubs].subBooks = (int*)malloc(sizeof(int));

		// Init total books in this sub-secction
		si->secSubs[si->totSecSubs].totSubBooks = 0;
		
		// Save sub-section id
		si->secSubs[si->totSecSubs].id = subSectionId;
		
		// Save book position
		si->secSubs[si->totSecSubs].subBooks[si->secSubs[si->totSecSubs].totSubBooks] = bookPosition;
		
		// Increase total books of THIS sub-secction
		si->secSubs[si->totSecSubs].totSubBooks++;

		// Increase total of sub-sections
		si->totSecSubs++;
	}
	#endif
	
	// C) In any case, increase total of books
	si->totSecBooks++;
	
}

/******************** PR2 - EX3A ********************/
tError si_getSectionInfo(tBookTable tabB, tSectionTable tabS, char sectionId, tSectionInfo *si ){
	int i;
	int idxSection;
	int bookPosition;
	char bookSectionId;
	char bookSubSectionId;
	tError retVal = OK;
	tSection searchSection;

	// Get section index from sections table
	idxSection = secTable_find(tabS, sectionId);

	// A) If section exists: create a section info table
	if (idxSection != -1) {
		// A1) Set section data into section info table
		searchSection = tabS.table[idxSection];
		si->section = searchSection;
		
		// A2) Init totals of tSectionInfo
		si->totSecSubs = 0;
		si->totSecBooks = 0;
		 
		// A3) Iterate over each book into books table
		for(i = 0; i < tabB.size; i++) {
			
			// Save book 'position', 'section id','sub-section id'
			bookPosition = i;
			bookSectionId = tabB.table[bookPosition].clas.secId;
			bookSubSectionId = tabB.table[bookPosition].clas.subId;
			
			// A4) We only must search for books which sections be the same that searched section
			if (sectionId == bookSectionId) {
				// A5) Add subsection
				si_add_subsection(si, bookSubSectionId, bookPosition);
			}
		}

		// A6) If finally there is not any book in this section, show an error
		if (si->totSecBooks == 0) {
			retVal = ERR_ENTRY_NOT_FOUND;
		}
		
	} else {
		// B) If the section does not exist in sections table, show an error
		retVal = ERR_INVALID_DATA;
	}

	return retVal;
}

/******************** PR2 - EX3B ********************/
tBook si_getBook(tBookTable tabB, tSectionInfo si, unsigned int nSub, unsigned int nBook) {
	tBook book;
	int idxBook;
	
	#ifdef SIMPLE_VERSION
	
	// Get book position stored in section info table
	// based on nSub and nBook
	idxBook = si.secSubs[nSub].subBooks[nBook];
	
	// Get book from books table
	book = tabB.table[idxBook];
	
	#endif
	#ifdef COMPLETE_VERSION
/******************** PR2 - EX6A ********************/
	// Get book position stored in section info table
	// based on nSub and nBook
	idxBook = si.secSubs[nSub].subBooks[nBook];
	
	// Get book from books table
	book = tabB.table[idxBook];
	#endif	

	return book;
}

/******************** PR2 - EX3C ********************/
void si_listSectionInfo(tBookTable tabB, tSectionInfo si){
	unsigned int nSub;
	unsigned int nBook;
	char sectionIdName[MAX_LINE];
	char bookInformation[MAX_LINE];
	tBook book;

	#ifdef SIMPLE_VERSION
	// ### Section ### 
	printf(" ------------------ \n");
	
	// Section: id and name 
	getSectionStr(si.section, MAX_LINE, sectionIdName);
	printf("Section: %s \n", sectionIdName);
	
	// Section: total sub-sections
	printf("Total of sub-sections: %u \n", si.totSecSubs);
	
	// Section: total books
	printf("Total of books: %u \n", si.totSecBooks);
	
	// ### Sub-Sections ### 
	for (nSub = 0; nSub < si.totSecSubs; nSub++) {
		
	printf(" ------------------ \n");
		
		// Sub-Section: id
		printf("[%d] Sub-Section Id: %c \n", nSub, si.secSubs[nSub].id);
		
		// Sub-Section: total books
		printf("Total books: %u \n", si.secSubs[nSub].totSubBooks);
		
		// ### Books ###
		printf(" ------------------ \n");
		
		for (nBook = 0; nBook < si.secSubs[nSub].totSubBooks; nBook++) {
			// Get book 
			book = si_getBook(tabB, si, nSub, nBook);
			
			// Format book information
			getBookStr(book, MAX_LINE, bookInformation);
			
			// Print book information
			printf("[%d] %s \n", nBook, bookInformation);
		}
	}
	#endif
	#ifdef COMPLETE_VERSION	
	/******************** PR2 - EX6A ********************/
	// ### Section ### 
	printf(" ------------------ \n");
	
	// Section: id and name 
	getSectionStr(si.section, MAX_LINE, sectionIdName);
	printf("Section: %s \n", sectionIdName);
	
	// Section: total sub-sections
	printf("Total of sub-sections: %u \n", si.totSecSubs);
	
	// Section: total books
	printf("Total of books: %u \n", si.totSecBooks);
	
	// ### Sub-Sections ### 
	for (nSub = 0; nSub < si.totSecSubs; nSub++) {
		
	printf(" ------------------ \n");
		
		// Sub-Section: id
		printf("[%d] Sub-Section Id: %c \n", nSub, si.secSubs[nSub].id);
		
		// Sub-Section: total books
		printf("Total books: %u \n", si.secSubs[nSub].totSubBooks);
		
		// ### Books ###
		printf(" ------------------ \n");
		
		for (nBook = 0; nBook < si.secSubs[nSub].totSubBooks; nBook++) {
			// Get book 
			book = si_getBook(tabB, si, nSub, nBook);
			
			// Format book information
			getBookStr(book, MAX_LINE, bookInformation);
			
			// Print book information
			printf("[%d] %s \n", nBook, bookInformation);
		}
	}
	#endif
	
}