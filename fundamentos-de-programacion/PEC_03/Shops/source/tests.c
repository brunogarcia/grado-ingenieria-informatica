#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "shop.h"

/*==========MAIN TESTS=========*/

// 1) Test insert client to empty list
void testInsertClientToEmptyList(int dni) {
	tShop shop;
	tClient client;
	
	// Init shop
	shopInit(&shop);
	
	// Create client
	createClient(&client, dni);
	
	// Add amount to client
	printf("======================================================\n");
	printf("#### Trying to register a new client with dni %d #### \n", dni);
	printf("======================================================\n");
	insertClient(&shop, client);

	// Show shop table
	printf("======================================================\n");
	printf("#### %s registered successfully #### \n", client.name);
	printf("======================================================\n");
	printShop(&shop);
}

// 2-5) Test insert client to list with clients
void testInsertClientToList(int dni) {
	tShop shop;
	tClient client;
	
	// Init shop
	shopInit(&shop);
	
	// Insert clients to shop
	insertClientsToShop(&shop);
	
	// Create client
	createClient(&client, dni);
	
	// Add amount to client
	printf("=========================================================\n");
	printf("#### Trying to register a new client with dni %d... #### \n", dni);
	printf("=========================================================\n");
	insertClient(&shop, client);

	// Show shop table
	printShop(&shop);
}

// 6) Test insert a client into a full list
void testInsertClientToFullList() {
	int i;
	int dni = 999;
	tShop shop;
	tClient client;
	
	// Init shop
	shopInit(&shop);
	
	// Create and insert 50 clients into empty shop list
	for (i = 1; i <= MAXCLIENTS; i++) {
		createClient(&client, i);
		insertClient(&shop, client);
	}
	
	// Try to insert the client number 51
	// This will fail because, 50 clients in the maximum in this shop list
	createClient(&client, dni);
	printf("===========================================================\n");
	printf("#### Trying to register a new client into a full list... #### \n");
	printf("===========================================================\n");
	insertClient(&shop, client);

	// Show shop table
	printShop(&shop);
}

// 7) Test discounts generation
void testDiscountsGeneration() {
	tShop shop;
	
	// Init shop
	shopInit(&shop);
	
	// Insert clients to shop
	insertClientsToShop(&shop);
	
	// Generate discount
	printf("==================================\n");
	printf("#### Generating discounts... #### \n");
	printf("==================================\n");
	generateDiscount(&shop);

	// Show shop table
	printShop(&shop);
}

/*==========THESE TESTS ARE NOT IN THE MENU=========*/

void testClientPosition() {
	tShop shop;
	int dni = 12;
	int position;
	
	// Init shop
	shopInit(&shop);
	
	// Insert clients to shop
	insertClientsToShop(&shop);
	
	// Search client
	position = posClient(&shop, dni);
	printClient(shop, position);

	// Show shop table
	printShop(&shop);
}

void testAddAmountToClient() {
	tShop shop;
	int dni = 12;
	float amount = 100.0;
	
	// Init shop
	shopInit(&shop);
	
	// Insert clients to shop
	insertClientsToShop(&shop);
	
	// Add amount to client
	addAmountClient(&shop, dni, amount);

	// Show shop table
	printShop(&shop);
}

/*==========AUXILIARY ACTIONS=========*/

void createClient(tClient *client, int dni) {
	client->dni = dni;
	strcpy(client->name, "I AM THE NEW USER");
	strcpy(client->email, "roboto@mail.com");
	client->accumulated = 0;
	client->thereIsCupon = FALSE;
}

void insertClientsToShop(tShop *shop) {
	int i;
	
	// Mock data 
	int dni[MAX_TEST_CLIENTS] = {12, 23, 34, 45, 66, 77};
	char name[MAX_TEST_CLIENTS][MAXSTRINGLEN] = {"eva", "bruno", "nire", "jazz", "orion", "migas"};
	char email[MAX_TEST_CLIENTS][MAXSTRINGLEN] = {"eva@gmail.com", "bruno@gmail.com", "nire@gmail.com", "jazz@gmail.com", "orion@gmail.com", "migas@gmail.com"};
	float accumulated[MAX_TEST_CLIENTS] = {120.6, 99.0, 84.0, 45.0, 26.0, 5.0};
	tBoolean thereIsCupon[MAX_TEST_CLIENTS] = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};

	// Fill shop table with mock data
	for (i = 0; i < 6; i++) {
		
		// insert data
		shop->clients[i].dni = dni[i];
		strcpy(shop->clients[i].name, name[i]);
		strcpy(shop->clients[i].email, email[i]);
		shop->clients[i].accumulated = accumulated[i];
		shop->clients[i].thereIsCupon = thereIsCupon[i];

		// update number of clients
		shop->numClients++;
	}
}

void printClient(tShop shop, int position) {
	printf("=======================\n");
	printf("CLIENT\n");
	printf("=======================\n");
	printf("pos: %d, dni: %d | name: %s | email: %s | accumulated: %.1f | there is cupon: %hu \n", position, shop.clients[position].dni, shop.clients[position].name, shop.clients[position].email, shop.clients[position].accumulated, shop.clients[position].thereIsCupon);
}

void printShop(tShop *shop) {
	int i;

	printf("=======================\n");
	printf("CLIENTS OF OUR SHOP\n");
	printf("=======================\n");

	// Print clients
	for (i = 0; i < shop->numClients; i++) {
		printf("pos: #%d | dni: %d | name: %s | email: %s | accumulated: %.1f | there is cupon: %hu \n", i, shop->clients[i].dni, shop->clients[i].name, shop->clients[i].email, shop->clients[i].accumulated, shop->clients[i].thereIsCupon);
	}
}