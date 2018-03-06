#include <stdio.h>
#include <list>
using namespace std;
int ranking[550][550];
int menRank[550][550];
int current[550];
int man[550];
list<int> free_men;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,x,y,count = 0;
        free_men.clear();
        scanf("%d", &n);
        for(x = 1;x <= n;x++)
        {
            int temp;
            scanf("%d", &temp);
            for(y = 1;y <= n;y++)
            {
                int man;
                scanf("%d", &man);
                ranking[x][man] = y;
                            }
           
            current[x] = -1;
        }
       
        for(x = 1;x <= n;x++)
        {
            int temp;
            scanf("%d", &temp);
            menRank[x][0] = 1;
            for(y = 1;y <= n;y++)
            {
                scanf("%d", &menRank[x][y]);
            }
            free_men.push_front(x);
        }
        while(count != n)
        {
           
            
            
                int man = free_men.front();
                free_men.pop_front();
                
              
             
                int woman = menRank[man][menRank[man][0]];
                if(current[woman] == -1)
                {
                    count++;
                    current[woman] = man;
                    
                    
                }
                else 
                {
                    int man2 = current[woman];
                    if(ranking[woman][man2] > ranking[woman][man])
                    {
                        
                        current[woman] = man;
                        free_men.push_back(man2);
                    }
                    else free_men.push_back(man);
                }
                menRank[man][0]++;
                
                
                
            
        
           
        }
        for(x = 1;x <= n;x++)
            man[current[x]] = x;
        for(x = 1;x <= n;x++)
            printf("%d %d\n", x, man[x]);
        
            
        
    }
    return 0;
}