#include <bits/stdc++.h>
 
using namespace std;
int N, M, K;
vector<long long> number;
vector<long long> seg;
 
long long init(int lo, int hi, int idx) {
    if(lo + 1 == hi) {
        return seg[idx] = number[lo];
    }
    int mid = (lo + hi) / 2;
    return seg[idx] = (init(lo, mid, idx*2) + init(mid, hi, idx*2 + 1));
}
 
long long update(int lo, int hi, int idx, int ni) {
    if(lo + 1 == hi) {
        return seg[idx] = number[ni];
    }
    int mid = (lo + hi)/2;
    if(ni < mid) {
        return seg[idx] = (update(lo, mid, idx*2, ni) + seg[idx*2 + 1]);
    }
    else {
        return seg[idx] = (update(mid, hi, idx*2 + 1, ni) + seg[idx*2]);
    }
}
long long psum(int lo, int hi, int idx, int start, int end) {
    if(lo == start && hi == end) {
        return seg[idx];
    }
    int mid = (lo + hi) / 2;
    if(end <= mid) {
        return psum(lo, mid, idx*2, start, end);
    }
    else if(mid <= start) {
        return psum(mid, hi, idx*2 + 1, start, end);
    }
    else {
        return (psum(lo, mid, idx*2, start, mid) + psum(mid, hi, idx*2 + 1, mid, end));
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    number = vector<long long>(N);
    seg = vector<long long>(N*5);
    for(int i = 0; i < N; i++) {
        cin>>number[i];
    }
    init(0, N, 1);
    for(int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin>>a>>b>>c;
        if(a == 1) {
            number[b - 1] = c;
            update(0, N, 1, b - 1);
        }
        else {
            cout<<(psum(0, N, 1, b - 1, c))<<"\n";
        }
    }
    
}
