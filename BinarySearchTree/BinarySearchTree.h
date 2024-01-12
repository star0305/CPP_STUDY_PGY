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
		cout << (root->key) << " "; //��� �湮
		preorder(root->left); // ���ʼ���Ʈ�� ��ȸ
		preorder(root->right); //������ ����Ʈ�� ��ȸ
	}
}


//Ž�� �Լ�(�ݺ�)
shared_ptr<BinaryTree_Node> BinarySearchTree::search(shared_ptr<BinaryTree_Node> root, int key) {
	
	while (root != NULL) {
		if (key == root->key) return root; // ã���� �ش� ��带 ��ȯ
		else if (key < root->key) //����� Ű �� ���� ���� ��� 
			root = root->left;
		else // ����� Ű �� ���� Ŭ ���
			root = root->right;
	}
	return NULL; // Ʈ���� �����̸� NULL ��ȯ
}

shared_ptr<BinaryTree_Node> BinarySearchTree::insert_node(shared_ptr<BinaryTree_Node> node,int data) {
	
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (node == NULL)
		return new_node(data);
	
	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (data < node->key)
		node->left = insert_node(node->left,data);
	else if (data > node->key)
		node->right = insert_node(node->right,data);
	//����� ��Ʈ �����͸� ��ȯ�Ѵ�.
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
		shared_ptr<BinaryTree_Node> temp = max_value_node(root->left);//���� ����Ʈ�� �� ���� ū ���� �����Ѵ�.

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