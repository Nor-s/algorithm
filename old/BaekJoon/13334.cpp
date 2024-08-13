#include <bits/stdc++.h>

using namespace std;
long long n, d;
vector<pair<long long, long long> > p;

bool comp(pair<long long, long long>& a, pair<long long, long long> &b) {
    if(a.second < b.second) {
        return true;
    }
    if(a.second == b.second && a.first < b.first) {
        return true;
    }

    return false;
}

long long solve() {
    long long answer = 0;
    priority_queue<pair<long long, long long> > q;
        
    for(int i = 0; i < n; i++) {
        while(!q.empty() && (-q.top().first) + d < p[i].second) {
            q.pop();
        }
        if(p[i].second - p[i].first <= d){
            q.push({-p[i].first, p[i].second});
            answer = max(answer, (long long)q.size());
        }
    }
    return answer;
}

int main() {
    cin>>n;
    p = vector<pair<long long, long long> >(n);
    for(int i = 0; i < n; i++) {
        cin>>p[i].first>>p[i].second;
        if(p[i].first > p[i].second) {
            swap(p[i].first, p[i].second);
        }
    }
    sort(p.begin(), p.end(), comp);
    cin>>d;
    cout<<solve();
}