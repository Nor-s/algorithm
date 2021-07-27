#include <bits/stdc++.h>

using namespace std;
int n, m;

struct uf{
    vector<int> parent;
    vector<int> rank;
    uf(int n) : parent(n), rank(n) {
        for(int i = 0 ; i < n; i ++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int u) {
        int ret = u;
        while(parent[ret] != ret) {
            int v = parent[ret];
            parent[ret] = parent[v];
            ret = v;
        }
        return ret;
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n >>m;
    uf s(n + 1);
    for(int i = 0; i < m; i++) {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        if(t1 == 0) {
            s.merge(t2, t3);
        }
        else {
            if(s.find(t2) == s.find(t3)) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
}