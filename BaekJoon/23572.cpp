#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N, K;
vector<int> graph[100'001];
int camera = 0;

int dfs(int here, int root)
{
    int maxdepth = INT32_MIN;
    int mindepth = INT32_MAX;
    for (int i = 0; i < graph[here].size(); i++)
    {
        if (root != graph[here][i])
        {
            int sub = dfs(graph[here][i], here);
            if (sub >= 0)
            {
                maxdepth = max(sub, maxdepth);
            }
            if (sub < 0)
            {
                mindepth = min(sub, mindepth);
            }
        }
    }
    if (maxdepth == INT32_MIN && mindepth == INT32_MAX)
    {
        return 1;
    }
    else if (maxdepth == INT32_MIN)
    {
        return mindepth + 1;
    }
    else if (maxdepth == K)
    {
        camera++;
        return -K;
    }
    else if (mindepth != INT32_MAX && maxdepth < abs(mindepth))
    {
        return mindepth + 1;
    }
    else
    {
        return maxdepth + 1;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int tmp = dfs(0, -1);
    if (tmp > 0)
    {
        camera++;
    }
    cout << camera;
}