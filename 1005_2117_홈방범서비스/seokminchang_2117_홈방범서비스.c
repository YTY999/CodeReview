
#if 0
#include <stdio.h>
#define ABS(m) ((m) > 0 ? (m) : -(m))
typedef struct
{
    int r;
    int c;
} home;

home homes[404];
int Map[21][21];
int N, M;
int idx;
int max = 0;
void input(void)
{
    int i, j;
    scanf("%d %d", &N, &M); // 처음에 도시의 크기와 얼마나 낼 수 있는지를 받아준다.
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &Map[i][j]);
            if (Map[i][j] == 1)
            {
                homes[idx].r = i;
                homes[idx++].c = j;
            }
        }
    }
}

void print_Map(int Map[22][22])
{
    int i, j;
    printf("Maps\n");
    for (i = 0; i < N ; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", Map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Calc_Area(int r, int c, int k)
{
    int i, j;//전체 배열을 순회해 줄 변수
    int cnt = 0; // return 해줄 애
    int Area[22][22] = { 0 } ; // 범위 내에 있는지를 확인해줄 친구
    Area[r][c] = 1;
    for ( i = 0; i  < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if ( ABS(r - i) + ABS(c - j) >= k) continue;
            Area[i][j] = 1;
        }
    }

    for (i = 0; i < idx; i++)
    {
        int hr = homes[i].r;
        int hc = homes[i].c;
        if (Area[hr][hc] == 1) cnt++;
    }

    return cnt;

}

void solution(void)
{
    int i, j, k, h;
    int max_security = 0;
    i = 1;
    while (i * i + (i - 1) * (i - 1) < idx * M) i++;
    max_security = --i;
    printf("%d\n", max_security);
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            for (k = max_security; k > 0; k--) {
                int secured = Calc_Area(i, j, k);
                int cost = secured * M - (k * k + (k - 1) * (k - 1));
//            printf("cost : %d\n", cost);
                if (cost < 0) continue;
//            printf("j : %d, secured : %d, hr : %d, hc ; %d\n", j, secured, hr, hc);
                if (secured > max) max = secured;
            }
            
        }
    }
}

int main(void)
{
    int i;
    int T;
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        max = 0;
        idx = 0;
        input();
        solution();
        printf("#%d %d\n", i,  max);
    }
    return 0;
}
#endif
// 최적화 시도해보기
#if 01
#include <stdio.h>
#define ABS(m) ((m) > 0 ? (m) : -(m))
typedef struct
{
    int r;
    int c;
} home;

home homes[404];
int Map[21][21];
int N, M;
int idx;
int max = 0;
void input(void)
{
    int i, j;
    scanf("%d %d", &N, &M); // 처음에 도시의 크기와 얼마나 낼 수 있는지를 받아준다.
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &Map[i][j]);
            if (Map[i][j] == 1)
            {
                homes[idx].r = i;
                homes[idx++].c = j;
            }
        }
    }
}

void print_Map(int Map[22][22])
{
    int i, j;
    printf("Maps\n");
    for (i = 0; i < N ; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", Map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Calc_Area(int r, int c, int k)
{
    int i, j;//전체 배열을 순회해 줄 변수
    int cnt = 0; // return 해줄 애
    int Area[22][22] = { 0 } ; // 범위 내에 있는지를 확인해줄 친구
    int startR = r - (k - 1) < 0 ? 0 : r - (k - 1);
    int endR = r + (k - 1) > N ? N : r + (k - 1);
    int startC = c - (k - 1) < 0 ? 0 : c - (k - 1);
    int endC = c + (k - 1) > N ? N : c + (k - 1);
    Area[r][c] = 1;
    for ( i = startR; i <= endR; i++)
    {
        for (j = startC; j <= endC; j++)
        {
            if ( ABS(r - i) + ABS(c - j) >= k) continue;
            Area[i][j] = 1;
        }
    }

    for (i = 0; i < idx; i++)
    {
        int hr = homes[i].r;
        int hc = homes[i].c;
        if (Area[hr][hc] == 1) cnt++;
    }

    return cnt;

}

void solution(void)
{
    int i, j, k, h;
    int max_security = 0;
    i = 1;
    while (i * i + (i - 1) * (i - 1) < idx * M) i++;
    max_security = --i;

    for (i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            for (k = max_security; k > 0; k--) {
                int secured = Calc_Area(i, j, k);
				if (secured < max) break;
                int cost = secured * M - (k * k + (k - 1) * (k - 1));

                if (cost < 0) continue;

                if (secured > max) max = secured;
            }

        }
    }
}

int main(void)
{
    int i;
    int T;
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        max = 0;
        idx = 0;
        input();
        solution();
        printf("#%d %d\n", i,  max);
    }
    return 0;
}
#endif