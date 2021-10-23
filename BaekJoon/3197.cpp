#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <tuple>

using namespace std;
using pii = pair<int, int>;
vector<pii> bird;
int h, w;
int board[1501][1501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int, int, int>> q;

vector<int> parent;

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= w || yy >= h || board[yy][xx] == board[y][x])
        {
            continue;
        }
        if (board[yy][xx] == -1)
        {
            board[yy][xx] = board[y][x];
            q.push({1, yy, xx});
            continue;
        }
        if (board[yy][xx] == 0)
        {
            board[yy][xx] = board[y][x];
            dfs(yy, xx);
        }
    }
}
bool dfsAll()
{
    int num = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = num++;
                dfs(i, j);
            }
        }
    }
    parent.resize(num);
    for (int i = 0; i < num; i++)
    {
        parent[i] = i;
    }
    return board[bird[0].first][bird[0].second] == board[bird[1].first][bird[1].second];
}

int find(int u)
{
    while (parent[u] != u)
    {
        int tmp = parent[u];
        parent[u] = parent[tmp];
        u = tmp;
    }
    return u;
}
int merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return 1;
    }
    parent[u] = v;
    return -1;
}

int bfs()
{
    while (!q.empty())
    {
        auto [day, y, x] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= w || yy >= h)
            {
                continue;
            }
            if (board[yy][xx] >= 0)
            {
                board[y][x] = board[yy][xx];
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= w || yy >= h || board[yy][xx] == board[y][x])
            {
                continue;
            }
            if (board[yy][xx] == -1)
            {
                board[yy][xx] = -2;
                q.push({day + 1, yy, xx});
            }
            else if (board[yy][xx] != -2)
            {
                merge(board[y][x], board[yy][xx]);
                if (find(board[bird[0].first][bird[0].second]) == find(board[bird[1].first][bird[1].second]))
                {
                    return day;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char aa;
            cin >> aa;
            if (aa == 'L')
            {
                bird.push_back({i, j});
            }
            if (aa == 'X')
            {
                board[i][j] = -1;
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }
    if (dfsAll())
    {
        cout << 0;
    }
    else
    {
        /*
        cout << "\n";
        for (int i = 0; i < h; i++)
        {
            copy(board[i], board[i] + w, ostream_iterator<int>(cout, " "));
            cout << "\n";
        }
        cout << "\n";
        */
        cout << bfs();
    }
}