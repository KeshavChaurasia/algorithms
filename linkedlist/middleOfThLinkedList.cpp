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

int middleOfTheLinkedList(ListNode* head){
	// HEAD 1 --> 2 --> 3 NULL
	// HEAD 1 --> 2 --> 3 --> 4 NULL
	unordered_map<int,int> table;
	ListNode* iterator = head;
	int counter = 0;
	while(iterator != NULL){
		table.insert(make_pair(counter,iterator->data));
		iterator = iterator->next;
		counter++;
	}
	return table[counter/2];
}

int main(){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	cout << middleOfTheLinkedList(node1) << endl;
	return EXIT_SUCCESS;

}
