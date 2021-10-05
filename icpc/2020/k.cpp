#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;
// 3:05

vector<vector<int>> board;
int h, w;
// 0 -> 도로
// 1 = 1의 비용으로 도로건설 가능
// 2 -> 2의 비용으로 다리건설
// -1 -> 건설 x
// 만약 건설 할 수 없으면 -1
// 최소비용 구하기
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> get_adj(int y, int x)
{
    vector<pair<int, int>> ret;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];

        if (yy >= h || xx >= w || yy < 0 || xx < 0)
        {
            continue;
        }
        if (board[yy][xx] == -1)
        {
            continue;
        }
        ret.push_back({yy, xx});
    }
    return ret;
}

int bfs(int y, int x)
{
    if (board[y][x] == -1)
    {
        return 1e9;
    }
    vector<vector<int>> cost(h, vector<int>(w, 1e9));
    priority_queue<pair<int, pair<int, int>>> pq;
    cost[y][x] = board[y][x];
    pq.push({-board[y][x], {y, x}});
    while (!pq.empty())
    {
        int dist = -pq.top().first;
        pair<int, int> pos = pq.top().second;
        pq.pop();
        if (dist > cost[pos.first][pos.second])
        {
            continue;
        }
        vector<pair<int, int>> adj = get_adj(pos.first, pos.second);
        for (int i = 0; i < (int)adj.size(); i++)
        {
            pair<int, int> there = adj[i];
            int dist_cost = dist + board[there.first][there.second];
            if (cost[there.first][there.second] > dist_cost)
            {
                pq.push({-dist_cost, there});
                cost[there.first][there.second] = dist_cost;
            }
        }
    }
    return cost[h - 1][w - 1];
}

int solve()
{
    return bfs(0, 0);
}

int main()
{
    cin >> h >> w;
    board.clear();
    board.resize(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
        }
    }
    int answer = solve();
    if (answer > 1e8)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}