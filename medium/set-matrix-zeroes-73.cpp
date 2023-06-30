// Problem: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.

/*
Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

 
Follow up:

1. A straightforward solution using O(mn) space is probably a bad idea.
2. A simple improvement uses O(m + n) space, but still not the best solution.
3. Could you devise a constant space solution?
*/

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> matrix) {
	// Finding number of elements in 2d matrix
	int n = 0;
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			n++;
		}
	}

	// Populating (i,j) in an array where elements are 0s
    pair<int,int> index[n];
    int idx = 0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
            	index[idx].first = i;
            	index[idx].second = j;
            	idx++;
            }
        }
    }

  // Using (i,j) from index[] to set rows and columns 0s 
    for(int a=0;a<idx;a++){
    	int x = index[a].first;
    	int y = index[a].second;
    	for(int i=0;i<matrix.size();i++){
    		for(int j=0;j<matrix[i].size();j++){
    			if(i==x){
    				matrix[i][j]=0;
    			}
    			if(j==y){
    				matrix[i][j]=0;
    			}
    		}
    	}
    }

  // Printing the output as required
    for(int i=0;i<matrix.size();i++){
    	for(int j=0;j<matrix[i].size();j++){
    		cout<< matrix[i][j] << " ";
    	}
    }
}

int main(){
  vector<vector<int> > matrix({
		{0,1,2,0},
		{3,4,5,2},
		{1,3,1,5}
	});
	setZeroes(matrix);
  return 0;
}
