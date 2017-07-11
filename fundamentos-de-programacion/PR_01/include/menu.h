#include "data.h"
#include "api.h"

/* Request an option to the user and check its validity */
int getOption(int numOptions);

/* Define the main menu options type */
typedef enum {MAIN_MENU_LOAD, MAIN_MENU_SAVE, MAIN_MENU_BOOKS, MAIN_MENU_SECTIONS, MAIN_MENU_STATS, MAIN_MENU_EXIT} tMainMenuOptions;

/* Define the book management menu options type */
typedef enum {BOOK_MENU_LIST, BOOK_MENU_ADD, BOOK_MENU_DEL, BOOK_MENU_SORT, BOOK_MENU_EXIT} tBookMenuOptions;

/* Define the section management menu options type */
typedef enum {SEC_MENU_LIST, SEC_MENU_ADD, SEC_MENU_INFO, SEC_MENU_EXIT} tSectionMenuOptions;

/* Define the status menu options type */
typedef enum {STAT_MENU_ON_LOAN, STAT_MENU_AUTHOR, STAT_MENU_SECTION, STAT_MENU_EXIT} tStatsMenuOptions;

/* Print the main menu options */
void printMainMenuOptions();

/* Get the option for the main menu */
tMainMenuOptions getMenuOption();

/* Perform the actions for the main menu */
void mainMenu(tAppData *appData);

/* Print the book management menu options */
void printBookMenuOptions();

/* Get the option for the book management menu */
tBookMenuOptions getBooksMenuOption();

/* Perform the actions for the book management menu */
void bookMenu(tAppData *appData);

/* Print the section management menu options */
void printSectionMenuOptions();

/* Get the option for the section management menu */
tSectionMenuOptions getSectionMenuOption();

/* Perform the actions for the section management menu */
void secMenu(tAppData *appData);

/* Print the stats menu options */
void printStatsMenuOptions();

/* Get the option for the status menu */
tStatsMenuOptions getStatsMenuOption();

/* Perform the actions for the status menu */
void statsMenu(tAppData appData);
