#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, Q;
vector<long long> number;
vector<long long> segtree;


long long initial(int lo, int hi, int idx) {
    if(lo + 1 == hi) {
        segtree[idx] = number[lo];
        return segtree[idx];
    }
    int mid = (lo + hi)/2;
    segtree[idx] = initial(lo, mid, idx*2) + initial(mid, hi, idx*2 + 1);
    return segtree[idx];
}

void change(int ni, int x, int lo, int hi, int idx) {
    int mid = (lo + hi)/ 2;
    segtree[idx] += (x -number[ni]);
    if(lo + 1 == hi) {
        return;
    }
    if(ni < mid) {
        return change(ni , x, lo, mid, idx*2);
    }
    else {
        return change(ni , x, mid, hi, idx*2 + 1);
    }
}

long long find(int start, int end, int idx, int lo, int hi) {
    if(start == lo && end == hi ) {
        return segtree[idx];
    }
    int mid = (lo + hi)/2;
    if(end <= mid) {
        return find(start, end, idx*2, lo, mid);
    }
    else if(mid <= start) {
        return find(start, end, idx*2 + 1, mid, hi);
    }
    else {
        return find(start, mid, idx*2, lo, mid) + find(mid, end, idx*2+1, mid, hi);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>Q;
    number = vector<long long>(N);
    segtree = vector<long long>(N*4);
    for(int i = 0; i < N; i++) {
        cin>>number[i];
    }
    initial(0, N, 1);
    for(int i = 0; i < Q; i++) {
        int lo, hi, ni;
        long long x;
        cin>>lo>>hi>>ni>>x;
        if(lo > hi) {
            swap(lo, hi);
        }
        cout<<find(lo - 1, hi, 1, 0, N)<<"\n"; 
        change(ni - 1, x, 0, N, 1);
        number[ni-1] = x;
    }
}