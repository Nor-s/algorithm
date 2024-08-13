// https : //codeforces.com/contest/1579/submission/130262146

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    long long T;
    cin >> T;
    while (T--)
    {
        long long n, ans = 0;
        cin >> n;
        map<long long, long long> mp;
        ordered_set s;
        for (long long i = 0; i < n; i++)
        {
            long long a;
            cin >> a;
            long long x = s.order_of_key(a);
            ans += min(x, i - mp[a] - x);
            s.insert(a);
            mp[a]++;
        }
        cout << ans << endl;
    }
    return 0;
}