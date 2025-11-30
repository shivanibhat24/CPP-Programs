class SubrectangleQueries {
private:
    struct Query {
        int row1, col1, row2, col2, value;
        
        bool contains(int i, int j) const {
            return i >= row1 && i <= row2 && j >= col1 && j <= col2;
        }
    };

    vector<vector<int>>& rectangle;
    vector<Query> queries;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rectangle(rectangle) {}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        queries.emplace_back(row1, col1, row2, col2, newValue);
    }
    
    int getValue(int row, int col) {
        for (int i = queries.size() - 1; i >= 0; i--) {
            if (queries[i].contains(row, col)) {
                return queries[i].value;
            }
        }
        return rectangle[row][col];
    }
};
