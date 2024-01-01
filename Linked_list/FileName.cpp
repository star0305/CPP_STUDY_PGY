#include <iostream>

using namespace std;

//node class (data&nextNode�� ����)
class LinkedList_Node {
public:
	int data;
	LinkedList_Node* nextNode;
};

//LinkedList class ����
class LinkedList {
private:
	LinkedList_Node* head;
	LinkedList_Node* tail;

public:
	LinkedList() {
		//head�� tail�� ������ �ʱ�ȭ
		head = NULL;
		tail = NULL;
	}

	//ù ��°�� node �߰�
	void addFrontNode(int x) {
		LinkedList_Node* temp = new LinkedList_Node;
		//temp�� �����ʹ� x
		temp->data = x;

		//LinkedList�� ������� ���
		if (head == NULL && tail == NULL) {
			// ù node�� temp
			head = temp;
			//������ node�� temp
			tail = temp;
		}
		//LinkedList�� �����Ͱ� ���� ���
		else {
			temp->nextNode = head;
			//head�� temp 
			head = temp;
		}
	}

	//�������� node �߰�
	void addNode(int x) {
		LinkedList_Node* temp = new LinkedList_Node;

		//temp�� �����ʹ� x
		temp->data = x;
		//temp�� nextNode = NULL��
		temp->nextNode = NULL;

		//LinkedList �� ��� �ִ� ���
		if (head == NULL && tail == NULL) {
			//ù node�� temp
			head = temp;
			//������ node�� temp
			tail = temp;
		}
		//LinkedList�� �����Ͱ� �ִ� ���
		else {
			//���� ������node�� nextNode�� temp
			tail->nextNode = temp;
			//������ node�� temp
			tail = temp;
		}
	}

	//node ����
	void insertNode(LinkedList_Node* prevNode, int x) {
		LinkedList_Node* temp = new LinkedList_Node;
		//temp�� ���̾�� x
		temp->data = x;

		//temp�� nextNode����
		//(���� �� ���� node�� nextNode�� tmep�� nextNode�� ����)
		temp->nextNode = prevNode->nextNode;

		//temp ����
		//temp ���� node�� nextNode�� temp�� ����
		prevNode->nextNode = temp;
	}

	//node ����
	void deleteNode(LinkedList_Node* prevNode) {
		// ������ node�� temp�� ����
		// (������ node�� ���� node�� nextNode)
		LinkedList_Node* temp = prevNode->nextNode;

		//������ node�� ���� 
		//(������ node�� nextNode�� ���� node�� nextNode�� ����)
		prevNode->nextNode = temp->nextNode;

		//temp ����
		delete temp;
	}

	//ù ��° ��� ��������
	LinkedList_Node* getHead() {
		return head;
	}
	//LinkedList ���
	void printLinkedList(LinkedList_Node* head) {
		if (head == NULL) {
			cout << "\n";
		}
		else {
			cout << head->data << " ";
			printLinkedList(head->nextNode);
		}
		cout << endl;
	}
};










//���� �Լ�
int main() {
	LinkedList ex;

	//0�߰�
	ex.addNode(0);
	//1�߰�
	ex.addNode(1);
	//2�߰�
	ex.addNode(2);

	//printLinkedList
	cout << "0,1,2�� LinkedList�� �߰� \n";
	ex.printLinkedList(ex.getHead());

	//-1�� ���� �տ� �߰�
	ex.addFrontNode(-1);

	//3�� �׹�°�� �߰�
	ex.insertNode(ex.getHead()->nextNode->nextNode, 3);
	cout << "-1�� ù��°�� �߰�, 3�� �׹�°�� �߰�\n";
	ex.printLinkedList(ex.getHead());

	//����° ��� ���� 
	ex.deleteNode(ex.getHead()->nextNode);

	//printLinkedList
	cout << "���� ° ��带 ����\n";
	ex.printLinkedList(ex.getHead());


}
