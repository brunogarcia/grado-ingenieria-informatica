#include "data.h"

/******************** PR2 - EX4A ********************/
typedef struct {
	tBook table[MAX_BOOKS];
	unsigned int total;
} tBookStack;

void bookStack_create(tBookStack *stack);

tBoolean bookStack_empty(tBookStack stack);

tError bookStack_push(tBookStack *stack, tBook newElement);

tError bookStack_pop (tBookStack *stack, tBook *element);

void bookStack_transfer(tBookStack *stack_dest, tBookStack *stack);

tError bookStack_search(tBookStack *stack, char *ISBN, tBook *book);