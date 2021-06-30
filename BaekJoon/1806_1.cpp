#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N, S;
vector<int> s;
vector<int> ssum;

void init() {
    ssum[0] = s[0];
    for(int i = 1; i < N; i++) {
        ssum[i] = ssum[i-1] +  s[i];
    }
}

void solve() {
    if(ssum.back() < S) {
        cout<<0;
        return;
    }
    int m = INT32_MAX;
    for(int i = N-1; i >= 0 ; i--) {
        if(ssum[i] < S) break;
        auto it = upper_bound(ssum.begin(), ssum.end(), ssum[i] - S);
        it--;
        m = min(i - (int)(it - ssum.begin()), m);
    }
    cout<<m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N>>S;
    s = vector<int>(N);
    ssum = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin>>s[i];
    }
    init();
    solve();
}