#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
void lcs(int i,int j);
int b[101][101];
int ar[100];
string s2;
int main()
{
    string s;
    getline(cin,s);
    while(!cin.eof())
    {
        int l=s.length();
        string::size_type pos=s.find_first_of(' ');
        string s1=s.substr(0,pos);
         s2=s.substr(pos+1,l-1-pos);
       
        int l1=pos;
        int l2=l-1-pos;
        int sub_length[l1+1][l2+1];
        
        for(int x=0;x<=l1;x++)
        {
            for(int y=0;y<=l2;y++)
            {
                sub_length[x][y]=0;b[x][y]=0;
                 ar[y]=0;
            }
           
        }
        for(int x=1;x<=l1;x++)
            for(int y=1;y<=l2;y++)
            {
                if(s1[x-1]==s2[y-1]) {sub_length[x][y]=sub_length[x-1][y-1]+1;b[x][y]=1;}
              
                else if (sub_length[x-1][y]>= sub_length[x][y-1]) {sub_length[x][y]=sub_length[x-1][y];b[x][y]=2;}
                else { sub_length[x][y]=sub_length[x][y-1];b[x][y]=3;}
            }
       
        cout<<s1;
        
        lcs(l1,l2);
        for(int x=0;x<l2;x++)
        {
            if(ar[x]!=1) cout<<s2[x];
        }
        cout<<endl;
        getline(cin,s);  
        
        
        
    }
        return 0;
}
void lcs(int i,int j)
{
    if(i==0 || j==0) return ;
    if(b[i][j]==1){ lcs(i-1,j-1);ar[j-1]=1;}
    else if(b[i][j]==2){ lcs(i-1,j);}
    else { lcs(i,j-1); }
    return ;
}