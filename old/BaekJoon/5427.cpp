#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <deque>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

deque<tuple<int, int, int, char> > q;
        int r, c;
char board[1001][1001];

int bfs() {
    while(!q.empty()){
        auto [y, x, day, what] = q.front();
        q.pop_front();
        for(int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];            
            if(what == '@'&&board[y][x] == '*') {
                continue;
            }
            if(yy < 0|| yy >= r||
               xx < 0|| xx >=c) {
                if(what == '@') {
                    return day + 1;
                }
                   continue;
            }

            if(board[yy][xx] == '.' ||(board[yy][xx] =='@' && what == '*')) {
                board[yy][xx] = what;
                q.push_back({yy, xx, day+1, what});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin>>c>>r;
        q.clear();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin>>board[i][j];
                if(board[i][j] == '*') {
                    q.push_back({i, j, 0, '*'});
                }
                if (board[i][j] =='@'){
                    q.push_front({i, j, 0, '@'});
                }
            }
        }
        int answer = bfs();
        if(answer == -1) {
            cout<<"IMPOSSIBLE\n";
        }
        else {
            cout<<answer<<"\n";
        }
    }
}