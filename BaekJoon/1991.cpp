#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> tree[26];

void preorder(int idx) {
    cout<<(char)(idx + 'A');
    if(tree[idx].first + 'A' != '.') {
        preorder(tree[idx].first);
    }
    if(tree[idx].second + 'A' != '.') {
        preorder(tree[idx].second);
    }
}
void inorder(int idx) {
    if(tree[idx].first + 'A' != '.') {
        inorder(tree[idx].first);
    }
    cout<<(char)(idx + 'A');
    if(tree[idx].second + 'A' != '.') {
        inorder(tree[idx].second);
    }
}
void postorder(int idx) {
    if(tree[idx].first + 'A' != '.') {
        postorder(tree[idx].first);
    }
    if(tree[idx].second + 'A' != '.') {
        postorder(tree[idx].second);
    }
    cout<<(char)(idx + 'A');
}
int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        char tmp1, tmp2, tmp3;
        cin>>tmp1>>tmp2>>tmp3;
        tree[tmp1 - 'A'].first = tmp2-'A';
        tree[tmp1 - 'A'].second = tmp3-'A';
    }
    preorder(0);
    cout<<"\n";

    inorder(0);
    cout<<"\n";
    
    postorder(0);
    cout<<"\n";
}