#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <tuple>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;
int T;

// 2xT
// 10 50
long long dp[1002];
long long dp1(int idx)
{
    if (idx > T + 1)
    {
        return 0;
    }
    if (idx == T + 1)
    {
        return 1ll;
    }
    if (dp[idx] == -1)
    {
        dp[idx] = 0;
        for (int i = 4; i + idx <= T + 1; i += 2)
        {
            dp[idx] += dp1(idx + i) * 2;
        }
        dp[idx] += dp1(idx + 2) * 3;
    }
    return dp[idx];
}
int dp2()
{
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for (int i = 4; i <= T; i++)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }
    return dp[T];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    cout << dp2();
    //   memset(dp, -1, sizeof dp);
    //   cout << "\n dp1: " << dp1(1);
}