#include <stdio.h>

#define abs(x) (((x) < 0) ? -(x) : (x))

int N, L, a, c, s;

int main(void)
{
	char m[200][100];
	int i, j;

	scanf("%d %d", &N, &L);
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			scanf("%d", &m[i][j]);
		}
		for (j = 0; j < N; ++j)
		{
			m[j+N][i] = m[i][j];
		}
	}

	for (i = 0; i < 2*N; ++i)
	{
		c = 1;
		s = 0;
		for (j = 1; j < N; ++j)
		{
			if (abs(m[i][j] - m[i][j-1]) > 1) break;
			if (m[i][j] == m[i][j-1])
			{
				if (++c >= L && s)
				{
					s = 0;
					c -= L;
				}
				continue;
			}
			if (m[i][j] > m[i][j-1]) {if(s || c < L) break;}
			else if (s++ && c < L) break;
			c = 1;
		}
		if (j == N && (!s || c >= L)) a++;
	}

	printf("%d\n", a);

	return 0;
}
