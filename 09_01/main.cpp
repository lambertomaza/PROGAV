#include <iostream>
#include <stdlib.h>
#include "tddprogdetallado.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	struct prog_detallado *SOTR  = (struct prog_detallado *)
				malloc(sizeof(struct prog_detallado*));
	prog_detallado(SOTR);
	system("pause");
	return 0;
}
