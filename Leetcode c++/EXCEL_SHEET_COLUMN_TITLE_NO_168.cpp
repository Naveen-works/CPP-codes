class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title;
        while(columnNumber>0)
        {
            columnNumber--;
            char letter='A'+(columnNumber%26);
            title=letter + title;
            columnNumber/=26;
        }
        return title;
    }
   
};

/*
1->Initialize title in the form of string variable 
2->In a while loop check condition that column_num > 0
3->decrement column_num to 1 for correct charater assignment
4->Create a character variable for assigning a char of 'A' + column_num%26
5-> Assign char to String "Title" (title=char+title)
6->Divide the column_num by 26 for move on next digit of counting number.

Time and space complexity:
O(log26(n))

*/
