#include <stdio.h>

int main(int argc, char *argv[])
{
    int f0, f1, f2;

    // initialize variables and write the while loop
    // Remember to update all variables within the loop
	f0 = 0;
	f1 = 1;

	printf("\t %d \n", f0);
	printf("\t %d \n", f1);

	while (f0 < 100) {
		f0 = f1 + f2;
		f2 = f1;
		f1 = f0;
		printf("\t %d \n", f0);
	}

    return 0;
}
