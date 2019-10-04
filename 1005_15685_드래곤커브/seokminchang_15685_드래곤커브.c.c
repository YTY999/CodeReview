#pragma warning(disable : 4996)

//µå·¡°ï Ä¿ºê
#if 01
#include <stdio.h>
typedef struct
{
	int x;
	int y;
	int d;
	int g;
}curve;
int idx;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int Map[105][105];
curve dragon[22];
int N;
int cnt;
int twosqr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
void input(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		int num1, num2, num3, num4;
		scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
		dragon[idx].x = num1;
		dragon[idx].y = num2;
		dragon[idx].d = num3;
		dragon[idx++].g = num4;
	}
}

void Move(void)
{
	int i, j, k;
	for (k = 0; k < idx; k++)
	{
		int r = dragon[k].y;
		int c = dragon[k].x;
		int dir[1030] = {0};
		for (i = 0; i <= dragon[k].g; i++)
		{
			if (i == 0) dir[i] = dragon[k].d;
			else
			{
				int newidx = 0;
				for (j = twosqr[i - 1] - 1; j >= 0; j--)
				{
					dir[twosqr[i - 1] + newidx++] = (dir[j] + 1) % 4;
				}

			}
		}

			Map[r][c] = 1;
			for (i = 0; i < twosqr[dragon[k].g]; i++)
			{
				r += dr[dir[i]];
				c += dc[dir[i]];
				Map[r][c] = 1;
			}
		
	}
}
void Mapcheck(void)
{
	int i, j;
	for (i = 0; i <= 99; i++)
	{
		for (j = 0; j <= 99; j++)
		{
			if (Map[i][j] == 0) continue;
			if (Map[i][j] * Map[i][j + 1] * Map[i + 1][j] * Map[i + 1][j + 1]) cnt++;

		}
	}

}


int main(void)
{
	input();
	Move();
	Mapcheck();
	printf("%d\n", cnt);
	return 0;
}
#endif

