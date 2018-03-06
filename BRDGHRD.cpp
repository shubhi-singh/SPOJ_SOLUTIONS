#include <stdio.h>
#include <algorithm>
using namespace std;
struct bridge
{
    int x;
    int y;
    
};

struct bridge ar[100010];
struct bridge lis[100010];
bool sortbyx(const struct bridge &a, const struct bridge &b)
{
    if(a.x < b.x) return true;
    else if(a.x == b.x && a.y < b.y) return true;
    return false;
}

int main()
{
    int t,n,count,x,i,j,mid;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(x = 0;x < n;x++)
            scanf("%d", &ar[x].x);
        for(x = 0;x < n;x++)
            scanf("%d", &ar[x].y);
        sort(ar, ar+n, sortbyx);
        count = 0;
        lis[count++] = ar[0];
        
        for(x = 1;x < n;x++)
        {
            i = 0;
            j = count-1;
        
            while(i <= j)
            {
                    mid = (i+j)/2;
                if(lis[mid].x <= ar[x].x && lis[mid].y <= ar[x].y)
                    i = mid+1;
                else j = mid-1;
                   
            }
            j++;
            
            if(j == count) count++;
            lis[j].x = ar[x].x;
            lis[j].y = ar[x].y;
        }
        printf("%d\n", count);
        
        
    }
    return 0;
}

