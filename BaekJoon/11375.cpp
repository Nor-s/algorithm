#include <bits/stdc++.h>
//11:55

using namespace std;
int N;
int M;
vector<vector<int> > workList;

bool dfs(int idx, vector<int>& person, vector<int>& work, vector<bool>& visited) {
    if(visited[idx]) {
        return false;
    }
    visited[idx] = true;
    for(int i = 0; i < workList[idx].size(); i++) {
        int worknum = workList[idx][i];
        if(work[worknum] == -1|| dfs(work[worknum], person, work, visited)) {
            person[idx] = worknum;
            work[worknum] = idx;
            return true;
        }
    }
    return false;
}

void solve() {
    vector<int> person(N, -1);
    vector<int> work(M , -1);
    int answer = 0;
    for(int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        if(dfs(i, person, work, visited)) {
            answer++;
        }
    }
    cout<<answer;
}

int main() {
    cin>>N>>M;
    workList = vector<vector<int> >(N);
    for(int i = 0; i < N; i++) {
        int c;
        cin>>c;
        for(int j = 0; j < c; j++) {
            int w;
            cin>>w;
            workList[i].push_back(w-1);
        }
    }
    solve();
}