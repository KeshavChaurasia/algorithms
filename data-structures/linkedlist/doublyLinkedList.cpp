#include<bits/stdc++.h>
using namespace std;

class Node{
   private:
   int data;
   Node* head=NULL;
   Node* tail=NULL;
   friend class DoublyLinkedList;
};

class DoublyLinkedList{
   private:
   int size = 0;
   Node* head;
   Node* tail;
   public:
   DoublyLinkedList();
   ~DoublyLinkedList();
};

DoublyLinkedList::DoublyLinkedList(){
   head=NULL;
   tail=NULL;
}
DoublyLinkedList::~DoublyLinkedList(){
   
}
int main(){
   DoublyLinkedList dll;
   return 0;
}