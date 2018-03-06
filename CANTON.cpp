#include <stdio.h>
#include <math.h>
#include <string>
int main()

{
    int t;
    scanf("%d", &t);
    while(t--)
    {
    long long a ;
    long long num, denom;
    scanf("%lld", &a);
    long long b = (sqrt(1 + 8*a) - 1) / 2;
    long long a2 = b * (b + 1) / 2;
    long long rem = a - a2;
    if(rem == 0)
    {
        if(b % 2 == 0)
        {
            num = b;
        denom = 1;
        }
        else
        {
            num = 1;
            denom = b;
            
        }
    }
    else 
    {
        if((b + 1) % 2 == 0)
        {
            num = rem;
            denom = b + 1 - rem + 1;
        }
        else 
        {
            denom = rem;
            num = b + 1 - rem + 1;
        }
    }
    printf("TERM %lld IS %lld/%lld\n", a, num, denom);
    }
    return 0;
}