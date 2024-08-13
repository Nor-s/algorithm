#include <bits/stdc++.h>

using namespace std;
int V, E;
vector<vector<int> > adjList;
set<int> answer;

int dfs(int here, vector<int>& visited, int& visitedNum, bool isRoot) {
    visited[here] = ++visitedNum;
    int ret = visited[here], child = 0;

    for(int i = 0; i < adjList[here].size(); i++) {
        int there = adjList[here][i];
        if(visited[there] == -1) {
            child++;
            int subtree =  dfs(there, visited, visitedNum, false);
            if(!isRoot && subtree >= visited[here]) {
                answer.insert(here);
            }
            ret = min(ret, subtree);
        }
        else {
            ret = min(ret, visited[there]);
        }
    }
    if(isRoot && child > 1) {
        answer.insert(here);
    }
    return ret;
}

void dfsAll() {
    vector<int> visited(V+1, -1);
    int visitedNum = 0;
    for(int i = 0; i < V; i++) {
        if(visited[i+1] != -1) continue;
        dfs(i+1, visited, visitedNum, true);
    }
    cout<<answer.size()<<"\n";
    for(auto item : answer) {
        cout<<item<<" ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>V>>E;
    adjList = vector<vector<int> > (V + 1);
    for(int i = 0; i < E; i++) {
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfsAll();
}