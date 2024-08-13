#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int N;
priority_queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    int x;
    

    for(int i = 0; i < N; i++){
        int tmp;
        cin>>tmp;
        if(tmp == 0) {
            if(q.empty()) {
                q.push(0);
            }
            cout<<q.top()<<"\n";
            q.pop();
        } else {
            q.push(tmp);
        }
    }
}