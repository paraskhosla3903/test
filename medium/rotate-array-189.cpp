// Problem: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

/*
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

Follow up:
Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

#include<bits/stdc++.h>
using namespace std;

// Time: O(nk) Space: O(1)
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    for(int j=1;j<=k;j++){
        int temp = nums[n-1];
        for(int i=n-2;i>=0;i--){
            nums[i+1] = nums[i];
        }
        nums[0] = temp;
    }
    for(int i=0;i<n;i++){
        cout<< nums[i] << ",";
    }
}

// Time: O(n) Space: O(1)
void kRotateVoid(vector<int>& a,int k){
    int n = nums.size();
    k = k%n;
    for(int i=0;i<k;i++){
        cout<< a[n-k+i] << ",";
    }
    for(int i=l;i<n;i++){
        cout<< a[i-k] << ",";
    }
}

// Time: O(n) Space: O(n)
vector<int> kRotateVector(vector<int>& a,int k){
    int n = nums.size();
    k = k%n;
    vector<int> v(n,0);
    for(int i=0;i<k;i++){
        v.push_back([n-k+i]);
    }
    for(int i=l;i<n;i++){
        v.push_back(a[i-k]);
    }
    return v;
}

vector<int> kRotateOptimised(vector<int>& a, int k){
    int n = a.size();
    k = k%n;
    for(int i=0;i<(n-k)/2;i++){
    	swap(a[i],a[n-k-1-i]);
    }
    for(int i=0;i<k/2;i++){
    	swap(a[n-k+i],a[n-1-i]);
    }
    for(int i=0;i<n/2;i++){
    	swap(a[i],a[n-1-i]);
    }
    return a;
}

// From [[a],[b]], we wish to get [[b],[a]]
// Analogous to matrix inversion inverse(ab) = inverse(b)inverse(a)
// Similarly inverse(inverse(a)inverse(b)) = ba
// We follow this strategy to go from ab to ba in place
// Time: O(n) Space: O(1)
vector<int> kRotateOptimal(vector<int>& a, int k){
    int n = a.size();
    k=k%n;
    reverse(a.begin(),a.begin()+n-k);
    reverse(a.begin()+n-k,a.end());
    reverse(a.begin(),a.end());
    return a;
}

int main(){
    vector<int> a;
	a.push_back(1);
	a.push_back(5);
	a.push_back(8);
	a.push_back(7);
	a.push_back(9);
	int k = 8;
	vector<int> v = kRotateOptimal(a,k);
	for(int i=0;i<v.size();i++){
		cout<< v[i] << ",";
	}
    return 0;
}
