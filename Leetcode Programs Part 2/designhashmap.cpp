class MyHashMap {
public:
    int m_size = 679;
    vector<vector<pair<int, int>>> m_buckets;
    MyHashMap() {
        m_buckets.resize(m_size);
    }    
    void put(int key, int value) {
        int idx = key%m_size;
        for(int i=0;i<m_buckets[idx].size();i++)
        {
            if(m_buckets[idx][i].first == key)
            {
                m_buckets[idx][i].second = value;
                return;
            }
        }
        m_buckets[idx].push_back(pair(key,value));
    }    
    int get(int key) {
        int idx = key%m_size;
        for(int i=0;i<m_buckets[idx].size();i++)
        {
            if(m_buckets[idx][i].first == key)
            {
                return m_buckets[idx][i].second;
            }
        }
        return -1;
    }    
    void remove(int key) {
        int idx = key%m_size;
        for(int i=0;i<m_buckets[idx].size();i++)
        {
            if(m_buckets[idx][i].first == key)
            {
                m_buckets[idx].erase(m_buckets[idx].begin() + i);
            }
        }
    }
};
