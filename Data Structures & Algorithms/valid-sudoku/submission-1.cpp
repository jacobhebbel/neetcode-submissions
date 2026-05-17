class Solution {
public:
    
    bool validateRows(vector<vector<char>> & board) {
        for (vector<char> row : board) {
            unordered_set<char> seen;
            for (char c : row) {
                if (c == '.') continue;
                
                if (seen.count(c)) return false;
                
                seen.insert(c);
            }
        }

        return true;
    }

    bool validateCols(vector<vector<char>> & board) {
        for (int i = 0; i < 9; i++) {
            
            unordered_set<char> seen;
            cout << "in column " << i << endl;

            for (int j = 0; j < 9; j++) {
                char c = board[j][i];

                if (c == '.') continue;

                cout << "looking at " << c << endl;
                if (seen.count(c)) return false;

                seen.insert(c);
            }
        }

        return true;
    }

    bool validateSquares(vector<vector<char>> & board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                
                // board[i][j] is the top-left index of a square
                unordered_set<char> seen;
                for (int k = 0; k < 9; k++) {

                    int rowOffset = k / 3;
                    int colOffset = k % 3;
                    char c = board[i + rowOffset][j + colOffset];

                    if (c == '.') continue;
                    
                    if (seen.count(c)) return false;

                    seen.insert(c);
                }

            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        return validateRows(board) && validateCols(board) && validateSquares(board);
    }
};
