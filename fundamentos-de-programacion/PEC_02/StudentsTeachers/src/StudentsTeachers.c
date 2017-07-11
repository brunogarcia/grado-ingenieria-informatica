#include <stdio.h>
#include "include/StudentsTeachers.h"

/*
 * Acción fillTeachersVector
 * - Tiene que devolver una variable de tipo tvector->teacher
 * - Inicializada con los valores que se indican en la siguiente tabla:
 * -----------------------------------------------------------
 * Posición vector     IdTeacher       bEnglish        cLevel
 * 0                   1               true            P
 * 1                   2               false           P
 * 2                   3               true            S
 * 3                   4               false           S
 * -----------------------------------------------------------
 * */
void fillTeachersVector(tTeacherVector *tvector)
{
    tvector->teacher[0].idTeacher = 1;
    tvector->teacher[1].idTeacher = 2;
    tvector->teacher[2].idTeacher = 3;
    tvector->teacher[3].idTeacher = 4;
    
    tvector->teacher[0].bEnglish = TRUE;
    tvector->teacher[1].bEnglish = FALSE;
    tvector->teacher[2].bEnglish = TRUE;
    tvector->teacher[3].bEnglish = FALSE;
    
    tvector->teacher[0].cLevel = 'P';
    tvector->teacher[1].cLevel = 'P';
    tvector->teacher[2].cLevel = 'S';
    tvector->teacher[3].cLevel = 'S';
}

/* Implementa una acción updateTeacherStudent que:
 * - Dada una variable de tipo tTeacherVector y una variable de tipo tStudent
 * - Devuelva esta última variable con el valor de idTeacher actualizado.
 * 
 * La acción tiene que buscar en el vector tTeacherVector: 
 *  - el identificador de profesor que le corresponde al estudiante según el nivel (unsigned char cLevel: P o S)
 *  - y si realiza o no las clases en inglés (tBool bEnglish)
 * 
 * Si no encontramos ningún profesor adecuado al estudiante, guardaremos el valor -1 en la variable idTeacher.
**/
void updateTeacherStudent(tTeacherVector tvector, tStudent *tstudent)
{
    int i;
    short int assignedTeacher = -1;
    
    // Search into teachers vector
    for (i = 0; i <= TEACHER_VECTOR_LEN; i++) {
        
        // Search for a match between teacher and student
        if ((tvector.teacher[i].cLevel == tstudent->cLevel) && (tvector.teacher[i].bEnglish == tstudent->bEnglish)) {
            // If we found a match, save idTeacher
            assignedTeacher = tvector.teacher[i].idTeacher;
        }
    }
     
   // Assign the teacher to student
   tstudent->idTeacher = assignedTeacher;
}

 /*
  * Acción readStudent 
  * - Lea del canal de entrada estándar *parte* de la información de un estudiante 
  * - Y la guarde en una variable de tipo tStudent. 
  * 
  * Tiene que leer:
  * - Identificador numérico que guardaremos en la variable dni.
  * - Valor numérico 0 o 1 indicando si las clases las hará o no en inglés
  *   - Valor 0 indica que no es inglés
  *   - Valor 1 indica que es inglés 
  *   - Valor a guardar en la variable bEnglish.
  * - Carácter indicando el nivel.
  *     - Los valores podrán ser ‘P’ o ‘S’.
  *     - Valor a guardar en la variable cLevel.
  * 
  * Puedes presuponer que los valores introducidos por el usuario serán correctos.
 **/
 void readStudent(tStudent *tstudent)
{
     unsigned short int dni;
     tBool bEnglish;
     unsigned char cLevel;     
     
     printf("-----------INSERT NEW STUDENT-----------\n");
     
     printf("1) Write dni \n");
     scanf("%hu", &dni);
     
     printf("2) Write english class (0 or 1) \n");
     scanf("%d", &bEnglish);

     printf("3) Write a level (P or S) \n");
     fflush(stdin);
     while(getchar()!='\n');
     cLevel = getchar();
     
     tstudent->cLevel = cLevel;
     tstudent->dni = dni;
     tstudent->bEnglish = bEnglish;
}


 /*
  * Acción writeStudent
  * - Dada una variable de tipo tStudent 
  * - Escriba por el canal de salida estándar:
  *     - dni
  *     - idTeacher
**/
void writeStudent(tStudent tstudent)
{
    printf("-----------STUDENT & TEACHER-----------\n");
    printf("dni: %d \n", tstudent.dni);
    printf("teacher: %d \n", tstudent.idTeacher);
}