Example 1:

Input: nums = [7,8,3,4,15,13,4,1]

Output: 5.5

Explanation:

step	nums	             averages
0	[7,8,3,4,15,13,4,1]	         []
1	[7,8,3,4,13,4]	             [8]
2	[7,8,4,4]	                 [8,8]
3	[7,4]						 [8,8,6]
4	[]					   		 [8,8,6,5.5]
The smallest element of averages, 5.5, is returned.



class Solution {
public:
    double minimumAverage(vector<int>& nums) 
    { 
        int i=0;
        int j=nums.size()-1;
        double average =INT_MAX;
        int first_element,last_element;
        sort(nums.begin(),nums.end());
        while(i<=j)
        {
            first_element=nums[i];
            last_element=nums[j];
            double result=double(first_element+last_element)/2;
            average=min(average,result);
            i++;
            j--;

        }
        return average;
    }
};




/*
1->Initialize first and last elemnent and indexes also.
2->Initialize avg as INT_MAX
3->Sort the give array
4->In awhile loop assign first and last element and perform give calculation
5->After that compare result with average 
6->Finally return the average


TIme and space complexity:


Time Complexity: O(n log n) due to sorting and O(n) due to the two pointers approach.
Space Complexity: O(log n) due to the sorting step and O(1) additional space for variables.

*/
