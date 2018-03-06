#include<iostream>
#include <stack>
#include <stdio.h>
using namespace std;
char ar[100][100];
char seq[]={'A','L','L','I','Z','Z','W','E','L','L'};
int r,c;
string res;
struct element
{
    int x;
    int y;
    int atr;
};
struct nav
{
  int a;
  int b;  
};
struct nav move[8];
int visited[100][100];
void DFS(struct element *start,int visited[][100]);
int main()
{
    move[0].a=-1;move[0].b=0;
    move[1].a=1;move[1].b=0;
    move[2].a=0;move[2].b=-1;
    move[3].a=0;move[3].b=1;
    move[4].a=1;move[4].b=1;
    move[5].a=-1;move[5].b=1;
    move[6].a=1;move[6].b=-1;
    move[7].a=-1;move[7].b=-1;
    int t;
    cin>>t;
    while(t--)
    {
        
        res="NO";
        stack<struct element *> A;
        cin>>r>>c;
        for(int x=0;x<r;x++)
            for(int y=0;y<c;y++) {ar[x][y]='0';visited[x][y]=0;}
        
        scanf("%*c");
        for(int x=0;x<r;x++)
        {
            int y;
            for( y=0;y<c;y++)
            {
                char c;
                scanf("%c",&c);
                if(c=='\n') break;
                
                
                ar[x][y]=c;
                
                visited[x][y]=0;
                if(ar[x][y]=='A')
                {
                    struct element *temp=new struct element;
                    temp->x=x;
                    temp->y=y;
                    temp->atr=1;
                    A.push(temp);
                }
            } 
            scanf("%*c");
            if(y!=c) break;
        } scanf("%*c");
        
        
        while(!A.empty())
        {
            struct element *temp=new struct element;
                    temp->x=(A.top())->x;
                    temp->y=(A.top())->y;
                    temp->atr=(A.top())->atr;
            DFS(temp,visited);
            if(res=="YES") break;
            else if(!A.empty()) A.pop();
            
        }
        cout<<res<<endl;
        
    }
}
void DFS(struct element *start,int visited[][100])
{
    
    if((start->atr)==10) {res="YES"; return;}
        

        int x=start->x;
        int y=start->y;
        int atr=start->atr;
        visited[x][y]=1;

        
       
        int t;
        for( t=0;t<8;t++)
        {
            int addx=move[t].a;
            int addy=move[t].b;
            int searchx=x+addx;
            int searchy=y+addy;
            if((searchx>=0 && searchx<r) && (searchy>=0 && searchy<c))
            {

                if(visited[searchx][searchy]==0)
                {   
                   
                    if(seq[atr]==ar[searchx][searchy])
                    {  
                        struct element *temp=new struct element;
                        temp->x=searchx;
                        temp->y=searchy;
                        temp->atr=atr+1;
                        DFS(temp,visited);
                    }
                }
            }
        }if(t==8) visited[x][y]=0;
        
    
        
    return ;  
}