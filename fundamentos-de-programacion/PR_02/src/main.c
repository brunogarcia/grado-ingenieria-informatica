#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "test.h"

int main(int argc, char **argv)
{
	int i;
	tBoolean testMode=FALSE;
	
	/* Define the variable to store the application data */
	tAppData appData;
	
	setbuf(stdout, NULL);  
	
	/* Initialize the data object */
	appData_init(&appData);
			
	/* Parse input parameters to see if we should run in normal mode or in test mode */
	for(i=1; i<argc; i++) {
		if(strcmp(argv[i], "-t")==0) {
			testMode=TRUE;			
		}
	}
	
	/* If test mode is active, run the tests. Otherwise, start the menu */
	if(testMode) {
		runTests();
	} else {
		mainMenu(&appData);
	}
	
	return 0;
}
