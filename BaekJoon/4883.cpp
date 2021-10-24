#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 12 55
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    register int t = 1;
    register int ba = 0, bb = 0, bc = 0;
    register int a, b, c;
    register int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cin >> ba >> bb >> bc;
        ba = 1e8;
        bc = bb + bc;
        for (register int i = 1; i < n; i++)
        {
            cin >> a >> b >> c;
            a = min(a + ba, a + bb);
            b = min({b + ba, b + bb, b + bc, a + b});
            c = min({c + bb, c + bc, b + c});
            ba = a;
            bb = b;
            bc = c;
        }
        cout << t++ << ". " << bb << "\n";
    }
}