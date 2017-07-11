#include <stdio.h>
#include "discount.h"

/* Sort discounts table */
void sortDiscountsShop(tDiscountsShop *discountsShop) {
	int i;
	int j;
	tDiscount tempDiscount;
	int numDiscounts = discountsShop->numDiscounts;
	
	// ## Bubble sort algorithm ##
	// Iterate over each discount on the table
	for (i = 0; i <= numDiscounts; i++) {
		for (j = 0; j <= numDiscounts - 1; j++) {
			// Compare dni of each discount
			if (discountsShop->discounts[j].dni > discountsShop->discounts[j+1].dni) {
				// Switch positions of discounts
				tempDiscount = discountsShop->discounts[j+1];
				discountsShop->discounts[j+1] = discountsShop->discounts[j];
				discountsShop->discounts[j] = tempDiscount;
			}
		}
	}
}

/* Find a discount by dni and apply changes */
void discountChanged(tDiscountsShop *discountsShop, int dni) {
	int i = 0;
	int state = -1;
	
	/* 
	 * Iterate over each discount on the table only if there are more discounts to look up and the state of search is still the default value (-1: not found a match)
	 * Exit if the state of search changed to 0, this is because has found a match.
	 * */
	while (i <= discountsShop->numDiscounts && state <= 0) {

		// Check if both dni are equals
		if (discountsShop->discounts[i].dni == dni) {
		
			// Check if the discount is already been used
			if (discountsShop->discounts[i].changed == TRUE) {
				// Show ‘discount used’ message
				printf("=============================================================\n");
				printf("ERROR!. Sorry, but the discount for %d is already been used. \n", dni);
				printf("=============================================================\n");
			} else {
				// Update changed value
				discountsShop->discounts[i].changed = TRUE;
			}

			// Cancel search because there was a match
			state = 0;
		}
		
		// Update index search
		i++;
	}
	
	// Show ‘discount not found’ message
	if (state == -1) {
		printf("===============================================\n");
		printf("ERROR!. Sorry, there is not a discount for %d. \n", dni);
		printf("===============================================\n");
	}
}