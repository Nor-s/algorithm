#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N, S;
vector<int> s;

void solve() {
    int idx = 0;
    int m = INT32_MAX;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += s[i];
        while(idx <= i && S <= sum) {
            m = min(m, i - idx + 1);
            sum -= s[idx];
            idx++;
        }
    }
    if(m == INT32_MAX) {
        cout<<0;
    }
    else {
        cout<<m;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N>>S;
    s = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin>>s[i];
    }
    solve();
}