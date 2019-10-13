#include <stdio.h>
#define MAX (11)
typedef struct _tree
{
	int y, x, age, flag;
}TR;
int N, M, K;
int a[MAX][MAX];
int nur[MAX][MAX];
TR tree[2][MAX*MAX*MAX * 50];
TR tmp[MAX*MAX*MAX * 50];
int cnt, sw;

void input(void)
{
	int i, j;

	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &nur[i][j]);
			a[i][j] = 5;
		}
	}

	for (i = 0; i<M; i++)
	{
		scanf("%d %d %d", &tree[sw][i].y, &tree[sw][i].x, &tree[sw][i].age);
	}
}

int TimePassed(void)
{
	int i, j;
	int cnt = M;
	int tmpcnt;
	int nsw;
	int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int dx[] = { 1, 0, -1, -1, -1, 0, 1, 1 };

	while (K--)
	{
		// spring + summer
		int livecnt=0;
		for (i = cnt-1; i >= 0; i--)
		{
			if (a[tree[sw][i].y][tree[sw][i].x] < tree[sw][i].age)
			{
				tree[sw][i].flag = 1;
			}
			else
			{
				a[tree[sw][i].y][tree[sw][i].x] -= tree[sw][i].age++;
				tmp[livecnt++] = tree[sw][i];
			}
		}

		// fall
		nsw = sw ^ 0x1;
		tmpcnt = 0;
		for (i = livecnt - 1; i >= 0; i--)
		{
			tree[nsw][tmpcnt++] = tmp[i];
		}


		for (i = 0; i<cnt; i++)
		{
			if (tree[sw][i].flag)
			{
				a[tree[sw][i].y][tree[sw][i].x] += (tree[sw][i].age / 2);
				tree[sw][i].flag = 0;
			}
			else // fall
			{
				if (!(tree[sw][i].age % 5))
				{
					for (j = 0; j < 8; j++)
					{
						int ny, nx;
						ny = tree[sw][i].y + dy[j];
						nx = tree[sw][i].x + dx[j];

						if (ny<1 || ny>N || nx<1 || nx>N) continue;
						tree[nsw][tmpcnt].y = ny;
						tree[nsw][tmpcnt].x = nx;
						tree[nsw][tmpcnt++].age = 1;
					}
				}
			}
		}
		cnt = tmpcnt;
		//printf("%d\n", cnt);
		sw = nsw;
		if (!cnt) break;

		// winter -- S2D2
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				a[i][j] += nur[i][j];
			}
		}
	}

	return cnt;
}

int main(void)
{
	input();
	printf("%d\n", TimePassed());

	return 0;
}