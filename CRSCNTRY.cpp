#include <iostream>
using namespace std;
int main()
{
    int d;
    cin>>d;
    while(d--)
    {
        int agnes[2001];
        int boys[2001];
        int max=0;
        int n;
        int x1=1;
        cin>>n;
        while(n!=0)
        {
            agnes[x1++]=n;
            cin>>n;
        }
        
        
        cin>>n;
        
        while(n!=0)
        {
            int x2=1;
            
           while(n!=0) 
           {
            boys[x2++]=n;
            cin>>n;
           }
            int ar[x1+1][x2+1];
            for( int y=0;y<x1;y++)
            {
                for(int z=0;z<x2;z++)
                {
                    ar[y][z]=0;
                }
            }
            for( int x=1;x<x1;x++)
            {
                for( int y=1;y<x2;y++)
                {
                    if(agnes[x]==boys[y]) ar[x][y]=ar[x-1][y-1]+1;
                    else if (ar[x-1][y]>ar[x][y-1]) ar[x][y]=ar[x-1][y];
                    else ar[x][y]=ar[x][y-1];
                }
            }
            if(ar[x1-1][x2-1]>=max) { max=ar[x1-1][x2-1];}
            
            
            
            
            cin>>n;
           
        }
        cout<<max<<endl;
        
    }
    return 0;
}