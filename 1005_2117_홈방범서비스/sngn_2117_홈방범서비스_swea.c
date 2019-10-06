#include <stdio.h>
#define ABS(a) ((a)>0 ? (a) : -(a))
int a[21][21];
int N, M;
int max, maxK;
int sx, sy, ex, ey;
int cnt;

void input(void)
{
    int i,j;

    max = 0;

    scanf("%d %d",&N, &M);
    if(N%2) maxK = N;
    else maxK = N+1;

    for(i=0 ; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j]) cnt++;
        }
    }
}

void calcServiced(int K)
{
    int i, j;
    int r, c;
    int sum;
    int area = (K*K + (K-1)*(K-1));

    if(area <= max) return;
    if(cnt*M - area<0) return;
    if(cnt==1) { max = 1; return; }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            sum = 0;
            for(r=-K+1; r<K; r++)
            {
                if(i+r<0 || i+r>=N) continue;
                for(c=-K+1; c<K; c++)
                {
                    if(j+c<0 || j+c>=N) continue;
                    if(ABS(r)+ABS(c) < K)
                    {
                        sum += a[i+r][j+c];
                    }
                }
            }
            if((sum > max) && (sum*M - area)>=0) max = sum;
        }
    }
}

int main(void)
{
    int TC;
    scanf("%d", &TC);
    for(int i=1; i<=TC; i++)
    {
        input();
        while(maxK)
        {
            calcServiced(maxK--);
        }
        if(!max) max = 1;
        printf("#%d %d\n", i, max);
    }

	return 0;
}