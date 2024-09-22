class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
       vector<vector<int>> tri(numRows);
       for(int i = 0; i < numRows; ++i) {
           tri[i].resize(i + 1); // Resize each row to have i + 1 elements
           tri[i][0] = tri[i][i] = 1; // First and last elements are 1
           for(int j = 1; j < i; ++j) {
               tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j]; // Compute the inner elements
           }
       }
       return tri;
    }
};

/*
1->Create a two dimensional vector array and assign a size(numrows) and Iterate from beginning
2->Now resize array based on index value (i.e tri[i].resize(i+1)
3->assign first and last element as 1
4->By forloop on some condition compute the values in between the range 


Time complexity:
O(numRows^2)

Space complexity:
O(numRows^2)
*/

