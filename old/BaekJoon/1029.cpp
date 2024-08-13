#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[1<<16][10][16];
int bf(vector<vector<int>>& adj, int visited, int price, int idx) {
    int& ret = cache[visited][price][idx];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int j = 0; j < (int)adj[idx].size(); j++) {
        if(adj[idx][j] < price || (visited &(1<<j))) continue;
        visited |= (1<<j);
        ret = max(ret, bf(adj, visited, adj[idx][j], j) + 1);
        visited &= ~(1<<j);
    }
    return ret;
}

int main() {
    int n = 0;
    cin>>n;
    vector<vector<int> > adj(n, vector<int>(n, 0));
    memset(cache, -1, sizeof cache);

    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < n; j++) {
            adj[i][j] = (int)s[j]-'0';
        }
    }

    cout<<bf(adj, (1<<15)|1 , 0, 0)+1;
}