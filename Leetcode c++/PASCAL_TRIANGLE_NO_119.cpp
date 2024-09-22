Input: rowIndex = 3
Output: [1,3,3,1]

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector <int> vec(rowIndex+1,1);
        for(int i=1;i<rowIndex;++i)
        {
            for(int j=i;j>0;--j)
            {
                vec[j]+=vec[j-1];
            }
        }
        return vec;
        
    }
};


/*
1->Initialize a vector array and set all values to 1 and size as rowindex+1
2->Iterate  from index 1 to rowindex-1 for proper insertion of values
3->Iterate backwards for between values and perform calculation vec[j]+=vec[j-1]


Time complexity:
O(N^2)


Space complexity:
O(N)
*/


/*
Another solution 
class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res(1, 1);
        long long prev = 1;
        for(int k = 1; k <= rowIndex; k++) {
            long long next_val = prev * (rowIndex - k + 1) / k;
            res.push_back(next_val);
            prev = next_val;
        }
        return res;
    }
};
*/
