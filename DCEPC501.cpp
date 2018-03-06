#include <iostream>
#include <string.h>
#define ll long long
using namespace std;
ll int input_ar[100000];
ll int sum_from[100000];

ll n;
ll int rec(ll pos)
{
   if(sum_from[pos]!=-1) return sum_from[pos];
   ll int max=0;
  
   ll temp2=0;
   if(pos+2<n) temp2=input_ar[pos]+rec(pos+2);
   else temp2=input_ar[pos];
   if(temp2>max) max=temp2;
   if(pos+1<n)
   {
       ll temp1=input_ar[pos]+input_ar[pos+1];
       ll temp2=0;
       if(pos+4<n) temp2=temp1+rec(pos+4);
       else temp2=temp1;
       if(temp2>max) max=temp2;
   }
    if(pos+2<n)
   {
       ll temp1=input_ar[pos]+input_ar[pos+1]+input_ar[pos+2];
       ll temp2=0;
       if(pos+6<n) temp2=temp1+rec(pos+6);
       else temp2=temp1;
       if(temp2>max) max=temp2;
       
   }
   
   sum_from[pos]=max;
   return max;
       
   
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        
        
        cin>>n;
        
        memset(input_ar,0,sizeof(ll int)*100000);
        memset(sum_from,-1,sizeof(ll int)*100000);
        for(ll int x=0;x<n;x++) cin>>input_ar[x];
        
        cout<<rec(0)<<endl;
        
        
        
    }
    return 0;
}