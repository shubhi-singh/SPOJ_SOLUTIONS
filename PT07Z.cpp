#include <iostream>
#include <list>
using namespace std;
int max_d;
int var_max;
void dfs(int source,int dist);
list<int> ar[100001];
int visited[100001];
int main()
{
    int n;
    cin>>n;
    max_d=0;
    var_max=0;
    
    for(int x=1;x<=n;x++)
    {
        ar[x].clear();
        visited[x]=0;
    }
    for(int x=1;x<n;x++)
    {
        int source,end;
        cin>>source>>end;
        ar[source].push_back(end);
        ar[end].push_back(source);
        
        
    }
    dfs(1,0);
    max_d=0;
    for(int x=1;x<=n;x++) visited[x]=0;
    dfs(var_max,0);
    cout<<max_d<<endl;
    return 0;
}
void dfs(int source,int dist)
{
    visited[source]=1;//not needed in a tree
    if(dist>max_d) {max_d=dist; var_max=source;}
    for(list<int> ::iterator i=ar[source].begin();i!=ar[source].end();i++)
    {
        if(visited[*i]!=1)
        dfs(*i,dist+1);
    }
    return ;
    
    
}