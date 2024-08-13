#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> solution;

int main() {
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) {
        int t;
        cin>>t;
        solution.push_back(t);
    }
    int answer = INT32_MAX;
    int a, b;
    for(int i = 0; i < N; i++) {
        auto it = lower_bound(solution.begin(), solution.end(), -solution[i]);
        it++;
        for(int j = 0; j < 3; j++) {
            int idx = it - solution.begin();
            if(idx != i && it < solution.end() && answer > abs(*it + solution[i])) {
                answer = abs(*it + solution[i]);
                a = solution[i];
                b = *it;
            }
            if(it == solution.begin()) {
                break;
            }
            it--;
        }
    }
    cout<<a<<" "<<b;
}