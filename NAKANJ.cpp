#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int addx[]={-2,-1,1,2,-2,-1,1,2};
    int addy[]={1,2,2,1,-1,-2,-2,-1};
    
    while(t--)
    {
        queue< pair<int,int> >Q;
        int visited[8][8];
        int dist[8][8];
        char c1,c2;int r1,r2;
        cin>>c1>>r1>>c2>>r2;
        int startx=c1-'a'; int starty;int endx=c2-'a';int endy;
         starty=8-r1;
        endy=8-r2;
        pair<int,int> temp;
        temp.first=startx;
        temp.second=starty;
        Q.push(temp);
        for(int x=0;x<8;x++)
        {
            for(int y=0;y<8;y++)
            {
                visited[x][y]=0;
                dist[x][y]=0;
            }
        }
        dist[starty][startx]=0;
        visited[starty][startx]=1;
        while(!Q.empty())
        {
            int currentx=(Q.front()).first;
             int currenty=(Q.front()).second;
             Q.pop();
             for( int x=0;x<8;x++)
             {
                 int tempx=currentx+addx[x];
                 int tempy=currenty+addy[x];
                 if(tempx>=0 && tempx<8 && tempy>=0 &&  tempy<8 && visited[tempy][tempx]==0)
                 {
                     visited[tempy][tempx]=1;
                     dist[tempy][tempx]=dist[currenty][currentx]+1;
                     pair<int,int> temp;
                     temp.first=tempx;
                     temp.second=tempy;
                     Q.push(temp);
                 }
                 
             }
            
            
        }
        cout<<dist[endy][endx]<<endl;
        
        
    }
    return 0;
}