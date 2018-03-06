#include <iostream>
#define ll long long int
using namespace std;
ll gcd(ll n,ll m);
int main()
{
    std::ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    while(n!=-1)
    {
        ll total;
        if(k%2==0)
        {
            total=((k*(k-2))/4);
        }
        else total=((k-1)/2)*((k-1)/2);
        ll total2=(n*(n-1))/2;
        
        if(total==total2) cout<<1<<endl;
        else if(total==0) cout <<0<<endl;
        else cout<<(total/gcd(total,total2))<<"/"<<(total2/gcd(total,total2))<<endl;
        cin>>n>>k;
    }
    return 0;
}
ll gcd(ll n,ll m)
{
    ll min ,max;
    max=n>m?n:m;
    min=n<m?n:m;
    if(max%min==0) return min;
    else {return gcd(max%min,min);}
    
}
