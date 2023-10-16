#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int N, M;
char m[1000][1000][5] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int solve(int y, int x) {
    if(m[y][x][4] == '.') {
        //좌
        if(m[y][x-1][4] == '.') {

        }
        //위
        if(m[y-1][x][4] == '.') {

        }
    }
        

}

int main() {
    cin>>N>>M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin>>m[i][j][4];
        }
    }
    solve(1, 1);
}