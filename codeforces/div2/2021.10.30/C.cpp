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

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e
#define coutvi(a, b) copy(a, b, ostream_iterator<int>(cout, " "))
#define coutvc(a, b) copy(a, b, ostream_iterator<char>(cout, " "))

using namespace std;
vector<int> a;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
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
        int n;
        cin >> n;
        a.clear();
        a.resize(n + 1);
        bool can = true;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] % (i + 1) == 0)
            {
                bool updated = false;
                int max = (a[i] < i + 1) ? a[i] : i;
                for (int j = 1; j + 1 <= max; j++)
                {
                    if (a[i] % (j + 1) != 0)
                    {
                        updated = true;
                        break;
                    }
                }
                if (!updated)
                {
                    can = false;
                }
            }
        }
        if (can)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}