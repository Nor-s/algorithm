#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <tuple>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;

int psum[100004];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> aa(n);
    for (int i = 0; i < n; i++)
    {
        cin >> aa[i];
        psum[i + 1] = psum[i] + aa[i];
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << "\n";
    }
}