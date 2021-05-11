#include <iostream>
#include <vector>

using namespace std;


void dfs(int here, vector<int>& a, vector<bool>& visited) {
    if(visited[here]) return;
    visited[here] = true;
    dfs(a[here], a, visited);
}
void dfsAll(vector<int>& a) {
    int count = 0;
    vector<bool> visited(a.size(), false);
    for(int i = 0; i < a.size(); i++) {
        if(!visited[i]) {
           dfs(i, a, visited);
           count++;
        }
    }
    cout<<((count == 1)? 0 : count) <<"\n";
}

int main() {
    vector<int> a;
    int n = 0;
    cin>>n;
    for(int i = 0; i < n ; i++) {
        int tmp = 0;
        cin>>tmp;
        a.push_back(tmp);
    }
    dfsAll(a);
}