class RangeFreqQuery {
public:
    unordered_map<int,vector<int>>index;

    RangeFreqQuery(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        for(int i=0;i<arr.size();i++){
            index[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {

        auto low=lower_bound(index[value].begin(),index[value].end(),left);
        auto upp=upper_bound(index[value].begin(),index[value].end(),right);

        return upp-low;
    }
};
