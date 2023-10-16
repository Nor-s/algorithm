#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

int R, C;
char board[101][101];
int cnt = 0;
int stick[101];
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0};
int direction = 1;
int visited[101][101];

vector<pair<int, int>> minerals;
int clusterIdx = 1;
int minY = 102;

bool isAir = false;

bool boundary(int x, int y)
{
    return x >= 0 && x < C && y >= 0 && y < R;
}
void dfs(int x, int y)
{
    visited[y][x] = clusterIdx;
    minerals.push_back(make_pair(y, x));

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny == R)
        {
            isAir = false;
        }
        if (!boundary(nx, ny))
        {
            continue;
        }
        if (board[ny][nx] == 'x' && visited[ny][nx] == 0)
        {
            dfs(nx, ny);
        }
    }
}

void simulation(int x, int y)
{
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (boundary(nx, ny) && board[ny][nx] == 'x' && visited[ny][nx] == 0)
        {
            clusterIdx = 1;
            minerals.clear();
            minY = 102;
            isAir = true;
            dfs(nx, ny);
            if (isAir)
            {
                for (int j = 0; j < minerals.size(); j++)
                {
                    auto [yy, xx] = minerals[j];
                    int h = 1;
                    for (; h < R; h++)
                    {
                        if (!boundary(xx, yy + h) || (board[yy + h][xx] == 'x' && visited[yy + h][xx] != visited[yy][xx]))
                        {
                            break;
                        }
                        else if ((boundary(xx, yy + h) && board[yy + h][xx] == 'x' && visited[yy + h][xx] == visited[yy][xx]))
                        {
                            h = 102;
                            break;
                        }
                    }
                    minY = min(minY, h - 1);
                }
                for_each(minerals.begin(), minerals.end(), [](pair<int, int> p)
                         { board[p.first][p.second] = '.'; });
                for_each(minerals.begin(), minerals.end(), [](pair<int, int> p)
                         { board[p.first + minY][p.second] = 'x'; });
                break;
            }
        }
        clusterIdx++;
    }
}

void colision(int height)
{
    int x = 0;
    if (direction < 0)
    {
        x = C - 1;
    }

    while (x >= 0 && x < C)
    {
        if (board[height][x] == 'x')
        {
            board[height][x] = '.';
            simulation(x, height);
            break;
        }
        x += direction;
    }
}

void simulation()
{
    for (int i = 0; i < cnt; i++)
    {
        colision(R - 1 - (stick[i] - 1));
        direction *= -1;
    }
    for (int j = 0; j < R; j++)
    {
        for (int k = 0; k < C; k++)
        {
            cout << board[j][k];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }

    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> stick[i];
    }
    simulation();
}