#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> segments;


int totalLen() {
    vector<pii> pq;
    int ret = 0;

    for(int i = 0; i < segments.size(); i++) {
        int lo = segments[i].second;
        int hi = segments[i].first;
        while(!pq.empty() && pq.back().second >= lo ) {
            if(lo > pq.back().first) {
                lo = pq.back().first;
            }
            ret -= (pq.back().second - pq.back().first);
            pq.pop_back();
        }
        ret += (hi - lo);
        pq.push_back({lo, hi});
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin>>a>>b;
        segments.push_back({b, a});
    }
    sort(segments.begin(), segments.end());
    cout<<totalLen();
}