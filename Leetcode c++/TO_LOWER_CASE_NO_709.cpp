
Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"

class Solution {
public:
    string toLowerCase(string s) 
    {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        return s ;
        
    }
};


/*
1->Just return the string of lower case  by using transform function.

Time complexity:
O(N)

Space complexity:
O(1)

*/
