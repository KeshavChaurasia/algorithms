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

// O(N) time | O(N) space
// uses O(N) space to create hash table
int findMergePointUsingHash(ListNode* head1, ListNode* head2){
    unordered_set<ListNode*> table;
    ListNode* iterator = head1;
    while(iterator != NULL){
        table.insert(iterator);
        iterator = iterator->next;
    }
    iterator = head2;
    while(iterator != NULL){
        if(table.find(iterator)!= table.end()){
           return iterator->data; 
        }
        iterator = iterator->next;
    }
    return -1;
}

// uses stack to find merge point in linked list
// O(N) time | O(N) space
// needs to store in stack
int findMergePointusingStack(ListNode* head1, ListNode* head2){
    stack<ListNode*> stack1;
    stack<ListNode*> stack2;
    ListNode* iterator = head1;
    while(iterator != NULL){
        stack1.push(iterator);
        iterator = iterator->next;
    }
    iterator = head2;
    while(iterator != NULL){
        stack2.push(iterator);
        iterator = iterator->next;
    }
    ListNode* prevNode = NULL;
    while(!stack1.empty() || !stack2.empty()){
        ListNode* tempNode1 = stack1.top();
        ListNode* tempNode2 = stack2.top();
        if(tempNode1 != tempNode2){
            if(prevNode == NULL){
                return -1;
            }
            return prevNode->data;
        }
        else {
            prevNode = tempNode1;
            stack1.pop();
            stack2.pop();
        }
    }
    return -1;
}

int main(){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(5);
	ListNode* node4 = new ListNode(7);
	ListNode* node5 = new ListNode(8);
	ListNode* node6 = new ListNode(9);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
    printLinkedList(node1);

	ListNode* node7 = new ListNode(2);
	ListNode* node8 = new ListNode(4);
	ListNode* node9 = new ListNode(6);
	node7->next = node8;
	node8->next = node9;
	node9->next = node4;
    printLinkedList(node7);
    cout << findMergePointUsingHash(node1,node7) << endl;
    cout << findMergePointusingStack(node1,node7) << endl;

    return EXIT_SUCCESS;
}