#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 10 30
int t, w_;
vector<int> tree;

int dp[1001][33];
int dp1(int idx, int w)
{
    if (w == w_ + 1)
    {
        return 0;
    }
    if (idx == t)
    {
        return 0;
    }
    int &ret = dp[idx][w];
    if (ret == -1)
    {
        ret = 0;
        ret = dp1(idx + 1, w) + ((w % 2 + 1) == tree[idx]);
        ret = max(ret, dp1(idx, w + 1));
    }
    return ret;
}

int main()
{
    cin >> t >> w_;
    tree.resize(t);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < t; i++)
    {
        cin >> tree[i];
    }
    cout << dp1(0, 0);
}