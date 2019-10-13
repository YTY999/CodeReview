#include <stdio.h>
typedef struct {
    int r;
    int c;
    int age;
}T;

T tree[2][105 * 105 * 10]; // 번갈아가면서 사용 예정
T dead[105 * 105 * 10]; // 죽은 애들만 따로 저장
int wp;
int dwp, drp;
int N, M, K;
int Map[12][12];
int yangboon[12][12];
int order;
int check;
void input(void);
void spring(void);
void summer(void);
void autumn(void);
void winter(void);
void printTree(void);

int main(void)
{
    int i;
    int cnt = 0;
    input();
    for (i = 0; i < K; i++)
    {

        spring();
        summer();
        autumn();

        winter();
    }


    printf("%d\n", wp);

    return 0;

}

void printTree(void)
{
    int i;
    printf("tree\n");
    for (i = 0; i < wp; i++)
    {

        printf("%d %d %d", tree[order][i].r, tree[order][i].c, tree[order][i].age);
    }
    printf("fin\n");
}

void input(void)
{
    int i, j;
    scanf("%d %d %d", &N, &M, &K);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            scanf("%d", &yangboon[i][j]); // 양분 정보를 받는다.
            Map[i][j] = 5;
        }
    }
    for (i = 0; i < M; i++)
    {
	int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
	tree[order][i].r = a;
	tree[order][i].c = b;
	tree[order][i].age = c;
	wp++;
    }
    
}

void spring(void)
{
    int i;
    int idx = 0;
    int r, c;
    for (i = wp-1; i >= 0; i--)
    {
        r = tree[order][i].r;
        c = tree[order][i].c;
        if (Map[r][c] >= tree[order][i].age)
        {
            Map[r][c] -= tree[order][i].age;
            tree[order][i].age++;
        }
        else
        {
            dead[dwp++] = tree[order][i];
            tree[order][i].age = -1;
        }

    }
    for (i = 0; i < wp; i++)
    {
        if(tree[order][i].age <= 0) continue;
        tree[order ^ 1][idx++] = tree[order][i];
    }
    wp = idx;
    order ^= 1;
}

void summer(void)
{
    int i;
    int r, c;
    for (i = 0; i < dwp; i++)
    {
        r = dead[i].r;
        c = dead[i].c;
        Map[r][c] += (dead[i].age / 2);
    }
    dwp = 0;
}

void autumn(void)
{
    int i;
    int j;
    int nr, nc;
    int tmp = wp;
    int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for (i = 0; i < tmp; i++)
    {
        if (tree[order][i].age % 5 || tree[order][i].age <= 0) continue;
        for(j = 0; j < 8; j++)
        {
            nr = tree[order][i].r + dr[j];
            nc = tree[order][i].c + dc[j];
            if(nr < 1 || nc < 1 || nr > N || nc > N) continue;
            tree[order][wp].r = nr;
            tree[order][wp].c = nc;
            tree[order][wp++].age = 1;

        }

    }
}

void winter(void)
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            Map[i][j] += yangboon[i][j];
        }
    }
}
