#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
using ull = unsigned long long;
int N{0}; // cross
int S{0};
int E{0};
int T{0};
// [i][j] i -> j : time, 0 == null
// path num

const ull MOD = 1000003U;

ull base[50][50] = {0};
ull answ[50][50] = {0};
// 11 - 12 - 13 - 14 - 15
// 21 - 22 - 23 - 24 - 25
// 31 - 32 - 33 - 34 - 35
// ..
// s , e

void mulmat(ull lhs[50][50], const ull rhs[50][50])
{
    ull ret[50][50];
    memset(ret, 0, sizeof ret);
    int size = N * 5;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int v = 0; v < size; v++)
            {
                ret[i][j] += lhs[i][v] * rhs[v][j];
                ret[i][j] = ret[i][j] % MOD;
            }
        }
    }
    memcpy(lhs, ret, 50 * 50 * sizeof ret[0][0]);
}

void pow(ull mat[50][50], int t)
{
    if (t == 1)
    {
        memcpy(mat, base, 50 * 50 * sizeof mat[0][0]);
    }
    else if (t % 2 == 1)
    {
        pow(mat, t - 1);
        mulmat(mat, base);
    }
    else
    {
        pow(mat, t / 2);
        mulmat(mat, mat);
    }
}

int solve()
{
    pow(answ, T);
    return answ[5 * S][5 * E];
}
/**
 
 3 1 3 5
012
201
120
 */

int main()
{
    cin >> N >> S >> E >> T;
    S--, E--;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            base[i * 5 + j][i * 5 + j - 1] = 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char w;
            cin >> w;
            w -= '0';
            if (w != 0)
            {
                base[i * 5][j * 5 + w - 1] = 1;
            }
        }
    }
    cout << solve();
}