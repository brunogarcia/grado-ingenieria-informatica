#include "data.h"

tError si_getSectionInfo(tBookTable tabB, tSectionTable tabS, char sectionId, tSectionInfo *si );

tBook si_getBook(tBookTable tabB, tSectionInfo si, unsigned int nSub, unsigned int nBook);

void si_listSectionInfo(tBookTable tabB, tSectionInfo si );

// Add subsection
void si_add_subsection(tSectionInfo *si, char subSectionId, int bookPosition);

// Search subsection
tBoolean si_search_subsection(tSectionInfo *si, char subSectionId);