#include <iostream>
using namespace std;
//메인 함수
int main() {
	LinkedList ex;

	//0추가
	ex.addNode(0);
	//1추가
	ex.addNode(1);
	//2추가
	ex.addNode(2);

	//printLinkedList
	cout << "0,1,2를 LinkedList에 추가 \n";
	ex.printLinkedList(ex.getHead());

	//-1을 제일 앞에 추가
	ex.addFrontNode(-1);

	//3을 네번째에 추가
	ex.insertNode(ex.getHead()->nextNode->nextNode, 3);
	cout << "-1을 첫번째에 추가, 3을 네번째에 추가\n";
	ex.printLinkedList(ex.getHead());

	//세번째 노드 삭제 
	ex.deleteNode(ex.getHead()->nextNode);

	//printLinkedList
	cout << "세번 째 노드를 삭제\n";
	ex.printLinkedList(ex.getHead());


}
