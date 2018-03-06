#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
string substring;
string s;
string sHalf;
string fHalf;
string palin;
string ans;
    

string strrev(string string1)
{
    int x;
    int last = string1.size()-1;
    int l = string1.size();
 
    for(x = 0; x < l/2 ;x++)
    {
        char temp = string1[x];
        string1[x] = string1[last];
        string1[last--] = temp;
    }
    string1[l] = '\0';
    
    return string1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
   
    while(t--)
    {
        cin>>s;
        
        int l = s.size();
        while(s[0]=='0' && l>1)
        { 
            l = s.size();
            s=s.substr(1,l);
        }
        l = s.size();
        
        if(l == 1 && s<"9")
            ans=++s[0];
        else
        
        if(l % 2 == 0)
        {
        fHalf=s.substr(0, l/2);
        sHalf=fHalf;
        sHalf=strrev(fHalf);
        palin = fHalf+sHalf;
        if(palin > s) ans = palin;
        else
        {
            int carry = 1;
            int sum;
            int index = l/2 - 1;
            do
            {   
                if(carry == 1)
                {
               int digit = fHalf[index]-48;
            
               digit++;
               sum = digit % 10;
               carry = digit / 10;
               fHalf[index] = 48+sum;
               index--;
                }
                
                
            }
            while(index >=0 && carry == 1);
            if(carry == 1)
            {
                 
                int index = 1;
                ans = '1';
                for(index = 1; index < l;index++)
                {
                    ans+='0';
                }
                ans+='1';
            }
            else ans = fHalf + strrev(fHalf);
        }
        
        
        }
        else
        {
        fHalf = s.substr(0, l/2);
        sHalf = fHalf;
        sHalf = strrev(sHalf);
        int mid = s[l/2];
     
        palin = fHalf + (char)mid + sHalf;
        if(palin > s) ans = palin;
        else
        {
            fHalf +=mid;
            int carry = 1;
            int sum;
            int index = l/2;
            do
            {
                if(carry == 1)
                {
                    int digit = fHalf[index]-48;
               digit++;
               sum = digit % 10;
               carry = digit / 10;
               fHalf[index] = sum+48;
               index--;
                }
            }
            while(index >= 0 && carry == 1);
            if(carry == 1)
            {
                int index = 1;
                ans = '1';
                for(index = 1; index < l;index++)
                {
                    ans+='0';
                }
                ans+='1';
            }
            else ans = fHalf + strrev(fHalf.substr(0, l/2));
        }
        }
        cout<<ans<<endl;
    }
    return 0;
}