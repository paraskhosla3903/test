// Problem: Valid Anagram - Leetcode 242 - Easy
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

/*
Properties:
1. All possible character subsets of s and t should be identical
2. Lengths of s and t should be the same (validation checkpoint)
M1: Unordered Map -> Each character in the map must point to the same frequency for both s and t. If that happens then necessarily s and t are anagrams
M2: Sort s and t lexicographically and check for equality (nlog(n))
*/

// Method 1: Sorting strings and then comparing
bool isAnagram1(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }
    
    int n = s.length();
    int s1[n],s2[n];
    for(int i=0;i<n;i++){
        s1[i]=(int)s[i];
        s2[i]=(int)t[i];
    }
    sort(s1,s1+n);
    sort(s2,s2+n);
    
    for(int i=0;i<n;i++){
    	if(s1[i]!=s2[i]){
    		return false;
    	}
    }

    return true;
}

// Method 2: Storing chars of string in hash map
bool isAnagram2(string s, string t){
	if(s.length()!=t.length()){
		return false;
	}

	int n = s.length();
	unordered_map<char,int> a; 
	unordered_map<char,int> b;

	for(int i=0;i<n;i++){
		a[s[i]]++;
		b[t[i]]++;
	}

	return a==b;

}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	cout<< isAnagram1("rat","cat") <<endl;
	cout<< isAnagram2("anagram","naaragm") <<endl;
	

	return 0;
}
