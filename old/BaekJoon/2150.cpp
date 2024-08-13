#include <bits/stdc++.h>

using namespace std;
int V, E;
vector<vector<int> > adjList;
vector<int> discovered;
int visitNum = 0;
vector<vector<int>> scc;
vector<bool> isscc;
int sccNum = 0;
vector<int> st;

int dfs(int here) {
    int ret = discovered[here] = visitNum++;
    int size = adjList[here].size();
    st.push_back(here);
    for(int i = 0; i < size; i++) {
        int there = adjList[here][i];
        if(discovered[there] == -1) {
            ret = min(ret, dfs(there));
        }
        else if(isscc[there] == false) {
            ret = min(ret, discovered[there]);
        }
    }
    if(discovered[here] == ret) {
        scc.push_back(vector<int>());
        while(!st.empty()) {
            int tmp = st.back();
            scc[sccNum].push_back(tmp);
            isscc[tmp] = true;
            st.pop_back();
            if(tmp == here) {
                break;
            }
        }
        sort(scc[sccNum].begin(), scc[sccNum].end());
        sccNum++;
    }

    return ret;
}

void solve() {
    for(int i = 0; i < V; i++) {
        if(discovered[i] == -1) {
            dfs(i);
        }
    }
    cout<<sccNum<<"\n";
    sort(scc.begin(), scc.end(), [](vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    });
    for(int i = 0; i < sccNum; i++) {
        for(int j = 0 ; j < scc[i].size(); j++) {
            cout<<scc[i][j]+1<<" ";
        }
        cout<<"-1\n";
    }
}

int main() {
    cin>>V>>E;
    isscc = vector<bool>(V, false);
    adjList = vector<vector<int> >(V);
    discovered = vector<int>(V, -1);
    for(int i = 0; i < E; i++) {
        int a, b;
        cin>>a>>b;
        adjList[a - 1].push_back(b-1);
    }
    solve();
}