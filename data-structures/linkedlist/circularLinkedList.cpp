#include<bits/stdc++.h>
using namespace std;

class Node{
   private:
   int data;
   Node* next;
   friend class CircularLinkedList;
};

class CircularLinkedList{
   private:
   int size;
   Node* cursor;
   public:
   CircularLinkedList();
   ~CircularLinkedList();
   bool empty();
   int front();
   int back();
   void advance();
   void add(int elem);
   void remove();
};
// constructor
CircularLinkedList::CircularLinkedList(){
   cursor = NULL;
}

// deconstructor
CircularLinkedList::~CircularLinkedList(){
   while(!this->empty()){
      this->remove();
   }
}

bool CircularLinkedList::empty(){
   return this->cursor == NULL;
}

int CircularLinkedList::front(){
   while(!this->empty()){
      return (this->cursor->next->data);
   }
   return -1;
}

int CircularLinkedList::back(){
   while(!this->empty()){
      return (this->cursor->data);
   }
   return -1;
}

void CircularLinkedList::advance(){
   cursor = cursor->next;
}

void CircularLinkedList:: remove(){
   Node* old = cursor->next;
   if(old == cursor){
      cursor = NULL;
   }else{
      cursor->next = old->next;
      delete old;
   }

}

void CircularLinkedList::add(int elem){
   Node* node = new Node;
   node->data = elem;
   if(cursor == NULL){
      node->next = node;
      cursor = node;
   }
   else {
      node->next = cursor->next;
      cursor->next = node;
   } 

}
int main(){
   CircularLinkedList cll;
   cll.add(5);
   cll.add(1);
   cll.add(2);
   cout << cll.front() << endl;
   cout << cll.back() << endl;
   return 0;
}