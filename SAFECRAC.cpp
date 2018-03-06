#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;
list<int> ar[10];
long int length;
long long int total;
long long int count[10];
long long int count2[10];
int visited[10];
void dfs(int vertex)
{
    
    visited[vertex]=1;
    long long int temp=0;
    for(list< int>::iterator i=ar[vertex].begin(); i!=ar[vertex].end(); i++)
    {
        temp+=count[*i];
        temp%=1000000007;
    }
    count2[vertex]=temp;
    return ;
}
int main()
{
    int q;
    scanf("%d",&q);
    ar[0].push_back(7);
    ar[1].push_back(2);
    ar[1].push_back(4);
    ar[2].push_back(1);
    ar[2].push_back(3);
    ar[2].push_back(5);
    ar[3].push_back(2);
    ar[3].push_back(6);
    ar[4].push_back(1);
    ar[4].push_back(5);
    ar[4].push_back(7);
    ar[5].push_back(2);
    ar[5].push_back(4);
    ar[5].push_back(6);
    ar[5].push_back(8);
    ar[6].push_back(3);
    ar[6].push_back(5);
    ar[6].push_back(9);
    ar[7].push_back(0);
    ar[7].push_back(4);
    ar[7].push_back(8);
    ar[8].push_back(5);
    ar[8].push_back(7);
    ar[8].push_back(9);
    ar[9].push_back(6);
    ar[9].push_back(8);
    std::ios::sync_with_stdio(false);
    while(q--)
    {
        total=0;
        scanf("%ld",&length);
        for(int x=0;x<10;x++) count[x]=1;
        for(int y=2;y<=length;y++)
        {
            
        for(int x=0;x<10;x++)
        {
        dfs(x);
        
        }
        for(int x=0;x<10;x++)
        {
            count[x]=count2[x];
        }
        }
        for(int x=0;x<10;x++)
        {
            total+=count[x];
        total%=1000000007;
        }
        printf("%lld\n",total);
        
        
    }
    return 0;
}