class Solution {
private:
    Node* falseLeaf = new Node(false, true);
    Node* trueLeaf = new Node(true, true);
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
private:
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
        if(n == 1) return (grid[r][c] == 1) ? trueLeaf : falseLeaf;
        n /= 2;
        Node* topLeft = dfs(grid, n, r, c);
        Node* topRight = dfs(grid, n, r, c + n);
        Node* bottomLeft = dfs(grid, n, r + n, c);
        Node* bottomRight = dfs(grid, n, r + n, c + n);
        int isLeaf = topLeft->isLeaf + topRight->isLeaf + bottomLeft->isLeaf + bottomRight->isLeaf;
        int sameVal = topLeft->val + topRight->val + bottomLeft->val + bottomRight->val;
        if(isLeaf == 4 && (sameVal == 4 || sameVal == 0)) {
            return topLeft;
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }};
