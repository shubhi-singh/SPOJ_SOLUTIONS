#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define UL 1000000001
 
using namespace std;
bool isPrime[100002];
int primes[100002];
int main()
{
   
    int t,x,y,c;
    scanf("%d", &t);
    while(t--)
    {
        int n,m,sqrtm,pcount=0;
        scanf("%d %d", &n,&m);
        sqrtm=(int) sqrt(m);
    
     
    int k=(int) sqrt(sqrtm);
    memset(isPrime+2,true,sizeof(bool)*(sqrtm -1 ));
    for( x = 2;x <= k ;x++)
        if(isPrime[x] == true)
        {
           
            for( y = 2*x;y <= sqrtm;y += x)
            {
                isPrime[y]=false;
            }
        }
    for(x = 2;x <= sqrtm;x++)
        if(isPrime[x]) primes[pcount++]=x;
 memset(isPrime,true,sizeof(bool)*(m-n+1));
    for( x = 0;x < pcount;x++)
    {
         c = ((int)(n / primes[x]) * primes[x]);
        
        for( y = c;y <= m;y += primes[x] )
 
        {    if(y < n) continue;
            isPrime[y-n]=false;
            
        }
    
    
    }
     for( x = 0;x < pcount;x++)
         if(primes[x] >= n  && primes[x] <= m) printf("%d\n",primes[x]);
     for( x = 0;x < m-n+1;x++)
         if(isPrime[x] && (x + n) != 1 ) printf("%d\n",x+n);
    }
    return 0;
}
 