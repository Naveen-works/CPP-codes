Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r



Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s





class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int n1=word1.size();
        int n2=word2.size();
        int length=max(n1,n2);
        string result;
        for(int i=0;i<length;++i)
        {
            if(i<n1)
            result+=word1[i];
            if(i<n2)
            result+=word2[i];
        }
    return result;
        
    }
};


/*
1->Find the length of both strings
2->Assign max length based on two strings
3->using For loop iterate from beginning to length
4->Append the characters of strings based on compairision of iteration 
5->Return the result


Time Complexity: 
	O(max(n1,n2))

Space Complexity: 
	O(n1+n2)

*/
