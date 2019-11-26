#include "func.h"
#include "phoneInfo.h"

int main(void) {

	DLINKEDLIST *DLL = (DLINKEDLIST*)malloc(sizeof(DLINKEDLIST));
	dlInit(DLL);

	menu(DLL);
}