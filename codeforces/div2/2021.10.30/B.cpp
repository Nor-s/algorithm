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

//    1
//   10
//   11
//  100
//  101
//  110
//  111
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111
// 같은것이 짝수개.
int dp[100001];
int xo[100001];
int dp2()
{
    for (int i = 0; i < a.size(); i++)
    {
        if (dp[i] == 0)
            dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    xo[i] = xo[i] ^ dp[j];
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    return xo[a.size() - 1];
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
        memset(dp, 0, sizeof dp);
        memset(xo, 0, sizeof xo);
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (dp2() == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}