

Given a string s, 
check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.



class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        string twice= s+s;
        string sub_twice = twice.substr(1,twice.size()-2);
        return sub_twice.find(s)!=string::npos;
    }
};



/*
1->Twice the string 
2-> Now create a substring of twice by removing frst and last charcter,if we didnt do that then it will match in begining
3->By using sub_twice search given string if it is not equal to npos retur true else false

Time Complexity and Space Complexity
O(n)
*/

