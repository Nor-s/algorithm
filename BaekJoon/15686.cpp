#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int board[51][51];

// 0 == bin, 1 == home, 2== chicken
// 치킨 거리 == 집과 가장 가까운 치킨집 사이의 거리.
// 도시의 치킨거리 == 모든 집의 치킨거리의 합
// |r1-r2| + |c1-c2|

vector<tuple<int, int, int>> home;
vector<tuple<int, int>> chick;
vector<int> dist;

int bfs(tuple<int, int, int> hh)
{
    queue<tuple<int, int, int>> qq;
    bool visited[51][51];
    memset(visited, 0, sizeof visited);
    visited[get<1>(hh)][get<2>(hh)] = true;
    qq.push(hh);

    static const int dx[4] = {1, -1, 0, 0};
    static const int dy[4] = {0, 0, 1, -1};
    while (!qq.empty())
    {
        auto [cost, yy, xx] = qq.front();
        qq.pop();
        for (int i = 0; i < 4; i++)
        {
            int yyy = yy + dy[i];
            int xxx = xx + dx[i];
            if (yyy >= n || xxx >= n || yyy < 0 || xxx < 0 || visited[yyy][xxx])
            {
                continue;
            }
            if (board[yyy][xxx] == 2)
            {
                return cost + 1;
            }
            else
            {
                visited[yyy][xxx] = true;
                qq.push({cost + 1, yyy, xxx});
            }
        }
    }
    return -1;
}

int dp(int idx, int select)
{
    if (chick.size() - select <= m)
    {
        int sum = 0;
        for (int i = 0; i < home.size(); i++)
        {
            sum += bfs(home[i]);
        }
        return sum;
    }
    if (idx == chick.size())
    {
        return INT32_MAX;
    }
    int answer = INT32_MAX;

    board[get<0>(chick[idx])][get<1>(chick[idx])] = 0;
    answer = min(answer, dp(idx + 1, select + 1));
    board[get<0>(chick[idx])][get<1>(chick[idx])] = 2;

    answer = min(answer, dp(idx + 1, select));
    return answer;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                home.push_back({0, i, j});
            }
            else if (board[i][j] == 2)
            {
                chick.push_back({i, j});
            }
        }
    }
    cout << dp(0, 0);
}