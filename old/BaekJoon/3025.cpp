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

class StoneGame
{
public:
    vector<vector<char>> board;
    vector<vector<pair<int, int>>> cached;
    vector<vector<int>> topWall;
    int R, C;
    int N;

    int findNextWall(int x, int y)
    {
        auto it = upper_bound(topWall[x].begin(), topWall[x].end(), y);
        if (it != topWall[x].end())
        {
            int index = it - topWall[x].begin();
            return topWall[x][index];
        }
        return -1;
    }

    // lo~hi 에는 . 또는 o 만이 있음이 보장됨. 또한 '.' < 'O' 이므로 lower_bound로 찾기 가능
    int findNextStone(int x, int lo_y, int hi_y)
    {
        auto it = lower_bound(board[x].begin() + lo_y, board[x].begin() + hi_y, 'O');

        // 만약 찾으면, 그 돌의 인덱스 리턴
        if (it != board[x].begin() + hi_y)
        {
            int index = it - board[x].begin();
            return index;
        }
        // 없으면 -1 리턴
        return -1;
    }

    pair<int, int> recursionDown(int x, int y)
    {
        pair<int, int> &ret = cached[x][y];
        if (ret.first == -1)
        {
            int yy = findNextWall(x, y);
            // 현재 돌의 위치와 가장 가까운 벽 사이에서 돌을 찾음
            int nexty = findNextStone(x, y, yy);
            if (nexty == -1)
            {
                return ret = {x, yy - 1};
            }
            if (x - 1 >= 0 && nexty - 1 >= 0 && board[x - 1][nexty - 1] == '.' && board[x - 1][nexty] == '.')
            {
                return ret = recursionDown(x - 1, nexty - 1);
            }
            else if (x + 1 < C && nexty - 1 >= 0 && board[x + 1][nexty - 1] == '.' && board[x + 1][nexty] == '.')
            {
                return ret = recursionDown(x + 1, nexty - 1);
            }
            else
            {
                return {x, nexty - 1};
            }
        }
        return ret;
    }

    void down(int x)
    {
        int y = 0;
        while (true)
        {
            if (cached[y][x] == -1)
            {
                // 먼저 돌을 떨어트리는쪽에서 가장 가까운 벽을 찾음
                int yy = findNextWall(x, y);
                // 현재 돌의 위치와 가장 가까운 벽 사이에서 돌을 찾음
                int nexty = findNextStone(x, y, yy);
                // cout << yy << ": " << nexty << "----\n";
                // 만일 돌이 없다면, 가장 가까운 벽 위에 돌을 세움
                if (nexty == -1)
                {
                    // cout << "NO STONE\n";
                    y = yy - 1;
                    break;
                }

                // 만약 미끄러지면, 그방향으로 다시 돌을 떨어트림 (x축 이동)
                // 만일 돌이 있다면, 왼쪽 체크
                if (x - 1 >= 0 && nexty - 1 >= 0 && board[x - 1][nexty - 1] == '.' && board[x - 1][nexty] == '.')
                {
                    // cout << "LEFT\n";
                    y = nexty - 1;
                    x = x - 1;
                }
                // //  오른쪽 체크
                else if (x + 1 < C && nexty - 1 >= 0 && board[x + 1][nexty - 1] == '.' && board[x + 1][nexty] == '.')
                {
                    // cout << "RIGHT\n";
                    y = nexty - 1;
                    x = x + 1;
                }
                // 그 위에 둔다.
                else
                {
                    // cout << "NO MOVE\n";
                    y = nexty - 1;
                    break;
                }
            }
        }
        board[x][y] = 'O';
    }

    void init()
    {
        cin >> R >> C;
        board = vector<vector<char>>(C, vector<char>(R));
        topWall = vector<vector<int>>(C, vector<int>(0));
        cached = vector<vector<pair<int, int>>>(C, vector<pair<int, int>>(R, {-1, -1}));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> board[j][i];
                if (board[j][i] == 'X')
                {
                    topWall[j].push_back(i);
                }
            }
        }
        // 땅도 벽으로 취급
        for (int i = 0; i < C; i++)
        {
            topWall[i].push_back(R);
        }

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            down(tmp - 1);
            // debug();
        }
        // debug();
    }
    void debug()
    {
        // cout << "=================\n";
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << board[j][i];
            }
            cout << "\n";
        }
        // cout << "=================\n";
    }
};

int main()
{
    StoneGame sg;
    sg.init();
    sg.debug();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}