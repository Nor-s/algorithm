#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
using namespace std;

/*
vector<int> dp(10001, 1e9);

void solve(vector<int> &coin, int n, int m)
{
    dp[0] = 0;
    for (int i = 0; i < coin.size(); i++)
    {
        for (int j = coin[i]; j <= m; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
}
*/

int cached[10001];

int solve2(vector<int> &coin, int k, int m)
{
    if (k < m)
    {
        return 1e9;
    }
    if (k == m)
    {
        return 0;
    }
    int &ret = cached[m];
    if (ret != -1)
    {
        return ret;
    }
    ret = 1e9;
    for (int i = 0; i < coin.size(); i++)
    {
        ret = min(ret, solve2(coin, k, m + coin[i]) + 1);
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    for (auto x = coin.begin(); x != coin.end(); x++)
        cin >> *x;

    memset(cached, -1, sizeof cached);
    solve2(coin, k, 0);
    cout << (cached[0] == 1e9 ? -1 : cached[0]);
}