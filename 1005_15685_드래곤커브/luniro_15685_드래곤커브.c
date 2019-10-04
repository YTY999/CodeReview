#include <stdio.h>

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int N, Q[1024];
int a[101][101];
int x, y, d, g;

void makeQ(void)
{
	int i, idx = 0;
	int t = 0;

	while (idx < 1023)
	{
		Q[idx++] = 1;
		for (i = idx - 2; i >= 0; --i)
		{
			Q[idx++] = -Q[i];
		}
		t = 2 * t + 1;
	}
}

void operation(void)
{
	int i;
	int t = 1 << g;

	a[y][x] = 1;
	for (i = 0; i < t; ++i)
	{
		y += dy[d];
		x += dx[d];
		a[y][x] = 1;
		d = (d + 4 + Q[i]) & 3;
	}
}

void input(void)
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d %d %d %d", &x, &y, &d, &g);
		operation();
	}
}

int cal(void)
{
	int i, j;
	int ret = 0;

	for (i = 0; i < 100; ++i)
	{
		for (j = 0; j < 100; ++j)
		{
			if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) ret++;
		}
	}
	
	return ret;
}

int main(void)
{
	makeQ();
	input();
	printf("%d\n", cal());

	return 0;
}
