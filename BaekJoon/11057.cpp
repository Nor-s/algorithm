#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
// 9 40

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(11, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }
    cout << accumulate(dp[n].begin(), dp[n].end(), 0) % 10007;
}