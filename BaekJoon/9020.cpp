// start : 2022-02-11 15:30:52
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
#include <cmath>
#define MAX_V 1e4 + 1
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> isPrime;
    isPrime.resize(MAX_V, 1);
    isPrime[0] = isPrime[1] = 0;
    int size = sqrt(MAX_V);
    for (int i = 2; i < size; i++)
    {
        for (int j = i * 2; j < MAX_V; j += i)
        {
            isPrime[j] = 0;
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int a;
        cin >> a;
        int size = a / 2, ans = 0;
        for (int i = 2; i <= size; ++i)
        {
            if (isPrime[i] && isPrime[a - i])
            {
                ans = i;
            }
        }

        cout << ans << " " << a - ans << "\n";
    }
}