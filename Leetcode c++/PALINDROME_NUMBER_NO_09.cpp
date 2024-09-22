



Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.


class Solution {
public:
    bool isPalindrome(int x) 
    {
      if(x<0)
        {
            return false;
        }
        long long orig_num = x; 
        long long rev_num = 0;  

        while (x > 0) {
            long long rem = x % 10;
            rev_num = rev_num * 10 + rem;
            x /= 10;
        }

        return orig_num == rev_num;

        
    }
};


/*
1->Initialize orig_num with x
2->While loop initialize remainder as x%10
3->Assign it to the reversed num
4->Finally return the compairision 

Time Complexity: 
O(log10(x))


Space Complexity: 

O(1)

*/


