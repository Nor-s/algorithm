#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> visited;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
long long answer = 0;
void dfs(int y, int x, int count, long long sum)
{
    if (count == 4)
    {
        answer = max(answer, sum);
        return;
    }
    vector<pair<int, int>> next;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (visited[ny][nx])
            continue;

        visited[ny][nx] = true;
        dfs(ny, nx, count + 1, sum + board[ny][nx]);
        if (count == 2)
        {
            for (int j = 0; j < next.size(); j++)
            {
                answer = max(answer, sum + board[ny][nx] + board[next[j].first][next[j].second]);
            }
        }
        visited[ny][nx] = false;
        next.emplace_back(ny, nx);
    }
}

int main()
{
    cin >> N >> M;
    board.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<int>(M, false));
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
        }
    }
    cout << answer;
}
