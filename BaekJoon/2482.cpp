#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


const int div1 = 1000000003;
int cache1[1001][1001];

int dp1(int n, int k, int count, int idx) {
    int &ret = cache1[count][idx];
    if(ret != -1) {
        return ret;
    }
    if(count == k) {
        return 1;
    }
    if(idx >= n || (n - idx)/2  + 1 < k - count) {
        return ret = 0;
    }

    return ret = (dp1(n, k, count + 1, idx + 2) + dp1(n, k, count, idx + 1)) % div1;
}

int main() {
    int N, K;
    cin>>N>>K;
    memset(cache1, -1, sizeof cache1);
    cout<<(dp1(N, K, 0, 1) + dp1(N, K, 1, 3))%div1<<"\n";
}
