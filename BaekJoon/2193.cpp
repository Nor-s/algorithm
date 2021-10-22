#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;
ll cached[100][3];
int n;
ll dp(int idx, int before)
{
    if (idx == n)
    {
        return 1ll;
    }
    ll &ret = cached[idx][before];
    if (ret == -1)
    {
        ret = 0;
        if (idx != 0)
        {
            ret += dp(idx + 1, 0);
        }
        if (before == 0)
        {
            ret += dp(idx + 1, 1);
        }
    }
    return ret;
}
ll dp1()
{
    memset(cached, 0, sizeof cached);
    cached[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        cached[i][0] += cached[i - 1][0] + cached[i - 1][1];
        cached[i][1] += cached[i - 1][0];
    }
    return cached[n - 1][0] + cached[n - 1][1];
}

int main()
{
    memset(cached, -1, sizeof cached);
    cin >> n;
    cout << dp1();
}