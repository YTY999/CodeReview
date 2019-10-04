#include <stdio.h>

#define abs(x) (((x) < 0) ? -(x) : (x))

typedef struct _point
{
	int y, x;
} P;

int N, M, MM, MH;
P QC[13], QH[100];
int min = 987654321;
int chk[13];

void input(void)
{
	int i, j, tmp;
	
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			scanf("%d", &tmp);
			if (tmp == 1)
			{
				QH[MH].y = i;
				QH[MH].x = j;
				MH++;
			}
			else if (tmp == 2)
			{
				QC[MM].y = i;
				QC[MM].x = j;
				MM++;
			}
		}
	}
}

void cal(void)
{
	int i, j, tmp_cnt, tmp;
	int cnt = 0;
	
	for (i = 0; i < MH; ++i)
	{
		tmp_cnt = 987654321;
		for (j = 0; j < MM; ++j)
		{
			if (chk[j] == 0) continue;
			tmp = abs(QH[i].y - QC[j].y) + abs(QH[i].x - QC[j].x);
			if (tmp < tmp_cnt) tmp_cnt = tmp;
		}
		cnt += tmp_cnt;
		if (cnt > min) return;
	}
	min = cnt;
}

void oper(int idx, int N)
{
	if (N + MM - idx < M) return;
	if (N >= M)
	{
		cal();
		return;
	}
	
	oper(idx + 1, N);
	chk[idx]++;
	oper(idx + 1, N + 1);
	chk[idx]--;
}

int main(void)
{
	input();
	oper(0, 0);
	printf("%d\n", min);
	return 0;
}
