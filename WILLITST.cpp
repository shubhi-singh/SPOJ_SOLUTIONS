#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long a ;
    scanf("%llu", &a);
    int power = (int)(log2(a) / log2(2));
    unsigned long long raised = (unsigned long long)(pow(2, power));
    if((a - raised) == 0) 
        printf("TAK\n");
    else printf("NIE\n");
   
    return 0;
}