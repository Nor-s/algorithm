#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

// 1 != 2
// N != N-1
// i != i-1 , i !=  i +1

int house[1004][4];

int cached[1004][4];
int n;
int dp(int idx, int before)
{
    if (idx == n)
    {
        return 0;
    }
    int &ret = cached[idx][before];
    if (ret == -1)
    {
        ret = 1e9;
        for (int i = 0; i < 3; i++)
        {
            if (before == i)
                continue;
            ret = min(ret, dp(idx + 1, i) + house[idx + 1][i]);
        }
    }
    return ret;
}
int dp2()
{
    cached[1][0] = house[1][0];
    cached[1][1] = house[1][1];
    cached[1][2] = house[1][2];
    for (int i = 2; i <= n; i++)
    {
        cached[i][0] = min(cached[i - 1][1], cached[i - 1][2]) + house[i][0];
        cached[i][1] = min(cached[i - 1][0], cached[i - 1][2]) + house[i][1];
        cached[i][2] = min(cached[i - 1][0], cached[i - 1][1]) + house[i][2];
    }
    return min(cached[n][0], min(cached[n][1], cached[n][2]));
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }
    // memset(cached, -1, sizeof cached);
    cout << dp2();
}