#include <iostream>
#include "doubly_linked_list.h"
#include "quick_sort.h"
using namespace std;


int main() {
	DoubleLinkedList* list = new DoubleLinkedList();
	list->insertHead(4);
	list->insertHead(10);
	list->insertHead(6); 
	list->insertHead(1);
	list->insertHead(9);
	list->insertHead(7);
	list->insertHead(3);
	list->insertHead(2);
	list->insertHead(8);
	list->insertHead(5);
	

	list->print();
	
	
	list->quick_sort(1,10);
	
}
