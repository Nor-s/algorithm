#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
long long D = 1000000007;
vector<vector<long long> > matrix = { {0, 1} , {1, 1}};

vector<vector<long long> > product(vector<vector<long long> >& a, vector<vector<long long> >& b) {
    vector<vector<long long> > ret(a.size(), vector<long long>(b[0].size(), 0)); 
    for(long long i = 0; i < a.size(); i++) {
        for(long long j = 0; j < b[0].size(); j++) {
            for(long long k = 0; k < b.size(); k++) {
                ret[i][j] = (ret[i][j] + (a[i][k]*b[k][j])%D)%D;
            }
        }
    }
    return ret;
}

vector<vector<long long> > product(long long b) {
    if(b == 1) {
        return matrix;
    }
    if(b%2 == 0) {
        vector<vector<long long> > tmp = product(b/2);
        return product(tmp, tmp);
    }
    else {
        vector<vector<long long> > tmp = product(b-1);
        return product(tmp, matrix);
    }
}

int main() {
    long long n;
    cin>>n;
    if(n == 0) {
        cout<<0;
    }
    else if(n <= 2) {
        cout<<1;
    }
    else {
        vector<vector<long long> > factorial2 = {{0}, {1}};
        vector<vector<long long> > W = product(n-2);
        vector<vector<long long> > answer = product(W, factorial2);
        cout<<(answer[0][0] + answer[1][0])%D;
    }
}