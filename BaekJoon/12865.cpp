#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<pair<int, int> > knapsack;
int N, K;

int cache[100000][100];
int answer = 0;
int dp(int currentk, int idx) {
    if(idx == N) {
        return 0;
    }
    int &ret = cache[currentk][idx];
    int w = currentk + knapsack[idx].first;
    if(ret != -1) {
        return ret;
    }
    ret = 0;

    if(w <= K) {
        ret = dp(w, idx + 1) + knapsack[idx].second;
    }
    return ret = max(ret, dp(currentk, idx + 1));
}

int main() {
    cin>>N>>K;
    memset(cache, -1, sizeof cache);

    for(int i = 0; i < N; i++) {
        int a, b; 
        cin>>a>>b;
        knapsack.push_back(make_pair(a, b));
    }
    cout<<dp(0, 0);
}