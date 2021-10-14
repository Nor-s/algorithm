#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e

using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
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
        int n;
        cin >> n;
        map<int, int> dic;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            dic[a]++;
        }
        if (dic.size() >= 2)
        {
            auto before = dic.begin();
            int min1 = before->first;
            int min2 = next(dic.begin(), 1)->first;
            int answer = abs(min1 - min2);
            for (auto it = next(dic.begin(), 2); it != dic.end(); it++)
            {
                int b = abs(it->first - min1);
                answer = gcd(answer, b);
            }
            if ()
                cout << answer << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}