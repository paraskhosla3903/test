// Problem: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

/*
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a 
subsequence of "abcde" while "aec" is not).


Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by 
one to see if t has its subsequence. In this scenario, how would you change your code?
*/


// Hint to Follow-up: https://leetcode.com/problems/is-subsequence/description/comments/1658486

#include<iostream>
using namespace std;

bool isSubSequence(string a, string b) {
    int n = a.length();
    int m = b.length();
    
    int i=0,j=0;
    
    while(i<n && j<m){
        if(a[i]==b[j]){
            i++;
        }
        j++;
    }
    
    return i==n;
}

/*
1. Traverse through the string a and string b 
using two pointers i and j strating at index 0.
2.As soon as you encounter a match (in order)
increment i, in addition to incrementing j which
is done in every iteration. 
3.If at the end of this operation, we find that 
every character in string a has been visited once 
in order i.e. i==n then we say that a is a is a 
subsequence of string b.
*/

int main(){
  cout<< isSubsequence("axy","adxcpy"); // 1
  cout<< isSubsequence("axy","yadxcp"); // 0
  return 0;
}

