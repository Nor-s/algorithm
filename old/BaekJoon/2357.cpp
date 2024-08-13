#include <bits/stdc++.h>

using namespace std;
vector<int> number;
vector<pair<int, int> > segTree;

pair<int, int> init(int lo, int hi, int idx){
    if(lo + 1 == hi) {
        return segTree[idx] = {number[lo], number[lo]};
    }
    int mid = (lo + hi) / 2;
    pair<int, int> left = init(lo, mid, idx * 2);
    pair<int, int> right = init(mid, hi, idx * 2 + 1);
    int minimum = min(left.first, right.first);
    int maximum = max(left.second, right.second);
    segTree[idx] = {minimum, maximum};
    return segTree[idx];
}

pair<int, int> query(int lo, int hi, int idx, int start, int end) {
    if(lo >= start && end >= hi) {
        return segTree[idx];
    }
    int mid = (lo + hi) / 2;
    if(end <= mid) {
        return query(lo, mid, idx*2, start, end);
    }
    else if(mid <= start) {
        return query(mid, hi, idx*2 + 1, start, end);
    }
    else {
        pair<int, int> left = query(lo, mid, idx * 2, start, mid);
        pair<int, int> right = query(mid, hi, idx * 2 + 1, mid, end);
        int minimum = min(left.first, right.first);
        int maximum = max(left.second, right.second);
        return {minimum, maximum};
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin>>N>>M;
    number = vector<int>(N);
    segTree = vector<pair<int, int> >(N*4);
    for(int i = 0; i < N; i++) {
        cin>>number[i];
    }
    init(0, N, 1);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin>>a>>b;
        if(a > b) {
            swap(a, b);
        }
        pair<int, int> answer = query(0, N, 1, a - 1, b);
        cout<<answer.first<<" "<<answer.second<<"\n";
    }

}
