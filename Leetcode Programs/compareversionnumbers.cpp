class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = get_list(version1); 
        auto v2 = get_list(version2);         
        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int v1_val = (i < v1.size()) ? stoi(v1[i]) : 0;
            int v2_val = (i < v2.size()) ? stoi(v2[i]) : 0;            
            if (v1_val < v2_val) {
                return -1;
            }
            if (v2_val < v1_val) {
                return 1;
            }
        }
        return 0;
    }
    vector<string> get_list(string &s) {
        stringstream ss(s); 
        string token; 
        vector<string> ret; 
        while (getline(ss, token, '.')) {
            ret.push_back(token);
        }
        return ret;
    }
};
