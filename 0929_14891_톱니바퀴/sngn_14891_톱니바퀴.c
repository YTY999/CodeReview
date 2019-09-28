#include <stdio.h>
int sawTooth[5][8];
int cmd[101][2];
int K;
int sw = -1;
enum chk{left=6, right=2};
enum index{sel=0,dir};

void input(void)
{
    int i,j;
    char tmp[10];

    for(i=1;i<=4;i++)
    {
        scanf("%s", &tmp[0]);
        for(j=0;j<8;j++) sawTooth[i][j] = tmp[j]-'0';
    }
    scanf("%d", &K);
    for(i=1;i<=K;i++)
    {
        scanf("%d %d", &cmd[i][sel], &cmd[i][dir]);
    }
}

void chkNMove(int t)
{
    int i,j;
    int sawDir[5] = {0};

    sawDir[cmd[t][sel]] = cmd[t][dir];
    for(i=cmd[t][sel];i<4;i++)
    {
        if(sawTooth[i][right]==sawTooth[i+1][left]) break;
        else sawDir[i+1] = sawDir[i]*sw;
    }
    for(i=cmd[t][sel];i>0;i--)
    {
        if(sawTooth[i][left]==sawTooth[i-1][right]) break;
        else sawDir[i-1] = sawDir[i]*sw;
    }

    // 톱니 이동하기
    for(i=1;i<=4;i++)
    {
        if(sawDir[i]==0) continue;
        else if(sawDir[i]<0) // 반시계방향
        {
            int tmp = sawTooth[i][0];
            for(j=0;j<7;j++)
            {
                sawTooth[i][j] = sawTooth[i][j+1];
                
            }
            sawTooth[i][7] = tmp;
        }
        else // 시계방향
        {
            int tmp = sawTooth[i][7];
            for(j=7;j>0;j--)
            {
                sawTooth[i][j] = sawTooth[i][j-1];
            }
            sawTooth[i][0] = tmp;
        }

    }
}
int calcScore(void)
{
    int score = 0;

    score+=sawTooth[1][0];
    score+=(sawTooth[2][0]<<1);
    score+=(sawTooth[3][0]<<2);
    score+=(sawTooth[4][0]<<3);

    return score;
}
int main(void)
{
    int i;

    input();
    for(i=1; i<=K; i++)
    {
        chkNMove(i);
    }
    printf("%d\n", calcScore());

	return 0;
}