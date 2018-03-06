#include<iostream>
#include<queue>
#include <map>
#include <vector>
#include<string>
#include <functional>
#include <string>
#define pii pair<int,int>
using namespace std;
vector<vector<vector<int> > > ar(10001,vector<vector<int> >(0,vector<int>(2)));
int finalised[10001];
map<string,int> key;
long int dist[10001];
int added[10001];



int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        key.clear();
       
        for(int x=1;x<=n;x++)
        {
            ar[x].clear();
            string name;
            cin>>name;
            key[name]=x;
            int freq;
            cin>>freq;
            while(freq--)
            {
                int index,cost;
                cin>>index>>cost;
                vector <int> temp1(2);
                temp1[0]=index;
                temp1[1]=cost;
                
                ar[x].push_back(temp1);
               
                
                
            }
            
        }//input test cases done
       
        int r;
        cin>>r;
        while(r--)
        {
          
        string source,end;
        cin>>source>>end;
        int a1=key[source];
        int a2=key[end];
        
          std::priority_queue< pii, vector<pii>, greater<pii> > v; 
        v.push(pii(0,a1));
        for(int x=1;x<=n;x++)
        {
            added[x]=0;
            dist[x]=200001;
            finalised[x]=0;
        }
         dist[a1]=0;
        while(!v.empty())
        {
            int index=v.top().second;
         
            v.pop();
            if(finalised[index]) continue;
            for(vector<vector<int> > ::iterator i=ar[index].begin();i!=ar[index].end();i++)
            {
                int current=(*i)[0];
                if(finalised[current]==0)
                {
                int temp=dist[index]+(*i)[1];
                if(temp<dist[current]) dist[current]=temp;
                v.push(pii(dist[current],current));
                }
            }
               finalised[index]=1;
           
            
            if(index==a2) break;
            
        }
        cout<<(dist[a2])<<endl;
        }
       
        
        
       
        
        
    }
    return 0;
    
}