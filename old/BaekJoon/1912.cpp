#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int n;
vector<ll> a;
vector<ll> psum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    a.resize(n);
    psum.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        psum[i + 1] = psum[i] + a[i];
    }
    ll minn = 0;
    ll answer = a[0];
    for (int i = 2; i <= n; i++)
    {
        ll sum = psum[i] - minn;
        answer = max(answer, max(sum, a[i - 1]));
        minn = min(psum[i], minn);
    }
    cout << answer;
}