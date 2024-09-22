#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> r_map;								//Map declaration
        int n=nums.size();
        
        
        
        for(int i=0;i<n;++i)              
        {
            int s=target-nums[i];
            if(r_map.find(s)!=r_map.end())
            {
                return {i,r_map[s]};					//Returning list
            }
             r_map[nums[i]]=i;

        }


        return  {} ;
        
    }
};


/*
1->Declaration map variable for mapping indexes of array
2-iterate till the end by compairision of target-nums[i]==s
3->Find that s is available or not if found then return i and r_map[s]

Time Complexity: O(n)
Space Complexity: O(n)

*/

/*

MY SOLUTION ::

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n=nums.size();
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                                
                if(nums[i]+nums[j]!=target)
                {
                continue;
                }
                else
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result ;
        
    }
};
*/
