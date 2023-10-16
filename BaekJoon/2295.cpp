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

using namespace std;

int n;
vector<int> v;

vector<int> sumab;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);
    sumab.reserve(n * n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumab.push_back(v[i] + v[j]);
        }
    }
    sort(sumab.begin(), sumab.end());

    int maxValue = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int findValue = v[j] - v[i];
            auto value = lower_bound(sumab.begin(), sumab.end(), findValue) - sumab.begin();
            if (value < sumab.size() && sumab[value] == findValue)
            {
                maxValue = max(maxValue, v[j]);
            }
        }
    }
    cout << maxValue;
}