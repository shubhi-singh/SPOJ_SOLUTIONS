#include <iostream>
#include <list>
using namespace std;
int total;
int visited[10002];
list<int> ar[10002];
int s,t;
void dfs(int s);
int main()
{
	std::ios::sync_with_stdio(false);
    int q=0;
    cin>>q;
    while(q--)
    {
        total=0;
        int c,b;
        cin>>c>>b>>s>>t;
        for(int x=1;x<=b;x++)
        {
            ar[x].clear();
            visited[x]=0;
        }
        for(int x=1;x<=b;x++)
        {
            int source,end;
            cin>>source>>end;
            ar[source].push_back(end);
            
            
        }
        if(s!=t)
        {dfs(s);
        cout<<total<<endl;}
        else cout<<1<<endl;
        
        
    }
    return 0;
}
void dfs(int source)
{
    visited[source]=1;
    list<int>::iterator i;
    for(i=ar[source].begin();i!=ar[source].end();i++)
    {
        int end=*i;
        if(visited[end]==0)
        {
            if(end==t) {total++;}
            else dfs(end);
            
        }
    } visited[source]=0;
    
    
    return ;
}