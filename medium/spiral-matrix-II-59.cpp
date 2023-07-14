// Problem: Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

/*
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Input: n = 1
Output: [[1]]

Constraints:
1 <= n <= 20
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n,vector<int>(n,0));
    
    int startRow = 0;
    int startCol = 0;
    int endRow = n-1;
    int endCol = n-1;
    int num = 1;
        
    while(startRow<=endRow && startCol<=endCol){
        // First Row
        for(int col=startRow;col<=endRow;col++){
            result[startRow][col] = num++;
        }
        
        // End Column
        for(int row=startRow+1;row<=endRow;row++){
            result[row][endCol] = num++;
        }

        // End Row
        for(int col=endCol-1;col>=startCol;col--){
            result[endRow][col] = num++;
        }

        // Start Column
        for(int row=endRow-1;row>=startRow+1;row--){
            result[row][startCol] = num++;
        }

        startRow++;startCol++;
        endRow--;endCol--;
    }
    
    return result;
}

void print2dVector(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<< matrix[i][j] << " ";
        }
        cout<<endl;
    }
}

int main(){
    int n;cin>>n;
    vector<vector<int>> m = generateMatrix(n);
    print2dVector(m);
    return 0;
}
