#include <stdio.h>
#define MAX (55)
#define DIST(a) ((a)>0 ? (a) : -(a))
typedef struct _pos { int y; int x; int dist[13]; } POS;
int a[MAX][MAX];
POS house[2*MAX];
int N, M;
int V[14]; // 치킨집 남길지 여부
POS chic[14];
int chic_cnt, home_cnt;
int min = 0x7fffffff;
int chicDist_sum;

void input(void)
{
    int i,j;
    scanf("%d %d", &N, &M);
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j]==1) // 집
            { 
                house[home_cnt].y = i; house[home_cnt++].x = j; 
            }
            else if(a[i][j]==2) // 치킨
            {
                chic[chic_cnt].y = i; chic[chic_cnt++].x = j;
            }
        }
    }
}

int CalcDist(int d, int chic_num)
{
    int i,j;
    int sum = 0;

    for(i=0; i< home_cnt; i++)
    {
        int tmp = DIST(house[i].y - chic[chic_num].y) + DIST(house[i].x - chic[chic_num].x);
        if (d==0) house[i].dist[d] = tmp;
        else if(house[i].dist[d-1] > tmp) house[i].dist[d] = tmp;
        else house[i].dist[d] = house[i].dist[d-1];
    }

    if(d == M-1)
    {
        for(i=0; i<home_cnt; i++)
        {
            sum += house[i].dist[d];
        }
    }

    return sum;
}

void DFS(int d, int n)
{
    if(d >= M)
    {
        if (min > chicDist_sum) min = chicDist_sum;
        return;
    }

    for(int i=n+1; i<chic_cnt; i++)
    {
        chicDist_sum = CalcDist(d, i);
        DFS(d+1, i);
    }
}


int main(void)
{
    input();
    DFS(0, -1);
    printf("%d\n", min);

	return 0;
}