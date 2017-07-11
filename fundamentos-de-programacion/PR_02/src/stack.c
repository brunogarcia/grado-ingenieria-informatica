#include "books.h"
#include "stack.h"
#include <string.h>

/******************** PR2 - EX4B ********************/
void bookStack_create(tBookStack *stack) {
	stack->total = 0;
}

/******************** PR2 - EX4C ********************/
tBoolean bookStack_empty(tBookStack stack) {
	// The result must be true by default
	tBoolean result = TRUE;
	
	// And only change if total of books is greater than zero
	if (stack.total > 0) {
		result = FALSE;
	}
	
	return result;
}

/******************** PR2 - EX4D ********************/
tError bookStack_push(tBookStack *stack, tBook newElement) {
	tError retVal = OK;
	
	// Return an error if the total of books in this stack
	// is equal to the maximum of books allowed
	if (stack->total == MAX_BOOKS) {
		retVal = ERR_MEMORY;
	} else {
		// Otherwise, add the new book at the end of the stack
		stack->table[stack->total] = newElement;
		
		// And increase the total of books
		stack->total++;
	}

	return retVal;
}

/******************** PR2 - EX4E ********************/
tError bookStack_pop (tBookStack *stack, tBook *element) {
    tError retVal = OK;

	// Return an error if the stack is empty
	if (stack->total == 0) {
		retVal = ERROR;
	} else {
		// Otherwise, copy the last book into element pointer
		book_cpy(element, stack->table[stack->total-1]);
		
		// And decrease total of books
		stack->total--;
	}
	
	return retVal;
}

/******************** PR2 - EX5A ********************/
void bookStack_transfer(tBookStack *stack_dest, tBookStack *stack){
	int i = 0;
	tBook book;
	
	while (i <= stack->total) {
		// First remove last book from source stack
		// And copy it to book pointer
		bookStack_pop(stack, &book);
		
		// Then add that book to the destination stack
		bookStack_push(stack_dest, book);
		
		// Increase counter
		i++;
	}
}

/******************** PR2 - EX5B ********************/
tError bookStack_search(tBookStack *stack, char *ISBN, tBook *book){
	int i = 0;
	int j;
	int areEqual;
	tError retVal = OK;
	tBoolean found = FALSE;
	
	// Search into stack a book that match with ISBN param
	while ((i <= stack->total) && (found == FALSE)) {
		// Compare ISBN
		areEqual = strcmp(stack->table[i].ISBN, ISBN);

		// If found it...
		if (areEqual == 0) {
			
			// First, copy current book to book pointer
			book_cpy(book, stack->table[i]);
			
			// Then, move one position to left all books from stack
			for (j = stack->total-1; j > i; j--) {
				stack->table[j-1] = stack->table[j];
			}
			
			// Decrease total of books from stack"
			stack->total--;
			
			// Cancel search, because there is a match
			found = TRUE;
		}
		
		// Increase counter
		i++;
	}
	
	// If not found any book, show a error
	if (found == FALSE) {
		retVal = ERR_ENTRY_NOT_FOUND;
	}

	return retVal;
}
