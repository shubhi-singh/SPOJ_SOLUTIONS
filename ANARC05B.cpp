#include <iostream>
using namespace std;
int ar1[10001];
int ar2[10001];
 int l1,l2;
int bsearch(int n);
int main()
{     
    std::ios::sync_with_stdio(false);
    while(1)
    {
        
        cin>>l1;
        if(l1!=0) 
        {
            int temp=0;
        long long int total=0;
        int index_count=0;
            int index1[l1+1]; long int csum1[l1+1];
            while(temp<l1) {
                cin>>ar1[temp];
                if(temp==0)  csum1[temp]=ar1[temp];
                else csum1[temp]=csum1[temp-1]+ar1[temp];
                temp++;
          
            }
            cin>>l2;
            int index2[l2+1]; long int csum2[l2+1];temp=0;
            while(temp<l2)
            {
                cin>>ar2[temp];
                if(temp==0)  csum2[temp]=ar2[temp];
                else csum2[temp]=csum2[temp-1]+ar2[temp];
                temp++;
            
            }
            for(int x=0;x<l1;x++)
            {
                int status=bsearch(ar1[x]);
                if(status!=-1){ index1[index_count]=x; index2[index_count++]=status; }
            }

            if(index1[index_count-1]==(l1-1)) {index1[index_count]=l1;csum1[l1]=csum1[l1-1];}
            else index1[index_count]=l1-1;
            if(index2[index_count-1]==(l2-1)) {index2[index_count]=l2;csum2[l2]=csum2[l2-1];}
            else index2[index_count]=l2-1;
            for(int x=0;x<=index_count;x++)
            {
                int add1=0;
                int add2=0;
                if(x!=0) {add1=csum1[index1[x-1]];add2=csum2[index2[x-1]];}
                add1=csum1[index1[x]]-add1;
                add2=csum2[index2[x]]-add2;
          
                total+=(add1>add2?add1:add2);

           
            }
            cout<<total<<endl;
            
            
            
            
        } else break;
        
        
        
    }
    return 0;
}
int bsearch(int n)
{
    int start=0;int end=l2-1;
    int mid=(start+end)/2;
    while(start<=end)
    {
        if(ar2[mid]==n) {return mid;}
        if(ar2[mid]>n) end=mid-1;
        else start=mid+1;
        mid=(start+end)/2;
    }
    return -1;
}