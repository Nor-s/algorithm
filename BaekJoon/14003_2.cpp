#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
vector<int> seq;
vector<vector<pair<int, int>>> lls; //first => value, second => idx

void insert(int x) {
    int j = -1;
    if(lls.empty() || lls.back().back().first < x) {
        if(!lls.empty()){
            j = lls.back().size() - 1;
        }
        lls.push_back({{x, j}});
    } 
    else {
        int lo = -1, hi = lls.size();

        while(true) {
            int mid = (lo + hi)/2;
            if(lo + 1 == hi) {
                if(hi != 0) {
                    j = lls[hi-1].size() -1;
                }
                lls[hi].push_back({x, j});
                break;
            }
            if(lls[mid].back().first < x) {
                lo = mid;
            } 
            else {
                hi = mid;
            }
        }
    }
}
void print(int i, int j) {
    if(i == -1) return;
    print(i - 1, lls[i][j].second);
    cout<<lls[i][j].first<<" ";
}
void solve() {
    for(int i = 0; i < N; i++) {
        insert(seq[i]);
    }
    cout<<lls.size()<<"\n";
    print(lls.size() -1, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    seq = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin>>seq[i];
    }
    solve();
}