#pragma warning(disable : 4996)

/* 2105. [모의 SW 역량테스트] 디저트 카페 */
#if 0
/*
https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
*/
#endif
#if 01
#include <stdio.h>
#define MAX (21)
int a[MAX][MAX];
int V[MAX][MAX];
int S[101];
int N;
int dx[] = {1, -1, -1, 1};
int dy[] = {1, 1, -1, -1};
int max;
int init_y, init_x;

void input(void)
{
	int i,j;

	scanf("%d", &N);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d", &a[i][j]);
			V[i][j] = 0;
		}
	}
	for(i=1;i<=100;i++) S[i] = 0;
}
void DFS(int y, int x, int dir, int rot_dir, int cnt)
{
	if(y<1 || y>N || x<1 || x>N) return;
	if(rot_dir==4 && (y==init_y && x==init_x))
	{
		if(max<cnt) max = cnt;
		return;
	}
	if(V[y][x] || S[a[y][x]]) return;

	V[y][x] = 1;
	S[a[y][x]] = 1;

	DFS(y+dy[dir], x+dx[dir], dir, rot_dir, cnt+1); // 직진
	if(dir+1>3) dir-=4;
	DFS(y+dy[dir+1], x+dx[dir+1], dir+1, rot_dir+1, cnt+1); // 회전
	V[y][x] = 0; S[a[y][x]]=0;
}
int main(void)
{
	int i,j;
	int TC, num=1;

	scanf("%d", &TC);
	while(TC--)
	{
		input();
		max = 0;
		for(i=1;i<=N;i++)
		{
			init_y=i;
			for(j=1;j<=N;j++)
			{
				init_x=j;
				DFS(i, j, 0, 1, 0);
				DFS(i, j, 1, 1, 0);
				DFS(i, j, 2, 1, 0);
				DFS(i, j, 3, 1, 0);
			}
		}
		if(max < 4) max = -1;
		printf("#%d %d\n",num++, max);
	}

	return 0;
}
#endif
