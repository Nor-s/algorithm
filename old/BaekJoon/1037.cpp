#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> trueDivisor;
int answer = INT32_MAX;

bool isOkay(int m) {
    for(int i = 0; i < trueDivisor.size(); i++) {
        if(m%trueDivisor[i] != 0 || trueDivisor[i] == m) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n = trueDivisor.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int tmp = trueDivisor[i]*trueDivisor[j];
            if(isOkay(tmp)) {
                cout<<tmp; 
                return;
            }
        }
    }

}
int main() {
    int N;
    cin>>N;
    trueDivisor = vector<int>(N);
    while(N--) {
        cin>>trueDivisor[N];
    }
    sort(trueDivisor.begin(), trueDivisor.end());
    solve();
}