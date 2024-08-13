#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
//11:28 53
// 12:45 53
using namespace std;
int n, m;
int board[1000][500] = {0};
int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};
int cached[1000][500];

int reverseDir(int dir)
{
    return (dir + 2) % 4;
}

int dp(int y, int x, int before)
{
    if (y == -1 || x == -1 || y == m || x == n)
    {
        return 0;
    }
    if (board[y][x] >= before)
    {
        return 0;
    }
    if (y == m - 1 && x == n - 1)
    {
        return 1;
    }

    int &ret = cached[y][x];
    if (ret != -1)
    {
        return ret;
    }
    ret = 0;
    for (int i = 0; i < 4; i++)
    {
        ret += dp(y + dy[i], x + dx[i], board[y][x]);
    }
    return ret;
}
void solve()
{
    cout << dp(0, 0, INT32_MAX);
}
/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10

3
*/

int main()
{
    cin >> m >> n;
    memset(cached, -1, sizeof(cached));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solve();
}