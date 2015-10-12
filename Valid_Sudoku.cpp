class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int column[10] = {0};
        int row[10] = {0};
        int square[9][10] = {0};

        for(int i = 0; i < 9; ++i) {
        	memset(column, 0, sizeof(column));
        	memset(row, 0, sizeof(row));

        	for(int j = 0; j < 9; ++j) {
				if(!checkValid(column, board[j][i]) 
					|| !checkValid(row, board[i][j]) 
					|| !checkValid(square[i/3*3 + j/3], board[i][j]))
					return false;
        	}
        }
        return true;
    }

    bool checkValid(int list[], char ch) {
    	if(ch == '.') {
    		return true;
    	}
    	if(ch - '0' <= 0 || list[ch - '0'] == 1) {
    		return false;
    	} else {
    		list[ch - '0'] = 1;
    		return true;
    	}
    }
};