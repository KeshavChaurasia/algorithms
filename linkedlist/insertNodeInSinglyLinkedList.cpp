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


void addNode(int data, ListNode* beforeNode){
    ListNode* newNode = new ListNode(data);
    newNode->next = beforeNode->next;
    beforeNode->next = newNode;
}

int main(){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;
	ListNode* terminatedHead = node1;
    addNode(4, node2);
    return EXIT_SUCCESS;
}