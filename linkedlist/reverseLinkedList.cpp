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

void printLinkedList(ListNode* head){
    ListNode* iterator = head;
    string s = "HEAD ";
    while(iterator != NULL){
        s = s + to_string(iterator->data) + " --> ";
        iterator = iterator->next;
    }
    s = s + " END";
    cout << s << endl;
}

ListNode* reverseLinkedListNaive(ListNode* head){
    ListNode* currNode = head;
    ListNode* prevNode = NULL;
    while(currNode != NULL){
        ListNode* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}
int main(){
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
    printLinkedList(node1);
    ListNode* reversedHead = reverseLinkedListNaive(node1);
    cout << "link list reversed" << endl;
    printLinkedList(reversedHead);
    return EXIT_SUCCESS;
}