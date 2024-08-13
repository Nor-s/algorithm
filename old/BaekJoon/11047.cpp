#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> A;


void solve(int k) {
    int count = 0;
    for(int i = (int)A.size() - 1; i >= 0; i--) {
        if(k/A[i]!= 0) {
            count += k/A[i];
            k %= A[i];
        }
    }
    cout<<count;
}

int main() {
    int n , k;
    cin>>n>>k;
    A = vector<int>(n);
    for(int i = 0; i < n; i++) {
        cin>>A[i];
    }
    solve(k);
}