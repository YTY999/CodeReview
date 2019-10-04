#include <stdio.h>

int gear[4];
int K;
int N, dir;
int ans;
int idx;

void operation(int dir)
{
	int i, tmp;

	idx = N;
	for (i = N - 1; i >= 0; --i)
	{
		if (((gear[i+1]>>1)^(gear[i]>>5)) & 1)
		{
			idx = i;
			continue;
		}
		break;
	}
	tmp = dir;
	for (i = N - 1; i >= idx; --i)
	{
		dir *= -1;
		if (dir == 1)
		{
			gear[i] = (gear[i] >> 1) | ((gear[i] & 1) << 7);
		}
		else
		{
			gear[i] = ((gear[i] << 1) & 0xff) | ((gear[i] >> 7) & 1);
		}
	}

	idx = N;
	for (i = N + 1; i < 4; ++i)
	{
		if (((gear[i]>>1)^(gear[i-1]>>5)) & 1)
		{
			idx = i;
			continue;
		}
		break;
	}
	dir = tmp;
	for (i = N; i <= idx; ++i)
	{
		if (dir == 1)
		{
			gear[i] = (gear[i] >> 1) | ((gear[i] & 1) << 7);
		}
		else
		{
			gear[i] = ((gear[i] << 1) & 0xff) | ((gear[i] >> 7) & 1);
		}
		dir *= -1;
	}
}

void input(void)
{
	int i, j, tmp;
	
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			scanf("%1d", &tmp);
			gear[i] <<= 1;
			gear[i] |= tmp;
		}
	}
	
	scanf("%d", &K);
	for (i = 0; i < K; ++i)
	{
		scanf("%d %d", &N, &dir);
		N -= 1;
		operation(dir);
	}
}

int cal(void)
{
	int ret = 0;
	int i;
	
	for (i = 0; i < 4; ++i)
	{
		ret += ((gear[i] & (1 << 7)) >> 7 - i);
	}
	
	return ret;
}

int main(void)
{
	input();
	printf("%d\n", cal());
	
	return 0;
}
