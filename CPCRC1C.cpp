#include <iostream>
#include <map>
using namespace std;
int sum(long int n);
map<long int,int> store;
int main()
{
    std::ios::sync_with_stdio(false);
    long int n=-1,m=-1;
    long long int total;
    cin>>n>>m;
    store.clear();
    while(n!=-1 && m!=-1)
    {
        total=0;
        
        for(long int x=n;x<=m;x++)
        {
            total+=sum(x);
        }
        cout<<total<<endl;
        cin>>n>>m;
    }
    return 0;
}
 int sum(long int n)
{
    if(store.find(n)!=store.end()) return store[n];
    int ld=n%10;
    long int rest=n/10;
    int rec=0;
    if(rest>0) rec=sum(rest);
    store[n]=ld+rec;
    return store[n];
    
    
}
