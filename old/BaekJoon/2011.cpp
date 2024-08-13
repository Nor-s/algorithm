#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 12 18
const int MOD = 1e6;
string s;
int cached[5001];
int dp(int idx)
{
    if (idx == s.size())
    {
        return 1;
    }
    if (s[idx] == '0')
    {
        return 0;
    }
    int &ret = cached[idx];
    if (ret == -1)
    {
        ret = dp(idx + 1);
        if (idx < s.size() - 1 && s.substr(idx, 2) <= "26")
        {
            ret = (ret + dp(idx + 2)) % MOD;
        }
    }
    return ret % MOD;
}

void solve()
{
    memset(cached, -1, sizeof cached);
    cout << dp(0);
}

int main()
{
    cin >> s;
    solve();
}