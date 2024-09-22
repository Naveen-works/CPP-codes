class Solution {
public:
    bool isPalindrome(string s) {
        string word;
        
        for(size_t i=0;i<s.length();++i)
        {
           
            if(isalnum(s[i]))
            {
               word+=tolower(s[i]);
            }
            else
            {
                continue;
            }
        }
        string rev_word=word;
        reverse(rev_word.begin(),rev_word.end());
        return rev_word==word;
        
    }
};

/*
Intuition
Verification of alpha numeric and convert to lower case then reverse that to obtain solution.

Approach
1->Iterate the string till end,
2->check each charcater by using isalnum() function then append character to word after the conversion of lowercase,
3->Initialize a new string for reverse operation,
4->check word and reverse_word is under the palindrome or not, 
5->Finally return truth value.

Complexity
Time complexity:
O(N)

Space complexity:
O(N)

*/
