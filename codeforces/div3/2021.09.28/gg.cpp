#include <bits/stdc++.h>

using namespace std;

vector<int> A;
int dp[10002][2001];

int solve(int idx, int left)
{
    if (left >= 2001)
        return left;

    int &ret = dp[idx][left];
    if (ret > 0)
        return ret;
    if (idx == A.size())
        return ret = left;

    ret = solve(idx + 1, left + A[idx]);
    if (left >= A[idx])
        ret = min(ret, max(left, solve(idx + 1, left - A[idx])));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        A.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int ret = INT_MAX;
        for (int i = 0; i <= A.size(); i++)
            memset(dp[i], -1, sizeof(dp[i]));

        for (int b = 0; b <= 2000; b++)
        {
            ret = min(ret, solve(0, b));
        }

        cout << ret << "\n";
    }
    return 0;
}