// start : 2022-02-10 17:43:50
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <tuple>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e
#define vcout(vf, ve) copy(vf, ve, ostream_iterator<int>(cout, " "));

using namespace std;

vector<int> T;
vector<int> M;
vector<int> C;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    T.resize(n + 1, 0);
    M.resize(n + 1, 0);
    C.resize(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i] >> M[i];
    }
    int b_max = 0;
    for (int i = 1; i <= n; i++)
    {
        b_max = max(b_max, C[i]);
        if (i + T[i] - 1 <= n)
        {
            C[i + T[i]] = max(b_max + M[i], C[i + T[i]]);
        }
    }
    cout << *max_element(C.begin(), C.end());
}