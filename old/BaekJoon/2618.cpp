#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, w;
vector<pair<int, int> > vp;

int dist(int idx1, int idx2) {
    int ret = abs(vp[idx1].first - vp[idx2].first) 
            + abs(vp[idx1].second - vp[idx2].second);
    return ret;
}

//n <= 1000, w <= 1000
int cached[1003][1003];
int answer[1003][1003];
int dp(int idx, int idx1, int idx2) {
    if(idx == w + 2) {
        return 0;
    }
    int &ret = cached[idx1][idx2];
    if(ret != -1) {
        return ret;
    }
    ret = dist(idx, idx1) + dp(idx+1, idx, idx2);
    int car2 = dist(idx, idx2) + dp(idx+1, idx1, idx);
    if(car2 < ret) {
        answer[idx1][idx2] = 2;
        ret = car2;
    } 
    else {
        answer[idx1][idx2] = 1;
    }
    return ret;
}

void print(int idx, int idx1, int idx2) {
    if(idx == w+2) {
        return;
    }
    int car = answer[idx1][idx2];
    cout<<car<<"\n";
    if(car == 1) {
        print(idx+1, idx, idx2);
    }
    else {
        print(idx + 1, idx1, idx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>w;
    memset(cached, -1, sizeof cached);
    vp.push_back({1, 1});
    vp.push_back({n, n});
    for(int i = 0; i < w; i++) {
        int a, b;
        cin>>a>>b;
        vp.push_back({a, b});
    }

    cout<<dp(2, 0, 1)<<"\n";
    print(2, 0, 1);
}
