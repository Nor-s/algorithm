#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;

const long long MOD = 1e9L;
int main()
{
    int n;
    cin >> n;
    long long dp[102][12];
    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= 10; i++)
        {
            if (j == 1)
            {
                if (i != 1)
                {
                    dp[j][i] = 1;
                }
            }
            else
            {
                dp[j][i] = (dp[j - 1][i - 1] + dp[j - 1][i + 1]) % MOD;
            }
        }
    }
    long long answer = 0;
    for (int i = 1; i <= 10; i++)
    {
        answer = (answer + dp[n][i]) % MOD;
    }
    cout << answer;
}