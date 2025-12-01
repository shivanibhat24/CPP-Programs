class FindSumPairs {
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;

    vector<int> nums1;
    vector<int> nums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for(int i : nums1) {
            m1[i]++;
        }

        for(int i : nums2) {
            m2[i]++;
        }
    }
    
    void add(int index, int val) {
        m2[nums2[index]]--;
        nums2[index] += val;
        m2[nums2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        for(const auto& i : m1) {
            int val2 = tot - i.first;

            if(m2.find(val2) != m2.end()) {
                count += (i.second * m2[val2]);
            }
        }

        return count;
    }
};
