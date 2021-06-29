#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int N, K;
map<int, int> C;
vector<pair<int, int> > item;
long long answer = 0;


void solve(int iidx) {
    if(iidx == -1) {
        return;
    }
    auto lo = C.lower_bound(item[iidx].second);

    for(auto it = lo; it != C.end(); it++) {
        if(it->second > 0) {
            answer += item[iidx].first;
            it->second--;
            if(it->second == 0) {
                C.erase(it->first);
            }
            break;
        }
    }
    return solve(iidx-1);
}

int main() {
    cin>> N >> K;
    item = vector<pair<int, int> >(N);

    for(int i = 0; i < N; i++) {
        cin>>item[i].second>>item[i].first;
    }
    sort(item.begin(), item.end());
    for(int i = 0; i < K; i++){
        int tmp;
        cin>>tmp;
        C[tmp]++;
    }
    solve(N-1);
    cout<<answer;
}