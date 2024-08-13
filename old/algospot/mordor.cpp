#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int testCase;

pair<int, int> selectMinMax(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == -1) return b;
    if(b.first == -1) return a;
    int min = a.first < b.first ? a.first: b.first;
    int max = a.second > b.second ? a.second: b.second;
    return make_pair(min, max);
}

struct milestone {
    vector<pair<int, int> > tree;
    int stoneN;
    milestone(const vector<int>& stone) {
        stoneN = stone.size();
        tree.resize(stoneN*4);
        init(stone, 0 ,0, stoneN);
    } 
    pair<int, int> init(const vector<int>& stone, int node,int lo, int hi) {
        int mid = (lo+hi)/2;
        if(lo + 1 == hi) return tree[node] = make_pair(stone[lo], stone[lo]);
        return tree[node] = selectMinMax(init(stone, node*2 + 1, lo, mid), init(stone, node*2 + 2, mid, hi));
    }
    pair<int, int> query(int node , int lo, int hi, int nlo, int nhi) {
        if(nhi <= lo || hi < nlo) return make_pair(-1, -1);
        if(lo<= nlo && nhi <= hi+1) return tree[node];
        int mid = (nlo+nhi)/2;

        return selectMinMax(query(node*2+1, lo, hi, nlo, mid), query(node*2 + 2, lo, hi, mid, nhi));
    }
    int query(int lo, int hi) {
        pair<int, int> ret = query(0, lo, hi, 0, stoneN);
        return ret.second - ret.first;
    }
};

int main() {
    cin>>testCase;
    while(testCase--)
    {
        int N, q, a, b;
        cin>>N>>q;
        vector<int> h;
        while(N--) 
        {
            scanf("%d",&a);
            h.push_back(a);
        }
        milestone tree(h);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n", tree.query(a,b));
        }
    }
}