
An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.




class Solution {
public:
    int calPoints(std::vector<std::string>& operations) 
    {
        vector<int> store;
        
        
        for (const string& op : operations)
        {
            int n=store.size();
            if (op == "C")
            {
                store.pop_back();
            }
            else if (op == "D")
            {
                store.push_back(store.back() * 2);
            }
            else if (op == "+")
            {
                 store.push_back(store[n - 1] + store[n - 2]);
               
            }
            else
            {
                store.push_back(stoi(op));
            }
        }
        
        int result = 0;
        for (int num : store)
        {
            result += num;
        }
        return result;
    }
};




/*
1->Iterate through the given string array
2->By condition statements satisfy constraints and store that in a vector array
3->Finally sum the elements of that array and return the integer.

Time and space complexity:
O(N)
*/











