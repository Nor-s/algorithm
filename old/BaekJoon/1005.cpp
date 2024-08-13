#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
vector<int> D;
vector<int> cost;
vector<vector<int> > order;

int sol(int here) {
    int &m = cost[here];
    if(m != -1) {
        return m;
    }
    m = 0;

    for(int i = 0; i < order[here].size(); i++) {
        int there = order[here][i];
        m = max(m, sol(there) + D[there]);
    }
    return m;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N, K, W;
        cin>>N>>K;
        D = vector<int>(N);
        cost = vector<int>(N, -1);
        order = vector<vector<int> >(N);
        for(int i = 0; i < N; i++) {
            cin>>D[i];
        }
        //a -> b
        for(int j = 0; j < K; j++) {
            int a, b;
            cin>>a>>b;
            order[b-1].push_back(a-1);
        }
        cin>>W;
        cout<<sol(W-1) + D[W-1]<<"\n";
    }
}