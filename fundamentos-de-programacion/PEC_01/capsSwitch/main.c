#include <stdio.h>
#include <ctype.h>
/*
 * Programa que lea un carácter 
 * y muestre por pantalla el carácter con capitalización invertida 
 * (mayúscula si era minúscula, o minúscula si era mayúscula), 
 * para el resto de caracteres debe mostrar el mismo carácter.
 * */
 
// Types definition
typedef enum { false, true } bool;

int main(int argc, char **argv)
{
    // Variables declaration
    bool isAValidCharacterToConvert;
    unsigned char originalCharacter;
    unsigned char convertedCharacter;
    
    // Read and save original character
    printf("Please, insert a character \n");
    originalCharacter = getchar();
    
    // Check if original character is an alphabetic value
    isAValidCharacterToConvert = isalpha(originalCharacter);
    
    // Print on screen a message
    if (isAValidCharacterToConvert) {
        // First, convert original character to lower case or uppera case
        convertedCharacter = islower(originalCharacter) ? 
                              toupper(originalCharacter) : 
                              tolower(originalCharacter);
        
        // Then, print converted character
        printf("%c \n", convertedCharacter);
    } else {
        // If original character is not an alphabetic value, print original character
        printf("%c \n", originalCharacter);
    }    
    
    return 0;
}
