#include<bits/stdc++.h>
using namespace std;

// This is a Naive Method to reverse a string
// Time Complexity = O(N)
// Space Complexity = O(1)
string reverseStringNaive(string s){
    string output = "";
    for(char c : s){
        output = c + output;
    }
    return output;
}

// This reduces runtime by half of naive approach
// Uses two pointers left right and swaps their values until they meet.
// Time Complexity = O(N)
// Space Complexity = O(1)
void reverseStringTP(string& s){
    int leftPointer = 0;
    int rightPointer = s.size()-1;
    while(leftPointer < rightPointer){
        char temp = s[leftPointer];
        s[leftPointer] = s[rightPointer];
        s[rightPointer] = temp;
        leftPointer++;
        rightPointer--;
    }
    cout << s << endl;
    return;
}

int main(){
    string s = "ALGORITHMS";
    cout << reverseStringNaive(s) << endl;
    reverseStringTP(s);
    return EXIT_SUCCESS;
}