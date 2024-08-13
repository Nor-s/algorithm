#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// 8:00
vector<int> coin;
int N;
int target;

int cached[10001][21];
int dp(int here, int current)
{
    if (current == target)
    {
        return 1;
    }
    if (current > target || here >= N)
    {
        return 0;
    }
    int &ret = cached[current][here];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;
    int size = (target - current) / coin[here] + 1;

    for (int i = 0; i < size; i++)
    {
        ret += dp(here + 1, current + coin[here] * i);
    }
    return ret;
}

int solve()
{
    return dp(0, 0);
}
/*
3
2
1 2
1000
3
1 5 10
100
2
5 7
22
*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(cached, -1, sizeof cached);
        cin >> N;
        coin.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> coin[i];
        }
        cin >> target;
        cout << solve() << "\n";
    }
}