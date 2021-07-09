#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<vector<long long> > board;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
long long answer = 0;

void myFor(int start, int end, int added, int dir) {
    vector<vector<bool> > merged(N, vector<bool>(N, false));
    for(int i = start; ((added > 0)? (i < end) : (i >= end)); i += added) {
        for(int j = start; ((added > 0) ? (j < end) : (j >= end)); j += added) {
            int y = i, x = j;
            long long number = board[y][x];
            if(number == 0) {
                continue;
            }
            while(true) {
                int yy = y + dy[dir];
                int xx = x + dx[dir];
                if(yy < 0 || yy >= N || xx < 0 || xx >= N ||(board[yy][xx] != 0 && board[yy][xx] != number) || merged[yy][xx]) {
                    break;
                }
                board[y][x] = 0;
                if(board[yy][xx] == number) {
                    board[yy][xx] += number;
                    answer = max(answer, board[yy][xx]);
                    merged[yy][xx] = true;
                    break;
                } 
                y = yy;
                x = xx;
                board[y][x] = number; 
            }
        }
    }
}

void gravity(int dir) {
    if(dir == 0 || dir == 1) {
        myFor(N-1, 0, -1, dir);
    }
    else if(dir == 2 || dir == 3) {
        myFor(0, N, 1, dir);
    }
}

void bf(int count) {
    if(count == 5) {
        return;
    }
    for(int i = 0; i < 4; i++) {
        vector<vector<long long> > tmp = board;
        gravity(i);
        bf(count + 1);
        board = tmp;
    }
}

int main() {
    cin>>N;
    board = vector<vector<long long> >(N, vector<long long>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin>>board[i][j];
            if(board[i][j] != 0) {
                answer = max(answer ,board[i][j]);
            }
        }
    }
    bf(0);
    cout<<answer;
}