#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
//2 50
using namespace std;

int n;
vector<int> w; // <= 100,000 모두 다름

int solve()
{
    int answer = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        answer = min(answer, w[i] + w[2 * n - 1 - i]);
    }
    return answer;
}

int main()
{
    cin >> n;
    w.resize(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    cout << solve();
}
