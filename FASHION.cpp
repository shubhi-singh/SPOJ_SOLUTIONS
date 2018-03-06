#include <iostream>
using namespace std;
int ar1[10001];
int ar2[10001];
void sort(int *n,int l1,int l2);
void merge(int *n,int l1,int l2);
int main()
{
   std::ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
      
       int x=0;
       while(x<n)
       {
           cin>>ar1[x];
           x++;
       }
     
       x=0;
       while(x<n)
       {
           cin>>ar2[x];
           x++;
       }
 
       
      
       sort(ar1,0,n-1);
       sort(ar2,0,n-1);
       int total=0;
       x=0;
       while(x<n)
       {
           total+=(ar1[x]*ar2[x]);
           x++;
       }
       cout<<total<<endl;
       
   }
   return 0;
}
void sort(int *n,int l1,int l2)
{
    int mid=(l1+l2)/2;
    if(l1<l2)
    {
        sort(n,l1,mid);
        sort(n,mid+1,l2);
        merge(n,l1,l2);
       
        
    }
    return ;
}
void merge(int *n,int l1,int l2)
{
    int mid=(l1+l2)/2;
    int mid2=mid+1;
    int l=0;
    int i=l1;
    int arr[l2-l1+1];
    while(l<(l2-l1+1))
    {
        if(*(n+i)<=*(n+mid2))
        {
            arr[l++]=*(n+i);i++;
        }
        else {
            arr[l++]=*(n+mid2);mid2++;
        }
        if(i>mid)
        {
            while(l<(l2-l1+1)){ arr[l++]=*(n+mid2);mid2++;}
            
        
        } else if( mid2>l2) while(l<(l2-l1+1)) {arr[l++]=*(n+i);i++;}
    }
    for(int x=0;x<l;x++)
    {
       *(n+l1)=arr[x];
       l1++;
    }
    return ;
    
}
    