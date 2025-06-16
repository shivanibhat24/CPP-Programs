class SnapshotArray {
public:
    vector<vector<pair<int,int>>>map;
    int snap_id = 0;
    SnapshotArray(int length) {
        map.resize(length);
    }    
    void set(int index, int val) {
        map[index].push_back({snap_id,val});
    }    
    int snap() {
        return snap_id++;
    }    
    int get(int index, int snap_id) {
        vector<pair<int,int>>&snapChanges = map[index];
        auto ub = upper_bound(snapChanges.begin(), snapChanges.end(),snap_id, [](int value, const pair<int,int>&p){ 
            return value<p.first;
        });
        if(ub==snapChanges.begin()) return 0;
        return prev(ub)->second;
    }
};
