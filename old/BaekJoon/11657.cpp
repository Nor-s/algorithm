#include <iostream>
#include <vector>
#include <utility>
#define MAX_V 500
#define INF INT64_MAX
using namespace std;
int V;

vector<pair<int, int>> adj[MAX_V];

vector<long long> bellmanFord(int src)
{
    vector<long long> upper(V, INF);
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
                if (upper[here] == INF)
                {
                    continue;
                }
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

int main()
{
    int M;
    int A, B, C;
    cin >> V >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        A--;
        B--;
        adj[A].push_back({B, C});
    }
    vector<long long> upper = bellmanFord(0);
    if (upper.size() == 0)
    {
        cout << "-1";
    }
    else
    {
        for (int i = 1; i < upper.size(); i++)
        {
            if (upper[i] >= INF - 2e9 * 100)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << upper[i] << "\n";
            }
        }
    }
}