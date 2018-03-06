#include<iostream>
using namespace std;
long long int total;
int ar[30];

void rec(int x,int last,int slast)
{
    if(x==-1) {total++; return;}
    int p=ar[x]+last;
    if(ar[x]<=last)
    {
        
        rec(x-1,ar[x],last);
        if((p)<=slast)
        rec(x-1,p,slast);
    }
    else if(p<=slast) rec(x-1,p,slast);
   
    return ;
}
int main()
{
	std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int f=1;
    while(s!="bye")
    {
    int l=s.length();
    total=0;
    for(int x=0;x<l;x++)
    {
        ar[x]=s[x]-48;
    }
    rec(l-2,ar[l-1],1000007);
    cout<<f<<". "<<total<<endl;
    f++;
    cin>>s;
    }
    return 0;
}