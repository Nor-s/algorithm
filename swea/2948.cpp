#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

constexpr int MOD = 100007;

int makeHash(string s)
{
    int ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret = (ret * 31 + (s[i] - 'a')) % MOD;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        bool mp[MOD];
        memset(mp, false, sizeof(mp));
        int a, b;
        {
            cin >> a >> b;
        }
        for (int i = 0; i < a; i++)
        {
            string s;
            cin >> s;
            mp[makeHash(s)] = true;
        }
        int count = 0;
        for (int i = 0; i < b; i++)
        {
            string s;
            cin >> s;
            if
        }
        cout << "#" << tc << " " << count << endl;
    }
}