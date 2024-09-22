

Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5




class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        vector<int> store;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=mat[i][i];
            sum+=mat[i][n-1-i];
            
        }
        
        if(n%2==1)
        {
           sum-=mat[n/2][n/2];
        }
        return sum;
    }
};




/*
1->Declare length 2X2 vector array
2->using a for loop print the diagonal elements based ont he formula
3->Remove the mid elemnet once as it is available twice
4->Finally return the sum

Time complexity:
O(n)

Space complexity:
O(1)
*/





