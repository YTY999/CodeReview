#include <stdio.h>
#define MAX (102)
int tob[5][9];
int order[MAX][2];

int K;
void input(void)
{
	int i, j;
	for (i = 1; i <= 4; i++)
	{
		for (j = 3; j <= 8; j++)
		{
			scanf("%1d", &tob[i][j]);
		}
		for (j = 1; j <= 2; j++)
		{
			scanf("%1d", &tob[i][j]);
		}
	}

	scanf("%d", &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &order[i][0], &order[i][1]);
	}
}

void clockMove(int k)
{
	int i;
	int tmp;
	tmp = tob[k][8];
	for (i = 8; i >= 2; i--)
	{
		tob[k][i] = tob[k][i - 1];
	}
	tob[k][1] = tmp;
}

void AntiClockMove(int k)
{
	int i;
	int tmp;
	tmp = tob[k][1];
	for (i = 2; i <= 8; i++)
	{
		tob[k][i - 1] = tob[k][i];
	}
	tob[k][8] = tmp;
}

void printList(void)
{
	int i, j, k;
	for (k = 1; k <= 4; k++)
	{
		printf("%d: ", k);
		for (i = 1; i <= 8; i++)
		{
			printf("%d ", tob[k][i]);
		}
		printf("\n");
	}
	printf("\n");
}


int main(void)
{
	int i, j;
	int start, check;
	int total;
	int flag[4] = {0};
	input();

	for (i = 0; i < K; i++)
	{
		//printf("begin=========%d\n", i + 1);
		for (j = 1; j <= 3; j++)
		{
			if (tob[j][5] != tob[j + 1][1]) flag[j] = 1;
			else flag[j] = 0;
		}
		start = order[i][0];
		check = order[i][1];
		//printf("begin=========%d\n", i+1);
		//printList();

		if (check == 1)clockMove(start);
		else AntiClockMove(start);
		check *= -1;

		for (j = start + 1; j <= 4; j++)
		{
			if (!flag[j - 1]) break;
			if (check == 1) clockMove(j);
			else AntiClockMove(j);

			check *= -1;
		}
		/*printf("right=========\n");
		printList();
		*/
		check = order[i][1] * (-1);
		for (j = start - 1; j >= 1; j--)
		{
			if (!flag[j]) break;
			if (check == 1)clockMove(j);
			else AntiClockMove(j);

			check *= -1;
		}
		//printf("left=========\n");
		//printList();



	}

	total = (tob[1][3] > 0 ? 1 : 0) + (tob[2][3] > 0 ? 2 : 0) + (tob[3][3] > 0 ? 4 : 0) + (tob[4][3] > 0 ? 8 : 0);
	printf("%d\n", total);

	return 0;
}