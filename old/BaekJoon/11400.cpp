#include <iostream>
#include <set>
#include <vector>

using namespace std;
int V, E;
vector<vector<int> > adjList;
set<pair<int, int> > answer;

int dfs(int here, int parent, vector<int>& discovered, int& visitedNum) {
    int ret = discovered[here] = visitedNum++;

    for(int i = 0; i < adjList[here].size(); i++) {
        int there = adjList[here][i];
        int subTree = discovered[there];
        if(parent == there) continue;
        if(subTree == -1) {
            subTree = dfs(there, here, discovered, visitedNum);
            if(subTree > discovered[here]) {
                int a = here, b = there;
                if(a > b) {
                    swap(a, b);
                }
                answer.insert({a, b});
            }
        }
        ret = min(ret, subTree);
    }
    return ret;
}

void dfsAll() {
    vector<int> discovered(V + 1, -1);
    int visitedNum = 0;
    for(int i = 0; i < V; i++) {
        if(discovered[i+1] == -1) {
            dfs(i+1, 0, discovered, visitedNum);
        }
    }
    cout<<answer.size()<<"\n";
    for(auto item : answer) {
        cout<<item.first<< " "<<item.second<<"\n";
    }
}
//a < b
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