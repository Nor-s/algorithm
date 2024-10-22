
// s: 1051
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

// beforeDir, x, y
int cached[4][1001][1001];
int N, M;
int BIG_NUM = INT32_MAX / 3;
int dx[] = {-1, 0, 1};
vector<vector<int>> cost;

int solve(int y, int x, int beforeDir)
{
    if (y >= N)
    {
        return 0;
    }
    if (x < 0 || x >= M)
    {
        return BIG_NUM;
    }

    int &ret = cached[beforeDir][y][x];
    if (ret != -1)
    {
        return ret;
    }
    ret = BIG_NUM;

    for (int i = 0; i < 3; i++)
    {
        if (beforeDir == i)
            continue;
        ret = min(ret, solve(y + 1, x + dx[i], i) + cost[y][x]);
    }

    return ret;
}

int main()
{
    cin >> N >> M;
    cost.resize(N, vector<int>(M, 0));
    memset(cached, -1, sizeof(cached));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cost[i][j];
        }
    }
    int answer = BIG_NUM;
    for (int j = 0; j < M; j++)
    {
        answer = min(answer, solve(0, j, 3));
    }
    cout << answer;
}