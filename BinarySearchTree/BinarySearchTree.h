#pragma once
#include <iostream>

using namespace std;



class BinaryTree_Node {
public:
	int key;
	shared_ptr<BinaryTree_Node> right;
	shared_ptr<BinaryTree_Node> left;
	
};

class BinarySearchTree {
public:
	
	void preorder(shared_ptr<BinaryTree_Node> node);
	shared_ptr<BinaryTree_Node> search(shared_ptr<BinaryTree_Node> node, int key);
	shared_ptr<BinaryTree_Node> insert_node(shared_ptr<BinaryTree_Node> node, int key);
	shared_ptr<BinaryTree_Node> new_node(int key);
	shared_ptr<BinaryTree_Node> delete_node(shared_ptr<BinaryTree_Node> root,int key);
	shared_ptr<BinaryTree_Node> max_value_node(shared_ptr<BinaryTree_Node> node);
};




void BinarySearchTree::preorder(shared_ptr<BinaryTree_Node> root) {
	if (root != NULL) {
		cout << (root->key) << " "; //노드 방문
		preorder(root->left); // 왼쪽서브트리 순회
		preorder(root->right); //오른쪽 서브트리 순회
	}
}


//탐색 함수(반복)
shared_ptr<BinaryTree_Node> BinarySearchTree::search(shared_ptr<BinaryTree_Node> root, int key) {
	
	while (root != NULL) {
		if (key == root->key) return root; // 찾으면 해당 노드를 반환
		else if (key < root->key) //노드의 키 값 보다 작을 경우 
			root = root->left;
		else // 노드의 키 값 보다 클 경우
			root = root->right;
	}
	return NULL; // 트리가 공백이면 NULL 반환
}

shared_ptr<BinaryTree_Node> BinarySearchTree::insert_node(shared_ptr<BinaryTree_Node> node,int data) {
	
	//트리가 공백이면 새로운 노드를 반환한다.
	if (node == NULL)
		return new_node(data);
	
	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (data < node->key)
		node->left = insert_node(node->left,data);
	else if (data > node->key)
		node->right = insert_node(node->right,data);
	//변경된 루트 포인터를 반환한다.
	return node;
}

shared_ptr<BinaryTree_Node> BinarySearchTree::new_node(int data) {
	shared_ptr<BinaryTree_Node> newNode = make_shared<BinaryTree_Node>();
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

shared_ptr<BinaryTree_Node> BinarySearchTree::delete_node(shared_ptr<BinaryTree_Node> root, int key) {
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = delete_node(root->left,key);
	else if (key > root->key)
		root->right = delete_node(root->right,key);
	else {
		if (root->left == NULL) {
			shared_ptr<BinaryTree_Node> temp = root->right;
			root.reset();
			return temp;
		}
		else if (root->right == NULL) {
			shared_ptr<BinaryTree_Node> temp = root->left;
			root.reset();
			return temp;
		}
		shared_ptr<BinaryTree_Node> temp = max_value_node(root->left);//왼쪽 서브트리 중 가장 큰 값을 대입한다.

		root->key = temp->key;
		root->left = delete_node(root->left,temp->key);
	}
	return root;
}

shared_ptr <BinaryTree_Node> BinarySearchTree::max_value_node(shared_ptr<BinaryTree_Node> node) {
	shared_ptr<BinaryTree_Node> cur = node;
	while (cur->right != NULL) {
		cur = cur->right;
	}
	return cur;
}