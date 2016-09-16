#include <stdio.h>
#include <stdlib.h>

void sameType(FILE *fh, FILE *out, char* get) {
	while(fgets(get, 100, fh) != NULL) {
		fputs(get, out);
	}
	fclose(out);
}

void convertToP3(FILE *fh, FILE *out, char* get, int size) {
	// Use new buffer to get unsigned char instead of char
	unsigned char* buff = (unsigned char*)get;
	unsigned char num;
	int i;

	// Iterates through the read file by each character
	while(fread(buff, size, 1, fh)) {
		for (i=0; i<size; i++) {
			num = buff[i];
			// Rewrites the data as ASCII
			fprintf(out, "%u \n", num);
		}
	} 
}

void convertToP6(FILE *fh, FILE *out, char* get, int size) {
	// fgetc and atoi
	// fwrite(ptr, size, nmemb, stream)
	unsigned char* buff = (unsigned char*)get;
	unsigned char num;
	int i;
	
	while(fread(buff, size, 1, fh)) {
		for (i=0; i<size; i++) {
			num = buff[i];
			atoi(num);
			fwrite(num, size, 1, out);
		}
	}
}

int main(int argc, char *argv[]) {
	// Checks if correct amount of arugments are inserted.
	if (argc != 4) {
		printf("Error: Incorrect amount of arguments.  Three is needed.\n");
		return(1);
	}

	// Checks if first argument is valid.
	if (strncmp(argv[1], "P6", 2) == 1 || strncmp(argv[1], "P3", 2) == 1) {
		printf("Error: First Argument must be in P3 or P6.\n");
		return(1);
	}

	FILE *fh;
	fh = fopen(argv[2], "r");

	if(fh == NULL) {
		perror("Error: Couldn't open file.");
		return(-1);
	}

	int i, color;
	int op_type;
	char type[2];

	FILE *out;
	out = fopen(argv[3], "w+");

	char* get = malloc(500); 
	int size = 500;

	while(1) {	
		get = fgets(get, 100, fh);	
		
		if (strcmp(get, "P3\n") == 0 || strcmp(get, "P6\n") == 0) {
			type[0] = get[0];
			type[1] = get[1];
			if (strncmp(type, argv[1], 2) == 0) {
				fputs(get, out);
				get = fgets(get, 100, fh);
				op_type = 0;
			} 
			else {
				fputs(argv[1], out);
				fputs("\n", out);
				get = fgets(get, 100, fh);
				op_type = 1;
			}
		}

		if (get[0] == '#') {
			continue;
		}
		else {
			fputs(get, out);
		}

		if (strcmp(get, "255\n") == 0) {
			color = atoi(get);
			break;
		}
	}

	if (op_type == 0) {
		sameType(fh, out, get);
	} 
	else {
		if (strncmp("P6", argv[1], 2) == 0) {
			convertToP6(fh, out, get, size);
		} 
		else {
			convertToP3(fh, out, get, size);
		}
	}

	fclose(fh);
	return(0);
}