#include <stdio.h>
#include <string.h>
#include <math.h>
#include "test.h"
#include "sections.h"
#include "books.h"
#define BOOK1 "9788431612269 1970 0 5 1 BIR Algebra_moderna"
#define BOOK2 "9780140816167 1996 1 8 1 WAT Test_your_vocabulary"
#define BOOK3 "9788489660007 1997 1 6 8 BRA Fundamentos_de_algoritmia"

void runTests() {	
	int passedTestPR1, passedTestPR2=0;
	int totalTestPR1, totalTestPR2=0;
	
	printf("=================================================\n");
	printf("====       PRACTICAL ACTIVITY 1 TESTS        ====\n");
	printf("=================================================\n");	
	runTestsPR1(&totalTestPR1, &passedTestPR1);

	printf("===================================\n");
	printf("====       TEST SUMMARY        ====\n");
	printf("===================================\n");		
	printf("\tPR1: Passed %d of %d [%0.2f%%]\n", passedTestPR1, totalTestPR1, (float)passedTestPR1/totalTestPR1*100.0);
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
	
	printf("\nTest 5.1: Save and load no data:");
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
	
	printf("\nTest 5.2: Save and load books:");
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
	printf(" BOOK TABLE FILTER \n");
	printf("=================================================\n");
	
	printf("\nTest 6.1: Books of a section in empty table:");
	(*totalTest)++;
	bookTable_init(&books);	
	
	bookTable_filterBySection(books, '5', &result);
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
	unsigned int i;
		
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

