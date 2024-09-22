class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
        
     }
};

/*
1-> initialize result as string variable
2->Using for each loop iterate each character 
3->Assign result using the formula of result=result*26 + (c-'A'+1)
4-> Return the result

Time complexity:
O(N)

Space complexity:
O(1)
*/
