/* Constants declaration */
#define TEACHER_VECTOR_LEN 4
#define STUDENT_VECTOR_LEN 6

/* Variables declaration */
typedef enum {FALSE=0, TRUE=1} tBool;

/*
 * Tipo de datos tTeacher
 * - Entero positivo idTeacher (el rango de valores irá de 1 a 10).
 * - Booleano bEnglish.
 * - Carácter cLevel (P o S)
 */
typedef struct
{
    unsigned short int idTeacher;
    tBool bEnglish;
    unsigned char cLevel;
} tTeacher;

 /*
 * Tipo de datos tTeacherVector 
 * - Guarda un vector de 4 elementos de tipo tTeacher
 */
typedef struct
{
    tTeacher teacher[TEACHER_VECTOR_LEN];
} tTeacherVector;

 
 /*
 * Tipo de datos tStudent
 * - Entero positivo dni (el rango de valores irá de 1 a 999)
 * - Booleano bEnglish
 * - Carácter cLevel
 * - Entero idTeacher
 */
typedef struct
{
    unsigned short int dni;
    tBool bEnglish;
    unsigned char cLevel;
    short int idTeacher;
} tStudent;
 
/* 
 * Tipo de datos tStudentVector
 *  - Guarda un vector de 6 elementos de tipo tStudent
 * */
typedef struct
{
    tStudent student[STUDENT_VECTOR_LEN];
} tStudentVector;

/*
 * Acción fillTeachersVector
 * - Tiene que devolver una variable de tipo tTeacherVector
 * */
 void fillTeachersVector(tTeacherVector *tvector);
 
 /*
  * Acción readStudent
  * - Lea del canal de entrada estándar *parte* de la información de un estudiante 
  * - Y la guarde en una variable de tipo tStudent. 
 **/
 void readStudent(tStudent *tstudent);
 
 /*
  * Acción writeStudent:
  * - dada una variable de tipo tStudent 
  * - escriba por el canal de salida estándar, el valor de las variables:
  *     - dni
  *     - y idTeacher
**/
void writeStudent(tStudent tstudent);

/* Acción updateTeacherStudent
 * - Dada una variable de tipo tTeacherVector y una variable de tipo tStudent
 * - Devuelva esta última variable con el valor de idTeacher actualizado
**/
void updateTeacherStudent(tTeacherVector tvector, tStudent *tstudent);
