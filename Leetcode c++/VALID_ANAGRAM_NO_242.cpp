An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


class Solution {
public:
    bool isAnagram(string s, string t) {

        int l=s.size();
        
        if(l!=t.size())
        return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<l;++i)
        {
            if(s[i]!=t[i])
            {
                return false;
            }
        }

        return true;
        
    }
};

/*
1->Sort the two strings
2->Iterate over all char of strings and check that both strings of characters are equally available

Time complexity :
O(NlogN)

Space complexity:
O(1)

*/
