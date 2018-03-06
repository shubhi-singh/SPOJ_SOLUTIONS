#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;


int main()
{
    ll t;
    cin>>t;
    char c;
    scanf("%c",&c);
    while(t--)
    {
        
        ll result;
        int a;
        
        scanf("%c",&c);
         c='\0';
        ll res=0;
        int l=0;
        ll ar[5000];
        char op[5000];
        
        while(c!= '\n')
        {
            scanf("%c",&c);
            if(c=='*' || c=='-' || c=='/'|| c=='+' || c=='=')
            {
                ar[l++]=res;
                res=0;
                if(c!='=')
                op[l-1]=c;
                
                
            
            }
            else if(c>=48 && c<=57)
            {
                res=res*10+(ll)(c-48);
            }
           
        } 
     
        
        result=ar[0];
        for(int x=0;x<l-1;x++)
        {
            if(op[x]=='*')
                result=result*ar[x+1];
            else if(op[x]=='/') result=result/ar[x+1];
            else if(op[x]=='-') result=result-ar[x+1];
            else if(op[x]=='+') result=result+ar[x+1];
        }
        cout<<result<<endl;
       
         
       
              
            
            
        
       
    }
    return 0;
}