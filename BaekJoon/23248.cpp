#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <list>

#define gx(p) p.second
#define gy(p) p.first

using namespace std;

int m, n, k;

vector<vector<int>> vv;

// 1200

int solve()
{
    int count = 1;
    list<int> li;
    li.push_back(vv[0].back());

    for (int i = 1; i < vv.size(); ++i)
    {
        int j = 0;
        int f = vv[i][0];

        for (auto &e : li)
        {
            auto low = lower_bound(vv[i].begin(), vv[i].end(), e);
            j++;
        }
    }
    return count;
}

int main()
{
    vector<pair<int, int>> yx;
    cin >> m >> n >> k;
    yx.resize(k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gy(yx[i]) = a;
        gx(yx[i]) = b;
    }
    sort(yx.begin(), yx.end());
    int before_y = -1;
    for (auto &e : yx)
    {
        int x = gx(e), y = gy(e);
        if (y != before_y)
        {
            vv.push_back(vector<int>());
        }
        vv.back().push_back(x);
        before_y = y;
    }
    cout << solve();
}