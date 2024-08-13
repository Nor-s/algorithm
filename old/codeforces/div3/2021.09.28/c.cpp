#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
vector<vector<char>> board;
int n, m, k;
// not yet painted = '.' / or '*;
// init = all white
// 좌표 i, j 왼쪽위부터 1,1 ~ n,m
// tic of size = d
// 두 대각선 은 검정 cell로 구성됨
// 이미칠한것은 그대로 블랙
// nxm =>  최저 k높이의 틱을 그려서 문양을 그릴 수 있는지?
// 백트래킹
// d < n
vector<pair<int, int>> painted;
map<pair<int, int>, int> chck;

bool erase1(int i, int j, int d)
{
    for (int h = 0; h <= d; h++)
    {
        if (i - h < 0 || j + h >= m || j - h < 0)
        {
            return false;
        }
        if (board[i - h][j + h] == '.' || board[i - h][j - h] == '.')
        {
            return false;
        }
    }
    chck[{i, j}]++;
    for (int h = 1; h <= d; h++)
    {
        chck[{i - h, j + h}]++;
        chck[{i - h, j - h}]++;
    }
    return true;
}

string solve()
{
    for (int i = painted.size() - 1; i >= 0; i--)
    {
        for (int h = k; h < n; h++)
        {
            // 밑에서부터 체크하므로
            if (erase1(painted[i].first, painted[i].second, h) == false)
                break;
        }
    }
    if (chck.size() == painted.size())
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        board.clear();
        board.resize(n, vector<char>(m));
        painted.resize(0);
        chck.clear();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '*')
                {
                    painted.push_back({i, j});
                }
            }
        }
        cout << solve() << "\n";
    }
}