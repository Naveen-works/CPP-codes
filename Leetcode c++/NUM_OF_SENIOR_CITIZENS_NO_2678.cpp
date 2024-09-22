Return the number of passengers who are strictly more than 60 years old.

 

Example 1:

Input: details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
Output: 2
Explanation: The passengers at indices 0, 1, and 2 have ages 75, 92, and 40. Thus, there are 2 people who are over 60 years old.
Example 2:

Input: details = ["1313579440F2036","2921522980M5644"]
Output: 0
Explanation: None of the passengers are older than 60.


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(const string& at:details)
        {
           string age =at.substr(11,2);
           int num=stoi(age);
           if(num>60)
           {
            count++;
           }
        }
        
        return count;
        
    }
};


/*
1->Using for each loop traverse each strings and reflect changes by using '&'
2->Extract the substr
3-> Convert it into int and check that is greater than 60 then increment count 
4->Finally return count

Time complexity :
O(N)

Space complexity:
O(1)
*/



