#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int A[4000], B[4000], C[4000], D[4000];
vector<int> CD;

void solve() {
    long long answer = 0;
    std::vector<int>::iterator lo, hi;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            lo = lower_bound(CD.begin(), CD.end(), -A[i] - B[j]);
            if(CD[lo-CD.begin()] != -A[i] -B[j]) continue;
            hi = upper_bound(CD.begin(), CD.end(), -A[i] - B[j]);
            answer += (hi - lo);
        }
    }
    cout<<answer<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        D[i] = d;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            CD.push_back(C[i] + D[j]);
        }
    }
    sort(CD.begin(), CD.end());
    solve();
}