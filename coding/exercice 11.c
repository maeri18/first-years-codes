#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int *p; // declration du pointeur
    i = 5;
    p = &i;
    printf("%d\n", i);
    *p = 4;
    printf("%d\n", i);
    return 0;
}

