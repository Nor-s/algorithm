#include <iostream>

using namespace std;

int cache[11][12];

void initial() {
    for(int i = 0; i <= 10; i++) {
        cache[i][0] = 1; cache[i][i+1] = 0;
        for(int j = 1; j <= i; j++) {
            cache[i][j] = cache[i-1][j-1] + cache[i-1][j];
        }
    }
}

int main() {
    int N, K;
    cin>>N>>K;
    initial();
    cout<<cache[N][K];
}