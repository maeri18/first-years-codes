#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t[7] = {1,0,3,4,0,6,3};
    float i=0;
    while(i<7)
    {
    if(t[(int)i]==0)
     printf("%0.f\n", i);
    i++;
    }

}
