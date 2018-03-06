#include <iostream>
#include <vector>
#include <list>
using namespace std;
void dfs( int x);
list < int>  ar[100001];

int visited[100001];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int count=0;
        int n;
        cin>>n;
        int c;
        cin>>c;
        for(int x=0;x<n;x++)
        {
            ar[x].clear();
            visited[x]=0;
        }
        
        if(c!=0)
        {
            for(int x=0;x<c;x++)
            {
                 int start,end;
                cin>>start>>end;
                ar[start].push_back(end);
                ar[end].push_back(start);
                
                
            }
        
        for(int x=0;x<n;x++)
        {
            if(visited[x]==0)
            {
                count++;
                dfs(x);
            }
        }
            
        }
        else count=n;
        cout<<count<<endl;
            
        
    }
    return 0;
}
void dfs(int x)
{
    visited[x]=1;
    for(list< int>::iterator i=ar[x].begin();i!=ar[x].end();i++)
    {
         int v=*i;
        if(visited[v]==0) dfs(v);
        
    }
    return ;
}