#include <stdio.h>
#include <stdlib.h>

// typedef struct Pixel {
// 	unsigned char r, g, b, a;
// }Pixel;

// Pixel *pixmap1d;

int width;
int height;

// void buffer() {
// 	int row, col;
// 	int dx, dy;

// 	pixmap1d = malloc(sizeof(Pixel) * width * height);

// 	for (row = 0; row < height; row += 1) {
// 		for (col = 0; col < width; col += 1) {
// 		// Enter code here, k-k-k-k-klappa
// 		}
// 	}
// }

int main(int argc, char *argv[]) {
	if (argc > 3) {
		printf("Error: Too little arguments.");
		return(1);
	}
	if (argc < 3) {
		printf("Error: Too many arguments.");
		return(1);
	}

	if (argc != 3) {
		printf("Error: Incorrect amount of arguments.  Three is needed.");
		return(1);
	}

	FILE *fh;
	int n, i;

	fh = fopen(argv[2], "r");

	if(fh == NULL) {
		perror("Error: Couldn't open file.");
		return(-1);
	}

	char* get = malloc(420*69);
	
	while(1) {
		get = fgets(get, 100, fh);
		if (strcmp(get, "P3\n") == 0) {
			printf("Dank brah.\n");
		}
		if (get[0] == '#' || get[0] == ' ') {
		  get = fgets(get, 100, fh);
		  i++;
		}

		printf("%s", get);
		if (strcmp(get, "255\n") == 0) {
			break;
		}
	}

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