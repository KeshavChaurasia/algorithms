// You are given two linked-lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.

// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next = NULL;
    ListNode(){}
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Solution{
   public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
      ListNode* results = NULL;
      ListNode* tempNode = NULL;
      ListNode* prevNode = NULL;
      int carry = 0;
      int a;
      int b;
      while(l1 != NULL || l2 != NULL){
         if(l1 != NULL){
            a = l1->val;
         }
         else {
            a = 0;
         }
         if(l2 != NULL){
            b = l2->val;
         }
         else {
            b = 0;
         }

         int sum = carry + a + b;
         carry = sum / 10;
         sum = sum % 10;
         
         tempNode = new ListNode(sum);

         if(results == NULL){
            results = tempNode;
         }else {
            prevNode->next = tempNode;
         }
         prevNode = tempNode;

         if(l1 != NULL){
            l1 = l1->next;
         }
         if(l2 != NULL){
            l2 = l2->next;
         }
      }
      if (carry > 0){
         prevNode->next = new ListNode(carry);
      }
      return results;
   }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode* results;
    Solution s;
    results = s.addTwoNumbers(l1,l2);
    while(results != NULL){
       cout << results->val << "\t";
       results = results->next;
    }
    cout << endl;
    return EXIT_SUCCESS;
}


