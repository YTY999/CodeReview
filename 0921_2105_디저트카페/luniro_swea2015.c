#include <stdio.h>

typedef struct _bitset
{
  long long b[2];
} bs;

int tc, T;
int N;
int arr[22][22];
bs chk[2][22][22];
int max, max2;
long long m[101];

void func3(int y1, int x1, int y2, int x2, int len, bs c);
void func2(int y1, int x1, int y2, int x2, int len, bs c);
void func(int y, int x)
{
  int ny = y + 1;
  int nx = x - 1;
  int len = 1;
  int t;
  bs c = {0, 0};

  c.b[arr[y][x] > 50] |= m[arr[y][x]]; 

  while (nx && ny < N)
  {
    t = arr[ny][nx] > 50;
    if (c.b[t] & m[arr[ny][nx]]) return;
    c.b[t] |= m[arr[ny][nx]];
    
    if (N - x + len > max2)
    {
      func2(y + 1, x + 1, ny + 1, nx + 1, len + 1, c);
    }
    len++;
    ny++;
    nx--;
  }
}

void func2(int y1, int x1, int y2, int x2, int len, bs c)
{
  int t;

  while (x1 <= N && y2 <= N)
  {
    t = arr[y1][x1] > 50;
    if (c.b[t] & m[arr[y1][x1]]) return;
    c.b[t] |= m[arr[y1][x1]];
    
    t = arr[y2][x2] > 50;
    if (c.b[t] & m[arr[y2][x2]]) return;
    c.b[t] |= m[arr[y2][x2]];

    if (len > max2)
    {
      func3(y1 + 1, x1 - 1, y2, x2, len, c);
    }

    len++;
    y1++;
    x1++;
    y2++;
    x2++;
  }
}

void func3(int y1, int x1, int y2, int x2, int len, bs c)
{
  int t;
  
  while (y1 != y2)
  {
    t = arr[y1][x1] > 50;
    if (c.b[t] & m[arr[y1][x1]]) return;
    c.b[t] |= m[arr[y1][x1]];

    y1++;
    x1--;
  }
  if (x1 != x2) return;
  max = len << 1;
  max2 = len;
}

int main(void)
{
  int i, j;
  long long z = 1LL;

  for (i = 1; i <= 50; ++i)
  {
    m[i] = m[i + 50] = z;
    z <<= 1;
  }

  scanf("%d", &T);
  for (tc = 1; tc <= T; ++tc)
  {
    max = -1;
    max2 = 0;

    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
    {
      for (j = 1; j <= N; ++j)
      {
        scanf("%d", &arr[i][j]);
      }
    }

    for (i = 1; i < N-1; ++i)
    {
      if ((N-i) <= max2) break;
      for (j = 2; j < N; ++j)
      {
        func(i, j);
      }
    }

    printf("#%d %d\n", tc, max);
  }

  return 0;
}
