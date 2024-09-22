#include <string>
#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1; 

        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            
            if (i >= 0) {
                sum += a[i] - '0';
                --i;
            }

           
            if (j >= 0) {
                sum += b[j] - '0'; 
                --j;
            }

            
            result += (sum % 2) + '0'; 
            carry = sum / 2;
        }
        std::reverse(result.begin(), result.end());

        return result;
    }
};

/*
1-> Initialize result,carry and the length of the two strings
2->Using while loop traverse backwards (i>=0 ||j>=0)
3->Initialize every time ssum with carry and check individually of x and y is greater than 0
4->Then append sum with a[i] and b[j] along with the conversion of char to num then decrement i andj
5->Append the result with of mod of sum by 2 along with the conversion of num to char again
6-> update the carry value of sum by 2 (i.e if s=1 then c=0)iterate until end
7->reverse the string finally return the result.


Time complexity
O(N)
*/

