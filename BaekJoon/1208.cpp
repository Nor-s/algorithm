#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int N, S;
vector<int> s;
void combination(int lo, int hi, int sum, map<int, int>& cache) {
    if(lo == hi) {
        cache[sum]++;
        return;
    }
   combination(lo+1, hi, sum, cache);
   combination(lo+1, hi, sum+s[lo], cache);
}
int main() {
    long long answer = 0;
    cin>>N>>S;
    s = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin>>s[i];
    }
    map<int, int> left;
    map<int, int> right;
    combination(0, N/2, 0, left);
    combination(N/2, N, 0, right);
    for(auto it = left.begin(); it != left.end(); it++) {
        answer += (long long)right[S - it->first]*(long long)it->second;
    }
    if(S == 0) {
        answer--;
    }
    cout<<answer;
}