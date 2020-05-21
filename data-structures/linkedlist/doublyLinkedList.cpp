// Doubly Linked List 
//
// HEAD <--> 1 <--> 2 <--> 3 <--> 4 <--> TAIL
#include<bits/stdc++.h>
using namespace std;

class ListNode{
	public:
	int data;
	ListNode* next;
	ListNode* prev;
	friend class DoublyLinkedList;
};
class DoublyLinkedList{
	private:
		ListNode* head;
		ListNode* tail;
		void insertBefore(ListNode* beforeNode, int data);
		void remove(ListNode* removeNode);
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		
		int size();
		bool isEmpty();
		void clear();

		void insertFront(int data);
		void insertBack(int data);
		void insertAt(int data, int index);

		void removeFront();
		void removeBack();
		void removeAt(int index);

		int peakFirst();
		int peakBack();

		bool contains(int data);

		void printLinkedList();
};
DoublyLinkedList::DoublyLinkedList(){
	head = new ListNode;
	tail = new ListNode;
	head->next = tail;
	tail->prev = head;
}
DoublyLinkedList::~DoublyLinkedList(){
	clear();
}
bool DoublyLinkedList::isEmpty(){
	return (head->next==tail);
}
void DoublyLinkedList::clear(){
	while(!isEmpty()){
		removeFront();
	}
}
void DoublyLinkedList::removeFront(){
	remove(head->next);
}
void DoublyLinkedList::removeBack(){
	remove(tail->prev);
}

void DoublyLinkedList::remove(ListNode* nodeToRemove){
	nodeToRemove->prev->next = nodeToRemove->next;
	nodeToRemove->next->prev = nodeToRemove->prev;
	delete nodeToRemove;
}
void DoublyLinkedList::removeAt(int index){
	ListNode* iterator = head->next;
	for(int i = 0; i < index; i++){
		if(iterator == tail){
			printf("%d not found\n",index);
			return;
		}
		iterator = iterator->next;
	}
	cout << iterator->data << endl;
	remove(iterator);
}
void DoublyLinkedList::insertBefore(ListNode* beforeNode, int data){
	ListNode* newNode = new ListNode;
	newNode->data = data;
	newNode->prev = beforeNode->prev;
	newNode->next = beforeNode;
	beforeNode->prev->next = newNode;
	beforeNode->prev = newNode;
}
void DoublyLinkedList::insertFront(int data){
	insertBefore(head->next, data);
}
void DoublyLinkedList::insertBack(int data){
	insertBefore(tail, data);
}
void DoublyLinkedList::printLinkedList(){
	string s = "HEAD ";
	ListNode* iterator = head->next;
	while(iterator!=tail){
		s = s + to_string(iterator->data) + " <--> ";
		iterator = iterator->next;
	}
	s  = s + "TAIL";
	cout << s << endl;
}
int DoublyLinkedList::peakFirst(){
	if(!isEmpty()){
		return head->next->data;
	}
	return -1;
}
int DoublyLinkedList::peakBack(){
	if(!isEmpty()){
		return tail->prev->data;
	}
	return -1;
}
bool DoublyLinkedList::contains(int data){
	ListNode* iterator = head->next;
	while(iterator != tail){
		if(iterator->data == data){
			return true;
		}
		iterator = iterator->next;
	}
	return false;
}
int main(){
	DoublyLinkedList list;
	list.insertFront(2);
	list.insertFront(3);
	list.insertBack(1);
	list.insertBack(0);
	list.printLinkedList();
	list.removeFront();
	list.removeBack();
	list.printLinkedList();
	list.removeAt(1);
	list.printLinkedList();
	cout << list.peakBack() << endl;
	return EXIT_SUCCESS;
}

