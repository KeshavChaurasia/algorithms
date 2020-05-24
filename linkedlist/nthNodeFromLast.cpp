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
// O(N) time | O(1) space
int nthNodeFromLastNaive(ListNode* head, int n){
	int count = 0;
	// base case check
	ListNode* iterator = head;
	while(iterator != NULL){
		count++;
		iterator = iterator->next;
	}
	if(count < n ){
		return -1;
	}
	if(count == n){
		return head->data;
	}
	iterator = head;
	for(int i = 0; i < count-n; i++){
		iterator = iterator->next;
	}
	return iterator->data;
}
// O(N) time | O(N) space
int nthNodeFromLast(ListNode* head, int n){
	unordered_map<int,int> table;
	ListNode* iterator = head;
	int count = 0;
	while(iterator != NULL){
		table.insert(make_pair(count,iterator->data));		
		count++;
		iterator = iterator->next;
	}
	if(count < n){
		return -1;
	}
	if(count == n){
		return head->data;
	}
	return table[count-n];

}
int nthNodeFromLastUsingTwoPointers(ListNode* head, int n){
	ListNode* iterator = head;
	ListNode* temp = head;
	for(int i = 0; i < n; i++){
		if(iterator == NULL){
			printf("Not enough nodes to traverse");
			return -1;
		}
		iterator = iterator->next;
	}
	while(iterator != NULL){
		iterator = iterator->next;
		temp = temp->next;
	}
	return temp->data;
}
int main(){
	// setting up linked list;
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	ListNode* head = node1;
	int n = 3;
	int nthNode = nthNodeFromLastNaive(head, n);
	cout << nthNode << endl;
	nthNode = nthNodeFromLast(head, n);
	cout << nthNode << endl;
	nthNode = nthNodeFromLastUsingTwoPointers(head,n);
	cout << nthNode << endl;
	return EXIT_SUCCESS;
}
