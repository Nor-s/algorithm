
// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> cost(N, vector<int>(M, 0));
    // max 값으로 초기화하는 것이 중요
    vector<vector<vector<int>>> cached(
        3, vector<vector<int>>(N, vector<int>(M, 1e9)));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cost[i][j];
            if (i == 0)
                cached[0][i][j] = cached[1][i][j] = cached[2][i][j] =
                    cost[i][j];
        }
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j > 0)
                cached[0][i][j] =
                    min(cached[1][i - 1][j - 1], cached[2][i - 1][j - 1]) +
                    cost[i][j];

            cached[1][i][j] =
                min(cached[0][i - 1][j], cached[2][i - 1][j]) + cost[i][j];

            if (j + 1 < M)
                cached[2][i][j] =
                    min(cached[1][i - 1][j + 1], cached[0][i - 1][j + 1]) +
                    cost[i][j];
        }
    }
    int answer = 1e9;
    for (int j = 0; j < M; j++)
    {
        answer = min({answer, cached[0][N - 1][j], cached[1][N - 1][j],
                      cached[2][N - 1][j]});
    }
    cout << answer;
}