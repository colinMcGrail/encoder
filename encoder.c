#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

	FILE *target;
	char *seed;
	char current;
	fpos_t currentpos;
	int seedlength;
	int counter = 0;

	seed = argv[2];

	seedlength = strlen(seed) - 1;

	target = fopen(argv[1], "r+");

	for(;;){
		fgetpos(target, &currentpos);
		if((current = getc(target)) == EOF)
			break;
		current = current + seed[counter++ % seedlength];
		fsetpos(target, &currentpos);
		putc(current, target);
	}
}
