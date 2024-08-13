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

int board[11][11];
int cached[11][11][(1 << 10) + 1][(1 << 10)+ 1];
int N;
int M;
int answer = 0;
int dy[4] = {-1, -1, 0, 0};
int dx[4] = {-1, 1, -1, 1};

pair<int, int> setBoard(int y, int x, int value, int current_state, int next_state)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= N || nx >= M || nx <= -1 || ny <= -1)
        {
            continue;
        }
        board[ny][nx] += value;
        if (i < 2)
        {
            if (board[ny][nx] > 0)
                next_state |= (1 << nx);
            else
                next_state &= ~(1 << nx);
        }
        else
        {
            if (board[ny][nx] > 0)
                current_state |= (1 << nx);
            else
                current_state &= ~(1 << nx);
        }
    }
    return {current_state, next_state};
}

int dp2(int y, int x, int current_state, int next_state)
{
    if(x <= -1) {
        return dp2(y - 1, M - 1, next_state, 0);
    }
    if (y == -1)
    {
        return 0;
    }
    int &ret = cached[y][x][current_state][next_state];
    if (ret == -1)
    {
        ret = 0;
        if (board[y][x] == 0)
        {
            auto [current, next] = setBoard(y, x, 1, current_state, next_state);
            ret = max(ret, dp2(y, x - 2, current, next) + 1);
            setBoard(y, x, -1, current, next);
        }
        ret = max(ret, dp2(y, x - 1, current_state, next_state));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        answer = 0;
        memset(cached, -1, sizeof cached);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                char tmp;
                cin >> tmp;
                if (tmp == '.')
                {
                    board[i][j] = 0;
                }
                else
                {
                    board[i][j] = 100000;
                }
            }
        }
        answer = dp2(N - 1, M - 1, 0, 0);
        cout << answer << "\n";
    }
}