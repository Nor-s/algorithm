// start : 2021-12-28 16:13:23

#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int dx[] = {1, 1, -1, -1, 2, -2, 2, -2};
int dy[] = {2, -2, 2, -2, 1, 1, -1, -1};

int box[301][301];
queue<tuple<int, int, int>> qtii;

int n;
int k, s;

int bfs()
{
    while (!qtii.empty())
    {
        auto [x, y, day] = qtii.front();
        qtii.pop();
        for (int i = 0; i < 8; i++)
        {
            int xx = dx[i] + x;
            int yy = dy[i] + y;

            if (xx < 0 || xx >= n || yy < 0 || yy >= n)
            {
                continue;
            }
            if (yy == k && xx == s)
            {
                return day + 1;
            }
            int &item = box[yy][xx];
            if (item == 0)
            {
                item = 1;
                qtii.push({xx, yy, day + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        qtii = queue<tuple<int, int, int>>();
        memset(box, 0, sizeof(box));
        cin >> n;
        int i, j;
        cin >> i >> j;
        box[i][j] = 1;
        qtii.push({j, i, 0});
        cin >> k >> s;
        if (k == i && j == s)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << bfs() << "\n";
        }
    }
}