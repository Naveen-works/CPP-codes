class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string flow=strs[0];
        
        for(int i=1;i<strs.size();++i)
        {
            while(strs[i].find(flow)!=0)
            {
                flow=flow.substr(0,flow.size()-1);
               

            }
        }
        return flow;
    
    
        
    }
};



/*
1->set prefix as str[0] of str[] 
2->Iterate from 2 and check if str[i].find(flow) is equal to 0 (if found in index 0 it returns 0)
3-> if it its not decrement flow to 1 and again iterate through it
4->return flow


Complexity-O(N*M)
*/

