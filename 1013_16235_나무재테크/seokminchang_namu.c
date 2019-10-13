/*
N * N 크기의 땅을 구매 
상도는 1 * 1 크기의 칸으로 이를 나누어 놓음 
r이 행, c가 열 

사계절 단위로 수행. 
for 문을 한번 돌때마다 이 사계절을 수행.

1단계 
자신의 나이만큼 양분을 먹고, 나이가 1 증가. 
(구조체 내부에 위치와 나이 정보 있어야 함) 
(양분의 정보를 담고 있을 배열 필요) 
양분을 먹지 못하면 죽는다. 죽는 나무는 별도로 기록 

2단계 
죽은 나무의 나이 / 2를 양분 배열에 추가 

3단계 
번식하는 나무. 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
이 부분을 어떻게 처리해줄지가 문제 ^오^
구조체 배열을 세개 만들자. 두개 만들어서 
한 배열에서 뒤에서부터 쭉 돌면서 r값 c값 같은 애의 양분을 소비하고,
소비하고 나서 살아남은 애는 다른쪽 배열로 옮겨준다. 그리고 나서 나이를 증
가시켜주고
죽은 애들은 dead 배열에 추가해준다. 그리고 나서 2단계 때 하나씩 처리해주고.

마지막 단계는 전체 영역에 양분을 추가해주면서 끝낸다.
*/
#include <stdio.h>
typedef struct {
    int r;
    int c;
    int age;
}T;

T tree[2][105 * 105]; // 번갈아가면서 사용 예정 
T dead[105 * 105]; // 죽은 애들만 따로 저장 
int wp, rp;
int dwp, drp;
int N, M, K;
int Map[]

void input(void);
void spring(void);
void summer(void);
void autumn(void);
void winter(void);

int main(void)
{
    return 0;

}

void input(void)
{
    int i, j;
    scanf("%d %d %d", &N, &M, &K); 
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf()
        }
    }
}