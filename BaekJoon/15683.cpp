#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int m[10][10];
int N, M, bin = 0;
int answer = INT32_MAX;

// right, left up down
vector<vector<int> > cctv[5] = {
    {{0}, {1}, {2}, {3}},
    {{0, 1}, {2, 3}},
    {{0, 3}, {0, 2}, {2, 1}, {1, 3}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};

// 0 = r / 1 = l / 2 = b / 3 = t
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};


void dp(int y, int x) {
    if(y == N && x == M + 1) {
        if(bin < answer){
            answer = bin;
        }
        return;
    }
    if(m[y][x] == -1) {
        return dp(y + 1, 1);
    }

    if(m[y][x] == 6 || m[y][x] == 0 || m[y][x] == 7) {
        return dp(y, x+1);
    }
    else {
       for(int i = 0; i < cctv[m[y][x] - 1].size(); i++) {
           vector<pair<int, int> > rememberPos;
           int count = 0;
           for(int j = 0; j < cctv[m[y][x] - 1][i].size(); j++) {
               int dir = cctv[m[y][x] - 1][i][j];
               int yy = y + dy[dir], xx = x + dx[dir];
               while(m[yy][xx] != 6 && m[yy][xx] != -1) {
                   if(m[yy][xx] == 0) {
                      count++;
                      m[yy][xx] = 7;
                      rememberPos.push_back(make_pair(yy, xx));
                   }
                   yy += dy[dir];
                   xx += dx[dir];
               }
           }
           bin -= count;
           dp(y, x + 1);
           bin += count;
           for(int j = 0; j < rememberPos.size(); j++) {
               m[rememberPos[j].first][rememberPos[j].second] = 0;
           }
       }
    }
}

void solve() {
    dp(1,1);
    cout<<answer<<"\n";
}

int main() {
    memset(m, -1, sizeof m);
    cin>>N>>M;

    for(int i = 1; i < N+1; i++) {
        for(int j = 1; j < M+1; j++) {
            cin>>m[i][j];
            if(m[i][j] == 0) {
                bin++;
            }
        }
    }

    solve();
}