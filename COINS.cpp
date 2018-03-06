#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

std::map <int,long long int> maxval;

long long int rec(long long int n);
int main()
{
    std::ios::sync_with_stdio(false);
    long long int n;
    while(cin>>n)
    {
     maxval.clear();
    maxval[0]=0;
    maxval[1]=1;
    cout<<rec(n)<<endl;
   
    }
    return 0;
}
long long int rec(long long int n)
{
    if(maxval.find(n)==maxval.end())
    {
        long long int temp=0;
        temp+=rec(n/2);
        temp+=rec(n/3);
        temp+=rec(n/4);
        if(temp>=n)
        maxval[n]=temp;
        else maxval[n]=n;
    }
    return maxval[n];
}