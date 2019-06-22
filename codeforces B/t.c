#include <stdio.h>

int main(void)
{
    int const j = 20;

    /* The below assignment is invalid in C++, results in error
       In C, the compiler *may* throw a warning, but casting is
       implicitly allowed */
    int *ptr = &j;  // A normal pointer points to const

    printf("*ptr: %d\n", *ptr);

    return 0;
}
