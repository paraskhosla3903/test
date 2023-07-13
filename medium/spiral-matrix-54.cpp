// Problem: Given an m x n matrix, return all elements of the matrix in spiral order.

/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include<bits.stdc++.h>
using namespace std;

// Time: O(mn) Space: O(1)
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int n = matrix.size();
    int m = matrix[0].size();

    int startRow = 0;
    int endRow = n-1;
    int startCol = 0;
    int endCol = m-1;
    
    while(startRow<=endRow && startCol<=endCol){
        // Start Row
        for(int col=startCol;col<=endCol;col++){
            result.push_back(matrix[startRow][col]);
            cout<< matrix[startRow][col] << " ";
        }

        // End Column
        for(int row=startRow+1;row<=endRow;row++){
            result.push_back(matrix[row][endCol]);
            cout<< matrix[row][endCol] << " ";
        }

        // End Row
        for(int col=endCol-1;col>=startCol;col--){
            if(startRow==endRow){
                break;
            }
            result.push_back(matrix[endRow][col]);
            cout<< matrix[endRow][col] << " ";
        }

        // Start Column
        for(int row=endRow-1;row>=startRow+1;row--){
            if(endCol==startCol){
                break;
            }
            result.push_back(matrix[row][startCol]);
            cout<< matrix[row][startCol] << " ";
        }

        startRow++;startCol++;
        endRow--;endCol--;
    }
        
    return result;
}

// Time: O(mn) Space: O(mn)
vector<int> spiralPrint(vector<vector<int>>& m) {
    vector<int> result;
    while(!m.empty()){
        // Print first (0th) column
        for(int i=0;i<m[0].size();i++){
            result.push_back(m[0][i]);
            cout<< m[0][i] << " ";
        }
        // Transform matrix m
        m.erase(m.begin());
        for(int i=0;i<m[0].size()/2;i++){
            for(int j=0;j<m.size();j++){
                swap(m[j][i],m[j][m[0].size()-1-i]);
            }
        }
        vector<vector<int>> transpose(m[0].size(),vector<int>(m.size(),0));
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                transpose[j][i] = m[i][j];
            }
        }
        m = transpose;
    }
    return result;
}

int main(){
    vector<vector<int>> m({{1,2,3},{4,5,6},{7,8,9}});
    spiralOrder(m);
    cout<<endl;
    spiralPrint(m);
    return 0;
}
