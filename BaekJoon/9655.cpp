#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define IS_9657

int cached[2][1001];
int dp(int n, int state)
{
    if (n <= 0)
    {
        // loss == state;
        return -1;
    }
    int &ret = cached[state][n];
    if (ret == -100)
    {
        ret = -dp(n - 1, (state + 1) % 2);
        if (n >= 3)
        {
            ret = max(ret, -dp(n - 3, (state + 1) % 2));
        }
#ifdef IS_9657
        if (n >= 4)
        {
            ret = max(ret, -dp(n - 4, (state + 1) % 2));
        }
#endif
    }
    return ret;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++)
    {
        fill(&cached[i][0], &cached[i][0] + 1001, -100);
    }
    if (dp(n, 0) == 1)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }
}
