#include <bits/stdc++.h>

using namespace std;
int N;

class cave {
public: 
    string name;
    map<string, cave> m;
    cave(string str = ".") {}
    cave* insert(string& str) {
        if(m.count(str) == 0) {
            m[str] = cave(str);
        }
        return &m[str];
    }
};

void dfs(map<string, cave>::iterator& it, int deepth) {
    for(int i = 0; i < deepth; i++) {
        cout<<"--";
    }
    cout<<it->first<<"\n";
    for(auto child = it->second.m.begin(); child != it->second.m.end(); child++) {
        dfs(child, deepth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cave root;
    for(int i = 0; i < N; i++) {
        int K;
        cin>>K;
        cave* np = &root;
        for(int j = 0; j < K; j++) {
            string tmp;
            cin>>tmp;
            np = np->insert(tmp);
        }
    }
    for(auto it = root.m.begin(); it != root.m.end(); it++) {
        dfs(it, 0);
    }
}