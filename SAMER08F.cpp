#include <iostream>
using namespace std;
int main()
{
    while(1)
    {
        int n,ans = 0;
        cin>>n;
        if(n == 0) break;
        
        for(int x = n;x >= 1;x--)
            ans += x*x;
        cout<<ans<<endl;
    }
    return 0;
}