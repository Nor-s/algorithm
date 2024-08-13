#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
 
using namespace std;
int N;
vector<int> seq;
vector<int> lls; 
 
void insert(int x) {
    if(lls.empty() || lls.back() < x) {
        lls.push_back(x);
    } 
    else {
        int lo = -1, hi = lls.size();
 
        while(true) {
            int mid = (lo + hi)/2;
            if(lo + 1 == hi) {
                lls[hi] = x;
                break;
            }
            if(lls[mid] < x) {
                lo = mid;
            } 
            else {
                hi = mid;
            }
        }
    }
}
void solve() {
    for(int i = 0; i < N; i++) {
        insert(seq[i]);
    }
    cout<<lls.size()<<"\n";
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
