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

int board[20][20];

int answer = 0;
// 0 : 가로, 1: 세로, 2: 대각선
int cached[20][20][3];
int N;

std::vector<std::vector<int>> rotate[3] = {
    // y x
    {{0, 1, 0}, {1, 1, 2}},
    {{1, 1, 2}, {1, 0, 1}},
    {{0, 1, 0}, {1, 0, 1}, {1, 1, 2}}};

bool check(int y, int x)
{
    return (board[y - 1][x] + board[y][x - 1]) == 0;
}

int dp(int y, int x, int dir)
{
    if (y == N && x == N)
    {
        return 1;
    }
    int &ret = cached[y][x][dir];
    if (ret == 0)
    {
        for (int i = 0; i < rotate[dir].size(); i++)
        {
            int ny = rotate[dir][i][0] + y;
            int nx = rotate[dir][i][1] + x;
            int ndir = rotate[dir][i][2];
            if (board[ny][nx] == 0)
            {
                if (ndir == 2 && !check(ny, nx))
                {
                    continue;
                }
                ret += dp(ny, nx, ndir);
            }
        }
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;

    memset(board, -1, sizeof board);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> board[i][j];
        }
    }
    int answer = dp(1, 2, 0);

    std::cout << answer << "\n";
}