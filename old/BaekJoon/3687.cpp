#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <utility>
#include <map>
#include <cstdint>

using namespace std;

int numb[] = {
    2,
    5,
    5,
    4,
    5,
    6,
    3,
    7,
    6,
    6};

map<int, int> mp = {
    {2, 1},
    {3, 7},
    {4, 4},
    {5, 2},
    {6, 6}, // {6, 0}
    {7, 8},
};

vector<long long> dp(101, 0);

long long GetMinValue(int x)
{
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;

    for (int i = 8; i <= x; i++)
    {
        dp[i] = INT64_MAX;
        for (int j = 2; j < 8; j++)
        {
            if (i - j >= 2)
            {
                dp[i] = min(dp[i], dp[i - j] * 10 + mp[j]);
            }
        }
        dp[i] = min(dp[i], dp[i - 6] * 10);
    }
    return dp[x];
}

string GetMaxValue(int x)
{
    int oneCount = x / 2;
    string ret = "";
    ret.reserve(x);
    if (x % 2 == 1)
    {
        oneCount--;
        ret.push_back('7');
    }
    while (oneCount > 0)
    {
        oneCount--;
        ret.push_back('1');
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int T = 0;
    cin >> T;
    long long minv = GetMinValue(100);

    for (int i = 0; i < T; i++)
    {
        int x;
        cin >> x;
        string maxv = GetMaxValue(x);
        cout << dp[x] << " "
             << maxv << "\n";
    }
}