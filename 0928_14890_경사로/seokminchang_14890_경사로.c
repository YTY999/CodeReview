
#include <stdio.h>
#define MAX (102)
int N;
int L;
int cnt;
int Map[MAX * 2][MAX];

void input(void)
{
	int i, j;
	scanf("%d %d", &N, &L);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &Map[i][j]);
		}
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			Map[j + N][i] = Map[i][j];
		}
	}
}

int Low_sadari_r(int i, int j)
{
	int k;
	int check = Map[i][j];
	for (k = j + 1; k <= j + L - 1; k++)
	{
		if (Map[i][k] != check) return 0;
	}
	return 1;
}

void solution(int i)
{
	int j, k;
	int same = Map[i][1];
	int used[MAX] = {0};
	for (j = 1; j <= N; j++)
	{
		if (Map[i][j] != same)
		{
			if (Map[i][j] - same > 1 || Map[i][j] - same < -1) return;
			if (Map[i][j] < same)
			{
				for (k = j; k <= j + L - 1; k++)
				{
					if (k > N || used[k]) return;
					used[k] = 1;
					if (Map[i][k] != Map[i][j]) return;

				}
				j = k - 1;
			}
			else
			{
				for (k = j - 1; k >= j - L; k--)
				{
					if (k < 1 || used[k]) return;
					used[k] = 1;
					if (Map[i][j - 1] != Map[i][k]) return;
				}

			}
			same = Map[i][j];
		}
	}
	cnt++;



}
int main(void)
{
	int i;

	input();
	for (i = 1; i <= 2 * N; i++)
	{
		solution(i);
	}
	printf("%d\n", cnt);

	return 0;
}