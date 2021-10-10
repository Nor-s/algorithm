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
int A, B, C;

int dp[51][51][51];
int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    int &ret = dp[a][b][c];
    if (ret != -1)
    {
        return ret;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return ret = w(20, 20, 20);
    }
    if (a < b && b < c)
    {
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    while (true)
    {
        cin >> A >> B >> C;
        if (A == -1 && B == -1 && C == -1)
        {
            break;
        }
        cout5("w(", A, ", ", B, ", ");
        cout2(C, ") = ");
        cout1(w(A, B, C));

        cout1('\n');
    }
}