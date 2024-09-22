
Example 1:

Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
Example 2:

Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
Example 3:

Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1




class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int result=1;
        for(int num:nums)
        {
            if(num==0)
            {
                return 0;
            }
            if(num <0)
            {
                result=-result;
            }

        }
        return result;
    }
};


/*
1->Create a variable for sign change purposes and assign it to initially 1.
2->Using for each loop check if number is equal to 0 then return 0.
3->Then if num is less than 0 then change sign of the result as -result.
4->Finally return the result.

Time complexity:
O(N)

Space complexity:
O(1)
*/
