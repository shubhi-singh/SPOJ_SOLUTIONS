#include<iostream>
#include<vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,e,t,m,total=0;
    vector<pii> ar[101];
    cin>>n>>e>>t>>m;
    for(int x=1;x<=n;x++)
    {
        ar[x].clear();
    }
    for(int x=1;x<=m;x++)
    {
        int start,end,d;
        cin>>start>>end>>d;
        ar[start].push_back(pii(end,d));
        
    }
    for(int x=1;x<=n;x++)
    {
          std::priority_queue< pii, vector<pii>, greater<pii> > v;
          long  dist[101];int f[101];
          for( int y=1;y<=n;y++)
          {
              dist[y]=200000001;
              f[y]=0;
          }
          dist[x]=0;
          v.push(pii(0,x));
          while(!v.empty())
          {
              
              int index=v.top().second;
              v.pop();
              if(f[index]) continue;
              int size=ar[index].size();
              for(int y=0;y<size;y++)
              {
                  int current=ar[index][y].first;
                  int d=ar[index][y].second;
                  if(f[current]==0)
                  {
                      long int temp=dist[index]+d;
                      if(dist[current]>temp) dist[current]=temp;
                      v.push(pii(dist[current],current));
                  }
              }
              f[index]=1;
              if(index==e) break;
          }
          if(dist[e]<=t) total++;
    }
    cout<<total<<endl;
    
    return 0;
}