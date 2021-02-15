#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

typedef int keyType;
struct Node {
	keyType key;
	int priority, size;
	Node* left;
	Node* right;

	// priority를 random으로 설정
	Node(const keyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}

	void setLeft(Node* newLeft) {
		left = newLeft;
		calcSize();
	}
	void setRight(Node* newRight) {
		right = newRight;
		calcSize();
	}
	
	// size 초기화
	void calcSize() {
		size = 1; // 자기자신
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

typedef pair<Node*, Node*> Nodepair;
Nodepair split(Node* root, keyType key) {
	if (root == NULL) return Nodepair(NULL, NULL);
	if (root->key < key) {
		Nodepair rs = split(root->right, key);
		root->setRight(rs.first);
		return Nodepair(root, rs.second);
	}
	Nodepair ls = split(root->left, key);
	root->setLeft(ls.second);
	return Nodepair(ls.first, root);
}
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		Nodepair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	}
	else root->setRight(insert(root->right, node));
	return root;
}

Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}
Node* erase(Node* root, keyType key) {
	if (root == NULL) return root;
 	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key) root->setLeft(erase(root->left, key));
	else root->setRight(erase(root->right, key));
	return root;
}
Node* kth(Node* root, int k) {
	int leftsize = 0;
	if (root->left != NULL) leftsize = root->left->size;
	if (k <= leftsize) return kth(root->left, k);
	if (k == leftsize + 1) return root; 
	return kth(root->right, k - leftsize - 1);
}
int countLessThan(Node* root, keyType key) {
	if (root == NULL) return 0;
	if (root->key >= key) {
		return countLessThan(root->left, key);
	}
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}
