#include <bits/stdc++.h>
//11: 40
using namespace std;
int N, M;
const int dx[3] = {-1, 1, 0};
const int dy[3] = {0, 0, 1};
//1 1 -> N M 
int m[1003][1003];
long long cached[1003][1003][3];
bool check[1003][1003];
long long toMax(int y, int x, int before) {
    long long &ret = cached[y][x][before];
    if(ret != INT64_MIN) {
        return ret;
    }
    if(y == N-1 && x == M-1) {
        return 0;
    }
    ret = -100000000;                                                                                                                             ;
    for(int i = 0; i < 3; i++) {
        int newy = y+dy[i];
        int newx = x+dx[i];
        if(newy < N && newy > -1 && newx < M && newx > -1 &&!check[newy][newx]) {
            check[newy][newx] = true;
            ret = max(ret ,toMax(newy, newx, i) + m[newy][newx]);
            check[newy][newx] = false;
        }
    }

    return ret;
}
void solve() {
    check[0][0] = true;
    cout<<toMax(0, 0, 2) + m[0][0]<<"\n";
}
int main() {
    cin>>N>>M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin>>m[i][j];
            check[i][j] = false;
            for(int k = 0; k < 3; k++) {
                cached[i][j][k] = INT64_MIN;
            }
        }
    }
    solve();
}