#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
// 1 5 6

vector<vector<char>> a;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

int bfs(int y, int x)
{
    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    dist[y][x] = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, y, x});
    while (!q.empty())
    {
        auto [cost, yy, xx] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int yyy = yy + dy[i];
            int xxx = xx + dx[i];
            if (yyy < 0 || yyy >= N || xxx < 0 || xxx >= M || a[yyy][xxx] == '0')
            {
                continue;
            }
            else
            {
                if (dist[yyy][xxx] == 1e9)
                {
                    dist[yyy][xxx] = cost + 1;
                    q.push({dist[yyy][xxx], yyy, xxx});
                }
            }
        }
    }
    return dist[N - 1][M - 1];
}

int main()
{
    cin >> N >> M;
    a.clear();
    a.resize(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << bfs(0, 0) + 1;
}