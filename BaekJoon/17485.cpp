#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;

int cached[1001][1001][4];
int dx[3] = {-1, 0, 1};

int dp(int y, int x, int before)
{
    if (y + 1 == board.size())
    {
        return 0;
    }

    int &ret = cached[y][x][before];

    if (ret != -1)
    {
        return ret;
    }
    ret = 1e9;

    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        if (before != i && nx >= 0 && nx < board[0].size())
        {
            ret = min(ret, dp(y + 1, nx, i) + board[y + 1][nx]);
        }
    }
    return ret;
}

int main()
{
    int n, m;
    memset(cached, -1, sizeof cached);
    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int answer = 1e9;
    for (int i = 0; i < m; i++)
    {
        answer = min(answer, dp(0, i, 3) + board[0][i]);
    }
    cout << answer;
}
