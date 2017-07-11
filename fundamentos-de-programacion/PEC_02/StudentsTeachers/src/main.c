#include <stdio.h>
#include "include/StudentsTeachers.h"

int main(int argc, char **argv)
{
    /* 1) Crea una variable de tipo tTeacherVector 
     * - Llama a la acción fillTeachersVector para inicializar la variable
     * */
    tTeacherVector tvector;
    fillTeachersVector(&tvector);

    /* 2) Crea una variable de tipo tStudentVector 
     * - Realiza de forma iterativa los siguientes pasos para rellenar y actualizar todas las posiciones del vector de estudiantes:
     *  - Utiliza la acción readStudent para pedir la información de un estudiante y guardarla en el vector de estudiantes.
     *  - Utiliza la acción updateTeacherStudent para actualizar el identificador de profesor para el estudiante leído anteriormente.
     * */
    int i;
    tStudentVector svector;
    
    for(i = 0; i <= STUDENT_VECTOR_LEN; i++) {
        // Request student information
        readStudent(&svector.student[i]);

        // Request teacher for this student
        updateTeacherStudent(tvector, &svector.student[i]);
    }


    /* 3) Recorre todas las posiciones del vector de la variable tStudentVector 
     * - Utiliza la acción writeStudent para escribir la información necesaria de cada uno de los estudiantes.
     * */
    for(i = 0; i <= STUDENT_VECTOR_LEN; i++) {
        writeStudent(svector.student[i]);
    }
    
    return 0;
}
