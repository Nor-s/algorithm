#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100000;
vector<int> seq;

int cached[5][5][MAX + 1];

int cost(int from, int to) {
    if(from > to) {
        swap(from, to);
    }
    if(from == to) {
        return 1;
    }
    else if(from == 0) {
        return 2;
    }
    else if((from == 1 && to == 3) || (from == 2 && to == 4)) {
        return 4;
    }
    else {
        return 3;
    }
}
int dp(int idx, int left, int right) {
    if(idx == seq.size()) {
        return 0;
    }
    int& ret = cached[left][right][idx];
    if(ret != -1) {
        return ret;
    }

    ret = dp(idx+1, seq[idx], right) + cost(left, seq[idx]);
    ret = min(dp(idx+1, left, seq[idx]) + cost(right, seq[idx]), ret);

    return ret;
}

void solve() {
    cout<<dp(0, 0, 0);
}


int main() {
    memset(cached, -1, sizeof cached);
    char ch;
    while((ch = getchar()) != '0') {
        if(ch == ' ') {
            continue;
        }
        seq.push_back((int) (ch - '0'));
    }
    solve();
}