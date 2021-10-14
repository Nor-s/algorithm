#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

using namespace std;
// 2 37 2 56
// 순간이동 => 2*X
// 점 N, 점 K => -1 or +2
int n, k;

vector<function<int(int)>> funcs = {
    [](int a)
    {
        return a * 2;
    },
    [](int a)
    {
        return a - 1;
    },
    [](int a)
    {
        return a + 1;
    }};

int bfs(int src, int dst)
{
    int maxx = max(dst, src) * 2 + 1;
    vector<int> dist(maxx, 1e9);
    queue<pair<int, int>> q;
    q.push({0, src});
    dist[src] = 0;
    while (!q.empty())
    {
        auto [sec, x] = q.front();
        q.pop();
        for (auto &func : funcs)
        {
            int xx = func(x);
            int nsec = sec + 1;
            if (xx >= 0 && xx < maxx)
            {
                if (dist[xx] == 1e9)
                {
                    dist[xx] = nsec;
                    q.push({nsec, xx});
                }
            }
        }
    }
    return dist[dst];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k);
}