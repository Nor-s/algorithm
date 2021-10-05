#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
vector<ll> a;
vector<pair<ll, ll>> radian;

ll cached[3001][3];

ll dp(int idx, int before_state, ll before_radian)
{
    if (idx == a.size())
    {
        return 0;
    }
    ll ret = cached[idx][before_state];
    if (ret != -1)
    {
        return ret;
    }
    ret = 0;
    if (before_state == 0)
    {
        ret = max(ret, dp(idx + 1, 0, 0));
        ret = max(ret, dp(idx + 1, 1, radian[idx].second) + radian[idx].second * radian[idx].second);
    }
    else
    {
        ret = max(ret, dp(idx + 1, 0, 0));
        if (before_radian + a[idx - 1] < a[idx])
        {
            ll remain = a[idx] - a[idx - 1] - before_radian;
            if (remain < radian[idx].second)
            {
                ret = max(ret, dp(idx + 1, 2, remain) + remain * remain);
            }
            else
            {
                ret = max(ret, dp(idx + 1, 1, radian[idx].second) + radian[idx].second * radian[idx].second);
            }
        }
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    radian.resize(n);
    memset(cached, -1, sizeof cached);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    radian[0].second = 1e9 + 11;
    for (int i = 1; i < n; i++)
    {
        radian[i - 1].first = 0;
        radian[i - 1].second = min(radian[i - 1].second, a[i] - a[i - 1]);

        radian[i].first = 0;
        radian[i].second = a[i] - a[i - 1];
    }

    cout << dp(0, 0, 0);
}