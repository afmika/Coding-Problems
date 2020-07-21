/*
79. Word Search
Medium

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

 

Constraints:

    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3
*/

#define row first
#define col second

class Solution {
public:
    vector<pair<int, int>> dir {
        {0, 1}, // left
        {0, -1}, // right
        {1, 0}, // down
        {-1, 0} // up
    };

    bool canGoTo ( pair<int, int> pos, vector<vector<char>>& grid ) {
        if ( pos.row < 0 || pos.row >= ((int) grid.size()) ) {
            return false;
        }
        if ( pos.col < 0 || pos.col >= ((int) grid[pos.row].size()) ) {
            return false;
        }
        return grid[pos.row][pos.col] != '.';
    }

    bool DFS (vector<vector<char>>& grid, pair<int, int> pos, string formed,  string word) {
        if ( formed.compare(word) == 0 ) {
            return true;
        }
        size_t last_idx = formed.size() - 1;
        if ( formed[ last_idx ] != word[ last_idx ] ) {
            return false;
        }

        for (auto d : dir) {
            pair<int, int> n_pos = {
                d.row + pos.row,
                d.col + pos.col
            };
            if ( canGoTo(n_pos, grid) ) {
                char ch = grid[n_pos.row][n_pos.col];
                grid[n_pos.row][n_pos.col] = '.';
                if ( DFS (grid, n_pos, formed + ch, word) ) {
                    return true;
                }
                grid[n_pos.row][n_pos.col] = ch;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if ( word.size() < 1 )
            return true;
        bool isFound = false;
        for (size_t row = 0; row < board.size(); row++) {
            for (size_t col = 0; col < board[row].size(); col++) {
                if ( board[row][col] == word[0] ) {
                    if ( word.size() == 1 ) {
                        return true;
                    }
                    char temp = board[row][col];
                    string current (1, temp);
                    board[row][col] = '.';
                    isFound = DFS(board, {row, col}, current, word);
                    board[row][col] = temp;
                }
                if ( isFound )
                    return true;
            }
        }
        return false;
    }
};