#include <iostream>
#include<string>
#include<cstring>
#include <stdio.h>
using namespace std;

int main()
{
    string ar[]={"063","010","093","079","106","103","119","011","127","107"};
    string s;
    getline(cin,s);
    while(!(s=="BYE"))
    {
        
        
        int plus=s.find('+');
        int equals=s.find('=');
        int left=0;;int right=0;
        int start=0;int end=3;
        while(start!=plus)
        {
            
            string temp=s.substr(start,end);
           
            for(int x=0;x<10;x++)
            {
                if(temp==ar[x])
                {
                    left=left*10+x;
                    break;
                }
            }
            start=start+3;
        }
        start=plus+1;
        end=3;
        while(start!=equals)
        {
            string temp=s.substr(start,end);
           
            for(int x=0;x<10;x++)
            {
                if(temp==ar[x])
                {
                    right=right*10+x;
                    break;
                }
            }
            start=start+3;
        }
        int val=left+right;
        string vals;
        while(val>0)
        {
            int digit=val%10;
            vals=ar[digit]+vals;
            val=val/10;
        }
        cout<<s<<vals<<endl;
        getline(cin,s);
    }
    return 0;
}
    
    