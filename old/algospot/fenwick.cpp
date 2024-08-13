#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n+1, 0) {}
    int sum(int pos) {
        ++pos;
        int ret = 0;
        while(pos>0) {
            ret += tree[pos];
            pos&=(pos-1);
        }
        return ret;
    }
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};



int C, N;
vector<int> A;

long long totalMove() {
    long long ret = 0;
    FenwickTree tree(1000000);
    for(int i = 0; i < A.size(); i++) {
        ret += tree.sum(1000000-1) - tree.sum(A[i]);
        tree.add(A[i], 1);
    }
    return ret;
}
int main() {
    cin>>C;
    while(C--) {
        cin>>N;
        A.clear();
        A.resize(N);
        while(N--) {
            int tmp;
            cin>>tmp;
            A.push_back(tmp);
        }
        cout<<totalMove()<<"\n";
    }
}