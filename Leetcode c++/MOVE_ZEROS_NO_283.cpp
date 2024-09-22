

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]



class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int found=0;
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]!=0)
            {
                nums[found++]=nums[i];
            }
            i++;
        }

        for(int i=found;i<n;++i)
        {
            nums[i]=0;
        }
        
    }
};


/*
1-> Create a found variable and initialize it to 0
2-> Iterate array till end if element is not 0 then assign it to array of position of found and increment it
3->Then finally iterate from found till end and assign 0's until it reaches nums.size()

Time complexity:
O(N)

Space complexity:
O(1)

*/
