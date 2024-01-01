#include <iostream>

using namespace std;

//노드 클래스 구현 (data값과 nextNode가 존재)
class LinkedList_Node {
public:
	int data;
	LinkedList_Node* nextNode;
};

//링크드 리스트 클래스 생성
class LinkedList {
private:
	LinkedList_Node* head;
	LinkedList_Node* tail;
public:
	LinkedList() {
		//head와 tail의 포인터를 초기화;
		head = NULL;
		tail = NULL;
	}
	//첫 번째의 node 추가
	void addFrontNode(int n);
	//마지막의 node 추가
	void addNode(int n);

	//node 삽입
	void insertNode(LinkedList_Node* prevNode, int n);
	//node 삭제
	void deleteNode(LinkedList_Node* prevNode);

	//첫 번째 노드 가져오기
	LinkedList_Node* getHead() {
		return head;
	}
	//LinkedList 출력
	void printLinkedList(LinkedList_Node* head);
};


//첫 번째의 node 추가
void LinkedList::addFrontNode(int n) {
	LinkedList_Node* temp = new LinkedList_Node;
	//temp의 데이터는 n
	temp->data = n;

	//LinkedList가 비어 있으면
	if (head == NULL) {
		// 첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		temp->nextNode = head;
		//head는 temp 
		head = temp;
	}
}

//마지막의 node 추가
void LinkedList::addNode(int n) {
	LinkedList_Node* temp = new LinkedList_Node;

	//temp의 데이터는 n
	temp->data = n;
	//temp의 nextNode = NULL값
	temp->nextNode = NULL;

	//LinkedList 가 비어 있으면
	if (head == NULL && tail == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		//현재 마지막node의 nextNode는 temp
		tail->nextNode = temp;
		//마지막 node는 temp
		tail = temp;
	}
}

//noed 삽입
void LinkedList::insertNode(LinkedList_Node* prevNode, int n) {
	LinkedList_Node* temp = new LinkedList_Node;
	//temp의 데이어는 n
	temp->data = n;

	//temp의 nextNode저장
	//(삽입 할 앞 node의 nextNode를 tmep의 nextNode에 저장)
	temp->nextNode = prevNode->nextNode;

	//temp 삽입
	//temp앞의 node의 nextNode를 temp로 저장
	prevNode->nextNode = temp;
}

//node 삭제
void LinkedList::deleteNode(LinkedList_Node* prevNode) {
	// 삭제할 node를 temp에 저장
	// (삭제할 node의 1단계 전 node의 nextNode)
	LinkedList_Node* temp = prevNode->nextNode;

	//삭제할 node를 제외 
	//(삭제할 node의 nextNode를 1단계 전 node의 전 nextNode에 저장)
	prevNode->nextNode = temp->nextNode;

	//temp 삭제
	delete temp;
}


//LinkedList 출력
void LinkedList::printLinkedList(LinkedList_Node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		printLinkedList(head->nextNode);
	}
	cout << endl;
}

//메인 함수
int main() {
	LinkedList ex;

	//0추가
	ex.addNode(0);
	//1추가
	//ex.addNode(1);
	//2추가
	//ex.addNode(2);

	//printLinkedList
	cout << "0,1,2를 LinkedList에 추가 \n";
	ex.printLinkedList(ex.getHead());

	//-1을 제일 앞에 추가
	ex.addFrontNode(-1);

	//3을 네번째에 추가
	//ex.insertNode(ex.getHead()->nextNode->nextNode->nextNode, 3);
	cout << "-1을 첫번째에 추가, 3을 네번재에 추가\n";
	ex.printLinkedList(ex.getHead());

	//세번째 노드 삭제 
	//ex.deleteNode(ex.getHead()->nextNode->nextNode);

	//printLinkedList
	cout << "세번 째 노드를 삭제\n";
	ex.printLinkedList(ex.getHead());


}