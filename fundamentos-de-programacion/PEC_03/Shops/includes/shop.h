/* This code ensures that this file is included only once */
#ifndef __DATA_H
#define __DATA_H
/* If the constant DATA_H is not defined (ifndef), the code is added, otherwise, this code is excluded. 
 * When the code is added, the constant is defined, 
 * therefore next time this file will be included it will be defined and no inclusion will be done.
 * */
 
#define MAXPURCHASES 50
#define MAXCLIENTS 50
#define MAXSTRINGLEN 100

typedef enum {FALSE=0, TRUE=1} tBoolean;

typedef struct{
	int dni;
	char name [MAXSTRINGLEN];
	char email [MAXSTRINGLEN];
	float accumulated;
	tBoolean thereIsCupon;
} tClient;

typedef struct{
	tClient clients [MAXCLIENTS];
	int numClients;
} tShop;

// Init shop
void shopInit(tShop *shop);

// Copy client
void clientCopy(tClient client1, tClient client2);

// Get client position on shop table
int posClient(tShop *shop, int dni);

// Insert client into shop table 
void insertClient(tShop *shop, tClient client);

// Update accumulated value of client
void addAmountClient(tShop *shop, int dni, float amount);

// Generate discount for each client
void generateDiscount(tShop *shop);

#endif /*__DATA_H*/