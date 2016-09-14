#include <stdio.h>
#include <stdlib.h>

// typedef struct Pixel {
// 	unsigned char r, g, b, a;
// }Pixel;

// Pixel *pixmap1d

void sameType(FILE *fh, FILE *out, char* get) {
	while(fgets(get, 100, fh) != NULL) {
		fputs(get, out);
		// if (fh == NULL) {
		// 	printf("This was the error.");
		// 	break;
		// }
	}
}

void convertP3(input, output) {

}

void convertP6(input, output) {

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

	FILE *out;
	out = fopen(argv[3], "w+");

	FILE *fh;
	fh = fopen(argv[2], "r");

	int i, color;
	int op_type;
	char type[2];

	if(fh == NULL) {
		perror("Error: Couldn't open file.");
		return(-1);
	}

	char* get = malloc(500);
	
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
			get = fgets(get, 100, fh);
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

	// printf("%c%c\n", type[0], type[1]);
	// printf("%i\n", color);

	fclose(fh);
	return(0);

	// int read
	// read = atoi(argv[1]);

	// printf("%s", read);
	
	// ATOI IS USED TO CONVERT CHAR INTO INT
	// Could be used to get total amount of chars
	// within a text file

	// buffer();

	// if (atoi(argv[0]) == '3') {
	// 	FILE* fh = fopen("new_p6.ppm", "w");
	// 	fwrite(pixmap1d, sizeof(Pixel), width*height, fh);
	// 	fclose(fh);
	// }
	// else if (atoi(argv[0] == '6')) {
	// 	FILE* fh = fopen("new_p3.ppm", "w");
	// 	fwrite(pixmap1d, sizeof(Pixel), width*height, fh);
	// 	fclose(fh);
	// }
	// else {
	// 	fprintf("Error: Can only convert to P3 or P6.");
	// }

	return 0;
}