#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
int T;
int n;
vector<int> student;
stack<int> s;

int dfs(int idx, vector<int>& discovered, int& answer) {
    static int vertexN = 0;
    int ret = discovered[idx] = vertexN++;
    int nextIdx = student[idx];
    s.push(idx);

    if(discovered[nextIdx] == -1) {
        ret = min(ret, dfs(nextIdx, discovered, answer));
    }
    else {
        ret = min(ret, discovered[nextIdx]);
    }
    if(ret == discovered[idx]) {
        int count = 0;
        while(true) {
            int tmp = s.top();
            count++;
            answer--;
            s.pop();
            if(idx == tmp) {
                break;
            }
        }
        if(count == 1 && idx != nextIdx) {
            answer++;
        }
    }

    return ret;
}
void dfsAll() {
    vector<int> discovered(n, -1);
    int answer = n;
    for(int i = 0; i < n; i++) {
        if(discovered[i] != -1) continue;
        dfs(i, discovered, answer);
    }
    cout<<answer<<"\n";;
}

int main() {
    cin>>T;
    while(T--) {
        cin>>n;
        student = vector<int>(n);
        s = stack<int>();
        for(int i = 0 ; i < n; i++) {
            int tmp;
            cin>>tmp;
            student[i] = tmp -1;
        }
        dfsAll();
    }
}