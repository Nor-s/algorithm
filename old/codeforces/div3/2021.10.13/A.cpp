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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int maxC;
        int A[3];
        cin >> A[0] >> A[1] >> A[2];
        maxC = max(A[0], max(A[1], A[2]));
        map<int, int> dic;
        for (int i = 0; i < 3; i++)
        {
            dic[A[i]]++;
        }
        int a[3];
        for (int i = 0; i < 3; i++)
        {
            a[i] = maxC - A[i];
            if (a[i] != 0)
            {
                a[i]++;
            }
            else
            {
                if (dic[maxC] > 1)
                {
                    a[i]++;
                }
            }
        }
        cout4(a[0], " ", a[1], " ");
        cout2(a[2], " \n");
    }
}