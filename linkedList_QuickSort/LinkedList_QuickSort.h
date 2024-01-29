#pragma once
#include <iostream>
#include <string>
using namespace std;
class DoubleLinkedList;

class Node {
	friend class DoubleLinkedList;
private:
	Node* next;// 그 다음 노드를 가리키는 포인터 변수
	Node* prev;// 자신의 앞 노드를 가리키는 포인터 편수
	int data;
	
public:
	
	
	Node(Node* n, Node* p, int d) {
		next = n;
		prev = p;
		data = d;
	}
	Node(int d) { next = prev = NULL; data = d; }
};

class DoubleLinkedList {
public:
	DoubleLinkedList();
	DoubleLinkedList(int);
	~DoubleLinkedList(); //소멸자
	Node* getHead();
	void insertHead(int); // 헤드 노드에 삽입하는 멤버 함수
	void insertTail(int); // 꼬리 노드에 삽입하는 멤버 함수
	void insert(int, int); // 노드를 삽입하는 멤버 함수
	void deleteHead(); // 헤드노드를 제거하는 멤버 함수
	void deleteNode(int); // 특정노드를 제거하는 멤버 함수
	void print(); // 클래스 내부의 객체들을 출력해줄 멤버
	int getsize(); //노드의 개수를 불러오는 멤버 함수
	void quick_sort(int,int); //quick sort 멤버함수
private:
	Node* head;
	Node* tail;
	int size;
};

DoubleLinkedList::DoubleLinkedList() {
	tail = head = NULL;
	size = 0;
}
DoubleLinkedList:: DoubleLinkedList(int value) {
	tail = head = new Node(value); //새로운 노드 선언
	size = 1;
}//생성자의 초기화
Node* DoubleLinkedList::getHead() {
	return head;
};

void DoubleLinkedList::insertHead(int value) {
	Node* newNode = new Node(value);// 새로운 노드 선언
	if (head == NULL) {
		tail = head; // 만약 헤드노드가 널일 때, 꼬리노드에 헤드노드를 삽입
	}else {
		newNode->next = head;
		head->prev = newNode;
	}
	head = newNode;
	size++;
}

void DoubleLinkedList::insertTail(int value) {
	Node* newNode = new Node(value); // 새로운 노드 선언
	if (tail == NULL) {
		head = tail; // 꼬리 노드가 널일 때 헤드노드에 꼬리노드 대입
	}else {
		newNode->prev = tail;
		tail->next = newNode;
	}
	tail = newNode;
	size++;
}

void DoubleLinkedList::insert(int index, int value) {
	if (index < 0 || index >= size) {
		cout << "IndexError" << endl;
		return;
	}
	else if (index == 0) {
		insertHead(value); //인덱스가 0일때는 헤드노드 삽입)
	}
	else if (index == size - 1) {
		insertTail(value); // 인덱스가 마지막 노드를 가리킬 때는 테일 노드 삽입
	} else {
		Node* newNode = new Node(value); // 새로운 노드 선언
		Node* cur = head; // 새로운 노드를 선언해 헤드 노드 대입
		int i = 0;
		while (i < index - 1) {//인덱스 노드의 전 노드가 될때까지 반복
			cur = cur->next;
			i++;
		}
		newNode->prev = cur;
		newNode->next = cur->next;
		cur->next = newNode;
		cur->prev = newNode->prev;
	}
	size++;
}



void DoubleLinkedList::deleteHead() {
	if (head != NULL) { // 리스트가 비어있지 않을 경우
		Node* remove = head;
		head = head->next; 
		head->prev = NULL;
		delete remove;
		size--;
	}
}
void DoubleLinkedList::deleteNode(int value) {
	Node* cur1 = head; 
	int i = 0; int j = 0;
	if (cur1->data == value) { 
		deleteHead();
		j++;
		}//헤드 노드에 데이터가 있는 경우 헤드를 삭제
	while (cur1->data != value&&j==0) {
		cur1 = cur1->next;
		i++; 
		if (cur1->data == value || i >= size) {
			cur1 = cur1->prev;
			break;
		}//value의 데이터를 가지고 있는 노드를 찾고 이전 노드로 감
		
	}
	if (cur1->data != value &&  i!= size-1 && j == 0) {// value의 값을 가지고 있는 노드가 중간에 있는 노드 일경우
		cur1->next = cur1->next->next;
		cur1->next->prev = cur1;
	} 
	if (cur1->data != value && i == size-1 && j == 0) {// value의 값을 가지고 있는 노드가 끝에 있는 노드 일경우
		cur1->next = NULL;
	}
}


void DoubleLinkedList::print() {
	Node* cur = head;
	while (cur != NULL) {
		if (cur->next == NULL) {
			cout << cur->data << endl;
		}else {
			cout << cur->data << " " << "<- ->" << " ";
		}
		if(cur!= NULL)
			cur = cur->next;
	}
}

DoubleLinkedList::~DoubleLinkedList() {
	Node* cur = head;
	while (cur != NULL) {
		deleteHead();
	}
}

int DoubleLinkedList::getsize() {
	return size;
	
}


void DoubleLinkedList::quick_sort(int start, int end) {
	Node* cur2 = head;
	Node* cur3 = head;
	
	if (start >= end) {
		// 노드가 1개인 경우
		return; //퀵 정렬 진행 불가
	}

	int pivot = start;
	int i = pivot + 1; // 왼쪽 출발 지점
	int j = end; // 오른쪽 출발 지점
	
	int temp;
	
	
	int data_pivot;
	int k = 1;

	
	while (k < start) { 
		cur3 = cur3->next;
		k++; 
	} // 피봇 데이터가 들어 있는 노드에 접근
	data_pivot = cur3->data;
	cur2 = cur3->next; //출발 지점 노드
	Node* back_cur2 = head;
	k = 1;
	while (k != end) {
		k++;
		if (back_cur2->next != NULL)
			back_cur2 = back_cur2->next;
	}//뒤에서 부터 출발할 노드
	
	while (i <= j) {
		//지점이 엇갈릴때 까지 반복
		while (i <= end && cur2->data <= data_pivot) {
			i++;
			if (cur2->next != NULL)
				cur2 = cur2->next;
		} // 앞에서 부터 출발하여 피봇 데이터 보다 작은 노드를 찾는다.
		while (j > start && back_cur2->data >= data_pivot) {
			j--;
			if (back_cur2->prev != NULL)
				back_cur2 = back_cur2->prev;
		} //뒤에서 부터 출발하여 피봇 데이터 보다 큰 노드를 찾는다.
		if (i > j) {
			// 엇갈림
			temp = back_cur2->data;
			back_cur2->data = data_pivot;
			cur3->data = temp;
			//피보 데이터와 j번째 노드를 스왑
		
		} else {
			//i번쨰와 j번째를 스왑
			temp = cur2->data;
			cur2->data = back_cur2->data;
			back_cur2->data = temp;
		}
		
		print();
	}
	//분할계산(피봇 데이터와 j번째 노드가 스왑 되는 경우 j번째를 기준으로 분할계산)
	quick_sort(start, j - 1);
	quick_sort(j + 1, end);
}
