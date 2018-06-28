#include <stdio.h>
#include "pngwriter.h"

#define NX 256
#define NY 256
#define DX 0.01
#define DY 0.01

typedef struct {
	//Grid points
	int nx;
	int ny;

	//Spacing
	double dx;
	double dy;

	//Square of the spacing
	double dx2;
	double dy2;

	//Array for the data points
	double array[NX+2][NY+2];

} tempfield;

void init_tempfield(tempfield *f, int nx, int ny) {
	f->nx = nx;
	f->ny = ny;
	f->dx = DX;
	f->dy = DY;
	f->dx2 = DX*DX;
	f->dy2 = DY*DY;

	for (int i=1; i<nx; i++)
		for (int j=1; j<ny; j++)
			f->array[i][j] = 0;

	for (int i=0; i<nx+1; i++) {
		f->array[0][i] = 85;
		f->array[nx-1][i] = 5;
	}

	for (int j=0; j<ny+1; j++) {
		f->array[j][0] = 20;
		f->array[j][ny-1] = 70;
	}
}

void laplacian(tempfield *f) {
	double lap[NX+2][NY+2];

	for (int i = 1; i < f->nx; i++) {
		for (int j = 1; j < f->ny; j++) {
			lap[i][j] =
				(f->array[i-1][j] - 2*f->array[i][j] + f->array[i+1][j])/(DX*DX) +
				(f->array[i][j-1] - 2*f->array[i][j] + f->array[i][j+1])/(DY*DY);
		}
	}

	for (int i = 1; i < f->nx; i++) {
		for (int j = 1; i < f->ny; j++) {
			f->array[i][j] = lap[i][j];
		}
	}
}

void print_field(tempfield *f) {
	int error_code;

	error_code =
		save_png((double *) f->array, f->nx + 2, f->ny + 2, "figure.png", 'c');

	if (error_code ==0) {
		printf("did figure.png");
	} else {
		printf("errorerror");
	}
}

int main() {
	tempfield f;

	init_tempfield(&f, NX, NY);
	laplacian(&f);
	//print_field(&f);

	return 0;
}
