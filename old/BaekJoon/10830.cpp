#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
long long N; 
long long D = 1000;
long long B;
vector<vector<long long> > matrix;

vector<vector<long long> > product(vector<vector<long long> >& a, vector<vector<long long> >& b) {
    vector<vector<long long> > ret(N, vector<long long>(N, 0)); 
    for(long long i = 0; i < N; i++) {
        for(long long j = 0; j < N; j++) {
            for(long long k = 0; k < N; k++) {
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
    cin>>N>>B;
    matrix = vector<vector<long long> >(N, vector<long long>(N));
    for(long long i = 0; i < N; i++) {
        for(long long j = 0; j < N; j++) {
            cin>>matrix[i][j];
        }
    }
    vector<vector<long long> > answer = product(B);

    for(long long i = 0 ; i < N; i++) {
        for(long long j = 0 ; j < N; j++) {
            cout<<answer[i][j]%D<<" ";
        }
        cout<<"\n";
    }
}