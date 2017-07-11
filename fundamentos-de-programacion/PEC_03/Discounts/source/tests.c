#include <stdio.h>
#include "tests.h"
#include "discount.h"

/*==========MAIN TESTS=========*/

/* Tests sort discounts */
void testSortDiscounts() {
	tDiscountsShop discountsShop;

	// First init a discount shop
	initDiscountsShop(&discountsShop);
	
	// Then sort the discounts table
	sortDiscountsShop(&discountsShop);
	
	// Show successful message
	printf("=======================================\n");
	printf("Discount shop table sorted successfully\n");
	printf("=======================================\n");
	
	// Check result
	printDiscountsShop(&discountsShop);
}

/* Test discount changed - success */
void testDiscountChangedSuccess() {
	tDiscountsShop discountsShop;
	int dni = 5;

	// First init a discount shop
	initDiscountsShop(&discountsShop);
	
	// Then try to change the user data (dni 5)
	discountChanged(&discountsShop, dni);
	
	// Show successful message
	printf("=======================\n");
	printf("DNI 5 updated\n");
	printf("=======================\n");
	
	// Check result
	printDiscountsShop(&discountsShop);
}

/* Test discount changed -fail */
void testDiscountChangedFail() {
	tDiscountsShop discountsShop;
	int dni = 1;
	
	// First init a discount shop
	initDiscountsShop(&discountsShop);
	
	// Then try to change the user data (dni 1)
	// This will be fail and show an error message
	// Becase this user has the changes value equal to TRUE
	discountChanged(&discountsShop, dni);
	
	// Check discount shop
	// Nothing has been changed
	printDiscountsShop(&discountsShop);
}

/* Test discount changed - not found */
void testDiscountChangedNotFound() {
	tDiscountsShop discountsShop;
	int dni = 99;
	
	// First init a discount shop
	initDiscountsShop(&discountsShop);
	
	// Then try to change the user data (dni 99)
	// This will be fail and show an error message
	// Because there is not an user with dni 99
	discountChanged(&discountsShop, dni);
	
	// Check discount shop
	// Nothing has been changed
	printDiscountsShop(&discountsShop);
}

/*==========AUXILIARY ACTIONS=========*/

/* Create a discounts shop with five discounts */
void initDiscountsShop(tDiscountsShop *discountsShop) {
	int i;
	int numDiscounts = 0;
	
	// Mock data 
	// - dni table must be unsorted
	// - one of them must have the changed value equal to TRUE 
	int dni[MAX_TEST_DISCOUNTS] = {3, 5, 1, 2, 4};
	float discount[MAX_TEST_DISCOUNTS] = {1.0, 2.0, 3.0, 4.0, 5.0};
	tBoolean changed[MAX_TEST_DISCOUNTS] = {FALSE, FALSE, TRUE, FALSE, FALSE};

	// Fill discount shop table with mock data
	for (i = 0; i < MAX_TEST_DISCOUNTS; i++) {
		discountsShop->discounts[i].dni = dni[i];
		discountsShop->discounts[i].discount = discount[i];
		discountsShop->discounts[i].changed = changed[i];
		discountsShop->numDiscounts = numDiscounts++;
	}
}

/* Print discount shop */
void printDiscountsShop(tDiscountsShop *discountsShop) {
	int i;
	int dni;
	float discount;
	tBoolean changed;

	printf("=======================\n");
	printf("DISCOUNT SHOP\n");
	printf("=======================\n");

	// Print discounts
	for (i = 0; i <= discountsShop->numDiscounts; i++) {
		dni = discountsShop->discounts[i].dni;
		discount = discountsShop->discounts[i].discount;
		changed = discountsShop->discounts[i].changed;

		printf("dni: %d | discount: %.1f | changed: %hu \n", dni, discount, changed);
	}
}