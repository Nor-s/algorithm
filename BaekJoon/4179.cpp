#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
int R, C;
queue<tuple<int, int, int, char>> q;
vector<vector<char>> A;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs()
{
    while (!q.empty())
    {
        auto [time, y, x, what] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (what == 'J' && (ny == -1 || ny == C || nx == -1 || nx == R))
            {
                return time + 1;
            }
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (A[ny][nx] == '#' || A[ny][nx] == 'F' || A[ny][nx] == what)
                continue;

            A[ny][nx] = what;
            q.push({time + 1, ny, nx, what});
        }
    }
    return -1;
}
// # 벽
// . 지나갈수있는 공간간
// J 초기위치 (지나갈수있음)
// F == 불이 난 공간
// 미로를 탈출 x =>  IMPOSSIBLE
// 미로 탈출 가장 빠른 시간 출력.
int main()
{
    cin >> C >> R;
    A.resize(C, vector<char>(R));

    pair<int, int> J;
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 'F')
            {
                q.push({0, i, j, A[i][j]});
            }

            if (A[i][j] == 'J')
            {
                J = {i, j};
            }
        }
    }
    q.push({0, J.first, J.second, 'J'});

    int answer = bfs();
    if (answer == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << answer;
    }
}