#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
// 6 4 8
vector<vector<int>> board;
vector<pair<int, int>> point;
int number = 2;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
int n;

queue<tuple<int, int, int>> q;
vector<vector<int>> dist;

void dfs(int y, int x)
{
    board[y][x] = number;
    bool is_end = false;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (xx < 0 || yy < 0 || yy >= n || xx >= n)
        {
            continue;
        }
        if (board[yy][xx] != 1)
        {
            if (board[yy][xx] == 0)
            {
                is_end = true;
            }
            continue;
        }
        dfs(yy, xx);
    }
    if (is_end)
    {
        q.push({0, y, x});
        dist[y][x] = 0;
    }
}

void init()
{
    dist.resize(n, vector<int>(n, 1e9));
    for (int i = 0; i < point.size(); i++)
    {
        auto [y, x] = point[i];
        if (board[y][x] == 1)
        {
            dfs(y, x);
            number++;
        }
    }
}

int solve()
{
    while (!q.empty())
    {
        auto [cost, y, x] = q.front();
        int num = board[y][x];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (xx < 0 || yy < 0 || yy >= n || xx >= n || board[yy][xx] == num)
            {
                continue;
            }
            if (board[yy][xx] != 0)
            {
                return dist[yy][xx] + cost;
            }
            else
            {
                board[yy][xx] = num;
                dist[yy][xx] = cost + 1;
                q.push({cost + 1, yy, xx});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    board.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                point.push_back({i, j});
            }
        }
    }
    init();

    cout << solve();
}