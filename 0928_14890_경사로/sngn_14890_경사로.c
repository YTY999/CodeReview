#include <stdio.h>
#define MAX (101)
int a[MAX][MAX];

int N, L;
int cnt;
void input(void)
{
    int i,j;

    scanf("%d %d", &N, &L);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
int findRoute(void)
{
    int i,j;
    

    // row route
    for(i=1;i<=N;i++)
    {
        int plain_x = 1;
        int V[2][MAX] = {0};
        for(j=1;j<N;j++)
        {
            int now = a[i][j], next = a[i][j+1];
            if(now == next) plain_x++;
            else if(now+1 == next)
            {
                if(plain_x>=L)
                {
                    plain_x = 0;
                    while(plain_x<L && !V[0][j-(plain_x)])
                    {
                        V[0][j-plain_x++] = 1;
                    }
                    if(plain_x!=L) break;
                    plain_x = 1;
                }
                else break;
            }
            else if(now == next+1)
            {
                int chance = L;
                plain_x = 1;
                while(chance>=1 && !V[0][j+chance]) 
                {
                    V[0][j+chance] = 1;
                    if(a[i][j+chance]!=next) break;
                    else chance--;
                }
                if(chance!=0) break;
                else j+=L-1;
            }
            else break;
        }
        //printf("row %d : %d\n",i, j);
        if(j==N) cnt++;
        // column route
        int plain_y = 1;
        for(j=1;j<N;j++)
        {
            int now = a[j][i], next = a[j+1][i];
            if(now == next) plain_y++;
            else if(now+1 == next)
            {
                if(plain_y>=L) 
                {
                    plain_y = 0;
                    while(plain_y<L && !V[1][j-plain_y])
                    {
                        V[1][j-plain_y++] = 1;
                    }
                    if(plain_y!=L) break;
                    plain_y=1;
                }
                else break;
            }
            else if(now == next+1)
            {
                int chance = L;
                plain_y = 1;
                while(chance>=1 && !V[1][j+chance]) 
                {
                    V[1][j+chance] = 1;
                    if(a[j+chance][i]!=next) break;
                    else chance--;
                }
                if(chance!=0) break;
                else j+=L-1;
            }
            else break;
        }
        //printf("column %d : %d\n",i, j);
        if (j==N) cnt++;
    }

    return cnt;
}
int main(void)
{
    input();
    printf("%d\n", findRoute());

	return 0;
}