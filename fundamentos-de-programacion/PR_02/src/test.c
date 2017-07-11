#include <stdio.h>
#include <string.h>
#include <math.h>
#include "test.h"
#include "info.h"
#include "sections.h"
#include "books.h"
#include "stack.h"
#define BOOK1 "9780201625714 1995 0 6 8 WEI Estructuras_de_datos_y_algoritmos"
#define BOOK2 "9780140816167 1996 1 8 1 WAT Test_your_vocabulary"
#define BOOK3 "9788489660007 1997 1 6 7 BRA Fundamentos_de_algoritmia"
#define SECTION1 "1 Philosophy"
#define SECTION2 "2 Religion"
#define SECTION3 "3 Social"
#define SECTION5 "5 Science"
#define SECTION6 "6 Applied"
#define SECTION7 "7 Arts"
#define SECTION8 "8 Language"
#define SECTION9 "9 History"

void runTests() {	
	int passedTestPR1, passedTestPR2;
	int totalTestPR1, totalTestPR2;
	
	printf("=================================================\n");
	printf("====       PRACTICAL ACTIVITY 1 TESTS        ====\n");
	printf("=================================================\n");	
	runTestsPR1(&totalTestPR1, &passedTestPR1);

	printf("=================================================\n");
	printf("====       PRACTICAL ACTIVITY 2 TESTS        ====\n");
	printf("=================================================\n");	
	runTestsPR2(&totalTestPR2, &passedTestPR2);
		
	printf("===================================\n");
	printf("====       TEST SUMMARY        ====\n");
	printf("===================================\n");		
	printf("\tPR1: Passed %d of %d [%0.2f%%]\n", passedTestPR1, totalTestPR1, (float)passedTestPR1/totalTestPR1*100.0);
	printf("\tPR2: Passed %d of %d [%0.2f%%]\n", passedTestPR2, totalTestPR2, (float)passedTestPR2/totalTestPR2*100.0);
	printf("\n\tTotal: Passed %d of %d [%0.2f%%]\n", passedTestPR1+passedTestPR2, totalTestPR1+totalTestPR2, (float)(passedTestPR1+passedTestPR2)/(totalTestPR1+totalTestPR2)*100.0);
	printf("===================================\n");		
}


void runTestsPR1(int *totalTest, int *passedTest) {
	*totalTest=0;
	*passedTest=0;
	
	test_cmp_cpy(totalTest, passedTest);
	test_book_tab(totalTest, passedTest);	
	test_persistence(totalTest, passedTest);
	test_search(totalTest, passedTest);
	test_count(totalTest, passedTest);
	
/*	test_api(totalTest, passedTest);*/
}

void runTestsPR2(int *totalTest, int *passedTest) {	
	*totalTest=0;
	*passedTest=0;	
	
	test_sort(totalTest, passedTest);
	test_sectionInfo(totalTest, passedTest);
	test_stack(totalTest, passedTest);
}

