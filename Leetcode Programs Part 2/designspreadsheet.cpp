class Spreadsheet {
  private:
    typedef pair<int, int> i2_t;
    int cells[1000][26];
    i2_t get_coord(string_view cell) {
      int x;
      from_chars(cell.begin() + 1, cell.end(), x);
      int y = cell[0] - 'A';
      return {x - 1, y};
    }
    int get_value(string_view sv) {
      int val;
      if (isdigit(sv[0])) {
        from_chars(sv.begin(), sv.end(), val);
      }
      else {
        auto [x, y] = get_coord(sv);
        val = cells[x][y];
      }
      return val;
    }
  public:
    Spreadsheet(int rows) {
      memset(cells, 0, sizeof(int) * rows * 26);
    }    
    void setCell(string cell, int value) {
      auto [x, y] = get_coord(cell);
      cells[x][y] = value;
    }    
    void resetCell(string cell) {
      auto [x, y] = get_coord(cell);
      cells[x][y] = 0;
    }    
    int getValue(string formula) {
      const char* c = formula.c_str();
      size_t m = find(formula.begin(), formula.end(), '+') - formula.begin();
      return get_value({c + 1, m - 1}) + get_value({c + m + 1, formula.size() - m - 1});
    }
};
