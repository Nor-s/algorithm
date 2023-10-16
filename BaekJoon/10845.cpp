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
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'p')
        {
            if (s[1] == 'o')
            {
                if (q.empty())
                {
                    cout << -1 << "\n";
                }
                else
                {
                    cout << q.front() << "\n";
                    q.pop();
                }
            }
            else
            {
                int a;
                cin >> a;
                q.push(a);
            }
        }
        else if (s[0] == 's')
        {
            cout << q.size() << "\n";
        }
        else if (s[0] == 'e')
        {
            cout << (int)q.empty() << "\n";
        }
        else if (q.empty())
        {
            cout << -1 << "\n";
        }
        else if (s[0] == 'f')
        {
            cout << q.front() << "\n";
        }
        else if (s[0] == 'b')
        {
            cout << q.back() << "\n";
        }
    }
}