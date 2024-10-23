// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

int N;
int cached[1001][2][3];
int MOD = 1000000;
int solve(int len, int late, int absent)
{
    if (len == N)
        return 1;

    int &ret = cached[len][late][absent];
    if (ret != -1)
        return ret;
    ret = 0;

    if (late == 0)
        ret += solve(len + 1, late + 1, 0) % MOD;

    ret += solve(len + 1, late, 0) % MOD;

    if (absent < 2)
        ret += solve(len + 1, late, absent + 1) % MOD;

    return ret % MOD;
}
int main()
{
    memset(cached, -1, sizeof(cached));
    cin >> N;
    cout << solve(0, 0, 0);
}