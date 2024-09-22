Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false



class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int l=nums.size();
        if(nums[0]<nums[l-1])
        {
            for(int i=0;i<l-1;++i)
            {
                if(nums[i]>nums[i+1])
                {
                    return false;
                }
            }
        }
        else
        {
            for(int i=0;i<l-1;++i)
            {
                if(nums[i]<nums[i+1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};


/*
1->Check that first element is less than last one  then it is non decreasing 
2->Within that check that num is decreasing then return false
3->Make the else condition as vice versa of if condition
4->Return the truth value

 Time complexity:
O(N)

Space complexity:
O(1)
*/
