// Singly Linked List
// Operations
// Insert --> Insert At Head , Insert At Tail, Insert At Middlet
// Delete --> Delete Head , Delete Tail, Delete Node At middle
// Search --> Contains
// Count 
// Delete
// peak --> peakHead, peakTail

#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next = NULL;
    friend class SinglyLinkedList;
};
class SinglyLinkedList {
    private:
    ListNode* head;
    public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    // check if linked List is empty
    bool isEmpty();
    // clear
    void clear();
    // count
    int size();
    // insert
    void insertFront(int data);
    void insertBack(int data);
    void insertAt(int data, int index);
    // delete
    void removeFront();
    void removeBack();
    void removeAt(int index);
    // peak
    int peakBack();
    int peakFront();
    // search
    bool contains(int data);
    void printLinkedList(); 
};
SinglyLinkedList::SinglyLinkedList():head(NULL){}
SinglyLinkedList::~SinglyLinkedList(){
    clear();
}
void SinglyLinkedList::clear(){
    while(!isEmpty()){
        removeFront();
    }
}
bool SinglyLinkedList::isEmpty(){
    return (head == NULL);
}
int SinglyLinkedList::size(){
	int count = 0;
	if(!isEmpty()){
		ListNode* iterator = head;
		while(iterator != NULL){
			count++;
			iterator = iterator->next;
		}
	}
	return count;
}

void SinglyLinkedList::insertFront(int data){
    ListNode* newNode = new ListNode;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
void SinglyLinkedList::insertBack(int data){
    if(isEmpty()){
        insertFront(data);
    }
    // create new Node
    ListNode* newNode = new ListNode;
    newNode->data = data;
    // iterate to the last element
    ListNode* iterator = head;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    // set last Nodes next Pointer to new Node
    iterator->next = newNode;
}
void SinglyLinkedList::insertAt(int data, int index){
    // HEAD 1 --> 2 --> 3 --> 4 --> NULL
    //iterate to that position
    ListNode* iterator = head;
    for(int i=0; i < index - 1; i++){
        if(iterator == NULL){
            printf("No Node found at index %d", i);
            break;
        }
        iterator = iterator->next;
    }
    // create new Node
    ListNode* newNode = new ListNode;
    newNode->data = data;
    //insert new Node before the 
    newNode->next = iterator->next;
    iterator->next = newNode;
}
void SinglyLinkedList::removeFront(){
	ListNode* nodeToRemove = head;
	head = nodeToRemove->next;
	delete nodeToRemove;
}
void SinglyLinkedList::removeBack(){
	if(isEmpty()){
		return;
	}
	if(size()==1){
		removeFront();
		return;
	}
	ListNode* iterator = head;
	while(iterator->next->next != NULL){
		iterator = iterator->next;
	}
	ListNode* nodeToRemove = iterator->next;
	// clear next pointer of second
	iterator->next = NULL;
	delete nodeToRemove;
}
void SinglyLinkedList::removeAt(int index){
	if(index > size()){
		printf("%d not found in linked list",index);
		return;
	}
	ListNode* iterator = head;
	for(int i = 0; i < index-1; i++){
		if(iterator == NULL){
			printf("Index not found \n");
			return;
		}
		iterator = iterator->next;
	}
	if(size()==1){
		removeFront();
		return;
	}
	ListNode* temp = iterator;
	ListNode* nodeToRemove = iterator->next;
	temp->next = nodeToRemove->next;
	delete nodeToRemove;
}
void SinglyLinkedList::printLinkedList(){
	string s = "HEAD ";
	ListNode* iterator = head;
	while(iterator != NULL){
		s = s + to_string(iterator->data) + " --> ";
	       	iterator = iterator->next;
	}
	s = s + " NULL";
	cout << s << endl;
}
int SinglyLinkedList::peakFront(){
	if(!isEmpty()){
		return head->data;
	}
	return -1;
}
int SinglyLinkedList::peakBack(){
	if(isEmpty())
		return -1;
	ListNode* iterator = head;
	while(iterator->next != NULL){
		iterator = iterator->next;
	}
	return iterator->data;
}
bool SinglyLinkedList::contains(int data){
	if(isEmpty())
		return false;
	ListNode* iterator = head;
	while(iterator != NULL){
		if(iterator->data == data){
			return true;
		}
		iterator = iterator->next;
	}
	return false;
}

int main(){
	SinglyLinkedList list;
	list.insertFront(1);
	list.insertFront(2);
	list.insertFront(3);
	list.insertFront(4);
	list.printLinkedList();
	list.insertBack(0);
	list.printLinkedList();
	list.insertFront(7);
	list.insertAt(5,0);
	list.insertAt(6,0);
	list.printLinkedList();
	list.removeBack();
	list.printLinkedList();
	list.removeFront();
	list.printLinkedList();
	list.removeAt(1);
	list.printLinkedList();
	cout << list.peakFront() << endl;
	cout << list.peakBack() << endl;
	cout << list.contains(0) << endl;
	return EXIT_SUCCESS;
}
