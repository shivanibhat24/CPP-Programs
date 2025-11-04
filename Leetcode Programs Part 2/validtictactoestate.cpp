constexpr int NoWinner = 0;
class Solution {
public:
    char get_winner(vector<string>& board) {
        char result = NoWinner;
        char line_winner;
        for (int row_index = 0; row_index < board.size(); ++row_index) {
            line_winner = board[row_index][0] & board[row_index][1] & board[row_index][2];
            if (line_winner == 'X' || line_winner == 'O') {
                result = result == NoWinner ? line_winner : result & line_winner;
            }
        }
        for (int column_index = 0; column_index < board.size(); ++column_index) {
            line_winner = board[0][column_index] & board[1][column_index] & board[2][column_index];
            if (line_winner == 'X' || line_winner == 'O') {
                result = result == NoWinner ? line_winner : result & line_winner;
            }
        }
        line_winner = board[0][0] & board[1][1] & board[2][2];
        if (line_winner == 'X' || line_winner == 'O') {
            result = result == NoWinner ? line_winner : result & line_winner;
        }
        line_winner = board[2][0] & board[1][1] & board[0][2];
        if (line_winner == 'X' || line_winner == 'O') {
            result = result == NoWinner ? line_winner : result & line_winner;
        }
        return result;
    }
    bool validTicTacToe(vector<string>& board) {
        int num_x = 0;
        int num_o = 0;
        for (const string& row : board) {
            for (const char square : row) {
                if (square == 'X') ++num_x;
                else if (square == 'O') ++ num_o;
            }
        }
        const char game_result = get_winner(board);
        if (num_x == num_o) {
            return game_result == NoWinner || game_result == 'O';
        } else if (num_x == num_o + 1) {
            return game_result == NoWinner || game_result == 'X';
        }
        return false;
    }
};
