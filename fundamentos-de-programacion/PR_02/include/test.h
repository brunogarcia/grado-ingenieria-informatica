/* Run all the test set */
#include "data.h"
#include "api.h"

void runTests();

void runTestsPR1(int* totalTest, int* passedTest);

/* Run all the test set for PR2 */
void runTestsPR2(int* totalTest, int* passedTest);

void test_initBookTable(tBookTable *table, char *c1, char *c2, char *c3, tBook *s1, tBook *s2, tBook *s3);

void test_sections(int* totalTest, int* passedTest);

/* Test the book comparison and copy */
void test_cmp_cpy(int* totalTest, int* passedTest);

/* Test the book table management*/
void test_book_tab(int* totalTest, int* passedTest);

/* Test the book data persistence */
void test_persistence(int* totalTest, int* passedTest);

/* Test the book search */
void test_search(int* totalTest, int* passedTest);

/* Test the book statistics */
void test_count(int* totalTest, int* passedTest);

/* Test the book sorting */
void test_sort(int* totalTest, int* passedTest);

void test_sectionInfo(int* totalTest, int* passedTest);

void test_stack(int* totalTest, int* passedTest);

