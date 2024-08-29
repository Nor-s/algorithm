#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// position remain w remain h
long long cached[51][51];
int N;
long long dp(int pos, int w, int h)
{
    if (pos == N * 2)
    {
        return 1;
    }

    long long &ret = cached[w][h];

    if (ret != -1)
        return ret;

    ret = 0;

    if (h)
        ret += dp(pos + 1, w, h - 1);
    if (w)
        ret += dp(pos + 1, w - 1, h + 1);

    return ret;
}

int main()
{
    for (;;)
    {
        cin >> N;
        if (N == 0)
            break;
        memset(cached, -1, sizeof cached);
        cout << dp(0, N, 0) << "\n";
    }
}