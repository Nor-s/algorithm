#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
int R, C;
vector<vector<char>> A;

queue<tuple<int, int, int>> q;
vector<vector<int>> dist;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int y, int x)
{
    while (!q.empty())
    {
        auto [day, yy, xx] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int yyy = yy + dy[i];
            int xxx = xx + dx[i];
            if (yyy < 0 || yyy >= C || xxx < 0 || xxx >= R)
            {
                if (A[yy][xx] == 'J')
                {
                    return day + 1;
                }
                continue;
            }
            if (A[yyy][xxx] == '#' || A[yyy][xxx] == 'F')
            {
                continue;
            }

            if (dist[yyy][xxx] == 1e9 || (A[yy][xx] == 'F' && A[yyy][xxx] == 'J'))
            {
                dist[yyy][xxx] = day + 1;
                A[yyy][xxx] = A[yy][xx];
                q.push({dist[yyy][xxx], yyy, xxx});
            }
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
    dist.resize(C, vector<int>(R, 1e9));

    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 'J' || A[i][j] == 'F')
            {
                q.push({0, i, j});
            }
        }
    }
    int answer = bfs(0, 0);
    if (answer == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << answer;
    }
}