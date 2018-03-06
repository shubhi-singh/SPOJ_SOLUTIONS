#include <iostream>
#include <list>
#include <queue>
#include <iomanip>
#include <stdio.h>
#define pdi pair<double,int>
using namespace std;
list<struct info> ar[101];
struct info
{
    int edge;
    double p;
};
int main()
{

    int n,m;
    cin>>n;
    while(n!=0)
    {
        cin>>m;
        for(int x=1;x<=n;x++)
            ar[x].clear();
        double dist[101];
        int f[101];
        for(int x=0;x<m;x++)
        {
            int source,end,p;
            cin>>source>>end>>p;
            struct info temp1;
            temp1.edge=end;
            temp1.p=p/100.0;
            ar[source].push_back(temp1);
            struct info temp2;
            temp2.edge=source;
            temp2.p=p/100.0;
            ar[end].push_back(temp2);
            
            
        }
        std::priority_queue<pdi,vector<pdi> > v;
        for(int x=1;x<=n;x++)
        {
            dist[x]=-1;
            f[x]=0;
            
        }
       
           
        v.push(pdi(1.0,1));
        dist[1]=1;
        while(!v.empty())
        {int index=v.top().second;
            
            
            v.pop();
            
            if(f[index]) continue;
            for(list<struct info>:: iterator i=ar[index].begin();i!=ar[index].end();i++)
            {
                int current=i->edge;
                double p=i->p;
               
                if(f[current]==0)
                {
                    double temp=dist[index]*p;
                    if(temp>dist[current]) 
                    { 
                        dist[current]=temp;
                        
                        v.push(pdi(temp,current));
                    }
                }
            }
            f[index]=1;
            if(index==n) break;
        }
        double g=dist[n]*100.0;
        int t=0;
        if(g<10) t=8;
        else t=9;
       
        printf("%.6f percent\n",(g+0.000000000000000001));
        
        cin>>n;
        
    }
    return 0;
}