#include <stdio.h>
int N, X, Y, d, g;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int dcnt, rcnt;
int dir[2048];
int V[101][101];
int G[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};


void traceRoute(void)
{
    int backpos;
    int cur_g = 0;

    V[Y][X] =1;
    dir[dcnt++] = d;
    X += dx[d];
    Y += dy[d];
    V[Y][X] =1;
    while(cur_g != g)
    {
        while(dcnt != G[cur_g])
        {
            d = (d+1)%4;
            dir[dcnt++] = d;
            X += dx[d];
            Y += dy[d];
            V[Y][X] = 1;            
        }
        cur_g++; backpos = dcnt;

        while(backpos)
        {
            d = (dir[--backpos] + 1) % 4;
            dir[dcnt++] = d;
            X += dx[d];
            Y += dy[d];
            V[Y][X] = 1;
        }
    }
}
int countRect(void)
{
    int i,j;

    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            if(V[i][j]+V[i+1][j]+V[i][j+1]+V[i+1][j+1]==4) rcnt++;
        }
    }

    return rcnt;
} 
int main(void)
{
    int i;

    scanf("%d", &N);
    for(i=0;i<N;i++)
    {
        dcnt = 0;
        scanf("%d %d %d %d", &X, &Y, &d, &g);

        traceRoute();
    }

    printf("%d\n", countRect());
}