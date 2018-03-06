/*
    Author : RAJON BARDHAN
    AUST CSE 27th Batch
    All my programming success are dedicated to my mom , dad , little sister madhobi , teachers , friends and love TANIA SULTANA RIMY

    Problem Name : PRINT - Prime Intervals ( SPOJ )
    ALGORITHM : Number Theory
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

char check[100000+10];
ll pr[100000+10] , p = 0 ;
int flag[10000000+10] ;

void sieve()
{
    for(int ij=2;ij<=100000;ij++)
    {
        if(check[ij]==NULL)
        {
            pr[p++] = ij ;
            for(int j=ij+ij;j<=100000;j+=ij) check[j] = 'N' ;
        }
    }
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    int T ;
    scanf("%d",&T);

    for(int cas=1;cas<=T;cas++)
    {
        ll a , b ;
        scanf("%lld%lld",&a,&b);

        for(int ij=0;ij<p;ij++)
        {
            ll mod = a%pr[ij] ;
            ll idx = pr[ij] - mod ;
            if(mod==0) idx = 0 ;

            for(int j=idx;j<=b-a;j+=pr[ij])
            {
                if(a+j!=pr[ij])
                {
                    flag[j] = cas ;
                }
            }
        }

        for(int ij=0;ij<=b-a;ij++)
        {
            if(flag[ij]!=cas) printf("%d\n",ij+a);
        }
    }
    return 0;
}