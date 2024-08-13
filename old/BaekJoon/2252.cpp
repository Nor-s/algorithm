#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
vector<vector<int> > adjList;
vector<bool> small;
vector<int> stack1;

void printStack() {
    for(int i = stack1.size()-1; i >= 0; i--) {
        cout<<stack1[i]+1<<" ";
    }
}

void dfs(int idx, vector<bool>& visited) {
    visited[idx] = true;

    for(int i = 0; i < adjList[idx].size(); i++) {
        if(!visited[adjList[idx][i]]) {
            dfs(adjList[idx][i], visited);
        }
    }
    stack1.push_back(idx);
}

void dfsAll() {
    vector<bool> visited(N, false);
    for(int i = 0; i < N; i++) {
        if(!visited[i] && !small[i]) {
            dfs(i, visited);
        }
    }
    printStack();
}

int main() {
    cin>>N>>M;
    adjList = vector<vector<int> > (N);
    small = vector<bool> (N, false);
    for(int i = 0; i < M; i++){
        int t1, t2;
        cin>>t1>>t2;
        adjList[t1-1].push_back(t2-1);
        small[t2-1] = true;
    }
    dfsAll();
}