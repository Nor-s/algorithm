#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <utility>
#include <map>
#include <cstdint>

using namespace std;

int n;
vector<int> v;
long long answer = 0L;

int main()
{
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int s = v[i] + v[j];
            int l = lower_bound(v.begin() + j + 1, v.end(), -s) - v.begin();
            int u = upper_bound(v.begin() + j + 1, v.end(), -s) - v.begin();

            answer += u - l;
        }
    }
    cout << answer << endl;
}
