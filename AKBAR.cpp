#include <iostream>
#include <list>
using namespace std;
int visited[1000001];
int c[1000001];
list<int> ar[1000001];
int flag;
int total;
int k;
void dfs(int source,int strength)
{
    if(visited[source]==0) total++;
    else if(visited[source]!=k) flag=1;
    visited[source]=k;

    if(strength!=0)
    {
        for(list<int>:: iterator i=ar[source].begin();i!=ar[source].end();i++)
        {
            int current=*i;
            if(visited[current]!=0 && visited[current]!=k) flag=1;
            if(flag==0 && c[current]==0)
            {
                c[source]=1;
                dfs(current,strength-1);
            }
            else if(flag==1) break;
        }
    }
    return ;
}
int main()
{
	std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,m;
        cin>>n>>r>>m;
        
        flag=0;
        total=0;
        for(int x=1;x<=n;x++)
        {
            ar[x].clear();
            visited[x]=0;
            c[x]=0;
        }
        for(int x=0;x<r;x++)
        {
            int start,end;
            cin>>start>>end;
            ar[start].push_back(end);
            ar[end].push_back(start);
            
        }
        for(int x=0;x<m;x++)
        {
             int s;
            cin>>k>>s;
            if(flag==0)
            dfs(k,s);
            
        }
        if(flag==0 && total==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