void test_cmp_cpy(int *totalTest, int *passedTest) {	
	tBook book1, book2;	
		
	printf("=================================================\n");
	printf(" BOOKS COMPARISON & COPY\n");
	printf("=================================================\n");
	
	printf("\nTest 3a1: Compare books. Different section:");
	(*totalTest)++;
	getBookObject(BOOK1, &book1);	
	getBookObject(BOOK2, &book2);	
	if( ( book_cmp(book1, book2) < 0 ) && ( book_cmp(book2,book1) > 0) ){
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL\n");
	}

	printf("\nTest 3a2: Compare books. Different subsection:");
	(*totalTest)++;
	getBookObject("9788448118488 1995 1 6 5 DOM Dirección_de_operaciones", &book1);	
	getBookObject("9780201625714 1995 1 6 8 WEI Estructuras_de_datos_y_algoritmos",&book2);	
	if( ( book_cmp(book1, book2) < 0 ) && ( book_cmp(book2,book1) > 0) ){
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL\n");
	}

	printf("\nTest 3a3: Compare books. Different author:");
	(*totalTest)++;
	getBookObject("9780201625714 1995 1 6 8 WEI Estructuras_de_datos_y_algoritmos",&book1);	
	getBookObject("9788489660007 1997 1 6 8 BRA Fundamentos_de_algoritmia",&book2);	
	if( ( book_cmp(book2, book1) < 0 ) && ( book_cmp(book1,book2) > 0) ){
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL\n");
	}

	printf("\nTest 3a4: Compare books. Different title:");
	(*totalTest)++;
	getBookObject("9780201625714 1995 1 6 8 BRA Programacion_basica",&book1);	
	getBookObject("9788489660007 1997 1 6 8 BRA Fundamentos_de_algoritmia",&book2);	
	if( ( book_cmp(book2, book1) < 0 ) && ( book_cmp(book1,book2) > 0) ){
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL\n");
	}

	printf("\nTest 3a5: Compare books. Different ISBN:");
	(*totalTest)++;
	getBookObject("9780201625714 1997 1 6 8 BRA Fundamentos_de_algoritmia",&book1);	
	getBookObject("9788489660007 1997 1 6 8 BRA Fundamentos_de_algoritmia",&book2);	
	if( ( book_cmp(book1, book2) < 0 ) && ( book_cmp(book2,book1) > 0) ){
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL\n");
	}
	
	printf("\nTest 3b: Copy book:");
	(*totalTest)++;
	getBookObject(BOOK1, &book1);	
	book_cpy(&book2,book1);	
	if( book_cmp(book1, book2) == 0 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL\n");
	}
}	

