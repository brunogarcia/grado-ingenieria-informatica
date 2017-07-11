#include <stdio.h>
#include "tests.h"

int main (int argc, char** argv) {
	int dniRegisted = 34;
	int dniStart = 1;
	int dniMiddle = 50;
	int dniEnd = 999;

	int option;
	
	/* Start the menu */
	do {
		printf("=======================\n");
		printf(" Menu \n");
		printf("=======================\n");
		printf("1) Empty list: add new client \n");
		printf("2) No empty list: add new client to start \n");
		printf("3) No empty list: add new client to middle \n");
		printf("4) No empty list: add new client to end \n");
		printf("5) No empty list: try to add a registered client \n");
		printf("6) Full list: try to add a client \n");
		printf("7) Generate discounts \n");
		printf("8) Exit\n");

		scanf("%d", &option);
	
		switch(option) {
		case 1:
			testInsertClientToEmptyList(dniRegisted);
			break;
		case 2:
			testInsertClientToList(dniStart);
			break;
		case 3:
			testInsertClientToList(dniMiddle);
			break;
		case 4:
			testInsertClientToList(dniEnd);
			break;
		case 5:
			testInsertClientToList(dniRegisted);
			break;
		case 6:
			testInsertClientToFullList();
			break;
		case 7:
			testDiscountsGeneration();
			break;
		case 8:
			break;
		default:
			printf("Ups! wrong choice. Please try again\n");
			break;
		}
	} while(option!=8);

	return 0;
	
}