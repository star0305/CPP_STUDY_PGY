#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
	shared_ptr<BinaryTree_Node> root1 = NULL;
	BinarySearchTree ex;
	
	root1 = ex.insert_node(root1, 20);
	root1 = ex.insert_node(root1, 30);
	root1 = ex.insert_node(root1, 40);
	root1 = ex.insert_node(root1, 70);
	root1 = ex.insert_node(root1, 10);
	root1 = ex.insert_node(root1, 60);

	

	cout << "이진 탐색트리 전위 순회 결과\n";
	ex.preorder(root1);

	if (ex.search(root1,20) != NULL)
		cout << "\n이진 탐색 트리에서 20을 발견함\n";
	else
		cout << "\n이진 탐색 트리에서 20을 발견못함\n";

	root1 = ex.delete_node(root1,40);
	
	cout << "이진 탐색트리 전위 순회 결과\n";
	ex.preorder(root1);


}
