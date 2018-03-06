#include <iostream>
#include <math.h>
using namespace std;
int rec(int x);
int main()
{
    int x;
    cin>>x;
    cout<<rec(x)<<endl;
   
    return 0;
    
}

int rec(int a)
{
    if(a==0) return 0;
    else if(a==1) return 1;
    else if(a==2) return 2;
     int c=sqrt(a)+1;
     int a1,b1;
    while(c>=1)
    {
        if(a%c==0)
        {
            a1=c;
            b1=a/c;
            break;
        }
        c--;
    }
     if(a1==1 || b1==1) return 0;
     return(rec(a1)+rec(b1)); 
    
}