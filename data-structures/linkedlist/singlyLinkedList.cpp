#include<bits/stdc++.h>
using namespace std;

class Node{
   private:
   int data;
   Node* next=NULL;
   friend class SinglyLinkedList;
};

class SinglyLinkedList {
   private:
   // stores the size of the linked list
   int size = 0;
   
   // pointer to head
   Node* head;

   public:

   // instantiates new singly linked list
   SinglyLinkedList();
   
   ~SinglyLinkedList();
   
   // checks if the list is empty or not
   bool isEmpty();
   
   // checks the size of the linked list
   int getSize();

   // clears all elements from the linked list
   void clear();

   // add an element to the tail of the linked list --> O(1)
   void addLast(int elem);

   // add an element to the head of the linked list --> O(1)
   void addFirst(int elem);

   // checks the value at the head of the list if it exists --> O(1) 
   int peekFirst();

   // checks the value at the tail of the list if it exists --> O(1)
   int peekLast();

   // Remove the first value at the head of linked list --> O(1)
   bool removeFirst();

   // Remove the last value at the tail of linked list --> O(N)
   bool removeLast();

   // Remove the node at a particular index -->O(N)
   bool removeAt(int index);

   // Remove the particular node of value --> O(N)
   bool remove(int elem);

   // returns the index of the element. returns -1 if not found --> O(N)
   int indexOf(int elem);

   // checks if the list contains an element
   bool contains(int elem);

   // returns chained linked list in the form "x --> x --> x"
   string toString();
};

SinglyLinkedList::SinglyLinkedList(){
   head = NULL;
}

SinglyLinkedList::~SinglyLinkedList(){
   clear();
}

void SinglyLinkedList::clear(){
   while(!isEmpty()){
      Node* old = head;    // saving the head pointer
      head = old->next;    // skipping over head
      delete old;          // deleting the old head
   }
   size = 0;
}

int SinglyLinkedList::getSize(){
   return size;            // returns the current size of the linked list
}

bool SinglyLinkedList::isEmpty(){
   return (head==NULL);    // if the head points to NULL then returns 0
}

void SinglyLinkedList::addLast(int elem){

   // if the list is null append it to the beginning
   if(isEmpty()){
      addFirst(elem);
   }
   else{
      Node* lastNode = head;
      // traverse at the end of the list to get the last node
      while(lastNode->next != NULL){
         lastNode = lastNode-> next;
      }
      // add new node and chain it to the last node 
      Node* node = new Node;
      node->data = elem;
      node->next = NULL;
      lastNode->next = node; 
      // increment the size of the array by 1
      size++;
   }
}

void SinglyLinkedList::addFirst(int elem){
   // create new node and set the next of new node to head.. and finally set new node as head node; 
   Node* node = new Node;
   node->data = elem;
   node->next = head;
   head = node;
   // increment the size of the list
   size++;
}

int SinglyLinkedList::peekFirst(){
   if(!isEmpty()){
      return head->data; // return the data of the head 
   }
   return -1; // if empty list it returns -1
}

int SinglyLinkedList::peekLast(){
   Node* lastNode = head;
   // traversing backward to get to the last node
   while(lastNode->next != NULL){
      lastNode = lastNode->next;
   }
   // returning the last node data
   return lastNode->data;
}

bool SinglyLinkedList::contains(int elem){
   // traversing through the list to check if element exists;
   if(!isEmpty()){
      Node* temp = head;
      while(temp != NULL){
         if(temp->data == elem){
            return true;
         }
         temp = temp->next;
      }
   }
   return false;
}

int SinglyLinkedList::indexOf(int elem){
   // returns 0 based index for the element
   int index = 0;
   Node* temp = head;
   while(temp != NULL){
      if(temp->data == elem){
         return (index);
      }
      index++;
      temp = temp->next;
   }
   // returns -1 if the element doesn't exist
   return -1;
}

string SinglyLinkedList::toString(){
   string arrow = " --> ";
   string result = "";
   string null = " NULL ";
   Node* temp = head;
   while(temp != NULL){
      result = result + to_string(temp->data) + arrow;
      temp = temp->next; 
   }
   return (result + null);
}

bool SinglyLinkedList::removeFirst(){
   // returns true if the element is removed else it returns false
   while (!isEmpty()){
      Node* old = head;
      head = old->next;
      size--;
      delete old;
      return true;
   }
   return false;
}
bool SinglyLinkedList::removeLast(){
   // returns true if the element is removed else it returns false
   if(!isEmpty()){
      Node* old = head;
      while(size == 1){
         return removeFirst();
      }
      // move to the second last node to delete the last node
      while(old->next->next != NULL){
         old = old->next;
      }
      delete old->next;
      old->next=NULL;
      size--;
      return true;

   }
   return false;
}

bool SinglyLinkedList::removeAt(int index){
   // returns true if the element is removed else it returns false
   if(!isEmpty()){
      if(index == 0){
         return removeFirst();
      }
      if(index == size-1){
         return removeLast();
      }
      Node* temp = head;
      for(int i = 0; i < index; i++){
         temp = temp->next;
      }
      Node* removeNode = temp->next;
      temp->next = removeNode->next;
      delete removeNode;
      size--;
      return true;
   }
   return false;
}

bool SinglyLinkedList::remove(int elem){
   // returns true if the element is removed else it returns false
   if(!isEmpty()){
      return removeAt(indexOf(elem));
   }
   return false;
}

int main(){
   // implementation
   SinglyLinkedList l;
   l.addFirst(1);
   l.addFirst(10);
   l.addFirst(13);
   l.addLast(2);
   l.addLast(3);
   l.addLast(4);
   l.addLast(8);
   l.addLast(7);
   cout << "SIZE: " << l.getSize() << endl;
   cout << "PEEK FIRST: " << l.peekFirst() << endl;
   cout << "PEEK LAST: " << l.peekLast() << endl;
   cout << "LIST CONTAINS 100: " << l.contains(100) << endl;
   cout << "LIST CONTAINS 4: " << l.contains(4) << endl;
   cout << "INDEX OF 1: " << l.indexOf(1) << endl;
   cout << "PRINT:" << l.toString() << endl;
   cout << "REMOVE FIRST: " << l.removeFirst() << endl;
   cout << "PRINT: " << l.toString() << endl;
   cout << "REMOVE LAST: " << l.removeLast() << endl;
   cout << "PRINT: " << l.toString() << endl;
   cout << "REMOVE AT INDEX 1: " << l.removeAt(1) << endl;
   cout << "PRINT: " << l.toString() << endl;
   cout << "REMOVE 13: " << l.remove(13) << endl;
   cout << "PRINT: " << l.toString() << endl;
   return 0;
}