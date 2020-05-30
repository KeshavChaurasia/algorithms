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

void printReversedLinkedList(ListNode* node){
	if(node == NULL){
		return;
	}
	printReversedLinkedList(node->next);
	cout << node->data << " ";
}

int main(){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;
	printReversedLinkedList(node1);
	return EXIT_SUCCESS;
}
