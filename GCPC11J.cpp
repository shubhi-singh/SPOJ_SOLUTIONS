#include <iostream>
#include <list>
using namespace std;
list< int> ar[100000];
int visited[100000];
int m;
int var_max;
int n;
void dfs(int start,int d);
void empty();
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
      
        cin>>n;
        empty();
        for(int x=0;x<(n-1);x++)
        {
            int start,end;
            cin>>start>>end;
            ar[start].push_back(end);
            ar[end].push_back(start);
        }
        m=-1;
        var_max=0;
        dfs(0,0);
        
        for(int x=0;x<n;x++)
        {
            visited[x]=0;
          
        }
        m=-1;
        dfs(var_max,0);
        int d=m;
        int TTL=(d%2==0)?d/2:(d+1)/2;
        cout<<TTL<<endl;
    }
    return 0;
}
void dfs(int start,int d)
{
    visited[start]=1;
    for(list<int>::iterator i=ar[start].begin();i!=ar[start].end();i++)
    {
        if(visited[*i]==0)
        {
            int new_dist=d+1;
            if(new_dist>m) { m=new_dist;var_max=*i;}
            dfs(*i,new_dist);
        }
    }
    return;
    
}

void empty()
{
     for(int x=0;x<n;x++)
        {
            ar[x].clear();
            visited[x]=0;
            
    
         }
     return ;
}