#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> T, P;

int main()
{
    int N;
    cin >> N;
    T.resize(N + 1);
    P.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }
    int dp[20];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= N; i++)
    {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (i + T[i] <= N + 1)
        {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }
    cout << *max_element(dp, dp + 20);
}