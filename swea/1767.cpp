#include <iostream>
#include <vector>
#include <set>

using namespace std;
// 0910

vector<int> v;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[14][14];
int N;
int answer = 0;

bool movePoint(int &y, int &x, int dir)
{
    y += dy[dir];
    x += dy[dir];
    if (board[y][x] != 0)
    {
        return false;
    }
    return true;
}

bool check(int point, int dir)
{
    int y = point / N;
    int x = point % N;
    while (movePoint(y, x, dir))
    {
    }
    if (board[y][x] == -1)
    {
        return true;
    }
    return false;
}

int setLine(int y, int x, int dir, int mark = 2)
{
    y += dy[dir];
    x += dx[dir];
    if (board[y][x] == -1)
    {
        return 0;
    }
    board[y][x] = mark;
    return 1 + setLine(y, x, dir, mark);
}

int subSet(int idx)
{
    if (idx == v.size())
    {
        return 0;
    }
    int y = v[idx] / N;
    int x = v[idx] % N;
    int ret = 0;

    // 해당 코어를 연결하거나
    for (int i = 0; i < 4; i++)
    {
        if (check(v[idx], i))
        {
            int line = setLine(y, x, i);
            ret = max(ret, line + subSet(idx + 1));
            setLine(y, x, i, 0);
        }
    }

    // 연결하지 않거나
    ret = max(ret, subSet(idx + 1));
    return ret;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        v.clear();
        answer = 0;
        memset(board, -1, sizeof board);
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '1' && (i != 1 && j != 1 && i != N && j != N))
                {
                    v.push_back(i * N + j);
                }
                if (i == 1 || j == 1 || i == N || j == N)
                {
                    count++;
                }
            }
        }
        subSet(0);
        cout << "#" << test_case << " " << answer + count << "\n";
    }
    return 0;
}