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
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int box[101][101][101];
queue<tuple<int, int, int, int>> qtiii;
int tomatosize = 0;
int m, n, h;

int bfs()
{
    int count = qtiii.size();
    int ret = 0;
    while (!qtiii.empty())
    {
        auto [x, y, z, day] = qtiii.front();
        qtiii.pop();
        for (int i = 0; i < 6; i++)
        {
            int xx = dx[i] + x;
            int yy = dy[i] + y;
            int zz = dz[i] + z;
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || zz < 0 || zz >= h)
            {
                continue;
            }
            int &item = box[zz][yy][xx];
            if (item == 0)
            {
                ret = max(ret, day + 1);
                count++;
                item = 1;
                qtiii.push({xx, yy, zz, day + 1});
            }
        }
    }
    if (count != tomatosize)
    {
        return -1;
    }
    return ret;
}

int main()
{
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                {
                    qtiii.push({k, j, i, 0});
                }
                if (box[i][j][k] != -1)
                {
                    tomatosize++;
                }
            }
        }
    }
    cout << bfs();
}