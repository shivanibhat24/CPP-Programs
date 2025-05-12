class UnionFind {
private:
	vector<int> rank, parent;
    void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])	
			rank[y]++;
	}
public:
	int forests { 0 };
	UnionFind(int n) {
		rank = vector<int>(n), parent = vector<int>(n);
		forests = n;
		for (int i = 0; i < n; ++i)
			parent[i] = i, rank[i] = 1;
	}
    int find_set(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find_set(parent[x]);
	}
    bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {	
			link(x, y);
			forests--;	
		}
		return x != y;
	}
};
class Solution {
    bool isSimilar(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] != b[i])
                diff += 1;
            if (diff > 2)
                return false;
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
		UnionFind uf(n);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (isSimilar(strs[i], strs[j]))
					uf.union_sets(i, j);
			}
		}
		return uf.forests;
    }
};
