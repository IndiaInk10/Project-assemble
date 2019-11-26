#include "func.h"

int main(void) {
	system("mode con cols=100 lines=30");

	DLINKEDLIST *sDLL = (DLINKEDLIST*)malloc(sizeof(DLINKEDLIST));
	DLINKEDLIST *vDLL = (DLINKEDLIST*)malloc(sizeof(DLINKEDLIST));
	dlSInit(sDLL);
	dlVInit(vDLL);

	dlInputFile(sDLL, "Subs.txt");
	dlInputFile(vDLL, "Videos.txt");

	Sleep(1000);

	Menu(sDLL, vDLL);

	return 0;
}