#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>

#define MAX 20000001

using namespace std;

vector<vector<int> > adj;
int N;

int cache[1<<16][16];
int solve(int visited, int idx) {
    int& ret = cache[visited][idx];
    if(visited == ((1<<N) -1)) {
        if(adj[idx][0] == 0) {
            return MAX;
        }
        return adj[idx][0];
    }
    if(ret != -1) {
        return ret;
    }
    ret = MAX;
    for(int i = 0; i < adj[idx].size(); i++) {
        if(adj[idx][i] == 0 || ((visited & (1<<i)) == (1<<i))) {
            continue;
        }
        ret = min(ret, solve(visited | 1<<i, i) + adj[idx][i]);
    }
    return ret;
}

int main() {
    cin>>N;
    memset(cache, -1, sizeof cache);
    adj = vector<vector<int> >(N, vector<int>(N,0));
    // i -> j
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin>>adj[i][j];
        }
    }
    cout<<solve(1, 0);
}