
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].




class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        
    for(int i=digits.size()-1;i>=0;--i)
        {
            if(digits[i]<9)
            {
                digits[i]++;
                return digits;
            }
            digits[i]=0;


        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};




/*
1->Iterate backwards
2->if digits less than 9 just increment the digit by 1 (digits[i]++) and return the array
3->Else assign 0 to digits[i] 
4->if all the digits are 9 then insert 1 at begin by d.insert(d.begin(),1) and finally return array

Time Complexity: 

O(n) in the worst-case scenario, 
O(1) in the best-case scenario.


Space Complexity: 
O(1) for auxiliary space

*/




