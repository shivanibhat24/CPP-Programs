class RandomizedCollection {
public:
    unordered_map<int, vector<int>> umap;
    vector<int> num;
    RandomizedCollection() {}

    bool insert(int val) {
        if (umap.find(val) == umap.end()) {
            num.push_back(val);
            umap[val].push_back(num.size() - 1);
            return true;
        } else {
            num.push_back(val);
            umap[val].push_back(num.size() - 1);
            return false;
        }
    }

    bool remove(int val) {
        if (umap.find(val) == umap.end()) {
            return false;
        } else {
            auto &indices = umap[val];
            int index = indices.back();
            indices.pop_back();

            int last = num.back();
            num[index] = last;

            auto &temp = umap[last];
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]==num.size()-1)
                {
                    temp[i]=index;
                    break;
                }
            }
            if (indices.size() == 0)
                umap.erase(val);
            num.pop_back();
            return true;
        }
    }

    int getRandom() {
        if(num.size()==0)
        {
            return 0;
        }
        int number = rand() % num.size();
        return num[number];
    }
};
