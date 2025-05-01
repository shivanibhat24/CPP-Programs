class Skiplist {
public:
    unordered_map<int, int> mp;
    Skiplist() {        
    }    
    bool search(int target) {
        return mp.find(target) != mp.end();
    }    
    void add(int num) {
        mp[num]++;
    }    
    bool erase(int num) {
        if(mp.find(num) == mp.end()) return false;

        mp[num]--;
        if(mp[num] == 0) mp.erase(num);

        return true;
    }
};
