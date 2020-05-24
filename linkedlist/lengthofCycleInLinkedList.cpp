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

int lengthOfCycleInLinkedList(ListNode* head){
	if(head == NULL){
		return 0;
	}
	// using floyd's cycle detection algorithms
	ListNode* fastPtr = head->next;
	ListNode* slowPtr = head;
	bool isCyclic = false;
	int counter = 0;
	while(fastPtr && slowPtr && fastPtr->next){
		if(fastPtr == slowPtr){
			isCyclic = true;
			break;
		}
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
	}
	if(isCyclic){
		fastPtr = fastPtr->next;
		while(fastPtr != slowPtr){
			counter++;
			fastPtr = fastPtr->next;
		}
	}
	return counter+1;
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

	cout << lengthOfCycleInLinkedList(terminatedHead) << endl;
	cout << lengthOfCycleInLinkedList(cyclicHead) << endl;

	return EXIT_SUCCESS;

}
