#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// 8 34
// vip => 자리못옮기는 회원
// 1 ~ N 다 팔림.
vector<int> seat;
int ds[3] = {1, 0, -1};
int cached[101][3];

int state(int idx)
{
    if (seat[idx] != 0 && idx - 1 >= 1 && seat[idx - 1] != 0)
    {
        return 0;
    }
    if (idx - 1 >= 1 && seat[idx - 1] == 0)
    {
        return 1;
    }
    if (seat[idx] == 0)
    {
        return 2;
    }
    return -1;
}

int dp(int idx)
{
    if (idx == seat.size())
    {
        return 1;
    }
    if (seat[idx] == 1e9)
    {
        return dp(idx + 1);
    }
    int &ret = cached[idx][state(idx)];
    if (ret == -1)
    {
        ret = 0;
        for (int i = 0; i < 3; i++)
        {
            int ss = ds[i] + idx;
            if (ss <= 0 || ss >= seat.size() || seat[ss] != 0)
            {
                continue;
            }
            seat[ss] = idx;
            ret += dp(idx + 1);
            seat[ss] = 0;
        }
    }
    return ret;
}

void solve()
{
    cout << dp(1);
}

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    memset(cached, -1, sizeof cached);
    seat.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        seat[a] = 1e9;
    }
    solve();
}