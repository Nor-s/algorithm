#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, c;
        char b;
        cin >> a >> b >> c;
        if (b == 'L')
        {
            mp[a] = -c;
        }
        else
        {
            mp[a] = c;
        }
    }
    int pos;
    cin >> pos;
    while (true)
    {
        if (mp.count(pos) == 0)
        {
            break;
        }
        pos += mp[pos];
    }
    cout << pos;
}