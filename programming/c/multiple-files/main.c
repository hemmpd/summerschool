#include "functions.h"

int main(void) {
	field f;

	init_field(&f, NX, NY);
	laplacian(&f);
	print_field(&f);

   return 0;
}
