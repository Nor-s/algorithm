#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int V;
const int MAX_V = 100, INF = 1e9;

vector<pair<int, int>> adj[MAX_V];

vector<int> bellmanFord(int src)
{
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;

    for (int iter = 0; iter < V; ++iter)
    {
        updated = false;
        for (int here = 0; here < V; ++here)

            for (int i = 0; i < adj[here].size(); i++)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if (upper[there] > upper[here] + cost)
                {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        if (!updated)
            break;
    }
    if (updated)
        upper.clear();
    return upper;
}
