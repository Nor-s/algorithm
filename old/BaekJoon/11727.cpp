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
        dp[idx] = (dp[idx] + dp1(idx + 1)) % 10007;
        dp[idx] = (dp[idx] + dp1(idx + 2) * 2) % 10007;
    }
    return dp[idx] % 10007;
}
int dp2()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= T; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    return dp[T];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof dp);

    cin >> T;
    cout << dp2() % 10007;
}