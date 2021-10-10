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

int n;
vector<double> a;
double k;
using ull = double;
ull sum = 0;

unsigned long long solve()
{
    unsigned long long answer = 0;
    for (int i = 0; i < a.size(); i++)
    {
        double find = k * 2.0 - a[i];
        int lo = lower_bound(a.begin() + i + 1, a.end(), find) - a.begin();
        int hi = upper_bound(a.begin() + i + 1, a.end(), find) - a.begin();
        answer += (hi - lo);
    }
    return answer;
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
        cin >> n;
        a.resize(n);
        sum = 0.0f;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        k = (double)sum / n;
        cout2(solve(), '\n');
    }
}