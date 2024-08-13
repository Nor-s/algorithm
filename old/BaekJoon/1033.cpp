#include <iostream>
#include <vector>
#include <utility>

using namespace std;

long long gcd(long long a, long long b) {
    if(a == 0) return b;
    else return gcd(b%a, a);
}   
pair<long long, long long> makePair(long long a, long long b) {
    int div = gcd(a, b);
    return make_pair(a/div, b/div);
}

struct unionFind {
    vector<pair<long long, long long> > n;
    vector<int> parent;
    unionFind(int _n) {
        for(int i = 0; i < _n; i++) {
            parent.push_back(i);
            n.push_back(make_pair(1LL, 1LL));
        }
    }
    void print() {
        for(int i = 0; i < (int)n.size() ; i++) {
            cout<<n[i].first<<" ";
        }
        cout<<"\n";
    }
    void merge(int a, int b, pair<long long, long long> p_q) {
        int aparent = parent[a];
        int bparent = parent[b];
        if(aparent == bparent) {
            return;
        }
        pair<long long, long long> aa  = makePair(n[a].first, n[a].second);

        for(int i = 0; i < (int)n.size(); i++) {
            if(parent[i] != aparent) continue;
            parent[i] = bparent;
            n[i] = makePair(n[i].first * n[b].first * p_q.first * aa.second, n[i].second * n[b].second * p_q.second * aa.first);
        }
    }
    void toInt() {
        int prod = n[0].second;
        for(int i = 1; i < (int)n.size(); i++) {
            prod = (prod*n[i].second)/gcd(prod, n[i].second);
        }
        for(int i = 0; i < (int)n.size(); i++) {
            n[i].first = (prod*n[i].first)/ n[i].second;
        }
    }
};

/*
5
4 0 1 1
4 1 3 1
4 2 5 1
4 3 7 1
*/
int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n-1, vector<int>(4));
    unionFind uf(n);
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < 4; j++) {
            cin>>v[i][j];
        }
        uf.merge(v[i][0], v[i][1], makePair(v[i][2], v[i][3]));
    }
    uf.toInt();
    uf.print();
}