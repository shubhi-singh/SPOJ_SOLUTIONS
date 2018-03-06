#include <iostream>
#define ll long long int
using namespace std;
ll euclid(ll a,ll b)
{
    ll min,max;
    if(a>=b) { max=a;min=b;}
    else { max=b;min=a;}
    if(max%min==0) return min;
    return euclid(max-min,min);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll gcd=euclid(a,b);
        ll lcm=a/gcd*b;
        cout<<lcm/a<<" "<<lcm/b<<endl;
    }
    return 0;
}