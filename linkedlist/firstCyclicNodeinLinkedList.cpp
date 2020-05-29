// Check whether the given linked list is NULL-terminated or not. If there is a cycle find the start node of the loop.

#include<bits/stdc++.h>
using namespace std;

class ListNode {
        public:
                int data;
                ListNode* next;
                ListNode(int data){
                        this->data = data;
                        this->next = NULL;
                }
};

int firstCyclicNodeInLinkedList(ListNode* head){
	if(head == NULL){
		return -1;
	}
	ListNode* fastPointer = head->next;
	ListNode* slowPointer = head;
	bool isCyclic = false;
	while(fastPointer != NULL && fastPointer->next != NULL && slowPointer != NULL){
		if(fastPointer == slowPointer){
			isCyclic = true;
			break;
		}
		fastPointer = fastPointer->next->next;
		slowPointer = slowPointer->next;
	}
	int counter = 10;
	if(isCyclic){
		// since we are setting slowpointer to head and head represents first node
		// we also need to seet fastPointer to next Node because
		// after meeting slowpointer and fastpointer slowpointer
		// in actual head->next refers firstNode but in our case head represents firstNode
		// and that's why
		slowPointer = head;
		fastPointer = fastPointer->next;
		while(fastPointer != slowPointer){
			fastPointer = fastPointer->next;
			slowPointer = slowPointer->next;
		}
		return slowPointer->data;
	}
	return -1;
}

int main(){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;
	ListNode* terminatedHead = node1;

	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);
	ListNode* node8 = new ListNode(8);
	ListNode* node9 = new ListNode(9);
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = node6;
	ListNode* cyclicHead = node4;

	cout << firstCyclicNodeInLinkedList(terminatedHead) << endl;
	cout << firstCyclicNodeInLinkedList(cyclicHead) << endl;
	return EXIT_SUCCESS;
}
