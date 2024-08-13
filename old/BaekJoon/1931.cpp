#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<uint32_t, uint32_t>> a(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    int answer = 1;
    auto before = a[0];
    for (int i = 1; i < N; i++)
    {
        if (before.first <= a[i].second)
        {
            answer++;
            before = a[i];
        }
    }
    cout << answer << "\n";
}