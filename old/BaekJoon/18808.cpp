#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iterator>

using namespace std;
// 스티커 차례대로 왼쪽 위부터
// 위치 못찾으면 90도 회전함 (4번 반복)
vector<vector<vector<int>>> sticker;
vector<vector<int>> board;
vector<int> scount;
int n, m, k;

pair<int, int> rotate(int y, int x, int ridx)
{
    static const int dc[4] = {1, 0, -1, 0};
    static const int ds[4] = {0, -1, 0, 1};
    return {dc[ridx] * x + ds[ridx] * y, -ds[ridx] * x + dc[ridx] * y};
}

bool is_okay(int y, int x, int idx, int ridx)
{
    int r = sticker[idx].size();
    int c = sticker[idx][0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            auto [xx, yy] = rotate(i, j, ridx);
            if (y + yy < 0 || y + yy >= n || x + xx < 0 || x + xx >= m || (sticker[idx][i][j] == 1 && board[yy + y][xx + x] == 1))
            {
                return false;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            auto [xx, yy] = rotate(i, j, ridx);
            if (sticker[idx][i][j] == 1)
            {
                board[yy + y][xx + x] = 1;
            }
        }
    }

    return true;
}

int solve()
{
    int answer = 0;
    for (int kk = 0; kk < k; kk++)
    {
        for (int r = 0; r < 4; r++)
        {
            bool updated = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (is_okay(i, j, kk, r))
                    {
                        updated = true;
                        answer += scount[kk];
                        /*
                        cout << "-------------" << r << "--------------------\n";
                        for (int idd = 0; idd < n; idd++)
                        {
                            copy(board[idd].begin(), board[idd].end(), ostream_iterator<int>(cout, " "));
                            cout << "\n";
                        }
*/
                        break;
                    }
                }
                if (updated)
                {
                    break;
                }
            }
            if (updated)
            {
                break;
            }
        }
    }
    return answer;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    board.resize(n, vector<int>(m, 0));
    sticker.resize(k);
    scount.resize(k, 0);
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        sticker[i].resize(r);
        for (int j = 0; j < r; j++)
        {
            sticker[i][j].resize(c);
            for (int k = 0; k < c; k++)
            {
                cin >> sticker[i][j][k];
                if (sticker[i][j][k] == 1)
                {
                    scount[i]++;
                }
            }
        }
    }
    cout << solve();
}