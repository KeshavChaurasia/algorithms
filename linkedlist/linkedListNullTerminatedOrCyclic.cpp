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


// returns 0 for null terminated and 1 for cyclic
// O(N) time | O(1) space complexity
bool linkedListNullTerminatedOrCyclicNaive(ListNode* head){
	unordered_set<ListNode*> table;
	ListNode* iterator = head;
	while(true){
		if(iterator == NULL){
			return false;
		}
		if(table.find(iterator) != table.end()){
			return true;
		}
		table.insert(iterator);
		iterator = iterator->next;
	}
	return false;
}	
// O(N) time | O(1) space complexity
bool linkedListNullTerminatedOrCyclic(ListNode* head){
	if(head == NULL){
		return false;
	}
	ListNode* fastPointer = head->next;
	ListNode* slowPointer = head;
	while(fastPointer != NULL && fastPointer->next != NULL && slowPointer != NULL){
		if(fastPointer == slowPointer){
			return true;
		}
		fastPointer = fastPointer->next->next;
		slowPointer = slowPointer->next;
	}
	return false;
	
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

	cout << linkedListNullTerminatedOrCyclicNaive(terminatedHead) << endl;
	cout << linkedListNullTerminatedOrCyclicNaive(cyclicHead) << endl;
	
	cout << linkedListNullTerminatedOrCyclic(terminatedHead) << endl;
	cout << linkedListNullTerminatedOrCyclic(cyclicHead) << endl;
	return EXIT_SUCCESS;
}
