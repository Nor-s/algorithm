#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

void recursionDelete(vector<vector<int> >& tree, set<int>& leap, int d) {
    if(tree[d].empty()) {
        leap.erase(d);
        return;
    }
    for(int i = 0; i < tree[d].size(); i++) {
        recursionDelete(tree, leap, tree[d][i]);
    }
    tree[d].clear();
}

int deleteTree(vector<vector<int> >& tree, int d) {
    set<int> leap;
    int size = tree.size();
    for(int i = 1; i < size; i++) {
        if(tree[i].empty()) {
            leap.insert(i);
        }
    }
    recursionDelete(tree, leap, d+1);
    return leap.size();
}

//tree => 0 is root
int main() {
    int n = 0, d = 0, answer = 0;
    cin>>n;
    vector<int> parent(n, 0);
    vector<vector<int> > tree(n+1);
    for(int i = 0; i < n; i++) {
        cin>>parent[i];
        tree[parent[i] + 1].push_back(i+1);
    }
    cin>>d;
    answer = deleteTree(tree, d);
    if(tree[parent[d]+1].size() == 1 && parent[d] != -1) {
        answer++;
    }
    cout<<answer<<"\n";
}