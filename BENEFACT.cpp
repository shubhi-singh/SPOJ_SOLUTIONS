#include <iostream>
#include <stack>
#include <list>
#include <queue>
using namespace std;

struct node
{
    int n;
    long long int d;
};
long long int dist[50001];
int visited[50001];
list<struct node*> nodes[50001];
int last_node(int n,int start);

int main(int argc , char * argv[] )
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int x=0;x<n;x++)
        {
            visited[x]=0;
            dist[x]=0;
            nodes[x].clear();
        }
        for(int x=0;x<n-1;x++)
        {
        long long a,b,c;
        cin>>a>>b>>c;
        struct node *temp=new struct node;
        temp->n=b-1;
        temp->d=c;
        nodes[a-1].push_back(temp);
        
        struct node *temp2=new struct node;
        
        temp2->n=a-1;
        temp2->d=c;
        
        
        nodes[b-1].push_back(temp2);
        
        
        }
    
        int last=last_node(n,0);
        for(int x=0;x<n;x++)
        {
            visited[x]=0;
            dist[x]=0;
        }
        last=last_node(n,last);
        cout<<dist[last]<<endl;
        
    }
 return 0;
    }

 int last_node(int n,int start)
{
    
        
    
    stack<int> index;
    index.push(start);
    int is_visited=index.top();
    while(!index.empty())
    {
      
        visited[is_visited]=1;
        list<struct node*>::iterator i;
        for( i=nodes[is_visited].begin(); i!=nodes[is_visited].end(); i++)
        {
             int pos=(*i)->n;
            
            if(visited[pos]==0)
            {
              
                index.push(pos);
                long long int t=dist[is_visited]+(*i)->d;
                dist[pos]=t;
                break;
            }
        }
        if(i==nodes[is_visited].end() && !index.empty())
            index.pop();
        if(!index.empty())
        is_visited=index.top();
    }
    long long int max=-1;
    int  send=0;
    for( int x=0;x<n;x++)
    {
        if(dist[x]>max)
        {
            max=dist[x];send=x;
        }
    }
     
    return send;
    
    
}