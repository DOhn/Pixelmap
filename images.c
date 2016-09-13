#include <stdio.h>
#include <stdlib.h>

typedef struct Pixel {
	unsigned char r, g, b, a;
}Pixel;

Pixel *pixmap1d;

int width;
int height;

void buffer() {
	int row, col;
	int dx, dy;

	pixmap1d = malloc(sizeof(Pixel) * width * height);

	for (row = 0; row < height; row += 1) {
		for (col = 0; col < width; col += 1) {
		// Enter code here, k-k-k-k-klappa
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf("Error: Incorrect amount of arguments.  Need 3.");
		return(1);
	}

	width = atoi(argv[1]);
	height = atoi(argv[2]);

	buffer();

	if (atoi(argv[0]) == '3') {
		FILE* fh = fopen("new_p6.ppm", "w");
		fwrite(pixmap1d, sizeof(Pixel), width*height, fh);
		fclose(fh);
	}
	else if (atoi(argv[0] == '6')) {
		FILE* fh = fopen("new_p3.ppm", "w");
		fwrite(pixmap1d, sizeof(Pixel), width*height, fh);
		fclose(fh);
	}
	else {
		fprintf("Error: Can only convert to P3 or P6.");
	}


	return 0;
}