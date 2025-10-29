class Solution {
private:
    std::vector<std::pair<int, int>> m_directions = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<std::vector<int>> m_cells;
    std::vector<std::vector<int>> m_mat;
    int m_rows;
    int m_cols;
    bool canMakeIt(int i){
        std::deque<std::pair<int, int>> queue;
        std::set<std::pair<int, int>> visited;
        for(int j = 0; j < i; j++){
            int r = m_cells[j][0];
            int c = m_cells[j][1];
            m_mat[r-1][c-1] = 1;
        }
        for(int col = 0; col < m_cols; col++){
            if(m_mat[0][col] == 0){
                queue.push_back({0, col});
                visited.insert({0, col});
            }
        }
        auto found = false;
        while(queue.size() && !found){
            auto p = queue.front();
            auto [row, col] = p;
            queue.pop_front();
            if(m_mat[row][col]) continue;
            if(row == m_rows - 1){
                found = true;
                break;
            }
            for(const auto [dr, dc]: m_directions){
                int _row = row + dr, _col = col + dc; 
                if(_row < 0 || _row >= m_rows) continue;
                if(_col < 0 || _col >= m_cols) continue;
                if(visited.find({_row, _col}) != visited.end()) continue;
                if(m_mat[_row][_col] == 0){
                    std::pair<int, int> _p = {_row, _col};
                    visited.insert(_p);
                    queue.push_back(_p);
                }
            }
        }
        for(int j = 0; j < i; j++){
            int r = m_cells[j][0];
            int c = m_cells[j][1];
            m_mat[r-1][c-1] = 0;
        }
        return found;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m_rows = row, m_cols = col;
        m_mat = std::vector(row, std::vector(col, 0));
        m_cells = cells;        
        int l = 0; 
        int r = cells.size() - 1;
        int m;
        while(l < r){
            m = l + 1 + (r - l) / 2;
            if(canMakeIt(m)){
                l = m;
            }else{
                r = m-1;
            }
        }
        return l;
    }
};
