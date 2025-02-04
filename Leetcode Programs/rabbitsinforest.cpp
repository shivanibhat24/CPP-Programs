class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int, int> m;
        int ans = 0;
        for(auto ele: arr) m[ele]++;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]==0) ans++;
            else if(m[arr[i]] > 0){
                ans += 1+arr[i];
                m[arr[i]]-=(arr[i]+1);
            }
        }
        return ans;
    }
};