void test_book_tab(int *totalTest, int *passedTest) {	
	tBookTable books;
	tBook book1, book2, book3;	
	tError retVal = OK;
	int i;
		
	printf("=================================================\n");
	printf(" BOOKS TABLE MANAGEMENT\n");
	printf("=================================================\n");
	
	printf("\nTest 4a1: Initialize the table:");
	(*totalTest)++;
	bookTable_init(&books);
	if(books.size==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL\n");
	}
	
	printf("\nTest 4a2: Add a book:");
	(*totalTest)++;
	bookTable_init(&books);	
	getBookObject(BOOK1, &book1);	
	retVal=bookTable_add(&books, book1);
	if(retVal!=OK) {		
		printf("\n\t-> FAIL (unexpected return value from addSection. Expected %d and returned %d)\n", OK, retVal);
	} else {		
		if(books.size==1) {
			if(book_cmp(books.table[0], book1)==0) {
				printf("\n\t-> OK\n");			
				(*passedTest)++;
			} else {
				printf("\n\t-> FAIL (Stored data is not correct)\n");
			}
		} else {
			printf("\n\t-> FAIL (Number of registers in table is incorrect. Expected 1, and have %d)\n", books.size);
		}
	}	
			
	printf("\nTest 4a3: Pass the maximum capacity of the table:");
	(*totalTest)++;
	bookTable_init(&books);	
	for(i=0;i<=MAX_BOOKS;i++) {
		getBookObject(BOOK1, &book1);
		retVal=bookTable_add(&books, book1);
		if(i<MAX_BOOKS) {
			if(retVal!=OK) {
				printf("\n\t-> FAIL (unexpected return value from addBook adding object %d of %d. Expected %d and returned %d)\n", i+1, MAX_BOOKS, OK, retVal);
				break;
			}
		} else {
			if(retVal==ERR_MEMORY) {
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else {
				printf("\n\t-> FAIL (unexpected return value from addBook adding last object. Expected %d and returned %d)\n", ERR_MEMORY, retVal);
			} 
		}
	}		
	
	printf("\nTest 4b: Search a book with a given ID");
	(*totalTest)++;
	getBookObject(BOOK2, &book2);
    book_cpy(&(books.table[100]),book2);
	i = bookTable_find(books, "9780140816167");
	if( i == 100 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected index returned. Expected %d and returned %d)\n", MAX_BOOKS - 1, i);
	}	

	
	printf("\nTest 4c1: Delete a book from an empty table:");
	(*totalTest)++;
	bookTable_init(&books);
	getBookObject(BOOK1, &book1);	
	bookTable_del(&books, book1);
	if(books.size==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 0, books.size);
	}	
	
	printf("\nTest 4c2: Delete the first book of a table:");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	
	bookTable_del(&books,book1);
	if(books.size==2) {
		if(book_cmp(books.table[0], book2)!=0 || book_cmp(books.table[1], book3)!=0){
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	}
	
	printf("\nTest 4c3: Delete the last book of a table:");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	
	bookTable_del(&books,book3);
	if(books.size==2) {
		if(book_cmp(books.table[0], book1)!=0 || book_cmp(books.table[1], book2)!=0){
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	}
	
	printf("\nTest 4c4: Delete book in middle of a table:");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	
	bookTable_del(&books,book2);
	if(books.size==2) {
		if(book_cmp(books.table[0], book1)!=0 || book_cmp(books.table[1], book3)!=0){
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	}
	
	printf("\nTest 4c5: Delete a non existing book:");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);

	bookTable_del(&books,book3);
	if(books.size==2) {
		if(book_cmp(books.table[0], book1)!=0 || book_cmp(books.table[1], book2)!=0){
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	}
	
}

void test_persistence(int *totalTest, int *passedTest) {
	tBookTable books;
	tBook book1, book2, book3;
	
	printf("=================================================\n");
	printf(" PERSISTENCE\n");
	printf("=================================================\n");
	
	printf("\nTest 5a: Save and load no data:");
	(*totalTest)++;
	bookTable_init(&books);	
	
	bookTable_save(books, "./testBook.csv");
	bookTable_init(&books);		
	bookTable_load(&books, "./testBook.csv");
	
	if(books.size==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	}
	
	printf("\nTest 5b: Save and load books:");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);

	bookTable_save(books, "./testBook.csv");
	bookTable_init(&books);		
	bookTable_load(&books, "./testBook.csv");
	
	if(books.size==3) {
		if(book_cmp(books.table[0], book1)!=0 || 
		   book_cmp(books.table[1], book2)!=0 ||
		   book_cmp(books.table[2], book3)!=0) {
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	}
}

void test_search(int *totalTest, int *passedTest) {	
	tBookTable books, result;
	tBook book1, book2, book3;	
		
	printf("=================================================\n");
	printf(" BOOK TABLE FILTER\n");
	printf("=================================================\n");
	
	printf("\nTest 6.1: Books of a section in empty table:");
	(*totalTest)++;
	bookTable_init(&books);	
	
	bookTable_filterBySection(books, '6', &result);
	if(result.size==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 0, result.size);
	}

	printf("\nTest 6.2: Books of a section in non empty table:");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	
	bookTable_filterBySection(books, '8', &result);
	if(result.size==1) {
		if(book_cmp(result.table[0], book2)!=0) {
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, result.size);
	}
}
	
void test_count(int *totalTest, int *passedTest) {	
	tBookTable books;
	tBook book1, book2, book3;	
	int i;
		
	printf("=================================================\n");
	printf(" BOOKS STATISTICS\n");
	printf("=================================================\n");
	
	printf("\nTest 7a1: Count books on loan of empty table:");
	(*totalTest)++;
	bookTable_init(&books);	
	
	i = bookTable_getOnLoanNumber(books);
	if(i==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 0, i);
	}
	
	printf("\nTest 7a2: Count books on loan (none):");
	(*totalTest)++;
	test_initBookTable(&books,BOOK2,BOOK2,BOOK3,&book1,&book2,&book3);
	
	i = bookTable_getOnLoanNumber(books);
	if(i==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 1, i);
	}

	printf("\nTest 7a3: Count books on loan (all):");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK1,BOOK1,&book1,&book2,&book3);
	
	i = bookTable_getOnLoanNumber(books);
	if(i==3) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 1, i);
	}

	printf("\nTest 7a4: Count books on loan (some):");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	
	i = bookTable_getOnLoanNumber(books);
	if(i==1) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 1, i);
	}
	
	printf("\nTest 7b1: Count books of an author on empty table:");
	(*totalTest)++;
	bookTable_init(&books);	
	
	i = bookTable_getAuthorNumber(books, "BRA");
	if(i==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 0, i);
	}

	printf("\nTest 7b2: Count books of an author (none):");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	i = bookTable_getAuthorNumber(books,"XXX");
	if(i==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 1, i);
	}

	printf("\nTest 7b3: Count books of an author (all):");
	(*totalTest)++;
	test_initBookTable(&books,BOOK3,BOOK3,BOOK3,&book1,&book2,&book3);
	i = bookTable_getAuthorNumber(books,"BRA");
	if(i==3) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 1, i);
	}
	
	printf("\nTest 7b4: Count books of an author (some):");
	(*totalTest)++;
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	i = bookTable_getAuthorNumber(books,"BRA");
	if(i==1) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of books in the table. Expected %d and returned %d)\n", 1, i);
	}
}
	
