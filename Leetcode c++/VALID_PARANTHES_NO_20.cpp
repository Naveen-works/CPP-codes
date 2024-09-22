class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        unordered_map<char,char> match_pairs={
            {')','('},
            {'}','{'},
            {']','['}};

        for (char ch:s)
        {
            if(match_pairs.find(ch)!=match_pairs.end())
            {
                if(!char_stack.empty() && char_stack.top()==match_pairs[ch])
                {
                    char_stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                char_stack.push(ch);
            }
        }
        return char_stack.empty();
        
        
    }
};

/*
1->create a stack variable of type char
2->create a unordered_map of char to char combination like closing as key opening as  a value
3-> Iterate using for each loop for(char c:s)
4->Using find() function check that it is a closing bracket by compairing not equal to map end
5->if it is not equal to end then it is closing bracket then check if stack is not empty and top char of stack matches the closing
pair if matches then pop the stack
6->else return false
7->If it is a opening bracket then just push it
8->Finally return stack.empty()



Time complexity:
O(N)


*/
