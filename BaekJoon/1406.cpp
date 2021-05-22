#include <iostream>
#include <vector>
#include <string>

using namespace std;

string inputString;
int m;

class linkedList {
    struct node {
        char c;
        node* right; 
        node* left;
        node(char _c, node* _lp = nullptr, node* _rp = nullptr): c(_c), left(_lp), right(_rp) {
            if(left != nullptr) left->right = this;
            if(right != nullptr) right->left = this;
        }
        void erase() {
            if(right != nullptr) right->left = left; 
            if(left != nullptr) left->right = right;
        }
    };

    node* header;
    node* tail;
    node* nodePointer;
    int size;

public:
    linkedList() {
        size = 0;
        header = nullptr;
        tail = nullptr;
        nodePointer = header;
    }
    void push(char _c) {
        if(header == nullptr) {
            header = new node(_c);
            tail = header;
        }
        else {
            tail = new node(_c, tail);
        }
        size++;
    }
    void pointerToRight() {
        nodePointer = tail;
    }
    void insertToPointer(char _c) {
        if(header == nullptr){
            push(_c);
            return;
        }
        if(nodePointer == nullptr) {
            nodePointer = new node(_c, nullptr, header);
            header = nodePointer;
        }
        else {
            nodePointer = new node(_c, nodePointer, nodePointer->right);
        }
    }
    void pop() {
        node* tmp = nodePointer;
        if(!toLeft()) {
            return;
        }
        if(tmp == header) {
            if(header->right == nullptr) {
                header = nullptr;
            }
            else
            header = header->right;
        }
        tmp->erase();
        delete tmp;
        size--;
    }
    bool toLeft() {
        if(nodePointer == nullptr)
            return false;
        nodePointer = nodePointer->left;
        return true;
    }
    bool toRight() {
        if(nodePointer == nullptr) {
            nodePointer = header;
            return true;
        }
        if(nodePointer->right == nullptr)
            return false;
        nodePointer = nodePointer->right;
        return true;
    }
    void print() {
        node* p = header;
        if(p == nullptr) {
            cout<<" ";
            return;
        }
        while(p!= nullptr) {
            cout<<p->c;
            p = p->right; 
        }
        cout<<"\n";
    }
};


int main() {
    linkedList L;
    char c;
    while((c = getchar()) != '\n') {
        L.push(c);
    }
    cin>>m;
    L.pointerToRight();

    for(int i = 0; i < m; i++) {
        char tmp;
        cin>>tmp;
        if(tmp == 'P') {
            cin>>tmp;
            L.insertToPointer(tmp);
        }
        else if(tmp == 'L') {
            L.toLeft();
        }
        else if(tmp == 'D') {
            L.toRight();
        }
        else if(tmp == 'B') {
            L.pop();
        }
    }
    L.print();
}