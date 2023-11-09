#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
// 12 11

using namespace std;
int n;
// 지각 두번, 결석 3번 연속 => 못함
int ATTEND = 0;
int LATE = 1;
int ABSENT = 2;

int cached[1001][2][3];

int dp(int idx, int late, int ab)
{
    if (idx == n)
    {
        return 1;
    }
    int &ret = cached[idx][late][ab];
    if (ret != -1)
    {
        return ret;
    }
    ret = 0;

    ret += dp(idx + 1, late, 0);
    if (late < 1)
    {
        ret += dp(idx + 1, late + 1, 0);
    }
    if (ab < 2)
    {
        ret += dp(idx + 1, late, ab + 1);
    }
    return ret;
}

int main()
{
    cin >> n;
    memset(cached, -1, sizeof cached);
    cout
        << dp(0, 0, 0);
}
