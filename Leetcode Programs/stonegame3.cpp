class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        int a = 0;
        int b = 0; 
        int c = 0; 
        for(int i = n-1 ; i>=0 ; i--){
            int result = INT_MIN;
            result = max(result,stones[i] - a);            
            if(i+2 <= n)
                result = max(result,stones[i] + stones[i+1] - b);
            if(i+3 <= n)
                result = max(result,stones[i] + stones[i+1] + stones[i+2] - c);
            c = b;
            b = a;
            a = result;
        }
        int diff = a;
        if(diff < 0) return "Bob";        
        if(diff > 0) return "Alice";        
        return "Tie";
    }
};
