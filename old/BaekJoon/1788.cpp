#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// f1 = 0 -1
// f0 = f-1 f-2
// f-1 - f-2 =  f-3
// f(n) = f (n + 2) - f(n + 1) 음수
// 8 40
const int MOD = 1e9;

//int cached[2000001];
void dp(int n)
{
    // int &ret = cached[n -]
}
void dp1(int n)
{
    vector<long long> d(abs(n) + 1, 0);
    vector<int> negative(abs(n) + 1, 1);
    if (n < 0)
    {
        d[1] = 1;
        for (int i = 2; i <= abs(n); i++)
        {
            d[i] = negative[i - 2] * d[i - 2] - negative[i - 1] * d[i - 1];
            negative[i] = (d[i] < 0) ? -1 : 1;
            d[i] = abs(d[i]) % MOD;
        }
    }
    else
    {
        d[1] = 1;
        for (int i = 2; i <= abs(n); i++)
        {
            d[i] = (d[i - 1] + d[i - 2]) % MOD;
        }
    }
    if (d[abs(n)] == 0)
    {
        cout << 0;
    }
    else
    {
        cout << negative[abs(n)];
    }
    cout << "\n"
         << d[abs(n)];
}

int main()
{
    int n;
    cin >> n;
    dp1(n);
}