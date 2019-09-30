#pragma warning(disable : 4996)
#include <stdio.h>
#define MAX (104)
typedef struct
{
    int r;
    int c;
    int amount;
    int dir;
} bac;

int N, M, K;
int Map[2][MAX][MAX];
int check[2][MAX][MAX];
bac bacteria[1005];
int world;
int ans;
int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, -1, 1};

void input(void);
void solution(void);
void printMap(void);
int main(void)
{
    int T;
    int i;
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        ans = 0;

        input();
        printMap();
        solution();
        printf("#%d %d\n", i, ans);
    }
    return 0;
}

void input(void)
{
    int i;
    int idx = 0;
    scanf("%d %d %d", &N, &M, &K);

    for (i = 0; i < K; i++)
    {
        int num1, num2, num3, num4;
        scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
        bacteria[i].r = num1;
        bacteria[i].c = num2;
        bacteria[i].amount = num3;
        bacteria[i].dir = num4;
        Map[world][num1][num2] = num3;
    }
}

void printMap(void)
{
    int i, j;
    for (i = 0; i <= N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            printf("%d ", Map[world][i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ReverseDir(int dir)
{
    switch (dir)
    {
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 4;
    default:
        return 3;
    }
}

void solution(void)
{
    int i, j, k;
    int nr, nc;
    for (k = 1; k <= M; k++)
    {
        for (i = 0; i < K; i++)
        {

            if (bacteria[i].amount == 0)
                continue;
            if (bacteria[i].amount != Map[world][bacteria[i].r][bacteria[i].c])
            {
                bacteria[i].amount = Map[world][bacteria[i].r][bacteria[i].c];
            }

            nr = bacteria[i].r + dr[bacteria[i].dir];
            nc = bacteria[i].c + dc[bacteria[i].dir];

            if (Map[world ^ 1][nr][nc] == 0)
            {
                if (nr > 0 && nc > 0 && nr < N - 1 && nc < N - 1)
                {
                    Map[world ^ 1][nr][nc] = bacteria[i].amount;
                    Map[world][bacteria[i].r][bacteria[i].c] = 0;
                }
                else
                {
                    Map[world ^ 1][nr][nc] = bacteria[i].amount = bacteria[i].amount / 2;
                    bacteria[i].dir = ReverseDir(bacteria[i].dir);
                    Map[world][bacteria[i].r][bacteria[i].c] = 0;
                }
                check[world][bacteria[i].r][bacteria[i].c] = 0;
                bacteria[i].r = nr;
                bacteria[i].c = nc;
                check[world ^ 1][nr][nc] = i;
            }
            else
            {
                int chk = check[world ^ 1][nr][nc];
                Map[world ^ 1][nr][nc] += bacteria[i].amount;
                if (bacteria[chk].amount < bacteria[i].amount)
                {
                    check[world ^ 1][nr][nc] = i;
                    bacteria[chk].amount = 0;
                }
                else
                {
                    bacteria[i].amount = 0;
                }
                check[world][bacteria[i].r][bacteria[i].c] = 0;
                Map[world][bacteria[i].r][bacteria[i].c] = 0;
                bacteria[i].r = nr;
                bacteria[i].c = nc;
            }
        }

        world ^= 1;
        printMap();
    }

    for (i = 0; i <= N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            if (Map[world][i][j] == 0)
                continue;
            ans += Map[world][i][j];
            Map[world][i][j] = 0;
            check[world][i][j] = 0;
        }
    }
}