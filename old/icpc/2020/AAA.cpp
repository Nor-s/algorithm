#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

vector<int> balls;
vector<pair<int, int>> sorted_balls;

int cached[100001];

int dp(int idx)
{
    if (idx == sorted_balls.size())
    {
        return 0;
    }
    int &ret = cached[idx];
    if (ret != -1)
    {
        return ret;
    }
    else
    {
        ret = 1;
        for (int i = idx + 1; i < sorted_balls.size(); i++)
        {
            if (sorted_balls[i].second > sorted_balls[idx].second)
            {
                ret = max(ret, dp(i) + 1);
            }
            else if (sorted_balls[i].first != sorted_balls[idx].first)
            {
                int tmp = sorted_balls[i].second;
                while (i + 1 < sorted_balls.size() && sorted_balls[i].first == sorted_balls[i + 1].first && sorted_balls[idx].second > sorted_balls[i].second)
                {
                    i++;
                }
                if (tmp != sorted_balls[i].second)
                {
                    i--;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return ret;
}

int solve()
{
    int answer = balls.size();

    for (int i = 0; i < sorted_balls.size(); i++)
    {
        int order = sorted_balls[i].second;
        int length = dp(order);
        answer = min(answer, static_cast<int>(balls.size()) - length);
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    balls.resize(n);
    sorted_balls.resize(n);
    memset(cached, -1, sizeof cached);
    for (int i = 0; i < n; i++)
    {
        cin >> balls[i];
        sorted_balls[i] = {balls[i], i};
    }
    sort(sorted_balls.begin(), sorted_balls.end());
    cout << solve();
}