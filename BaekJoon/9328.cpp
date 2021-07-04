#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cstring>
#include <queue>

using namespace std;
int h, w;
char m[101][101];
bool hkey[26];
queue<pair<int, int> > e;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer = 0;

void dfs(int y, int x, vector<vector<bool> > &visited) {
    visited[y][x] = true;

    for(int i = 0; i < 4; i++) {
        int yy = y + dy[i], xx = x + dx[i];
        if(yy < 0 || xx < 0 || yy >= h || xx >= w || m[yy][xx] == '*' || visited[yy][xx]) {
            continue;
        }
        if(m[yy][xx] >= 'A' && m[yy][xx] <= 'Z' && hkey[m[yy][xx] - 'A'] == false) {
            e.push({yy, xx});
            continue;
        }

        if(m[yy][xx] >= 'a' && m[yy][xx] <= 'z') {
            hkey[m[yy][xx] - 'a'] = true;
        }
        else if(m[yy][xx] == '$') {
            answer++; 
        }
        m[yy][xx] = '.';
        dfs(yy, xx, visited);
    }
}

void solve() {
    vector<vector<bool> > visited(h, vector<bool>(w, false));
    int count = 0;
    answer = 0;
    while(!e.empty() && count <= e.size()) {
        int i = e.front().first, j = e.front().second;
        count++;

        e.pop();
        if(visited[i][j]) {
            continue;
        }
        if(m[i][j] >= 'A' && m[i][j] <= 'Z' && hkey[m[i][j] - 'A'] == false) {
            e.push({i, j});
            continue;
        }
        else {
            if(m[i][j] >= 'a' && m[i][j] <= 'z') {
                hkey[m[i][j] - 'a'] = true;
            }
            else if(m[i][j] == '$') {
                answer++;
            }
            m[i][j] = '.';
            dfs(i, j, visited);
            count = 0;
        }
    }
    std::cout<<answer<<"\n";
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>h>>w;
        e = queue<pair<int, int> >();
        memset(hkey, 0, sizeof hkey);
        
        // '.' == bin   /  '*' == wall   /  '$' == paper  /   ABC...Z == door  /   abc...z == key
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin>>m[i][j];
                if((i == 0 || i == h - 1 || j == 0 || j == w - 1 ) && m[i][j] !=  '*')  {
                    e.push({i,j});
                    if(m[i][j] >= 'a' && m[i][j] <= 'z') {
                        hkey[m[i][j] - 'a'] = true;
                    }
                }
            }
        }
        getchar();           
        int ch;
        while((ch = getchar()) != '\n') {
            if(ch == '0') {
                getchar();
                break;
            }
            hkey[ch - 'a'] = true;
        }
        solve();
    }
}