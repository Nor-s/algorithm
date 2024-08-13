#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
int N;
vector<int> q;
map<int, int> m;

void setDivisor(int tmp) {
    m[tmp]++;
    for(int i = 2; i <= sqrt(tmp); i++) {
        if(tmp%i == 0) {
            m[i]++;
            if(i != sqrt(tmp)){
                m[tmp/i]++;
            }
        }
    }
}

void solve() {
    for(int i = 1; i < q.size(); i++) {
        int tmp = q[i] - q[i-1];
        setDivisor(tmp);
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second == q.size()-1) {
            cout<<it->first<<" ";
        }
    }
}

int main() {
    cin>>N;
    while(N--) {
        int tmp;
        cin>>tmp;
        q.push_back(tmp);
    }
    sort(q.begin(), q.end());
    solve();
}