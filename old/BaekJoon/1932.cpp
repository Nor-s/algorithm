#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <iterator>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;
// 11 23

int tt[5002], jj[5002];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> jj[j];
            jj[j] = max(jj[j] + ((j - 1 < 0) ? 0 : tt[j - 1]), jj[j] + tt[j]);
        }
        swap(tt, jj);
    }
    cout << *max_element(tt, tt + n + 1);
}