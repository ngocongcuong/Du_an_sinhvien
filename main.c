#include <stdio.h>
#include <stdlib.h>
#include "date.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SV d;
	inputSV(&d);
	outputSV(d);
	return 0;
}
