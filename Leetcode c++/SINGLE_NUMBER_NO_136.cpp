

Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1


class Solution {
public:
    int singleNumber(vector<int>& nums) {
         
         int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            result = result ^ nums[i];
        }

        return result;
    
        
    }
};

/*
1->Assign result= value of index 0
2->Iterate from 1 till end
3->calulate result using XOR function result^=nums[i];
4->Return the result

*/
