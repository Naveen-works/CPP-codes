Example 1:

Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, 
so it ended up at the origin where it started. Therefore, we return true.
Example 2:

Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. 
We return false because it is not at the origin at the end of its moves.




class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int h=0,v=0; 
        
        for (char& move : moves)
        {
            switch(move)
            {
                case 'U':
                    v++;
                    break;
                case 'D':
                    v--;
                    break;
                case 'L':
                    h++;
                    break;
                case 'R':
                    h--;
                    break;
                
            }

        }
        return v==0 && h==0;
    }
};



/*
1-> Initialize horizonatal and vertical variables to track movements 
2-> For up and left make h++ and v++ and vice versa for down and right
3->Return the truth value that both variables back to origin by containing 0.

Time complexity:
O(N)

space complexity:
O(1)
*/
