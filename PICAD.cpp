#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;
typedef pair<long double ,long double> pii;
pii instant[10001];


void merge(pii ar[],ll i,ll f)
{
    ll mid=(i+f)/2;
    ll mid2=mid+1;
    ll i1=i;
    ll l=0;
    pii temp[f-i+1];
    while(i1<=mid && mid2<=f)
    {
        if(ar[i1].first<=ar[mid2].first)
            temp[l++]=ar[i1++];
        else temp[l++]=ar[mid2++];
    }
    while(l<(f-i+1))
    {
        if(i1<=mid)
            temp[l++]=ar[i1++];
        if(mid2<=f)
            temp[l++]=ar[mid2++];
    }
    for(ll x=i;x<=f;x++)
        ar[x]=temp[x-i];
    return ;
}
void sort(pii ar[],ll i,ll j)
{
    if(i<j)
    {
        ll mid=(i+j)/2;
        sort(ar,i,mid);
        sort(ar,mid+1,j);
        merge(ar,i,j);
    }
    return ;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t=10;
    while(t--)
    {
        int n;
        long double p,k;
        cin>>p>>k;
       
        ll headCount=0;
        ll headCountMax=0;
        ll headCountMin=0;
        ll index=0;
       
        cin>>n;
        
       
        for(ll x=0;x<n;x++)
        {
            long double enter,exit;
            cin>>enter>>exit;
            
         
            instant[index].first=enter;
            instant[index].second=1;
           
            index++;
            instant[index].first=exit+0.5;
            instant[index].second=-1;
              index++;  
        }
        
        sort(instant,0,2*n-1);
        
        for(ll x=0;x<2*n;x++)
        {
            headCount+=instant[x].second;
            if(x==p)  headCountMin=headCount;
            if(instant[x].first>=p && (instant[x].first)<=k)
            {
            if(headCount>headCountMax) headCountMax=headCount;
            if(headCount<headCountMin) headCountMin=headCount;
            }
        }
        cout<<headCountMin<<" "<<headCountMax<<endl;
    }
    return 0;
    
}