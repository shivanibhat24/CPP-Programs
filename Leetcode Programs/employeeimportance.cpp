class Solution {
public:
    unordered_map<int, Employee*> mp;
    int dfs(int id) {
        Employee* e = mp[id];
        int total = e->importance;
        for (int sub : e->subordinates) {
            total += dfs(sub);
        }
        return total;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto e : employees) {
            mp[e->id] = e;
        }
        return dfs(id);
    }
};
