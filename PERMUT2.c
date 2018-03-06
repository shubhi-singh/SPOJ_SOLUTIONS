#include <stdio.h>
int ar[100001];
int main()
{
    int n,x,flag;
    scanf("%d", &n);
    while(n != 0)
    {
        
         flag = 0;
        for(x = 1;x <= n;x++)
        
            scanf("%d", &ar[x]);
           
            
        
        for(x = 1;x <= n;x++)
        {
            if(ar[ar[x]] != x )
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
            printf("not ambiguous\n");
        else printf("ambiguous\n");
          scanf("%d", &n);
    }
    return 0;
}