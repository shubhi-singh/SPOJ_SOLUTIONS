#include <iostream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
    int t;
    int ar[100][100];
    int move[]={-1,0,+1};
    cin>>t;
    while(t--)
    {
        int n,m;
        long int ar1[100];
        long int ar2[100];
        cin>>n>>m;
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                cin>>ar[x][y];
                if(x==(n-1)) { ar1[y]=ar[x][y];ar2[y]=0;}
            }
            
        }
        for(int x=(n-2);x>=0;x--)
        {
            for(int y=0;y<m;y++)
            {
                long int max=0;
                for(int z=0;z<3;z++)
                {
                    int add=y+move[z];
                    if(add>=0 && add<m)
                    {
                        if(ar1[add]>max) max=ar1[add];
                    }
                }
                ar2[y]=ar[x][y]+max;
            }
   
            for(int y=0;y<m;y++)
            {
                ar1[y]=ar2[y];ar2[y]=0;
            }
        }
        long int max=0;
        for(int x=0;x<m;x++)
        {
            if(ar1[x]>max) max=ar1[x];
        }
        cout<<max<<endl;
        
    }
    return 0;
    
}