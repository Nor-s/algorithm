#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct NODE {
    int priority;
    int key, size;
    NODE *right, *left;
    NODE(const int& _key): key(_key), priority(rand()), size(1), right(NULL), left(NULL) {}
    void calcSize() {
        size = 1;
        if(right) size+=right->size;
        if(left) size+=left->size;
    }
    void setLeft(NODE* node) {
        left = node;
        calcSize();
    }
    void setRight(NODE* node) {
        right = node;
        calcSize();
    }
};
typedef pair<NODE*, NODE*> CHILDPAIR;

CHILDPAIR split(NODE* root, int key) {
    if(root == NULL) return CHILDPAIR(NULL, NULL);
    if(root->key < key) {
        CHILDPAIR rs = split(root->right, key);
        root->setRight(rs.first);
        return CHILDPAIR(root, rs.second);
    }
    CHILDPAIR ls = split(root->left, key);
    root->setLeft(ls.second);
    return CHILDPAIR(ls.first, root);
}
NODE* insert(NODE* root, NODE* node) {
    if(root == NULL) return node; 
    if(root->priority < node->priority) {
        CHILDPAIR child = split(root, node->key);
        node->setLeft(child.first);
        node->setRight(child.second);
        return node;
    }
    if(root->key < node->key) 
        root->setRight(insert(root->right, node));
    else
        root->setLeft(insert(root->left, node));
    return root;
}
NODE* merge(NODE* left, NODE* right) {
    if(left == NULL) return right;
    if(right == NULL) return left;
    if(left->priority < right->priority) {
        right->setLeft(merge(left, right->left));
        return right;
    }
    left->setRight(merge(left->right, right));
    return left;
}
NODE* erase(NODE* root, int key) {
    if(root == NULL) return NULL;
    if(key == root->key) {
        NODE* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if(key < root->key) {
        root->setLeft(erase(root->left, key));
    }
    else 
        root->setRight(erase(root->right, key));
    return root;
}

NODE* kth(NODE* tree, int k) {
    int leftSize = tree->left == NULL ? 0: tree->left->size;
    if(leftSize + 1 == k) return tree;
    if(leftSize < k) return kth(tree->right, k - leftSize - 1);
    return kth(tree->left, k);
}



int testCase = 0;
int N;
int a, b;
const int MOD = 20090711;

int A(int i, const int* before = NULL)
{
    if(i == 0) return 1983;
    if(before==NULL)
        return ((A(i-1)* (long long)a)%MOD + b )%MOD;
    return (((*before) * (long long)a)%MOD + b )%MOD;
}

int median() {
    int ret = 0;
    int before = 1983;
    NODE* tree = NULL;
    for(int i = 0; i < N; i++) {
        NODE* node = new NODE(A(i, &before));
        tree = insert(tree, node);
        ret =  (ret+kth(tree, i/2 + 1)->key)%MOD;
        before = node->key;
    }
    return ret;
}
//N median... even=> smaller
int main()
{
    cin>>testCase;
    while(testCase--)
    {
        cin>>N>>a>>b;
        cout<<median()<<"\n";
    }
}