#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
vector<int> seq;
vector<vector<pair<int, int>>> lls; //first => value, second => idx

void insert(int x, int idx) {
    if(lls.empty() || lls.back().back().first < x) {
        lls.push_back({{x, idx}});
    } 
    else {
        int lo = -1, hi = lls.size();

        while(true) {
            int mid = (lo + hi)/2;
            if(lo + 1 == hi) {
                lls[hi].push_back({x, idx});
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
void print(int idx, int seqIdx) {
    if(idx == -1) return;
    int lo = -1, hi = lls[idx].size();
    while(true) {
        int mid = (lo + hi)/2;
        if(lo + 1 == hi) {
            seqIdx = lls[idx][mid].second;
            break;
        }
        else if(lls[idx][mid].second < seqIdx) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    print(idx -1 , seqIdx);
    cout<<seq[seqIdx]<<" ";
}
void solve() {
    for(int i = 0; i < N; i++) {
        insert(seq[i], i);
    }
    cout<<lls.size()<<"\n";
    print(lls.size() - 1, N - 1);
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