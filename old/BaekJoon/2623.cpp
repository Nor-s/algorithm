#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<bool> > adjlist;
vector<bool> visited;
vector<int> s;


bool dfs(const int& x) {
    visited[x] = true;
    for(int i = 0 ; i < adjlist[x].size(); i++) {
        if(adjlist[x][i] == false) continue;
        if(visited[i]) {
            auto iter = find(s.begin(), s.end(), i);
            if(iter == s.end())  return false;
        }
        else {
            if(!dfs(i)) return false;
        }
    }
    s.push_back(x);
    return true;
}
void dfsAll(int N) {
    visited = vector<bool>(N, false);
    for(int i = 0 ; i < N; i++) {
        if(!visited[i]) {
            if(!dfs(i)) {
                cout<<0;
                return;
            }
        }
    }
    for(int i = N-1; i >= 0; i--) {
        cout<<s[i]+ 1<<"\n";
    }
}

int main() {
    int N, M;
    cin>>N>>M;
    adjlist = vector<vector<bool> > (N, vector<bool>(N, false));
    for(int i = 0; i < M; i++) {
        int t;
        cin>>t;
        int a, b;
        for(int j = 0; j < t; j++) {
            cin>>a;
            a--;
            if(j != 0) {
                adjlist[b][a] = true;
            }
            b = a;
        }
    }
    dfsAll(N);
}
