#include <stdio.h>

void add_one_to_both(int *a, int *b) {
    (*a)++;
    (*b)++;
}

int main() {
    int a, b;
    a = 10;
    b = 20;
    add_one_to_both(&a, &b);

    printf("a=%d\n", a);
    printf("b=%d\n", b);

	return 0;
}
