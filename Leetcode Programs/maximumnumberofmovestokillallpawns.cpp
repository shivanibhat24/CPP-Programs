const int MOD = 1e9 + 7;
const int BOARD_SIZE = 50;
const int KNIGHT_MOVES = 8;
int knight_dx[KNIGHT_MOVES] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knight_dy[KNIGHT_MOVES] = {1, 2, 2, 1, -1, -2, -2, -1};
int pawn_index[BOARD_SIZE][BOARD_SIZE], min_moves[BOARD_SIZE][BOARD_SIZE];
class Solution {
public:
    vector<vector<int>> shortest_distance;
    void computeShortestPaths(vector<vector<int>> &positions, int start) {
        int total_positions = shortest_distance.size();
        int remaining_pawns = total_positions;
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({positions[start][0], positions[start][1]});
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                min_moves[i][j] = MOD;
            }
        }        
        min_moves[positions[start][0]][positions[start][1]] = 0;
        shortest_distance[start][start] = 0;
        remaining_pawns--;        
        while (!bfsQueue.empty() && remaining_pawns) {
            int x = bfsQueue.front().first, y = bfsQueue.front().second;
            bfsQueue.pop();
            for (int move = 0; move < KNIGHT_MOVES; move++) {
                int nx = x + knight_dx[move], ny = y + knight_dy[move];
                if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && 
                    min_moves[x][y] + 1 < min_moves[nx][ny]) {
                    min_moves[nx][ny] = min_moves[x][y] + 1;
                    bfsQueue.push({nx, ny});
                    if (pawn_index[nx][ny] >= 0) {
                        remaining_pawns--;
                        shortest_distance[start][pawn_index[nx][ny]] = min_moves[nx][ny];
                    }
                }
            }
        }
    }    
    int total_pawns;
    vector<vector<int>> dp;
    int optimalMoves(int knight_pos, int remaining_pawns_mask) {
        if (!remaining_pawns_mask) return 0;
        if (dp[knight_pos][remaining_pawns_mask] != -1) return dp[knight_pos][remaining_pawns_mask];
        bool isAliceTurn = ((total_pawns & 1) == (__builtin_popcount(remaining_pawns_mask) & 1));
        int best_move = isAliceTurn ? 0 : MOD;
        for (int i = 0; i < total_pawns; i++) {
            if (!(remaining_pawns_mask & (1 << i))) continue; 
            int move_count = optimalMoves(i, remaining_pawns_mask ^ (1 << i));
            int total_moves = shortest_distance[knight_pos][i] + move_count;            
            if (isAliceTurn) best_move = max(best_move, total_moves);
            else best_move = min(best_move, total_moves);
        }        
        return dp[knight_pos][remaining_pawns_mask] = best_move;
    }    
    int maxMoves(int knight_x, int knight_y, vector<vector<int>>& pawn_positions) {
        total_pawns = pawn_positions.size();
        int max_mask = (1 << total_pawns) - 1;
        pawn_positions.push_back({knight_x, knight_y});
        int total_positions = pawn_positions.size();
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) pawn_index[i][j] = -1;
        }
        for (int i = 0; i < total_positions; i++) {
            pawn_index[pawn_positions[i][0]][pawn_positions[i][1]] = i;
        }
        shortest_distance = vector<vector<int>>(total_positions, vector<int>(total_positions, MOD));
        for (int i = 0; i < total_positions; i++) computeShortestPaths(pawn_positions, i);
        dp = vector<vector<int>>(total_pawns, vector<int>(max_mask + 1, -1));        
        int max_total_moves = 0;
        for (int i = 0; i < total_pawns; i++) {
            max_total_moves = max(max_total_moves, 
                                  shortest_distance[total_pawns][i] + optimalMoves(i, max_mask ^ (1 << i)));
        }        
        return max_total_moves;
    }
};
