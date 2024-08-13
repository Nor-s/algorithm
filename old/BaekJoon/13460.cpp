#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;
int N, M;
char board[14][14];
pair<int, int> ma[2];
pair<int, int> goal;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int answer = 11;

void gravity(int dir) {
    bool blueFirst = false;
    if(ma[0].first == ma[1].first 
    && ((dir == 0 && (ma[0].second < ma[1].second)) 
     || (dir == 2 && (ma[0].second > ma[1].second))) ) {
        blueFirst = true;
    }
    if(ma[0].second == ma[1].second 
    && ((dir == 1 && (ma[0].first < ma[1].first)) 
     || (dir == 3 && (ma[0].first > ma[1].first))) ) {
        blueFirst = true;
    }
    for(int i = 0; i < 2; i++) {
        while(true) {
            int &y = ma[blueFirst].first;
            int &x = ma[blueFirst].second;
            pair<int, int> tmp = {y+dy[dir], x + dx[dir]};
            char next = board[tmp.first][tmp.second];
            if(next == '#' || (tmp == ma[!blueFirst] && next != 'O')) {
                break;
            }
            y += dy[dir];
            x += dx[dir];
            if(next == 'O') {
                break;
            }
        }
        blueFirst = !blueFirst;
    }
}

void dp(int count) {
    if(count > 10 || ma[1] == goal) {
        return;
    }
    if(ma[0] == goal) {
        answer = min(answer, count);
        return;
    }
    for(int i = 0; i < 4; i++) {
        pair<int, int> temp[2] = {ma[0], ma[1]} ;
        gravity(i);
        if(temp[0] == ma[0] && temp[1] == ma[1]) {
            continue;
        }
        dp(count+ 1);
        ma[0] = temp[0]; ma[1] = temp[1];
    }
}

void solve() {
    dp(0);
    if(answer <= 10) {
        cout<<answer;
    }
    else {
        cout<<-1;
    }
}

int main() {
    cin>>N>>M;
    getchar();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            board[i][j] = getchar();
            if(board[i][j] == 'R') {
                ma[0].first = i;
                ma[0].second = j;
            }
            if(board[i][j] == 'B') {
                ma[1].first = i;
                ma[1].second = j;
            }
            if(board[i][j] == 'O') {
                goal.first = i;
                goal.second = j;
            }
        }
        getchar();
    }
    solve();
}