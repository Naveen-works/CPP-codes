class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
         if(nums[n-1]<target)
            {
                return n;
            }
        for(int i=0;i<n;++i)
        {
            
            if(target<=nums[i])
            {
                return i;
            }
        }
        return true;
    }
};

/*
1->Check if target less than n-1 return n
2->if target <=nums[i] return i
3-> Finally return true

Time complexity:
O(Log(n))

Space complexity:
O(1)
*/
