Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int length=arr.size();
         int Difference=arr[1]-arr[0];
        for(int i=1;i<length-1;++i)
        {
           if(arr[i+1]-arr[i]!=Difference)
            {
                return false;
            }
            
        }
        return true;
        
    }
};


/*
1->Sort the given array
2->Initiate diffrence as difference of first two numbers
3->Using for loop from it=1 check that difference is satisfied or not
4-> Return final truth value

Time complexity:
O(n logn)

Space complexity:
O(logn)
*/



