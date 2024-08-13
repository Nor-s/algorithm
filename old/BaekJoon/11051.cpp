#include <iostream>

using namespace std;

int cache[1001][1002];

void initial() {
    for(int i = 0; i <= 1000; i++) {
        cache[i][0] = 1; cache[i][i+1] = 0;
        for(int j = 1; j <= i; j++) {
            cache[i][j] = (cache[i-1][j-1] + cache[i-1][j])%10007;
        }
    }
}

int main() {
    int N, K;
    cin>>N>>K;
    initial();
    cout<<cache[N][K];
}