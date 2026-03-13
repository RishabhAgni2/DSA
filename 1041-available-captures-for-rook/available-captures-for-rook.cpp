class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r, c;

        // Find the rook position
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == 'R') {
                    r = i;
                    c = j;
                }
            }
        }

        int captures = 0;

        // Move Up
        for(int i = r - 1; i >= 0; i--) {
            if(board[i][c] == 'B') break;
            if(board[i][c] == 'p') {
                captures++;
                break;
            }
        }

        // Move Down
        for(int i = r + 1; i < 8; i++) {
            if(board[i][c] == 'B') break;
            if(board[i][c] == 'p') {
                captures++;
                break;
            }
        }

        // Move Left
        for(int j = c - 1; j >= 0; j--) {
            if(board[r][j] == 'B') break;
            if(board[r][j] == 'p') {
                captures++;
                break;
            }
        }

        // Move Right
        for(int j = c + 1; j < 8; j++) {
            if(board[r][j] == 'B') break;
            if(board[r][j] == 'p') {
                captures++;
                break;
            }
        }

        return captures;
    }
};