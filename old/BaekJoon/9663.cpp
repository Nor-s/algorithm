#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;
int N;
bool m[14][14] = {false,};
int answer = 0;

void check(int y, int x, vector<pair<int, int> >& mask) {
    int dy[3] = {y, y, y};
    for(int dx = x + 1; dx < N; dx++) {
        dy[0] -= 1;
        dy[1] += 1;
        for(int j = 0; j < 3; j++) {
            if(dy[j] < N &&dy[j] >= 0 && !m[dy[j]][dx]) {
                m[dy[j]][dx] = true;
                mask.push_back(make_pair(dy[j], dx));
            }
        }
    }
}

void solve(int x) {
    if(x == N) {
        answer++;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(m[i][x]) continue;
        vector<pair<int, int> > mask;
        check(i, x, mask);
        solve(x+1);
        for(int j = 0; j < mask.size(); j++) {
            m[mask[j].first][mask[j].second] = false;
        }
    }
}

int main() {
    cin>>N;
    memset(m, false, sizeof m);
    solve(0);
    cout<<answer;
}