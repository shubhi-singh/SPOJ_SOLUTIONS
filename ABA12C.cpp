#include <iostream>
#include <string.h>
#define ll long long
using namespace std;
int price [101];
int dp[101];
int k;
int rec(int val)
{
    if(dp[val]!=-2) return dp[val];
    int min=-1;
    for(int x=1;x<=k;x++)
    {
        if(price[x]!=-1 && x<=val)
        {
            int rem=val-x;
            int temp=rec(rem);
            if(temp!=-1)
            {
                if(min==-1)
                    min=temp+price[x];
                else if(temp+price[x]<min) min=temp+price[x];
            }
        }
    }
    dp[val]=min;
    return min;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n>>k;
       for(int x=0;x<101;x++)
       {
           price[x]=-1;
           dp[x]=-2;
       }
       dp[0]=0;
      
       for(int x=1;x<=k;x++) cin>>price[x];
       cout<<rec(k)<<endl;
    }
    return 0;
}