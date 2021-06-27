#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long cache[2002][2002];

void initial(long long M) {
    for(int i = 0; i < 2001; i++) {
        cache[i][i+1] = 0; cache[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            cache[i][j] = (cache[i-1][j] + cache[i-1][j-1])%M;
        }
    }
}

vector<long long> decimalToM(long long N, long long M) {
    vector<long long> ret;
    do {
        ret.push_back(N%M);
        N/= M;
    }while(N!= 0);
    return ret;
}

long long sol(long long N, long long K, long long M) {
    vector<long long> nlist = decimalToM(N, M);
    vector<long long> klist = decimalToM(K, M);
    long long ret = 1;

    for(int i = 0; i < nlist.size(); i++) {
        if(klist.size() <= i) {
            break;
        }
        if(nlist[i] < klist[i]) { 
            return 0;
        }
        ret = (ret * cache[nlist[i]][klist[i]])%M;
    }
    return ret;
}

// N <= 1e18 , M <= 2000
int main() {
    long long N, K, M;
    cin>>N>>K>>M;
    initial(M);
    cout<<sol(N, K, M);
}