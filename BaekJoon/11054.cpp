#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;
int N;
int dec1[1002][1001], inc[1002][1001];
vector<int> v;

int initial(int idx, int num, int a[1002][1001], int idxControl) {
    if(idx == -1 || idx == N) {
        return 0;
    }
    int& ret = a[num][idx];
    if(ret != -1) {
        return ret;
    }
    
    ret = initial(idx + idxControl, (num > v[idx])? v[idx]: num, a, idxControl) + (int)(num > v[idx]);
    if(num != 1001)
        ret = max(ret, initial(idx + idxControl, num, a, idxControl));
    return ret;
}
//10
//1 5 2 1 4 3 4 5 2 1

int main() {
    cin>>N;
    v = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin>>v[i];
    }

    memset(dec1, -1, sizeof dec1);
    memset(inc, -1, sizeof inc);

    int m = 0;
    for(int i = N-1; i >= 0; i--) {
        initial(i, 1001, inc, -1);
        initial(i, 1001, dec1, 1);
        if(m < inc[1001][i] + dec1[1001][i]) {
            m = inc[1001][i] + dec1[1001][i];
        }
    }
    
    cout<<m-1;
}