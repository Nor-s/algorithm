#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int MAX_V = 10, INF = 1e9;
int v;
vector<pair<int, int>> adj[MAX_V];
vector<int> dijkstra(int src)
{
    vector<int> dist(v, INFINITY);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int V;
vector<pair<int, int>> adj[MAX_V];
vector<int> dijkstra2(int src)
{
    vector<bool> visited(V, false);
    vector<int> dist(V, INF);
    dist[src] = 0;
    visited[src] = false;

    while (true)
    {
        int closest = INF, here;
        for (int i = 0; i < V; i++)
            if (dist[i] < closest && !visited[i])
            {
                here = i;
                closest = dist[i];
            }

        if (closest == INF)
            break;
        visited[here] = true;
        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            if (visited[there])
                continue;
            int nextDist = dist[here] + adj[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}