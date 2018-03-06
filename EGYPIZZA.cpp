#include <iostream>
using namespace std;
int main()
{
    long int n;
    int a,b;char c;
        long int half=0;
        long int three_quarter=0;
        long int quarter=0;
       long  int total=1;
    cin>>n;
    while(n--)
    {
        
        cin>>a;
        cin>>c;
        cin>>b;
        if(a==1 && b==2) half++;
        if(a==1 && b==4) quarter++;
        if(a==3 && b==4) three_quarter++;
       
    }
        total+=three_quarter;
        if(half%2==0) { total+=(half/2); half=0;} 
        else { total+=(((half-1)/2)+1); half=1;}
        half=half*2;
        if(quarter!=0)
        {
            long int left=(half+three_quarter)-quarter;
            long int add;
            if(left>=0) add=0;
            else {
                long int temp=(-1*left)/4;
                add=temp+1;
                
            }
            total+=add;
        }
        cout<<total<<endl;
        
        
    
    return 0;
 }
 