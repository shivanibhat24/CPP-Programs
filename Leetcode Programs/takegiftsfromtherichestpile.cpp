class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxi;
        for(int gift: gifts){
            maxi.push(gift);
        }

        for(int i=0; i<k; i++){
            int g= maxi.top();
            maxi.pop();
            int rem= floor(sqrt(g));
            maxi.push(rem);
        }
        long long ans=0;
        while(!maxi.empty()){
            ans+=maxi.top();
            maxi.pop();
        }
        return ans;
    }
};
