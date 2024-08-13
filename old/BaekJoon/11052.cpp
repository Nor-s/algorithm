#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 8 23
vector<int> p;
// card 1, 2, 3, 4, 5, 6, 7, n
// kind : 8
// 돈을 최대한 많이 지불하여 카드 N 개 를 구매.
// 카드팩 가격 pi

int main()
{
    int n;
    cin >> n;
    p.resize(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> p[i];
    }

    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j + i <= n; j++)
        {
            dp[j + i] = max(dp[j + i], dp[j] + p[i]);
        }
    }
    cout << dp[n];
}