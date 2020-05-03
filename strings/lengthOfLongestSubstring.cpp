// Given a string, find the length of the longest substring without repeating characters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
   bool isValid(string s);
   int lengthOfLongestSubstringNaive(const string & s);
   int lengthOfLongestSubstring(const string& s);

};

bool Solution::isValid(string s){
   unordered_set<char> m;
   for(char c : s){
      if(m.find(c)!= m.end()){
         return false;
      }
      m.insert(c);
   }
   return true;
}

// a b c a b c b b
// naive approach
// O(n^3) time | O(n) space
int Solution::lengthOfLongestSubstringNaive(const string& s){
   if (s.empty()){
      return 0;
   }
   int maxLength = INT_MIN;
   for(int i = 0; i < s.size()-1; i++){
      for(int j = i;j < s.size()-1; j++){
         string substring = s.substr(i,j-i+1);
         if(isValid(substring)){
            maxLength = max(maxLength,j-i+1);
         }
         // added to make it more optimal 
         else {
            break;
         }
      }
   }
   return maxLength;
}

// O(n^2) time | O(n) space
int Solution::lengthOfLongestSubstring(const string& s){
   int left = 0;
   int right = 0;
   int maxLength = 0;
   unordered_set<char>map;
   while(right < s.size()){
      if(map.find(s[right]) != map.end()){
         map.erase(s[left]);
         left++;
      }
      else {
         map.insert(s[right]);
         maxLength = max(maxLength,(int)map.size());
         right++;
      }

   } 
   return maxLength;
}


int main(){
   string s = "abrkaabcdefghijjxxx";
   Solution solution;
   int length = solution.lengthOfLongestSubstringNaive(s);
   cout << "Naive Approach: " << length << endl;
   length = solution.lengthOfLongestSubstring(s);
   cout << "Best Approach: " << length << endl;
   return EXIT_SUCCESS;
}