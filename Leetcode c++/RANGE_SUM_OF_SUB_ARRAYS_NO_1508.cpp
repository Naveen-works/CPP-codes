Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. 
After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. 
The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. 
The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.

Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50




class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        vector<int> store;
        const int MOD = 1'000'000'007;
        for(int i=0;i<n;++i)
        {
            int m=0;
            for(int j=i;j<n;++j)
            {
                
                 m+=nums[j];
                 store.push_back(m);
            }
        }
        sort(store.begin(),store.end());
        long long result=0;
        left=left-1;
        while(left<right)
        {
           result=(result+store[left])%MOD;
            left++;
            
        }
        return static_cast<int>(result);
      
        
    }
};



/*
1->Create a vector array for storing sums
2->Use for loop calculate sums and store that in the array
3->Then sort that array 
4-> As result will be long we use mod to reduce optimize the result mod of 1'000'000'007
5-> Finally return the int result

Time complexity:
O(N^2 log N)

Space comlexity:
O(N^2)

*/
