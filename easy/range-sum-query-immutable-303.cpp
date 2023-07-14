// Problem: Range Sum Query - Immutable (Prefix Sums)

/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:
NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between
indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Constraints:
1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 104 calls will be made to sumRange.
*/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        if(left!=0){
            return nums[right]-nums[left-1];
        }
        return nums[right];
    }
};

int main(){
	vector<int> nums({-2,0,3,-5,2,-1});
  	int left,right;
	cin>>left>>right;
  	NumArray* obj = new NumArray(nums);
  	int param_1 = obj->sumRange(left,right);
  	cout<< param_1;
  	return 0;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
