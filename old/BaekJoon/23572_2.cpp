#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

vector<set<int>> adjList;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    adjList.clear();
    adjList.resize(n);
    queue<pair<int, int>> q;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].insert(b);
        adjList[b].insert(a);
    }
    // min max
    vector<pair<int, int>> dp(n, {INT32_MAX, INT32_MIN});
    // 잎들
    for (int i = 0; i < n; i++)
    {
        if (adjList[i].size() <= 1)
        {
            q.push({0, i});
        }
    }
    int answer = 0;
    while (!q.empty())
    {
        auto [d, here] = q.front();
        q.pop();
        if (adjList[here].size() == 0)
        {
            if (d >= 0 && q.empty())
                answer++;
            continue;
        }

        int next = *adjList[here].begin();

        adjList[next].erase(here);
        dp[next].first = min(dp[next].first, d + 1);
        dp[next].second = max(dp[next].second, d + 1);

        if (adjList[next].size() <= 1)
        {
            int mindepth = dp[next].first;
            int maxdepth = dp[next].second;
            int depth;
            if (maxdepth < abs(mindepth))
            {
                depth = mindepth;
            }
            else if (adjList[next].size() != 0 && maxdepth == k)
            {
                depth = -(k + 1);
                answer++;
            }
            else
                depth = maxdepth;
            dp[next] = {depth, depth};

            q.push({depth, next});
        }
    }
    cout << answer;
}