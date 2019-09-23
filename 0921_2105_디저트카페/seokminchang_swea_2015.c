
#include <stdio.h>
#define MAX (22)
int N;
int Map[MAX][MAX];
int dr[] = {1, 1, -1, -1};
int dc[] = {1, -1, -1, 1};
int max;
int chk[101];

void initchk(void)
{
	int i;
	for (i = 0; i <= 100; i++)
	{
		chk[i] = 0;
	}
}

void input(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &Map[i][j]);
		}
	}
}

void printList(void)
{
	int i, j;
}

void DFS(int sr, int sc, int r, int c, int cnt, int dir)
{
	int nr, nc;
	int i;
	nr = r + dr[3];
	nc = c + dc[3];
	if (nr == sr && nc == sc && cnt >= 4)
	{
		if (cnt > max) max = cnt;
		return;
	}

	for (i = dir; i < 4; i++)
	{
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr < 1 || nc < 1 || nr > N || nc > N) continue;
		if (chk[Map[nr][nc]]) continue;
		chk[Map[nr][nc]] = 1;
		DFS(sr, sc, nr, nc, cnt + 1, i);
		chk[Map[nr][nc]] = 0;
	}

}


int main(void)
{
	int T;
	int i, j, k;

	scanf("%d", &T);
	for (k = 1; k <= T; k++)
	{
		max = 0;
		input();
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				initchk();
				chk[Map[i][j]] = 1;
				DFS(i, j, i, j, 1, 0);
			}
		}

		if (max != 0)printf("#%d %d\n", k, max);
		else printf("#%d %d\n", k, -1);
	}

	return 0;
}