// Problem: Given a string, return the largest frequency character

/*
Input: abbbccccdd
Output: c
*/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Taking a character array as input and storing the frequency
// of each character in the array in a count array comprising of 256 0s at
// initialisation. 256 because that is the number of characters ASCII encoding
// allows for. Once we store the frequency, we just find the maximum frequency
// and return the character corresponding to the index of that frequency cell.
char largestFrequencyCharacter (char c[], int size) {
    int count[256]={0};
    int max=0;
    char result;
    for(int i=0;i<size;i++){
        count[(int)c[i]]++;
        if(count[(int)c[i]]>max){
            max=count[(int)c[i]];
            result=c[i];
        }
    }
    return result;
}

// Approach 2: Taking a string s as input, we store the frequency of the characters
// in the form of an unordered map and then iterate over the elements in the map to
// get the most frequently occuring element and return that character element.
char largestFrequencyCharacter(string s) {
    unordered_map <char,int> freq;
    for(char x : s){
        freq[x]++;
    }
    int max = 0;
    char result;
    for(char x : s){
        if(freq[x]>max){
            max = freq[x];
            result = x;
        }
    }
    return result;
}

int main(){
  cout<< largestFrequencyCharacter("abbbccccdd");
  return 0;
}
