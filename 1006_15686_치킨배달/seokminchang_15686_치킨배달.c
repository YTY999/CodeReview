#pragma warning(disable : 4996)
// Ä¡Å² °Å¸®
#if 01
#include <stdio.h>
#define MAX (55)
#define ABS(m) (m) > 0 ? (m) : -(m)

int N, M;
int Map[MAX][MAX];
int cr[15];
int cc[15];
int hr[2 * MAX];
int hc[2 * MAX];
int chk[15];
int min = 0x7fff0000;
int cidx;
int hidx;

void input(void)
{
	int i, j;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == 2)
			{
				cr[cidx] = i;
				cc[cidx++] = j;
			}
			else if (Map[i][j] == 1)
			{
				hr[hidx] = i;
				hc[hidx++] = j;
			}
		}
	}

}



void DFS(int L, int rest)
{
	if (L >= cidx || rest == M)
	{
		int i, j;
		int tot = 0;
		if (rest > M || rest < M) return;
		for (i = 0; i < hidx; i++)
		{
			int check = 3000;
			for (j = 0; j < cidx; j++)
			{
				if (chk[j] > 0) continue;

				int num = (ABS(cc[j] - hc[i])) + (ABS(cr[j] - hr[i]));

				if (num < check) check = num;
			}
			tot += check;
		}
		if (tot < min) min = tot;
		return;
	}


	chk[L] = 1;
	DFS(L + 1, rest - 1);
	chk[L] = 0;
	DFS(L + 1, rest);

}

int main(void)
{
	input();
	DFS(0, cidx);
	printf("%d\n", min);
	return 0;
}
#endif // 0
