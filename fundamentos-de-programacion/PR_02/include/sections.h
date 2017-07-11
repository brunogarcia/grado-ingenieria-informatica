#include "data.h"

/* Get a textual representation of a section */
void getSectionStr(tSection section, int maxSize, char *str);

/* Get a section object from its textual representation */
tError getSectionObject(const char *str, tSection *section);

/* Compare two sections */
int section_cmp(tSection s1, tSection s2);

/* Copy the section data in src to dst*/
void section_cpy(tSection *dst, tSection src);

/* Initialize the table of sections */
void secTable_init(tSectionTable *tabSec);

/* Add a new section to the table of sections */
tError secTable_add(tSectionTable *tabSec, tSection section);

/* Find a section in the table */
int secTable_find(tSectionTable tabSec, char sectionId);

/* Remove the first occurence of a section in the table */
void secTable_del(tSectionTable *tabSec, tSection section);

/* Load the table of sections from a file */
tError secTable_load(tSectionTable *tabSec, const char* filename);

/* Save a table of sections to a file */
tError secTable_save(tSectionTable tabSec, const char* filename);
