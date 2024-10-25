#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;
vector<vector<char>> board;
vector<pair<int, int>> C;
uint32_t cost[101][101][4] = {
    0,
};
int N, M;

struct Node
{
    int count;
    int y, x, dir;
    Node(int count, int y, int x, int dir) : count(count), y(y), x(x), dir(dir)
    {
    }
    const bool operator<(const Node &n) const
    {
        return count > n.count;
    }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dijk(int y, int x)
{
    priority_queue<Node> pq;
    for (int i = 0; i < 4; ++i)
    {
        cost[y][x][i] = 0;
        pq.push(Node(0, y, x, i));
    }

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        if (cost[cur.y][cur.x][cur.dir] < cur.count)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            if ((i + 2) % 4 == cur.dir)
                continue;

            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (ny >= N || ny < 0 || nx >= M || nx < 0 || board[ny][nx] == '*')
                continue;

            int tmp = (i != cur.dir) ? 1 : 0;

            int new_cost = cur.count + tmp;

            if (cost[ny][nx][i] > new_cost)
            {
                cost[ny][nx][i] = new_cost;
                pq.push(Node(new_cost, ny, nx, i));
            }
        }
    }

    int dsty = C[1].first;
    int dstx = C[1].second;
    return std::min({cost[dsty][dstx][0], cost[dsty][dstx][1],
                     cost[dsty][dstx][2], cost[dsty][dstx][3]});
}

int main()
{
    cin >> M >> N;
    board.resize(N, vector<char>(M));
    memset(cost, -1, sizeof(cost));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'C')
            {
                C.push_back({i, j});
            }
        }
    }
    cout << dijk(C[0].first, C[0].second);
    return 0;
}
