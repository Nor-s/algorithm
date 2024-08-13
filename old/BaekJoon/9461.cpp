#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 5 22
int N;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        long long dp[101];
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        for (int i = 6; i <= N; i++)
        {
            dp[i] = dp[i - 5] + dp[i - 1];
        }
        cout << dp[N] << "\n";
    }
}