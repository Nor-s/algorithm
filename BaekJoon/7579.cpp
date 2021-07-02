#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
using namespace std;
int N, M;
vector<int> C;
vector<int> A;
const int MAX = 10001;

int cache[101][MAX];

int solve(int idx, int cost) {
    if(idx == N) {
        return 0;
    }
    int& ret = cache[idx][cost];
    if(ret != -1) {
        return ret;
    }
    
    ret = solve(idx + 1, cost);
    if(C[idx] <= cost)
        ret = max(ret, solve(idx + 1, cost - C[idx]) + A[idx]);
    return ret;
}

int bsearch() {
    int lo = -1, hi = accumulate(C.begin(), C.end(), (int)0), mid;
    while(lo + 1 != hi) {
        mid = (lo+hi)/2;
        if(solve(0, mid) >= M) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return hi;
}

int main() {
    cin>>N>>M;
    A = C = vector<int>(N);
    memset(cache, -1, sizeof cache);
    
    for(int i = 0; i < N; i++) {
        cin>>A[i];
    }

    for(int i = 0; i < N; i++) {
        cin>>C[i];
    }
    cout<<bsearch();
}