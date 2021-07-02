#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

std::string a, b;
int cache[1001][1001];
int tracking[1001][1001];

int da[3] = {1, 0, 1};
int db[3] = {0, 1, 1};

int solve(int aIdx, int bIdx) {
    if(aIdx == a.size() || bIdx == b.size()) {
        return 0;
    }
    int& ret = cache[aIdx][bIdx];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    for(int i = 0; i < 3; i++) {
        int temp = solve(aIdx + da[i], bIdx + db[i]) + ((i == 2) ? (int)(a[aIdx] == b[bIdx]) : 0);
        if(temp > ret) {
            tracking[aIdx][bIdx]= i;
            ret = temp;
        }
    }
    return ret;
}
void print(int aidx, int bidx) {
    if(aidx == a.length() || bidx == b.length()) return;
    if(a[aidx] == b[bidx] && tracking[aidx][bidx] == 2) {
        std::cout<<a[aidx];
    }
    return print(aidx + da[tracking[aidx][bidx]], bidx + db[tracking[aidx][bidx]]);
}
 
int main() {
    std::cin>>a>>b;
    memset(cache, -1, sizeof cache);
    int len = solve(0, 0);
    std::cout<<len<<"\n";
    if(len != 0) {
        print(0, 0);
    }
}
