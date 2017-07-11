#include <stdio.h>
#include "discount.h"

#define MAX_TEST_DISCOUNTS 5

/*==========MAIN TESTS=========*/

/* Tests sort discounts */
void testSortDiscounts();

/* Test discount changed - success */
void testDiscountChangedSuccess();

/* Test discount changed -fail */
void testDiscountChangedFail();

/* Test discount changed - not found */
void testDiscountChangedNotFound();


/*==========AUXILIARY ACTIONS=========*/

/* Create a discounts shop with five discounts */
void initDiscountsShop(tDiscountsShop *discountsShop);

/* Print discount shop */
void printDiscountsShop(tDiscountsShop *discountsShop);