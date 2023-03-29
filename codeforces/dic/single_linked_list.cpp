#include<iostream>
#include <vector>

using namespace std;


struct Node {
	Node* next{ nullptr };
	long long num;
	Node(int x) : num(x) {
	}
	void addNext(int x) {
		Node* tmp = new Node(x);
		tmp->next = this->next;
		this->next = tmp;
	}
	void remove() {
		if (this->next) {
			Node* tmp = this->next->next;
			delete next;
			this->next = tmp;
		}
	}
};

Node* find(int index, Node * node) {
	Node * tmp = node->next;
	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	return tmp;
}

void insertNext(Node * node, int x, long long num) {
	find(x, node)->addNext(num);
}
void destroyNext(Node * node, int x) {
	find(x, node)->remove();
}
void change(Node *node, int x, long long y) {
	find(x, node)->num = y;
}
