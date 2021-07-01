#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    vector<long long> s(N);
    long long answer = 3000000001;
 
    for(int i = 0; i < N; i++) {
        cin>>s[i];
    }
    sort(s.begin(), s.end());
 
    long long abc[3] = {s[0], s[1], s[2]};
 
    for(int i = 0; i < N; i++) {
       for(int j = i + 1; j < N; j++) {
           long long sum = s[i] + s[j];
           auto lo = lower_bound(s.begin() + j + 1, s.end(), -sum);
           int test[2] = {(int) (lo - s.begin()),
                          (int) (lo - 1 - s.begin())};
          
           for(int k = 0; k < 2; k++) {
               int idx = test[k];
               if(idx < 0 || idx >= N) {
                   continue;
               }
               if(answer > abs(sum + s[idx]) && idx != j) {
                   answer = abs(sum + s[idx]);
                   abc[0] = s[i];
                   abc[1] = s[j];
                   abc[2] = s[idx];
               }
           }
       }
    }
    
    sort(abc, abc + 3);
    
    std::cout<<abc[0]<<" "<<abc[1] << " " << abc[2];
}
