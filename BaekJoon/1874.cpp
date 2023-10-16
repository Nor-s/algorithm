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
#include <queue>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e
#define coutvi(a, b) copy(a, b, ostream_iterator<int>(cout, " "))
#define coutvc(a, b) copy(a, b, ostream_iterator<char>(cout, " "))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        vector<int> A(a), B(b);
        for (int i = 0; i < a; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < b; i++)
        {
            cin >> B[i];
        }
        sort(B.begin(), B.end());
        int sum = 0;
        for (int i = 0; i < a; i++)
        {
            int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            sum += idx;
        }
        cout << sum << "\n";
    }
}