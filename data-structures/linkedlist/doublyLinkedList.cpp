#include<bits/stdc++.h>
using namespace std;

class Node{
   private:
   int data;
   Node* prev = NULL;
   Node* next = NULL;
   friend class DoublyLinkedList;
};

class DoublyLinkedList{
   private:
   int size = 0;
   Node* header;
   Node* trailer;
   void remove(Node* node);
   void add(Node* node, int elem);

   public:
   DoublyLinkedList();
   ~DoublyLinkedList();

   void clear();
   int getSize();
   bool isEmpty();

   bool contains(int elem);

   void addFirst(int elem);
   void addLast(int elem);

   int peekFirst();
   int peekLast();

   bool removeFirst();
   bool removeLast();
   bool removeAt(int index);
   bool remove(int elem);

   int indexOf(int elem);
   
   string toString();
   
};

DoublyLinkedList::DoublyLinkedList(){
   size = 0;
   header = new Node;
   trailer = new Node;
   header->next = trailer;
   trailer->prev = header;
}
DoublyLinkedList::~DoublyLinkedList(){
   while(!this->isEmpty()){
      this->removeFirst();
   }
   delete header;
   delete trailer;
}

void DoublyLinkedList::clear(){
   while(!this->isEmpty()){
      this->removeFirst();
   }
}

void DoublyLinkedList::remove(Node* node){
   Node* prevNode = node->prev;
   Node* nextNode = node->next;
   prevNode->next = nextNode;
   nextNode->prev = prevNode;
   delete node;
}

bool DoublyLinkedList::removeFirst(){
   if(!this->isEmpty()){
      this->remove(this->header->next);
      size--;
      return true;
   }
   return false;
}

bool DoublyLinkedList::removeLast(){
   if(!this->isEmpty()){
      this->remove(this->trailer->prev);
      size--;
      return true;
   }
   return false;
}

bool DoublyLinkedList::remove(int elem){
   Node* temp = header;
   while(temp->next != trailer){
      if(temp->data == elem){
         this->remove(temp);
         size--;
         return true;
      }
   }
   return false;
}

bool DoublyLinkedList::isEmpty(){
   return (this->header->next==trailer);
}


// insert newNode before node
void DoublyLinkedList::add(Node* node, int elem ){
   Node* newNode = new Node;
   newNode->data = elem;
   newNode->next = node;
   newNode->prev = node->prev;
   node->prev->next = newNode;
   node->prev = newNode;
}

void DoublyLinkedList::addFirst(int elem){
   add(header->next,elem);
   size++;
}

void DoublyLinkedList::addLast(int elem){
   this->add(trailer,elem);
   size++;
}

int DoublyLinkedList::peekFirst(){
   if(!isEmpty()){
      return header->next->data;
   }
   return -1;
}
int DoublyLinkedList::peekLast(){
   if(!this->isEmpty()){
      return this->trailer->prev->data;
   }
   return -1;
}

bool DoublyLinkedList::contains(int elem){
   if(!this->isEmpty()){
      Node* node = header;
      while(node->next != trailer){
         if(node->data == elem){
            return true;
         }
         node = node->next;
      }
   }
   return false;
}

int main(){
   DoublyLinkedList dll;
   dll.addFirst(1);
   dll.addLast(5);
   cout << dll.peekLast() << endl;
   cout << dll.contains(100) << endl;
   dll.addLast(10);
   return 0;
}