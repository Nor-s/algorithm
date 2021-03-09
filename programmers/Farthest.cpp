#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

vector<vector<int> > adj;

int bfs(int src)
{
    int farthest = -1, count = 0;
    vector<int> distance(adj.size(), -1);
    queue<int> q;
    q.push(src);
    distance[src] = 0;
    while(!q.empty())
    {
        int here = q.front(); q.pop();
        int dist = distance[here];
        for(int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i];
            int nextDist = dist + 1;
            if(distance[there] == -1)
            {
                if(farthest < nextDist)
                {
                    farthest = nextDist;
                    count = 1;
                }
                else if(farthest == nextDist)
                    count++;
                    
                q.push(there);
                distance[there] = nextDist;
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int> > edge) {
    int answer = 0;
    adj = vector<vector<int> > (n+1);
    for(int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    return bfs(1);
}

int main()
{
    int n, m;
    cin>>n;
    cin>>m;
    vector<vector<int> > edge;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        vector<int> tmp = {a, b};
        edge.push_back(tmp);
    }
    cout<<solution(n, edge)<<"\n";
}