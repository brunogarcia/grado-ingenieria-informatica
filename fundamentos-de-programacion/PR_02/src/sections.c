#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sections.h"

void getSectionStr(tSection section, int maxSize, char *str) {
	int length;
	
	length = snprintf(str,maxSize-1,"%c %s", section.id, section.name);			
	str[length]='\0';
}

tError getSectionObject(const char *str, tSection *section) {
	tError retVal = OK;
	
	sscanf(str, "%c %s", &section->id, section->name);

	return retVal;
}

int section_cmp(tSection s1, tSection s2) {
	int retVal = 0;
	
    if (s1.id > s2.id) {
        retVal = 1;
	} else if (s1.id < s2.id) {
        retVal = -1;
    } 
	
	return retVal;
}

void section_cpy(tSection *dst, tSection src) {

	dst->id = src.id; 
	strcpy(dst->name, src.name); 

}


void secTable_init(tSectionTable *tabSec) {
	tabSec->size=0;
}

tError secTable_add(tSectionTable *tabSec, tSection section) {

	tError retVal = OK;
	/* Check if there enough space for the new section */
	if(tabSec->size>=MAX_SECTIONS) {
		retVal = ERR_MEMORY;
	}

	if (retVal == OK){
		/* Add the new section to the end of the table */
		section_cpy(&tabSec->table[tabSec->size],section);
		tabSec->size++;
	}
	
	return retVal;
}


int secTable_find(tSectionTable tabSec, char sectionId) {
	int i;
	int idx = -1;
	
	i=0;
	while(i< tabSec.size && idx==-1) {
		/* Check if the id is the same */
		if(tabSec.table[i].id==sectionId) {
			idx = i;
		}
		i++;
	}
	
	return idx;
}

void secTable_del(tSectionTable *tabSec, tSection section) {
	int i;
    int pos;

	pos = secTable_find(*tabSec,section.id);
	if (pos!=-1){
	/* If the section is found, all the rest of the elements are displaced one position */
		for(i=pos; i<tabSec->size-1; i++) {		
			section_cpy(&tabSec->table[i],tabSec->table[i+1]);
		}
		tabSec->size=tabSec->size-1;		
	}
}


tError secTable_save(tSectionTable tabSec, const char* filename) {
	
	tError retVal = OK;
	FILE *fout=0;
	int i;
	char str[MAX_LINE];
	
	/* Open the output file */
	if((fout=fopen(filename, "w"))==0) {
		retVal = ERR_CANNOT_WRITE;
	} else {
	
        /* Save all sections to the file */
        for(i=0;i<tabSec.size;i++) {
            getSectionStr(tabSec.table[i], MAX_LINE, str);
            fprintf(fout, "%s\n", str);
        }
            
        /* Close the file */
        fclose(fout);
	}
    
	return retVal;
}

tError secTable_load(tSectionTable *tabSec, const char* filename) {
	
	tError retVal = OK;
	FILE *fin=0;
	char line[MAX_LINE];
	tSection newSection;
	
	/* Initialize the output table */
	secTable_init(tabSec);
	
	/* Open the input file */
	if((fin=fopen(filename, "r"))!=NULL) {

		/* Read all the sections */
		while(!feof(fin) && tabSec->size<MAX_SECTIONS) {
			/* Remove any content from the line */
			line[0] = '\0';
			/* Read one line (maximum 511 chars) and store it in "line" variable */
			fgets(line, MAX_LINE-1, fin);
			/* Ensure that the string is ended by 0*/
			line[MAX_LINE-1]='\0';
			if(strlen(line)>0) {
				/* Obtain the object */
				getSectionObject(line, &newSection);
				/* Add the new section to the output table */
				secTable_add(tabSec, newSection);		
			}
		}
		/* Close the file */
		fclose(fin);
		
	}else {
		retVal = ERR_CANNOT_READ;
	}
	

	return retVal;
}
