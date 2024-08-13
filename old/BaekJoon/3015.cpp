#include <bits/stdc++.h>

using namespace std;
int N;
vector<long long> h;

void solve() {
    long long answer = 0;
    vector<pair<long long, int>> s;
    for(int i = 0; i < N; i++) {
        int count = 1;
        while(!s.empty() && s.back().first < h[i]) {
            //h[i]와의 쌍
            answer += s.back().second;
            s.pop_back();
        }
        //s.back()과의 쌍
        if(!s.empty() && s.back().first == h[i]) {
            answer += s.back().second;
            count = s.back().second+1;
            s.pop_back();
        }
        if(!s.empty()) {
            answer++;
        }
        s.push_back({h[i], count});
    }

    cout<<answer;
}
void solve2() {
    long long answer = 0;
    vector<int> s;
    h.push_back(INT64_MAX);
    for(int i = 0; i < N+1; i++) {
        long long back = h[i], count = 0;
        if(i == N) {
            answer -= s.size();
        }
        while(!s.empty() && h[s.back()] < h[i]) {
            // 같은것끼리 쌍을 이루는것
            if(back == h[s.back()]) {
                count++;
                answer += count;
            }
            else {
                count = 0;
            }
            back = h[s.back()];
            //h[i] 와 쌍을 이루는것
            answer++;
            s.pop_back();
        }
        if(!s.empty() && h[s[0]] != h[i]) {
            //s[0] 와 쌍을 이루는것
            answer++;
        }
        s.push_back(i);
    }

    cout<<answer;
}
int main() {
    cin>>N;
    h = vector<long long>(N);
    for(int i = 0; i < N; i++) {
        cin>>h[i];
    }
    solve();
   // cout<<"\n";
   // solve2();
   return 0;
}