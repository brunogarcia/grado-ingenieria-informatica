#include <stdio.h>
#include "shop.h"

#define MAX_TEST_CLIENTS 7

/*==========MAIN TEST=========*/

// 1) Test insert client to empty list
void testInsertClientToEmptyList(int dni);

// 2-5) Test insert client to list with clients
void testInsertClientToList(int dni);

// 6) Test insert a client into a full list
void testInsertClientToFullList();

// 7) Test discounts generation
void testDiscountsGeneration();

/*==========THESE TESTS ARE NOT IN THE MENU=========*/

/* Tests search client by dni */
void testClientPosition();

/* Tests add amount to client */
void testAddAmountToClient();

/*==========AUXILIARY ACTIONS=========*/

/* Insert clients to shop */
void insertClientsToShop(tShop *shop);

/* Create client */
void createClient(tClient *client, int dni);

/* Print client */
void printClient(tShop shop, int position);

/* Print shop */
void printShop(tShop *shop);