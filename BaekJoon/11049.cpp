#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <list>

using namespace std;
vector<pair<int, int> > matrix;

int cache[501][501];
int dp(int start, int end) {
    int &ret = cache[start][end];
    if(ret != -1) {
        return ret; 
    }
    if(start + 1 == end) {
        return 0;
    }
    if(start+2 == end) {
        return ret = matrix[start].first*matrix[start].second*matrix[start+1].second;
    }
    ret = INT32_MAX;
    for(int i = start + 1; i < end; i++) {
        ret = min(dp(start, i) + dp(i, end) + matrix[start].first * matrix[i].first * matrix[end-1].second, ret);
    }
    return ret;
}

int main() {
    int N;
    cin>>N;
    memset(cache, -1, sizeof cache);
    for(int i = 0; i < N; i++) {
        int r, c;
        cin>>r>>c;
        matrix.push_back(make_pair(r, c));
    }
    cout<<dp(0, N);
}