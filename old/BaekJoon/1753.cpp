#include <bits/stdc++.h>

using namespace std;
int V, E;
int src;

vector<pair<int, int> > adjList[20000];

void dijk(int s) {
    vector<int> ret(V, INT32_MAX);
    priority_queue<pair<int, int> > pq; 
    pq.push({0, s});
    ret[s] = 0;

    while(!pq.empty()) {
        int here = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if(ret[here] < dist) {
            continue;
        }
        for(int i = 0; i < (int)adjList[here].size(); i++) {
            int there = adjList[here][i].second;
            int nextdist = adjList[here][i].first + dist;
            if(ret[there] > nextdist) {
                ret[there] = nextdist;
                pq.push({-(nextdist), there});
            }
        }
    }
    for(int i = 0; i < V; i++) {
        if(ret[i] != INT32_MAX) {
            cout<<ret[i]<<"\n"; 
        }
        else {
            cout<<"INF\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>V>>E;
    cin>>src;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        adjList[a-1].push_back({c, b-1});
    }
    dijk(src-1);
}