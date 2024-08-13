#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
vector<int> a;
int dp[1001][1001];

int solve()
{
    memset(dp, 0, sizeof dp);
    dp[0][a[0]] = a[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (j < a[i])
            {
                dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][j] + a[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    return *max_element(dp[n - 1], dp[n - 1] + 1001);
}

int main()
{
    cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve();
}