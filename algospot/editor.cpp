#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
 
struct UnionFindSet {
    vector<int> father;
    vector<int> rank;

    vector<int> size;

    vector<int> reverse;
    UnionFindSet(int n): father(n), rank(n, 1), size(n,1), reverse(n, -1) {
        for(int i = 0; i < n; i++){
            father[i] = i;
        }
    }
    int find(int u) {
        if(u == -1) return -1;
        if(u == father[u]) return u;
        return father[u] = find(father[u]);
    }
    bool merge(int u, int v, int state) {
        u = find(u); v = find(v);
        int ru = find(reverse[u]), rv = find(reverse[v]);
        if(state == -1) {
            if(u == v) return false;
            if(ru != -1) if(!merge(ru, v, 1)) return false;
            if(rv != -1) if(!merge(u, rv, 1)) return false;

            reverse[u] = v;
            reverse[v] = u;
            return true;
        }
        else {
            if(u == v) return true;
            if(ru == v || rv == u) return false;

            if(rank[u] > rank[v]) swap(u,v);
            father[u] = v;
            reverse[v] = ru > rv ? ru: rv;
            size[v] += size[u];
            size[u] = 0;
            if(rank[u] == rank[v]) rank[v]++;
            return true;
        }
    }
    int calc() {
        int ret = 0;
        int vim = 0;
        int emacs = 0;
        bool travel[10000] = {false, };
        for(int i = 0; i < father.size(); i++)
        {
            int u = find(i);
            if(travel[u]) continue;
            if(reverse[u] == -1){
                ret += size[u];
            }
            if(reverse[u] != -1) {
                int v = find(reverse[u]);
                vim += size[u] > size[v] ? size[u] : size[v];
                emacs += size[u] < size[v] ? size[u] : size[v];
                travel[v] = true;
            }
            travel[u] = true;
        }
        return ret + vim;

    }
};
int C;
int N;
int M;
vector<pair<int, pair<int, int> > > comment;
 
void findContradiction() {
    UnionFindSet S(N);
    for(int i = 0 ; i < M; i++) {
        if(!S.merge(comment[i].second.first, comment[i].second.second, comment[i].first)) {
            cout<<"CONTRADICTION AT "<<i+1<<"\n";
            return;
        }
    }
    cout<<"MAX PARTY SIZE IS "<<S.calc()<<"\n";
    return;
}
 
int main() {
    cin>>C;
    while(C--) {
        cin>>N>>M;
        comment.clear();
        for(int i = 0; i < M; i++){
            string inform;
            int a, b;
            cin>>inform>>a>>b;
            int tmp = (inform[0] == 'A' ? 1: -1); 
            comment.push_back( pair<int, pair<int, int> >(tmp,  make_pair(a, b)));
        }
        findContradiction();
    }
}

