#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
   
    std::ios::sync_with_stdio(false);
    while(t--)
    {
         long long int sum=0;
    long long int var=0;
    long long int n=0;
        cin>>n;
        
        for(long long int x=0;x<n;x++)
        {
            cin>>var;
            sum=(sum+var)%n;
            var=0;
            
        }
        
        if(sum==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}