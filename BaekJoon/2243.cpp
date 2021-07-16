#include <bits/stdc++.h>

using namespace std;
const int flavorMax = 1000001;
//1~1,000,000
// 1~1000,000 /  #
vector<int> seg;

int update(int lo, int hi, int idx, int b, int c) {
    if(lo + 1 == hi) {
        seg[idx] += c;
        return seg[idx];
    }
    int mid = (lo + hi)/2;
    if(b < mid) {
        return seg[idx] = update(lo, mid, idx*2, b, c) + seg[idx*2 + 1];
    }
    else {
        return seg[idx] = update(mid, hi, idx*2 + 1, b, c) + seg[idx*2];
    }
}

int findCandy(int lo, int hi, int idx, int rank) {
    if(lo + 1 == hi) {
        return lo;
    }
    int mid = (lo + hi)/2;
    int left = seg[idx*2];
    if(left < rank) {
        return findCandy(mid, hi, idx*2 + 1, rank - left);
    }
    else {
        return findCandy(lo, mid, idx*2, rank);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    seg = vector<int>(flavorMax*4 + 1, 0);
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin>>a;
        //pop - b rank => cout
        if(a == 1) {
            cin>>b;
            int candy = findCandy(0, flavorMax, 1, b);
            update(0, flavorMax, 1, candy, -1);
            cout<<candy<<"\n";
        }
        //push b - flavor , c - #, c > 0 => push ,  c < 0 => pop
        else {
            cin>>b>>c;
            update(0, flavorMax, 1, b, c);
        }
    }
}