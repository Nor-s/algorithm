#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int k;
// v <= 20000, E <= 200000
int V, E;
vector<vector<int> > adjList;

bool bfs(int src, vector<int>& setNum) {
    int visitNum = 1;
    queue<int> q;
    q.push(src);
    setNum[src] = 0;

    while(!q.empty()) {
        int here = q.front();
        int num = setNum[here];

        q.pop();

        for(int i = 0; i < adjList[here].size(); i++) {
            int there = adjList[here][i];
            int& tnum = setNum[there];
            if(tnum == -1) {
                visitNum++;
                tnum = (num == 0)? 1 : 0;
                q.push(there);
            }
            else if(tnum == num) {
                return false;
            }
        }
    }
    return true;
}
bool bfsAll() {
    bool ret = true;
    vector<int> setNum(V, -1);
    for(int i = 0; i < V; i++) {
        if(setNum[i] == -1) {
            ret &= bfs(i, setNum);
        }
    }
    return ret;
}
/*
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
*/
int main() {
    cin>>k;
    while(k--) {
        cin>>V>>E;
        adjList = vector<vector<int> >(V);
        for(int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            adjList[a-1].push_back(b-1);
            adjList[b-1].push_back(a-1);
        }
        if( V > 1 && bfsAll()) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
}