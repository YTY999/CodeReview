#include <stdio.h>
#define MAX (101)
typedef struct str
{
	int y, x, cnt, dir;
}MIC;
int a[MAX][MAX];
int N, M, K;
MIC mic[1001];
MIC Q[MAX*MAX*2];
int wp,rp;
int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, -1, 1};
int V[3][MAX][MAX];

void input(void)
{
	int i;

	scanf("%d %d %d", &N, &M, &K);
	for(i=0;i<K;i++)
	{
		scanf("%d %d %d %d", &mic[i].y, &mic[i].x, &mic[i].cnt, &mic[i].dir);
	}
}
void moveMIC(void)
{
	int i,j;
	int max[MAX][MAX] = {0};

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			V[2][i][j] = V[1][i][j] = V[0][i][j] = 0;
		}
	}

	for(i=0; i<K; i++)
	{
		if(!mic[i].cnt) continue;
		mic[i].y += dy[mic[i].dir];
		mic[i].x += dx[mic[i].dir];
		V[0][mic[i].y][mic[i].x]++;
		V[1][mic[i].y][mic[i].x] += mic[i].cnt;
		if(mic[i].cnt > max[mic[i].y][mic[i].x]) 
		{
			max[mic[i].y][mic[i].x] = mic[i].cnt;
			V[2][mic[i].y][mic[i].x] = mic[i].dir;
		}
		
	}

	for(i=0; i<K; i++)
	{
		if(!mic[i].cnt) continue;
		if(mic[i].cnt == max[mic[i].y][mic[i].x]) continue;
		
		mic[i].cnt = 0;
	}
}
void chkMIC(void)
{
	int i;

	for(i=0; i<K; i++)
	{
		if(!mic[i].cnt) continue;
		if(mic[i].y<1 || mic[i].y>=N-1 || mic[i].x<1 || mic[i].x>=N-1)
		{
			mic[i].cnt/=2;
			if(mic[i].dir&0x1) mic[i].dir+=0x1;
			else mic[i].dir-=0x1; 
		}
		else if(V[0][mic[i].y][mic[i].x]>1)
		{
			mic[i].cnt = V[1][mic[i].y][mic[i].x];
			mic[i].dir = V[2][mic[i].y][mic[i].x];
		}
	}
}
int countMIC(void)
{
	int i;
	int sum = 0;

	for(i=0; i<K; i++)
	{
		sum += mic[i].cnt;
	}

	return sum;
}
int main(void)
{
	int TC;
	int i;
	
	scanf("%d", &TC);
	for(i=1; i<=TC; i++)
	{
		input();
		while(M--)
		{
			moveMIC();
			chkMIC();
		}
		printf("#%d %d\n", i, countMIC());
	}

	return 0;
}