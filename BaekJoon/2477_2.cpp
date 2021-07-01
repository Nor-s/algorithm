#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> solution(N);

    for(int i = 0; i < N; i++) {
        cin>>solution[i];
    }

    int answer = INT32_MAX;
    int a, b, i = 0, idx = N - 1;
    while(i < idx) {
        int sum = abs(solution[i] + solution[idx]);
        if(answer > sum) {
            answer = sum;
            a = solution[i];
            b = solution[idx];
        }
        if(abs(solution[i]) > abs(solution[idx])) {
            i++;
        }
        else {
            idx--;
        }
    }
    cout<<a<<" "<<b;
}