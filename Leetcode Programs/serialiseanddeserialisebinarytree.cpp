class Codec {
public:
    vector<string> splitByComma(const string& input) {
        vector<string> result;
        stringstream ss(input);
        string word;
        while (std::getline(ss, word, ',')) {
            result.push_back(word);
        }
        return result;
    }
    string serialize(TreeNode* root) {
        string ans = "";
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans = ans + to_string(root->val) + ",";
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode * temp = q.front(); q.pop();
                if (temp->left) {
                    ans += to_string((temp->left)->val);
                    ans.push_back(',');
                    q.push(temp->left);
                } else {
                    ans += "null,";
                }
                if (temp->right) {
                    ans += to_string((temp->right)->val);
                    ans.push_back(',');
                    q.push(temp->right);
                } else {
                    ans += "null,";
                }
            }
        }
        return ans;
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> words = splitByComma(data);
        TreeNode* root = new TreeNode(stoi(words[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode * temp = q.front(); q.pop();
                if (words[i] != "null") {
                    TreeNode * new_node = new TreeNode(stoi(words[i]));
                    temp->left = new_node;
                    q.push(new_node);
                } 
                i++;
                if (i >= words.size()) return root;
                if (words[i] != "null") {
                    TreeNode * new_node = new TreeNode(stoi(words[i]));
                    temp->right = new_node;
                    q.push(new_node);
                } 
                i++;
                if (i >= words.size()) return root;
            }
        }        
        return root;
    }
};
