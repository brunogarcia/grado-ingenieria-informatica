#include <stdio.h>
#include "shop.h"

// Init shop
void shopInit(tShop *shop) {
	shop->numClients = 0;
}

// Get client position on shop table
int posClient(tShop *shop, int dni) {
	int i = 0;
	int position = -1;
	tBoolean founded = FALSE;
	
	// Iterate over each client on our shop
	while (i <= shop->numClients && founded == FALSE) {

		// Check if both dni are equals
		if (shop->clients[i].dni == dni) {
			// return position
			position = i;
			
			// updated 'founded' flag
			// this allow us to exit of search on the next iteration
			founded = TRUE;
		}
		
		// Update index search
		i++;
	}
	
	return position;
}

// Insert client into shop table 
void insertClient(tShop *shop, tClient client) {
	int i = 0;
	int j;
	tBoolean founded = FALSE;
	int positionToInsert;
	
	// Check if this client exists into our shop
	int position = posClient(shop, client.dni);
	
	// If this client is not register yet
	if (position == -1) {
		
		// Check if the shop table have enough space for another client
		if (shop->numClients < MAXCLIENTS) {

			// Search the right position to insert the new client
			while (i <= shop->numClients && founded == FALSE) {
				if (shop->clients[i].dni > client.dni) {
					positionToInsert = i;
					founded = TRUE;
				}

				// Update index search
				i++;
				
				// If there is not a match, the position to insert is the last one
				if (i == shop->numClients) {
					positionToInsert = i;
				}
			}
			
			// Move the clients one position to the right
			// Starting from position of new client
			for (j = shop->numClients-1; j >= positionToInsert; j--) {
				shop->clients[j+1] = shop->clients[j];
			}
			
			// Update number of clients
			shop->numClients += 1;

			// Insert new client
			shop->clients[positionToInsert] = client;
		} else {
			// Show 'not enough space' message
			printf("#### Error. Sorry, currently there is not enough space for another client.#### \n");
		}
	} else {
		// Show ‘client registered’ message
		printf("#### Error. Sorry, the client with dni %d is already registered on position #%d #### \n", client.dni, position);
	}
}

// Update accumulated value of client
void addAmountClient(tShop *shop, int dni, float amount) {
	// search client
	int position = posClient(shop, dni);
	
	// check if client exists into our shop
	if (position != -1) {
		// if client exists, update accumulated value
		shop->clients[position].accumulated += amount;
	} else {
		// show ‘client is not registered’ message
		printf("#### Error. Sorry, the client with dni %d is not registered. #### \n", dni);
	}
}

// Generate discount for each client
void generateDiscount(tShop *shop) {
	int i;
	float discountCoupon;
	float minimumForDiscount = 100.0;
	float discountRate = 0.03;
	
	// Iterate over each client on our shop
	for (i = 0; i <= shop->numClients; i++) {

		// check if this client has enough balance accumulated to getting a discount coupon
		if (shop->clients[i].accumulated >= minimumForDiscount) {
			// generate discount coupon
			discountCoupon = shop->clients[i].accumulated * discountRate;
			
			// show discount coupon
			printf("Client %d: new discount of %.3f euros \n", shop->clients[i].dni, discountCoupon);
			
			// reset accumulated value
			shop->clients[i].accumulated = 0; 
			
			// update 'thereIsCupon' flag
			shop->clients[i].thereIsCupon = TRUE;
		} 

	}
}