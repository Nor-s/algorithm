#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <queue>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e
#define coutvi(a, b) copy(a, b, ostream_iterator<int>(cout, " "))
#define coutvc(a, b) copy(a, b, ostream_iterator<char>(cout, " "))

using namespace std;

// s -> g h -> 목적지들
// s -> h g -> 목적지들

vector<int> dij(int here, vector<vector<int>> &adj)
{
    vector<int> ret(adj.size(), INT32_MAX / 3);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, here});
    ret[here] = 0;
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (ret[node] < dist)
        {
            continue;
        }
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[node][i] != INT32_MAX / 3)
            {
                int cost = adj[node][i];
                if (cost + dist < ret[i])
                {
                    ret[i] = cost + dist;
                    pq.push({cost + dist, i});
                }
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        s--;
        g--;
        h--;
        vector<vector<int>> adj(n, vector<int>(n, INT32_MAX / 3));
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            a--;
            b--;
            adj[a][b] = d;
            adj[b][a] = d;
        }
        vector<int> target;
        for (int i = 0; i < t; i++)
        {
            int a;
            cin >> a;
            a--;
            target.push_back(a);
        }
        vector<int> S = dij(s, adj);
        vector<int> G = dij(g, adj);
        vector<int> H = dij(h, adj);
        vector<int> ans;
        int cost = INT32_MAX / 3;
        for (int i = 0; i < t; i++)
        {
            int sgh = S[g] + adj[g][h] + H[target[i]];
            int shg = S[h] + adj[h][g] + G[target[i]];
            int distance = min(sgh, shg);
            if (S[target[i]] == distance)
            {
                ans.push_back(target[i] + 1);
            }
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}