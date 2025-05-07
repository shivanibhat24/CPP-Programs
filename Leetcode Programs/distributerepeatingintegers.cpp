class Solution {
public:
    bool bt(vector<int>& quantity, int customer, vector<int>& count){
        if(customer == quantity.size()) return true;
        for(int i = 0; i < count.size(); i++){
            if(count[i] >= quantity[customer]){
                count[i] -= quantity[customer];
                if(bt(quantity, customer + 1, count)) return true;
                count[i] += quantity[customer];
                while(1){
                    if(i < count.size()-1){
                        if(count[i] == count[i+1]) i++;
                        else break;
                    }
                    else return false;
                }
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity){
        unordered_map<int,int> temp;
        for(int v : nums) temp[v]++;
        vector<int> count; int t = 0,tmax = 0;
        for(auto& p : temp){
            count.push_back(p.second);
            t += p.second;
            tmax = max(tmax, p.second);
        }
        int f = 0, fmax = 0;
        for(int& v : quantity){
            f += v;
            fmax = max(fmax,v);
        }
        if(t < f || tmax < fmax) return false;
        sort(quantity.rbegin(),quantity.rend());
        return bt(quantity,0,count);
    }
};
