#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;
long long int total[5001];
int conv(char c);
int main()
{
    string s="";
    getline(cin,s);
    while(!(s=="0"))
    {
        int l=s.length();
        int start=1;
        total[0]=1;
        if(conv(s[0])>=1 && conv(s[0])<=26) total[1]=1;
        else total[1]=0;
        for(int x=1;x<(l);x++)
        {
            total[x+1]=0;
            if(conv(s[x])!=0)
            {
            total[x+1]+=total[x];
            if(conv(s[x-1])!=0 && conv(s[x-1])>=1 && conv(s[x-1])<=2) total[x+1]+=total[x-1];
            } else total[x+1]+=total[x-1];
            
          
        }
        cout<<total[l]<<endl;
        
        getline(cin,s);
        
    }
    return 0;
  
}
int conv(char c)
{
    return (c-48);
}