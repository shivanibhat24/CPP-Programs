class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int c=0;
        int p=0;
        for (int i=0;i<gas.size();i++){
            c+=gas[i];
            p+=cost[i];
        }
            if (c<p){
                return -1;
            }
        int cc=0;
        int start=0;
        for (int i=0;i<gas.size();i++){
            cc+=gas[i]-cost[i];
            if (cc<0){
                cc=0;
                start=i+1;
            }
        }
        return start;
        
        
    }
};
