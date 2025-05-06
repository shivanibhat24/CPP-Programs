class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for(auto clothes : machines)
            sum += clothes;        
        if(sum % (machines.size()) != 0)
            return -1;
        int req = sum/(machines.size());
        int right = 0;
        int ans = 0;
        for(int i=0; i<machines.size(); i++) {
            right = machines[i] + right - req;
            ans = max(ans, max(abs(right), machines[i]-req));
        }
        return ans;
    }
};
