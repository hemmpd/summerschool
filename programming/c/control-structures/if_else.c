#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 54;

    // write the control structure as described in the exercise
    // and run the code with different values for i
    if (i < 0) {
        printf("Integer is negative\n");
    } else if (i == 0) {
        printf("Integer is zero\n");
    } else if (i > 100) {
	printf("Integer is greater than 100\n");
    } else {
	printf("Something else\n");
    }

    return 0;
}
