#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;
// 6 4 8
vector<vector<char>> board;
vector<vector<bool>> visited;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
int n;

vector<function<bool(char, char)>> f = {
    [](char a, char b)
    {
        return a == b;
    },
    [](char a, char b)
    {
        if ((a == 'G' && b == 'R') || (a == 'R' && b == 'G'))
        {
            return true;
        }
        return a == b;
    }};

void dfs(int y, int x, int ii)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (xx < 0 || yy < 0 || yy >= n || xx >= n || visited[yy][xx])
        {
            continue;
        }
        if (!f[ii](board[y][x], board[yy][xx]))
        {
            continue;
        }
        dfs(yy, xx, ii);
    }
}

void dfsAll()
{
    int aa = 0;
    visited.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j, 0);
                aa++;
            }
        }
    }
    cout << aa << " ";
    aa = 0;
    visited.clear();
    visited.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] == 1)
            {
                dfs(i, j, 1);
                aa++;
            }
        }
    }
    cout << aa;
}

int main()
{
    cin >> n;
    board.resize(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    dfsAll();
}