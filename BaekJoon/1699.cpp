#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
// 12 34

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 1; i <= sqrt(n); i++)
    {
        for (int j = 0; j + i * i <= n; j++)
        {
            dp[j + i * i] = min(dp[j + i * i], dp[j] + 1);
        }
    }
    cout << dp[n];
}