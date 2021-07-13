#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int> > adjList;
int answer = 0;

bool dfs(int idx, vector<bool>& visited) {
    int adjadaptor = 0;
    bool isadaptor = false;
    visited[idx] = true;
    for(int i = 0; i < adjList[idx].size(); i++) {
        int there = adjList[idx][i];
        if(visited[there]) continue;
        if(dfs(there, visited)) {
            isadaptor = true;
        }
        else {
            adjadaptor++;
        }
    }
    if(isadaptor) {
        answer++;
    }
    return (adjadaptor == adjList[idx].size() - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N;
    adjList = vector<vector<int> > (N);
    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin>>a>>b;
        a--;b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<bool> visited(N, false);
    dfs(0, visited);
    cout<<answer<<"\n";
}