void test_sort(int *totalTest, int *passedTest) {	
	tBookTable books, result;
	tBook book1, book2, book3;	
	unsigned int i;
	tError retVal;
		
	printf("=================================================\n");
	printf(" BOOKS SORTING\n");
	printf("=================================================\n");

	printf("\nTest 1a1: Sorted add of a book in empty table:");
	(*totalTest)++;
	bookTable_init(&books);		
	getBookObject(BOOK1,&book1);
	if(bookTable_sortedAdd(&books, book1)==OK){
		if(books.size==1) {
			if(book_cmp(books.table[0], book1)==0){
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else printf("\n\t-> FAIL (Values are not correct)\n");
		} else printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 1, books.size);
	} else printf("\n\t-> FAIL (sortedAdd error)\n");


	printf("\nTest 1a2: Sorted add of a book at the end of a table:");
	(*totalTest)++;
	bookTable_init(&books);		
	getBookObject(BOOK1,&book1);
	bookTable_add(&books, book1);
	getBookObject(BOOK2,&book2);
	if(bookTable_sortedAdd(&books, book2)==OK){
		if(books.size==2) {
			if(book_cmp(books.table[0], book1)==0 && book_cmp(books.table[1], book2)==0){
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else printf("\n\t-> FAIL (Values are not correct)\n");
		} else printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	} else printf("\n\t-> FAIL (sortedAdd error)\n");

	printf("\nTest 1a3: Sorted add of a book at the beginning of a table:");
	(*totalTest)++;
	bookTable_init(&books);		
	getBookObject(BOOK1,&book1);
	bookTable_add(&books, book1);
	getBookObject(BOOK3,&book3);
	if(bookTable_sortedAdd(&books, book3)==OK){
		if(books.size==2) {
			if(book_cmp(books.table[0], book3)==0 && book_cmp(books.table[1], book1)==0 ){
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else printf("\n\t-> FAIL (Values are not correct)\n");
		} else printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 2, books.size);
	} else printf("\n\t-> FAIL (sortedAdd error)\n");

	printf("\nTest 1a4: Sorted add of a book in full table:");
	(*totalTest)++;
	bookTable_init(&books);
	for(i=0;i<=MAX_BOOKS;i++) {
		getBookObject(BOOK1, &book1);
		retVal=bookTable_sortedAdd(&books, book1);
		if(i<MAX_BOOKS) {
			if(retVal!=OK) {
				printf("\n\t-> FAIL (unexpected return value from addBook adding object %d of %d. Expected %d and returned %d)\n", i+1, MAX_BOOKS, OK, retVal);
				break;
			}
		} else {
			if(retVal==ERR_MEMORY) {
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else {
				printf("\n\t-> FAIL (unexpected return value from addBook adding last object. Expected %d and returned %d)\n", ERR_MEMORY, retVal);
			} 
		}
	}		
	
	printf("\nTest 1b1: Sort empty table:");
	(*totalTest)++;
	bookTable_init(&books);
	
	bookTable_sort(books, &result);
	if(result.size==0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 0, result.size);
	}

	printf("\nTest 1b2: Sort sorted books:");
	(*totalTest)++;
	bookTable_init(&books);
	test_initBookTable(&books,BOOK3,BOOK1,BOOK2,&book3,&book1,&book2);
	bookTable_sort(books, &result);
	if(result.size==3) {
		if(book_cmp(result.table[0], book3)!=0 ||
			book_cmp(result.table[1], book1)!=0 ||
			book_cmp(result.table[2], book2)!=0) {
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 3, result.size);
	}


	printf("\nTest 1b3: Sort books:");
	(*totalTest)++;
	bookTable_init(&books);		
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	bookTable_sort(books, &result);
	if(result.size==3) {
		if(book_cmp(result.table[0], book3)!=0 ||
			book_cmp(result.table[1], book1)!=0 ||
			book_cmp(result.table[2], book2)!=0) {
			printf("\n\t-> FAIL (Values are not correct)\n");
		} else {
			printf("\n\t-> OK\n");
			(*passedTest)++;
		}
	} else {
		printf("\n\t-> FAIL (unexpected number of registers in the table. Expected %d and returned %d)\n", 3, result.size);
	}
}

void test_initSecTable(tSectionTable *table, char *c1, char *c2, char *c3, char *c5, char *c6, char *c7, char *c8, char *c9, 
          tSection *s1, tSection *s2, tSection *s3, tSection *s5, tSection *s6, tSection *s7, tSection *s8, tSection *s9) {
	
	/* Create test sections */
	getSectionObject(c1, s1);	
	getSectionObject(c2, s2);	
	getSectionObject(c3, s3);	
	getSectionObject(c5, s5);	
	getSectionObject(c6, s6);	
	getSectionObject(c7, s7);	
	getSectionObject(c8, s8);	
	getSectionObject(c9, s9);	

	/* Add the sections to the table */
	secTable_init(table);		
	secTable_add(table, *s1);
	secTable_add(table, *s2);
	secTable_add(table, *s3);
	secTable_add(table, *s5);
	secTable_add(table, *s6);
	secTable_add(table, *s7);
	secTable_add(table, *s8);
	secTable_add(table, *s9);

}

void test_initBookTable(tBookTable *table, char *c1, char *c2, char *c3, tBook *s1, tBook *s2, tBook *s3) {
	
	/* Create 3 test books */
	getBookObject(c1, s1);	
	getBookObject(c2, s2);	
	getBookObject(c3, s3);	
	
	/* Add the books to the table */
	bookTable_init(table);		
	bookTable_add(table, *s1);
	bookTable_add(table, *s2);
	bookTable_add(table, *s3);

}

void test_sectionInfo(int* totalTest, int* passedTest) {

	tBookTable books;
	tBook book1, book2, book3;
	tSectionTable sections;
	tSection section1,section2,section3,section5,section6,section7,section8,section9;
	tSectionInfo si;
		
	test_initSecTable(&sections,SECTION1,SECTION2,SECTION3,SECTION5,SECTION6,SECTION7,SECTION8,SECTION9,
		&section1,&section2,&section3,&section5,&section6,&section7,&section8,&section9);
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);
	
	printf("=================================================\n");
	printf(" SECTION INFO \n");
	printf("=================================================\n");
	
	printf("\nTest1: Get the section info for a non existing section:");
	(*totalTest)++;
	if(si_getSectionInfo(books, sections, '4', &si)==ERR_INVALID_DATA) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL.\n");	
	}
	
	printf("\nTest2: Get the section info for an empty section:");
	(*totalTest)++;
	if(si_getSectionInfo(books, sections, section9.id, &si)==ERR_ENTRY_NOT_FOUND) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL.\n");	
	}

	printf("\nTest3: Get the section info for a section with only 1 subsection:");
	(*totalTest)++;
	if(si_getSectionInfo(books, sections, section8.id, &si)==OK) {
		if(si.totSecSubs!=1) {
			printf("\n\t-> FAIL. Invalid quantities.\n");
		} else {
			if(book_cmp(si_getBook(books,si,0,0),book2)==0) {
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else {
				printf("\n\t-> FAIL. Invalid book.\n");	
			}
		}
	}

	printf("\nTest4: Get the section info for a section with many subsections:");
	(*totalTest)++;
	if(si_getSectionInfo(books, sections, section6.id, &si)==OK) {
		if(si.totSecSubs!=2) {
			printf("\n\t-> FAIL. Invalid quantities.\n");
		} else {
			if(book_cmp(si_getBook(books,si,0,0),book1)==0 &&
			   book_cmp(si_getBook(books,si,1,0),book3)==0) {
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else {
				printf("\n\t-> FAIL. Invalid book.\n");	
			}
		}
	}
}

void test_stack(int* totalTest, int* passedTest) {
	tBookTable books;
	tBook book1, book2, book3, book;
	tBookStack stack, stackd;

	/* Prepare the test data */
	test_initBookTable(&books,BOOK1,BOOK2,BOOK3,&book1,&book2,&book3);

	printf("=================================================\n");
	printf(" STACK\n");
	printf("=================================================\n");
	
	printf("\nTest1: Initialize the stack:");
	(*totalTest)++;
	bookStack_create(&stack);
	if(bookStack_empty(stack)) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL, stack not empty\n");
	}

	printf("\nTest2: Add an element to the stack:");
	(*totalTest)++;
	bookStack_create(&stack);
	if(bookStack_push(&stack, book1)!=OK) {
		printf("\n\t-> FAIL, ERROR in push\n");
	} else if(bookStack_empty(stack)) {
		printf("\n\t-> FAIL, stack empty\n");
	} else {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	}
	
	printf("\nTest 3: Push and pop an element:");
	(*totalTest)++;
	bookStack_create(&stack);
	if(bookStack_push(&stack, book1)!=OK) { 
		printf("\n\t-> FAIL, ERROR in push\n");
	} else if(bookStack_empty(stack)==TRUE) {
		printf("\n\t-> FAIL, stack empty after push\n");
	} else if(bookStack_pop(&stack, &book)!=OK) {
		printf("\n\t-> FAIL, stack empty\n");
	} else if(book_cmp(book1, book)!=0 ) {
		printf("\n\t-> FAIL, invalid book on top\n");
	} else if(bookStack_empty(stack)!=TRUE) {
		printf("\n\t-> FAIL, stack not empty after pop\n");
	} else {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	}
	
	printf("\nTest 4: Push two elements and pop an element:");
	(*totalTest)++;
	bookStack_create(&stack);
	if(bookStack_push(&stack, book1)!=OK) {
		printf("\n\t-> FAIL, ERROR in push 1st element\n");
	} else if(bookStack_push(&stack, book2)!=OK) {
		printf("\n\t-> FAIL, ERROR in push 2nd element\n");
	} else if(bookStack_empty(stack)==TRUE) {
		printf("\n\t-> FAIL, stack empty\n");
	} else if(bookStack_pop(&stack, &book)!=OK) {
		printf("\n\t-> FAIL, stack empty\n");
	} else if(book_cmp(book2, book)!=0) {
		printf("\n\t-> FAIL, invalid book on top\n");
	} else if (bookStack_empty(stack)==TRUE) {
		printf("\n\t-> FAIL, stack after 1 pop empty\n");
	} else {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	}
	
	printf("\nTest 5: Pop all elements:");
	(*totalTest)++;
	bookStack_create(&stack);
	bookStack_push(&stack, book1);
	bookStack_push(&stack, book2);	
	
	if(bookStack_pop(&stack, &book)!=OK) {
		printf("\n\t-> FAIL, stack empty after 2nd push\n");
	} else if(book_cmp(book2, book)!=0) {
		printf("\n\t-> FAIL, invalid book on top\n");
	} else if (bookStack_pop(&stack, &book)!=OK) {
		printf("\n\t-> FAIL, stack after 1st pop empty\n");
	} else if (book_cmp(book1, book)!=0) {
		printf("\n\t-> FAIL, invalid book in 2nd pop\n");
	} else if (!bookStack_empty(stack)) {
		printf("\n\t-> FAIL, stack after 2nd pop not empty\n");
	} else {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	}
	
	printf("\nTest 6: Pop all elements and add a new element:");
	(*totalTest)++;
	bookStack_create(&stack);
	bookStack_push(&stack, book1);
	bookStack_push(&stack, book2);
	bookStack_pop(&stack, &book);
	bookStack_pop(&stack, &book);
	if(bookStack_push(&stack, book1)!=OK) {
		printf("\n\t-> FAIL, ERROR in PUSH\n");
	} else if(bookStack_pop(&stack, &book)!=OK) {
		printf("\n\t-> FAIL, stack empty\n");
	} else if(book_cmp(book1, book)!=0 ) {
		printf("\n\t-> FAIL, invalid book on top\n");
	} else if (bookStack_empty(stack)!=TRUE) {
		printf("\n\t-> FAIL, stack not empty after pop\n");
	} else {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	}

	printf("\nTest 7: Transfer elements of a stack to another:");
	(*totalTest)++;
	bookStack_create(&stack);
	bookStack_push(&stack, book1);
	bookStack_push(&stack, book2);
	bookStack_create(&stackd);
	bookStack_push(&stackd, book3);
	bookStack_transfer(&stackd,&stack);
	if (bookStack_empty(stack)!=TRUE) {
		printf("\n\t-> FAIL, source stack not empty\n");
	} else if(bookStack_pop(&stackd, &book)!=OK) {
		printf("\n\t-> FAIL, destination stack empty\n");
	} else if(book_cmp(book1, book)!=0) {
		printf("\n\t-> FAIL, first element not correct\n");
	} else if(bookStack_pop(&stackd, &book)!=OK) {
		printf("\n\t-> FAIL, only 1 element in destination stack\n");
	} else if(book_cmp(book2, book)!=0) {
		printf("\n\t-> FAIL, second element not correct\n");
	} else if(bookStack_pop(&stackd, &book)!=OK) {
		printf("\n\t-> FAIL, only 2 elements in destination stack\n");
	} else if(book_cmp(book3, book)!=0) {
		printf("\n\t-> FAIL, third element not correct\n");
	} else if (bookStack_empty(stackd)!=TRUE) {
		printf("\n\t-> FAIL, more than 3 elements in destination stack\n");
	} else {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	}	
	
	printf("\nTest 8: Search an element in a stack:");
	(*totalTest)++;
	bookStack_create(&stack);
	bookStack_push(&stack, book1);
	bookStack_push(&stack, book2);
	bookStack_push(&stack, book3);
	if (bookStack_search(&stack, "9780140816167",&book)!=OK) {
		printf("\n\t-> FAIL, book not found\n");
	} else if(book_cmp(book2,book)!=0){
		printf("\n\t-> FAIL, result book not correct\n");
	} else if(bookStack_pop(&stack, &book)!=OK) {
		printf("\n\t-> FAIL, stack empty\n");
	} else if(book_cmp(book3, book)!=0) {
		printf("\n\t-> FAIL, first book in stack not correct\n");
	} else if(bookStack_pop(&stack, &book)!=OK) {
		printf("\n\t-> FAIL, only a book in stack\n");
	} else if(book_cmp(book1, book)!=0) {
		printf("\n\t-> FAIL, second book in stack not correct\n");
	} else if (bookStack_empty(stack)!=TRUE) {
		printf("\n\t-> FAIL, more than 2 elements in destination stack\n");
	} else {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	}

}