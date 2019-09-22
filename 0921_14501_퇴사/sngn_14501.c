#pragma warning(disable : 4996)

/* 14501. 퇴사 */
#if 0
/*
https://www.acmicpc.net/problem/14501
*/
#endif
#if 0
#include <stdio.h>
#define MAX (15+5)
int T[MAX]; // 걸리는 기간
int P[MAX]; // 상담 비용
int N;
int max;

void input(void)
{
	int i;
	scanf("%d", &N);
	for(i=1;i<=N;i++)
	{
		scanf("%d %d", &T[i], &P[i]);
	}
}
void DFS(int d, int day, int sum)
{
	if(day>= N)
	{
		if(day==N && max<sum) max = sum;
		return;
	} 
	//if(day+T[day+1]>=N && sum+P[day+1]<=max) return;
	

	DFS(d+1, day+T[day+1], sum+P[day+1]);
	DFS(d, day+1, sum);
}
int main(void)
{
	input();
	DFS(0, 0, 0);
	printf("%d\n", max);

	return 0;
}
#endif
