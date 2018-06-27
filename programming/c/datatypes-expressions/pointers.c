#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    // declare a pointer variable and assign it to address of e.g. a
	int *p;

    // Evaluate expressions using both the original and the pointer variable
    // and investigate the value / value pointed to
	a = 10;
	b = 4;
	c = 2;

	p = &a;
	c += (*p) + b;

	printf("c = %d, should be 16\n", c);

	p = &c;
	b += 2*(*p);

	printf("b = %d, should be 36\n", b);

    return 0;
}
