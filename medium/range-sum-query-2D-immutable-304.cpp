// Problem: Given a 2D matrix matrix, handle multiple queries of the following type:

/*
Calculate the sum of the elements of matrix inside the rectangle defined 
by its upper left corner (sr, sc) and lower right corner (er, ec).

Implement the NumMatrix class:
NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int sr, int sc, int er, int ec) Returns the sum of the elements of matrix inside 
the rectangle defined by its upper left corner (sr, sc) and lower right corner (er, ec).

You must design an algorithm where sumRegion works on O(1) time complexity.

Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-10^4 <= matrix[i][j] <= 10^4
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 10^4 calls will be made to sumRegion.
*/

#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // populating first row
        for(int j=1;j<n;j++){
            matrix[0][j] += matrix[0][j-1];
        }
        // populating first column
        for(int i=1;i<m;i++){
            matrix[i][0] += matrix[i-1][0];
        }
        // populating remainder of the matrix
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }
        this->matrix = matrix;
    }
    
    int sumRegion(int sr, int sc, int er, int ec) {
        if(sr>0 && sc>0){
		    return matrix[er][ec] - matrix[sr-1][ec] - matrix[er][sc-1] + matrix[sr-1][sc-1];
	    }
	    else if(sr==0 && sc!=0){
		    return matrix[er][ec] - matrix[er][sc-1];
	    }
	    else if(sr!=0 && sc==0){
		    return matrix[er][ec] - matrix[sr-1][ec];
	    }
	    else{	// when sr,sc = 0,0
		    return matrix[er][ec];
	    }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
