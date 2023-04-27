#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp = fopen("fred2.txt", "w+");
	if (fp  == NULL) {
		fputs("Cannot open fred.txt file\n", stderr);
		return EXIT_FAILURE;
	}
	fpos_t pos;
	if (fgetpos(fp, &pos) != 0) {
		perror("get position");
		return EXIT_FAILURE;
	}
	if (fputs("abcdefghijklmnopqrstuvwxyz", fp) == EOF) {
		fputs("Cannot write to fred.txt file\n", stderr);
	}
	if (fsetpos(fp, &pos) != 0) {
		perror("set position");
		return EXIT_FAILURE;
	}
	long int fpi = ftell(fp);
	if (fpi == -1L) {
		perror("seek");
		return EXIT_FAILURE;
	}
	printf("file position = %ld\n", fpi);
	if (fputs("0123456789", fp) == EOF) {
		fputs("Cannot write to fred.txt file\n", stderr);
	}
	if (fclose(fp) == EOF) {
		fputs("Failed to close file\n", stderr);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
