#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n, k;
map<int, int> c;

const int INF = 1e9 + 1;
int cached[2][10001];
int dp()
{
    int cur = 0;
    int nxt = 1;
    fill(&cached[cur][0], &cached[cur][0] + 10001, INF);
    cached[cur][0] = 0;
    for (auto it = c.begin(); it != c.end(); it++)
    {
        fill(&cached[nxt][0], &cached[nxt][0] + 10001, INF);
        int coin = it->second;
        for (int j = 0; j <= k; j++)
        {
            int i = -1;
            while (true)
            {
                i++;
                if (j + i * coin > k)
                {
                    break;
                }
                if (cached[cur][j] == INF)
                {
                    continue;
                }
                cached[nxt][j + i * coin] = min(cached[nxt][j + i * coin], i + cached[cur][j]);
            }
        }
        cur = (cur + 1) % 2;
        nxt = (nxt + 1) % 2;
    }
    return cached[cur][k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        c[-d] = d;
    }
    int answer = dp();
    if (answer == INF)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}