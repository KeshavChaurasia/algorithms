// in circular linked list we track tail instead of cursor for easy coding
// Circular Linked list has 5 special functions
// add()
// remove()
// front()
// back()
// advance()

#include<bits/stdc++.h>
using namespace std;

class ListNode {
	public:
		int data;
		ListNode* next;
	friend class CircularLinkedList;
};
class CircularLinkedList {
	private:
		ListNode* cursor;
	public:
		CircularLinkedList();
		~CircularLinkedList();

		void insert(int data);
		void remove();
		void advance();
		int front();
		int back();

		void clear();
		int size();
		bool isEmpty();
		bool contains();

		void printLinkedList();
		
};
CircularLinkedList::CircularLinkedList():cursor(NULL){}

CircularLinkedList::~CircularLinkedList(){
	clear();
}
void CircularLinkedList::clear(){
	while(!isEmpty()){
		remove();
	}
}
bool CircularLinkedList::isEmpty(){
	return (cursor == NULL);
}
int CircularLinkedList::back(){
	if(!isEmpty()){
		return cursor->data;
	}
	return -1;
}
int CircularLinkedList::front(){
	if(!isEmpty()){
		return cursor->next->data;
	}
	return -1;
}
void CircularLinkedList::advance(){
	cursor = cursor->next;
}

void CircularLinkedList::insert(int data){
	ListNode* newNode = new ListNode;
	newNode->data = data;
	if(cursor == NULL){
		newNode->next = newNode;
		cursor = newNode;
	}
	else {
		newNode->next = cursor->next;
		cursor->next = newNode;
		//cursor = newNode;
	}
}

void CircularLinkedList::remove(){
	ListNode* nodeToRemove = cursor->next;
	if(nodeToRemove == cursor){
		cursor = NULL;
	}
	else {
		cursor->next = nodeToRemove->next;
	}
	delete nodeToRemove;
}
void CircularLinkedList::printLinkedList(){
	if(isEmpty()){
		printf("Circular linked list empty");
		return;
	}
	string s = "";
	ListNode* iterator = cursor->next;
	if(iterator != NULL){
		do {
			s = s + to_string(iterator->data) + " --> ";
			iterator = iterator->next;
		}while(iterator != cursor->next);
	}
	s = s + "CURSOR";
	cout << s << endl;

}
int main(){
	CircularLinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	cout << list.front() << endl;
	cout << list.back() << endl;
	list.printLinkedList();
	return EXIT_SUCCESS;
}

