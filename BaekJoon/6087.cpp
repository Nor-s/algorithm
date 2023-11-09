#include <bits/stdc++.h>

using namespace std;
/**

7 8
.......
......C
......*
*****.*
....*..
....*..
.C..*..
.......

*/
int n, m;
vector<vector<char>> board;
int cached[101][101][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int yy, xx;

int dfs(int y, int x, int dir)
{
    if (board[y][x] == 'C' && y != yy && x != xx)
    {
        cout << "--------------\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
        return 0;
    }

    int &ret = cached[y][x][dir];
    if (ret != -1)
    {
        return ret;
    }
    ret = INT32_MAX / 2;
    for (int i = 0; i < 4; i++)
    {
        if ((i + 2) % 4 == dir)
        {
            continue;
        }
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        {
            continue;
        }
        if (board[ny][nx] == '*')
        {
            continue;
        }
        int count = 0;
        if (i != dir && dir != 4)
        {
            count = 1;
        }
        char xxx = board[ny][nx];
        ///  board[ny][nx] = '-';
        ret = min(ret, dfs(ny, nx, i) + count);
        ///  board[ny][nx] = xxx;
    }
    return ret;
}

int main()
{
    cin >> m >> n;
    board.resize(n, vector<char>(m));
    memset(cached, -1, sizeof cached);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'C')
            {
                yy = i;
                xx = j;
            }
        }
    }
    cout << dfs(yy, xx, 4);
}
