#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet
{
    vector<int> father, rank;
    DisjointSet(int V) : father(V, 0), rank(V, 1)
    {
        for (int i = 0; i < V; i++)
            father[i] = i;
    }
    int find(int u)
    {
        if (father[u] == u)
            return u;
        return father[u] = find(father[u]);
    }
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] > rank[v])
            swap(u, v);
        father[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
    }
};

const int MAX_V = 100;
int V;
vector<pair<int, int>> adj[MAX_V];

int kruskal(vector<pair<int, int>> &selected)
{
    int ret = 0;
    selected.clear();
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < V; ++u)
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    sort(edges.begin(), edges.end());
    DisjointSet sets(V);
    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if (sets.find(u) == sets.find(v))
            continue;
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}
