#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 9 14
int n, k;
vector<int> coin;

int main()
{
    cin >> n >> k;
    coin.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j + coin[i] <= k; j++)
        {
            dp[j + coin[i]] += dp[j];
        }
    }
    cout << dp[k];
}