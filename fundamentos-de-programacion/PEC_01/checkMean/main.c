#include <stdio.h>

/*
 * Programa que lea 5 enteros y 1 real 
 * muestre por pantalla una "y" 
 * si el número *real* coincide con la *media* de los 5 números enteros 
 * o una "n" en caso contrario.
 * */
 
// Types definition
typedef enum { false, true } bool;

int main(int argc, char **argv)
{    
    // Constants declaration
    unsigned char totalItems = 5;
    
    // Variables declaration
    unsigned int number1;
    unsigned int number2;
    unsigned int number3;
    unsigned int number4;
    unsigned int number5;
    unsigned int sumOfItems;
    float averageOfNumbers;
    float numberToCheck;
    bool areEquals;
    
    // Read and save five integer numbers
    printf("a) Please, write five integer numbers \n");
    scanf("%d", &number1);
    scanf("%d", &number2);
    scanf("%d", &number3);
    scanf("%d", &number4);
    scanf("%d", &number5);
    
    // Read one float number
    printf("b) Please, write one float number \n");
    scanf("%f", &numberToCheck);
    
    // Sum all integer numbers
    sumOfItems = number1 + number2 + number3 + number4 + number5;
    
    // Create an average of all integer numbers
    averageOfNumbers = (float) sumOfItems / (float) totalItems;
    
    // Check if float number is equal to average number
    areEquals = (numberToCheck == averageOfNumbers); 
    
    // print messages
    if (areEquals) {
        printf("y \n");
    } else {
        printf("n \n");
    }
    
	return 0;
}
