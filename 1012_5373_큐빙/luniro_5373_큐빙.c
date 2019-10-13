#include <stdio.h>

char m[7] = "wgobry";
char out[13] = "www\nwww\nwww\n";
int y[8] = {0, 1, 2, 6, 10, 9, 8, 4};
int z[3][5] = {{0, 2, 5, 4, 0}, {0, 3, 5, 1, 0}, {1, 2, 3, 4, 1}};
char Q[1001][3];
int T, N;
int p[8];
char L[54][2], R[54][2], U[54][2], D[54][2], F[54][2], B[54][2];

void init(void)
{
    int i, j;
    int t1, t2;

    for (i = 0; i < 54; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            L[i][j] = R[i][j] = U[i][j] = D[i][j] = F[i][j] = B[i][j] = -1;
        }
    }
    
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            t1 = 8 * z[2][i] + j;
            t2 = 8 * z[2][i+1] + j;
            U[t1][0] = t2;
            U[t2][1] = t1;
        }

        for (j = 4; j < 7; ++j)
        {
            t1 = 8 * z[2][i] + j;
            t2 = 8 * z[2][i+1] + j;
            D[t1][1] = t2;
            D[t2][0] = t1;
        }
        
        for (j = 2; j < 5; ++j)
        {
            t1 = 8 * z[0][i] + (((z[0][i] & 3) != 0) ? (4 + j) % 8 : j);
            t2 = 8 * z[0][i+1] + (((z[0][i+1] & 3) != 0) ? (4 + j) % 8 : j);
            R[t1][0] = t2;
            R[t2][1] = t1;
        }

        for (j = 6; j < 9; ++j)
        {
            t1 = 8 * z[0][i] + (((z[0][i] & 3) == 0) ? j % 8 : j - 4);
            t2 = 8 * z[0][i+1] + (((z[0][i+1] & 3) == 0) ? j % 8 : j - 4);
            L[t1][1] = t2;
            L[t2][0] = t1;
        }
        
        for (j = 4; j < 7; ++j)
        {
            t1 = 8 * z[1][i] + ((z[1][i] % 5 == 0) ? j : ((z[1][i] == 3) ? (j + 2) % 8 : j - 2) );
            t2 = 8 * z[1][i+1] + ((z[1][i+1] % 5 == 0) ? j : ((z[1][i+1] == 3) ? (j + 2) % 8 : j - 2) );
            F[t1][0] = t2;
            F[t2][1] = t1;
        }
        
        for (j = 0; j < 3; ++j)
        {
            t1 = 8 * z[1][i] + ((z[1][i] % 5 == 0) ? j : ((z[1][i] == 3) ? (j + 2) : (6 + j) % 8 ) );
            t2 = 8 * z[1][i+1] + ((z[1][i+1] % 5 == 0) ? j : ((z[1][i+1] == 3) ? (j + 2) : (6 + j) % 8 ) );
            B[t1][1] = t2;
            B[t2][0] = t1;
        }
    }
    
    for (i = 0; i < 8; ++i)
    {
        U[i][0] = (i + 2) % 8;
        U[i][1] = (i + 6) % 8;
        D[40 + i][0] = 40 + (i + 2) % 8;
        D[40 + i][1] = 40 + (i + 6) % 8;
        L[8 + i][0] = 8 + (i + 2) % 8;
        L[8 + i][1] = 8 + (i + 6) % 8;
        R[24 + i][0] = 24 + (i + 2) % 8;
        R[24 + i][1] = 24 + (i + 6) % 8;
        F[32 + i][0] = 32 + (i + 2) % 8;
        F[32 + i][1] = 32 + (i + 6) % 8;
        B[16 + i][0] = 16 + (i + 2) % 8;
        B[16 + i][1] = 16 + (i + 6) % 8;
    }
}

int main(void)
{
    int i;
    int s;
    
    init();

    scanf("%d", &T);
    while (T--)
    {
        for (i = 0; i < 8; ++i)
        {
            p[i] = i;
            out[y[i]] = 'w';
        }
        scanf("%d\n", &N);
        for (i = 0; i < N; ++i)
        {
            scanf("%s", Q[i]);
        }
        
        while (N--)
        {
            s = (Q[N][1] == '+');
            if (Q[N][0] == 'U')
            {
                for (i = 0; i < 8; ++i)
                {
                    if (U[p[i]][s] < 0) continue;
                    p[i] = U[p[i]][s];
                }
            }
            else if (Q[N][0] == 'D')
            {
                for (i = 0; i < 8; ++i)
                {
                    if (D[p[i]][s] < 0) continue;
                    p[i] = D[p[i]][s];
                }
            }
            else if (Q[N][0] == 'L')
            {
                for (i = 0; i < 8; ++i)
                {
                    if (L[p[i]][s] < 0) continue;
                    p[i] = L[p[i]][s];
                }
            }
            else if (Q[N][0] == 'R')
            {
                for (i = 0; i < 8; ++i)
                {
                    if (R[p[i]][s] < 0) continue;
                    p[i] = R[p[i]][s];
                }
            }
            else if (Q[N][0] == 'F')
            {
                for (i = 0; i < 8; ++i)
                {
                    if (F[p[i]][s] < 0) continue;
                    p[i] = F[p[i]][s];
                }
            }
            else if (Q[N][0] == 'B')
            {
                for (i = 0; i < 8; ++i)
                {
                    if (B[p[i]][s] < 0) continue;
                    p[i] = B[p[i]][s];
                }
            }
        }

        for (i = 0; i < 8; ++i)
        {
            out[ y[i] ] = m[ p[i]/8 ];
        }
        printf("%s", out);
    }
    
    return 0;
}
