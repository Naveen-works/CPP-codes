


Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true





class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int count=0;
        for(int i=0;i<nums.size()-1;++i)
        {
           if (find(nums.begin() + i + 1, nums.end(), nums[i]) != nums.end()) {
            count++;
        }

        }
        if(count!=0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};





/*
1->Initialize a set for storing
2->Use for-each loop for iterate each digit
3->use find() function for checking duplicate values if found return true else insert into set
4->Finally return the bool value


Time and space complexity:
O(N)

*/
