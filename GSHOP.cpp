#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,k2;
        long int ar[100];
        long long int total=0;
        cin>>n>>k2;
        int k=k2;
        long int positive=0;
        long int negative=0;
        long int left=0;
        int pcount=0;
        int ncount=0;
        int zero=0;
        long int min=100007;
        for(int x=0;x<n;x++)
        {
            cin>>ar[x];
            long int mod=ar[x]>=0? ar[x]:ar[x]*-1;
            if(mod<min) min=mod;
            if(ar[x]<0)
            {
                ncount++;
                if(k!=0){k--; negative+=(ar[x]*-1);ar[x]=ar[x]*-1; }
                else left+=(ar[x]*-1);
            }
            else if(ar[x]>0) { positive+=ar[x];pcount++;}
            else if(ar[x]==0) zero++;
        }
        if(ncount==0 && pcount!=0)
        {
            total=positive;
            if(k2%2!=0 && zero==0) total=positive-2*ar[0];
            
        }
        else if(ncount!=0 && pcount==0)
        {
            if(ncount>k2) total=negative-left;
            else if(ncount==k2) total=negative; 
            else { 
                   if((k2-ncount)%2!=0) { ar[n-1]=ar[n-1]*-1;
                   total=negative+2*ar[n-1];}
                   else total=negative;
                 }
        }
        else if(ncount!=0 && pcount!=0)
        {
           
            if(ncount>k2) total=negative-left+positive;
            else if(ncount==k2) total=negative+positive;
            else {
                if((k2-ncount)%2!=0 && zero==0) 
            total=negative+positive-2*min;
                if((k2-ncount)%2!=0 && zero!=0) total=negative+positive ;
                if((k2-ncount)%2==0) total=positive+negative;
            }
        }
        
        cout<<total<<endl;
    }
    return 0;
}