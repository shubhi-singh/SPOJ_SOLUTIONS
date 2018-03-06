#include<iostream>
#define ll long long
ll ar[200001];
ll aux[200001];
ll count;
using namespace std;
void merge(ll ar[],ll aux[],ll i,ll mid,ll f)
{
    ll i1=i;
    ll i2=mid+1;
    for(ll x=i;x<=f;x++)
    {
        aux[x]=ar[x];
    }
    for(ll x=i;x<=f;x++)
    {
        if(i1>mid)
            ar[x]=aux[i2++];
        else if(i2>f)
            ar[x]=aux[i1++];
        else
        {
            if(aux[i1]<=aux[i2])
            {
                ar[x]=aux[i1++];
            }
            else
            {
                count+=(mid-i1+1);
                ar[x]=aux[i2++];
            }
        }
        
    }
    return ;
        
}
void sort(ll ar[],ll aux[],ll i,ll f)
{
    

    if((i<f))
    {
        ll mid=(i+f)/2;
        sort(ar,aux,i,mid);
        sort(ar,aux,mid+1,f);
        merge(ar,aux,i,mid,f);
    }
    return ;
     
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll x=0;x<n;x++)
        {
            cin>>ar[x];
        }
        count=0;
        sort(ar,aux,0,n-1);
        cout<<count<<endl;
    }
    return 0;
            
}