#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int V, E;
vector<vector<pair<int, int> > > adjList;

void MST() {
    vector<int> dist(V, INT32_MAX);
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        int here = q.top().second;
        int cost = -q.top().first;
        q.pop();
        if(dist[here] <= cost)
            continue;
        dist[here] = cost;

        for(int i = 0; i < adjList[here].size(); i++) {
            int there = adjList[here][i].second;
            int cost2 = adjList[here][i].first;
            if(dist[there] == INT32_MAX) {
                q.push(make_pair(-cost2, there));
            }
        }
    }
    cout<<accumulate(dist.begin(), dist.end(), (int)0);
}

int main() {
    cin>>V>>E;
    adjList = vector<vector<pair<int, int> > >(V);
    for(int i = 0; i < E; i++) {
        int tmp1, tmp2, tmp3;
        cin>>tmp1>>tmp2>>tmp3;
        adjList[tmp1-1].push_back(make_pair(tmp3, tmp2-1));
        adjList[tmp2-1].push_back(make_pair(tmp3, tmp1-1));
    }
    MST();
}