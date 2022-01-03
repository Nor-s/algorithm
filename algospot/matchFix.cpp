#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 987654321;
int V, n, m, totalCount, xmatch;

vector<vector<int> > capacity;
vector<int> currentWin;
vector<pair<int, int> > match;
vector<vector<int> > flow;


int networkFlow(int src, int sink)
{
    while(true)
    {
        queue<int> q;
        vector<int> parent = vector<int>(V, -1);
        parent[src] = src;
        q.push(src);
        while(!q.empty() && parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            for(int there = 0; there < V; there++)
            {
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1) break;
        int cost = INF;
        for(int i = sink; i != src; i = parent[i])
            cost = min(cost, capacity[parent[i]][i] - flow[parent[i]][i]);
        for(int i = sink; i != src; i = parent[i])
        {
            flow[i][parent[i]] -= cost;
            flow[parent[i]][i] += cost;
        }
        totalCount += cost;
    }
    return totalCount;
}


bool isCanWin(int w)
{
    for(int i = 0 ; i < n ; i++){
        capacity[i + m + 2][1] = ((i == 0 ? w: w-1) - currentWin[i]);
        if(capacity[i+m+2][1] < 0) return false;
    }
    return (networkFlow(0, 1) == m);
}


int solve()
{
    int ret = -1;
    capacity = vector<vector<int> > (V , vector<int>(V, 0));
    flow = vector<vector<int> >(V, vector<int>(V, 0));

    for(int i = 0; i < m ; i++)
    {
        capacity[0][i+2] = 1;
        capacity[i+2][m + 2 + match[i].first] = 1;
        capacity[i+2][m + 2 + match[i].second] = 1;
    }

    for(int i = currentWin[0]; i <= currentWin[0] + xmatch ; i++)
        if(isCanWin(i)&&flow[m+2][1] + currentWin[0] == i)
            return i;
    return ret;
}


int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        cin>>n>>m;
        currentWin = vector<int>(n, 0);
        match = vector<pair<int, int> > (m);
        xmatch = 0;
        totalCount = 0;
        V = n + m + 2;
        for(int i = 0; i < n; i++)
            cin>>currentWin[i];
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin>>a>>b;
            match[i] = make_pair(a, b);
            if(a == 0 || b == 0)
                xmatch++;
        }
        cout<<solve()<<"\n";
    }
}