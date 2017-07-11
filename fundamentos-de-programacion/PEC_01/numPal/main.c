#include <stdio.h>
/*
 * 1) Un programa que lea *un entero* que tenga *5 dígitos* 
 * 2) Indique si el número entrado es *palíndromo* 
 *    - Ejemplo: 12321 
 * 3) En caso de que sea palíndromo muestre el mensaje:
 *    - "The number is Palindrome"
 * 4) De lo contrario el mensaje:
 *    - "The number is not Palindrome". 
 * 5) Verificar que el número entrado tiene cinco dígitos.
 * */

// Types definition
typedef enum { false, true } bool;

int main(int argc, char **argv)
{
    // Constants declaration
    unsigned char digitsRequired = 5;
    
    // Variables declaration
    unsigned int originalNumber;
    unsigned int reverseNumber = 0;
    unsigned int temporaryNumber;
    unsigned char digitsOfOriginalNumber = 0;
    bool isPalindrome;
    
    // Read and save original number
	printf("Please, insert a five digit number \n");
    scanf("%d", &originalNumber);
    
    // Save a copy of original number
    temporaryNumber = originalNumber;
    
    /*
     * Check if temporary number is a five digits number
     * pre    : temporaryNumber = 12345  | digitsOfOriginalNumber = 0
     * 1º loop: temporaryNumber = 1234   | digitsOfOriginalNumber = 1
     * 2º loop: temporaryNumber = 123    | digitsOfOriginalNumber = 2
     * 3º loop: temporaryNumber = 12     | digitsOfOriginalNumber = 3
     * 4º loop: temporaryNumber = 1      | digitsOfOriginalNumber = 4
     * 5º loop: temporaryNumber = 0      | digitsOfOriginalNumber = 5
     * post   : temporaryNumber = 0      | digitsOfOriginalNumber = 5
     *
     */
    while (temporaryNumber != 0) {
        temporaryNumber = (temporaryNumber / 10);
        digitsOfOriginalNumber++;
    }
    
    // It's not a five digit number...
    if (digitsOfOriginalNumber != digitsRequired) {
        // Print on screen an error message and exit
        printf("It's not a five digit number. Please try again. \n");
        return 0;
    }    
    
    // Save one more time a copy of original number
    temporaryNumber = originalNumber;
    
    /*
     * Create a reverse copy of temporary number
     * pre    : temporaryNumber = 12345 | reversedNumber = 0
     * 1º loop: temporaryNumber = 1234  | reversedNumber = 5
     * 2º loop: temporaryNumber = 123   | reversedNumber = 54
     * 3º loop: temporaryNumber = 12    | reversedNumber = 543
     * 4º loop: temporaryNumber = 1     | reversedNumber = 5432
     * 5º loop: temporaryNumber = 0     | reversedNumber = 54321
     * post   : temporaryNumber = 0     | reversedNumber = 54321
     * */
    while (temporaryNumber != 0) {
        reverseNumber = (reverseNumber * 10) + (temporaryNumber % 10);
        temporaryNumber = temporaryNumber / 10;
    }
    
    // Check if original number is equal to reverse number
    isPalindrome = (originalNumber == reverseNumber);

    // Print on screen a message
    if (isPalindrome) {
        // Success message
        printf("The number is Palindrome \n");
    } else {
        // Error message
        printf("The number is not Palindrome \n");
    }
    
    return 0;
}
