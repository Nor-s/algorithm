#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;
using ll = long long;
int n;
vector<int> a;
vector<ll> seg;

ll update(int lo, int hi, int idx, int x)
{
    if (hi < x || x < lo)
    {
        return seg[idx];
    }
    if (lo == x && hi == x)
    {
        return ++seg[idx];
    }

    int mid = (lo + hi) / 2;
    return seg[idx] = update(lo, mid, idx * 2, x) + update(mid + 1, hi, idx * 2 + 1, x);
}
ll query(int lo, int hi, int idx, int qlo, int qhi)
{
    if (hi < qlo || qhi < lo)
    {
        return 0;
    }
    if (qlo <= lo && hi <= qhi)
    {
        return seg[idx];
    }
    int mid = (lo + hi) / 2;
    return query(lo, mid, 2 * idx, qlo, qhi) + query(mid + 1, hi, 1 + 2 * idx, qlo, qhi);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    a.resize(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        int idx = b[i].second;
        int num = i + 1;
        if (i != 0 && b[i - 1].first == b[i].first)
        {
            num = a[b[i - 1].second];
        }
        a[idx] = num;
    }
    seg.resize(4 * n + 4, 0);
    ll answer = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        answer += query(0, n, 1, 0, a[i] - 1);
        update(0, n, 1, a[i]);
    }
    cout << answer;
}