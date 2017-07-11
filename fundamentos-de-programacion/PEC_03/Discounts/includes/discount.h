/* This code ensures that this file is included only once */
#ifndef __DATA_H
#define __DATA_H
/* If the constant DATA_H is not defined (ifndef), the code is added, otherwise, this code is excluded. 
 * When the code is added, the constant is defined, 
 * therefore next time this file will be included it will be defined and no inclusion will be done.
 * */
 
#define MAXDISCOUNTS 50

/* Definition of a boolean type */
typedef enum {FALSE=0, TRUE=1} tBoolean;

/* Definition of a discount */
typedef struct {
	int dni;
	float discount;
	tBoolean changed;
} tDiscount;

/* Definition of a discount shop */
typedef struct {
	tDiscount discounts[MAXDISCOUNTS];
	int	numDiscounts;
} tDiscountsShop;

/* Sort discounts table */
void sortDiscountsShop(tDiscountsShop *discountsShop);

/* Find a discount by dni and apply changes */
void discountChanged(tDiscountsShop *discountsShop, int dni);

#endif /*__DATA_H*/