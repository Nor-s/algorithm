#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;
int n, k;
vector<int> m;

bool go_hole(int idx)
{
    int cat = 0;
    for (int i = idx; i < m.size(); i++)
    {
        if (cat >= m[i])
        {
            return false;
        }
        cat += (n - m[i]);
    }
    return true;
}

int bisearch()
{
    int lo = 0, hi = m.size() - 1;
    int mid = 0;
    while (lo != hi)
    {
        mid = (lo + hi) / 2;
        if (go_hole(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return m.size() - hi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        m.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> m[i];
        }
        sort(m.begin(), m.end());
        cout << bisearch() << "\n";
    }
}