

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 

No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true




class Solution {
public:
    bool isIsomorphic(string s, string t) 
    { 
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char> c_map;
        unordered_set<char> c_set;
        
        for(int i=0;i<s.length();++i)
        {
            char c1=s[i];
            char c2=t[i];

            if(c_map.find(s[i])!=c_map.end())
            {
                if(c_map[c1]!=c2)
                {
                    return false;
                }
            }
            else
            {
                if(c_set.find(c2)!=c_set.end())
                {
                    return false;
                }   
                c_map[c1]=c2;
                c_set.insert(c2);

            }
            
        }
        return true;
        
    }
};


/*
1->Check if both string are equal,if not return false
2->Initialize unordered map and set  for character assignment.
3->Iterate from begining check the two conditions.
4->If character is found in map then check that value is equal to char,if it is not return false
5->Else find that char 2 is already in set,if it is return false,then assign map of char1 to char2
and insert char2 to set.
6->Return bool value.


Time and space complexity :
O(N)
*/
