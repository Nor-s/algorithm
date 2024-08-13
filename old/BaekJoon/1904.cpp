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
//1202
//1210

int mod = 15746;
int cached[1000001];

int dp(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int &ret = cached[n];
    if (ret != -1)
    {
        return ret;
    }
    ret = 0;

    ret = (ret + dp(n - 2)) % mod;
    ret = (ret + dp(n - 1)) % mod;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cached, -1, sizeof cached);
    int n;
    cin >> n;
    cout << dp(n);
}