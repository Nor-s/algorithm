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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        // n % 4 == 8 % n
        // n % 4 == 2 % n , 0, 1, 2, 3
        // a = 2%(4*x + a)
        // a == 2 or  n ==  2*4*x + 3*a  
    }
}