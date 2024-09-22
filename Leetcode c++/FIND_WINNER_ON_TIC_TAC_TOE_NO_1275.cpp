

Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.


Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.


Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.



class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
     vector<vector<vector<int>>> results;
     results={
            {{0,0}, {0,1}, {0,2}}, 
            {{1,0}, {1,1}, {1,2}}, 
            {{2,0}, {2,1}, {2,2}}, 
            {{0,0}, {1,0}, {2,0}}, 
            {{0,1}, {1,1}, {2,1}}, 
            {{0,2}, {1,2}, {2,2}}, 
            {{0,0}, {1,1}, {2,2}}, 
            {{0,2}, {1,1}, {2,0}}  
        };

        vector<vector<int>> x;
        vector<vector<int>> o;
     for(int i=0;i<moves.size();++i)
     {
        if(i%2==0)
        {
            x.push_back(moves[i]);
        }
        else
        {
            o.push_back(moves[i]);
        }
     }
     
     for(const auto& win : results)
     {
        if(all_of(win.begin(),win.end(),[&](const vector<int>& pos) {
                return find(x.begin(), x.end(), pos) != x.end();}))
        {
            return "A";
        }
        else if(all_of(win.begin(),win.end(),[&](const vector<int>& pos) {
                return find(o.begin(), o.end(), pos) != o.end();}))
        {
            return "B";
        }
     }
     if(moves.size()==9)
     {
        return "Draw";
     }
     return "Pending";
    }
};



/*
1->Create a three dimensional array for combination of winning position
2->Separate 'X' and 'O' moves
3->For every win pos in results array check that a pos is available in X or O 
4-> Check that all combination of win is available in X or O and return true
5-> Return "A" or "B" Based on truth and return "Draw" if moves.size() is equal to 0.

Time complexity:
O(1)

Space complexity:
O(M)


*/


/*
//Another solution
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> winner = {
            {0,1,2}, {3,4,5}, {6,7,8},
            {0,3,6}, {1,4,7}, {2,5,8},
            {0,4,8}, {2,4,6}
        };
        vector<int> board(9,0);

        for(int i = 0; i<moves.size(); i++){
            int r = moves[i][0], c = moves[i][1];
            board[r*3 + c] = (i%2 == 0) ? 1 : 2;
        }

        for(auto & combo : winner){
            if(board[combo[0]] != 0 && board[combo[0]] == board[combo[1]] &&
            board[combo[1]] == board[combo[2]]){
                return board[combo[0]] == 1 ? "A" : "B";
            }
        }

        if(moves.size() == 9){
            return "Draw";
        }
        return "Pending";
        
    }
};
*/


