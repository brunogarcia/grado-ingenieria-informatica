#include <stdio.h>
#include "tests.h"

int main (int argc, char** argv) {
	int option;
	
	/* Start the menu */
	do {
		printf("=======================\n");
		printf(" Menu \n");
		printf("=======================\n");
		printf("1) Test: sort discount table\n");
		printf("2) Test: discount change - success\n");
		printf("3) Test: discount change - fail\n");
		printf("4) Test: discount change - not found\n");
		printf("5) Exit\n");

		scanf("%d", &option);
	
		switch(option) {
		case 1:
			testSortDiscounts();
			break;
		case 2:
			testDiscountChangedSuccess();
			break;
		case 3:
			testDiscountChangedFail();
			break;
		case 4:
			testDiscountChangedNotFound();
			break;
		case 5:
			break;
		default:
			printf("Ups! wrong choice. Please try again\n");
			break;
		}
	} while(option!=5);

	return 0;
}