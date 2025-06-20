class MyHashSet {
public:
unordered_set<int> st;
    MyHashSet() {
    }    
    void add(int key) {
        st.insert(key);
    }    
    void remove(int key) {
        st.erase(key);
    }    
    bool contains(int key) {
        if(st.find(key)!=st.end()){
            return true;
        }
        return false;
    }
};
