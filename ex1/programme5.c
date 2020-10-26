#include<stdio.h>
int main()
{
    int p[4] = {1,-2,3,4};
    int *q = p ;
    int d = *q&*q++|*q++;
    printf("c=%d\n",d);
    printf("c=%d \n",*q);


}
//c=-1
//c=3

