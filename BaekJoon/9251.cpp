#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

std::string a, b;
int cache[1001][1001];

int solve(int aIdx, int bIdx) {
    if(aIdx == a.size() || bIdx == b.size()) {
        return 0;
    }
    int& ret = cache[aIdx][bIdx];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    
    ret = solve(aIdx + 1, bIdx);
    ret = std::max(ret, solve(aIdx, bIdx + 1));
    ret = std::max(ret, solve(aIdx + 1, bIdx + 1) + (int)(a[aIdx] == b[bIdx]));
    
    return ret;
}

int main() {
    std::cin>>a>>b;
    memset(cache, -1, sizeof cache);
    std::cout<<solve(0, 0);
}