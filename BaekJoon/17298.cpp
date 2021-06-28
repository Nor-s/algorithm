#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> A;
vector<int> answer;

void solve() {
    stack<int> s;
    A.push_back(INT32_MAX);
    for(int i = 0; i < A.size(); i++) {
        while(!s.empty() && (A[s.top()] < A[i])) {
            answer[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i = 0; i < answer.size(); i++) {
        if(answer[i] == INT32_MAX) {
            cout<<-1<<" ";
        }
        else {
            cout<<answer[i]<< " ";
        }
    }
}

int main() {
    int N;
    cin>>N;
    A = answer = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin>>A[i];
    }
    solve();
}