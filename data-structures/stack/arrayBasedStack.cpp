// Operations performed in STACK
// push(e): Insert element e at the top of the stack.
// pop(): Remove the top element from the stack; an error occurs if the stack is empty.
// top(): Return a reference to the top element on the stack, with- out removing it; an error occurs if the stack is empty.
// Additionally, let us also define the following supporting functions: 
// size(): Return the number of elements in the stack.
// empty(): Return true if the stack is empty and false otherwise

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class ArrayStack{
   private:
   int capacity;
   int topIndex;
   T* stackArray;

   public:
   ArrayStack(int capacity);
   ~ArrayStack();
   int size();
   bool empty();
   T& top();
   void push(T elem);
   void pop();
};

template <typename T>
ArrayStack<T>::ArrayStack(int capacity){
   this->stackArray = new T[capacity];
   this->capacity = capacity;
   this->topIndex = -1;
}
template <typename T>
ArrayStack<T>:: ~ArrayStack(){
   delete this->stackArray;
}

template <typename T>
int ArrayStack<T>::size(){
   return (this->topIndex+1);
}

template <typename T>
bool ArrayStack<T>::empty(){
   return this->topIndex < 0;
}

template <typename T>
T& ArrayStack<T>::top(){
   if(this->empty()) throw "Top of empty stack";
   return this->stackArray[topIndex];
}

// 1 
template<typename T>
void ArrayStack<T>::push(T elem){
   if(this->size()==this->capacity) throw "Push to full Stack";
   this->stackArray[++topIndex] = elem;
}

template<typename T>
void ArrayStack<T>::pop(){
   if(this->empty()) throw "Pop from empty stack";
   --topIndex;
}


int main(){
   ArrayStack<int> stack(100);
   stack.push(10);
   stack.push(5);
   stack.pop();
   stack.pop();
   stack.push(10);
   cout << stack.top() << endl;
   return EXIT_SUCCESS;
}
