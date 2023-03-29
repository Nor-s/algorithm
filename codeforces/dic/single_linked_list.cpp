#include<iostream>
#include <vector>

using namespace std;

struct Node {
	Node* next{ nullptr };
	int num;
	Node(int x) : num(x) {
	}
	void addNext(int x) {
		Node* tmp = new Node(x);
		tmp->next = this->next;
		this->next = tmp;
	}
	void removeNext() {
		if (next) {
			Node* tmp = this->next->next;
			delete next;
			next = tmp;
		}
	}
};

void insert(Node * node, int x, int numsize, int numbers[]) {
	Node* tmp = node;
	while (x--) {
		tmp = tmp->next;
	}
	while (numsize--) {
		tmp->addNext(numbers[numsize]);
	}
}
void destroy(Node * node, int x, int y) {
	Node* tmp = node;
	while (x--) {
		tmp = tmp->next;
	}
	while (y--) {
		tmp->removeNext();
	}
}
void push_back(Node* node, int y, int numbers[]) {
	Node* tmp = node;
	while (tmp->next) {
		tmp = tmp->next;
	}
	insert(tmp, 0, y, numbers);
}

int main(int argc, char** argv)
{
	Node * root = new Node(-1);
	std::vector<int> d{ 1, 2, 3 };
	Node* tmp = root;
	for (int i = 0; i < d.size(); i++) {
		tmp->addNext(d[i]);
		tmp = tmp->next;
	}
	tmp = root;
	insert(root, 0, 3, std::vector<int>({ 3, 3, 3 }).data());
	tmp = root;
	add(root, 3, std::vector<int>({ 1,1, 1 }).data());

	while (tmp) {
		cout << tmp->num<<" ";
		tmp = tmp->next;
	}
	cout << "\n";
}
