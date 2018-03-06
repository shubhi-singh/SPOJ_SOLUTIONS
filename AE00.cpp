#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int total=0;
    if(n==1){ cout<<1<<endl; return 0;}
    for(int x=1;x<=n;x++)
    {
        
        int fact=0;
        for(int y=1;y<=sqrt(x);y++)
        {
            if((x%y)==0)
            {
                fact++;
            }
        }
        total+=fact;
    }
    cout<<total<<endl;
    return 0;
}