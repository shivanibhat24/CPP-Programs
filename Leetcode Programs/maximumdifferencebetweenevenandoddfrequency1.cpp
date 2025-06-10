class Solution {
public:
    int maxDifference(std::string s) {        
        std::vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        for (int freq : frequency) {
            if (freq > 0) { 
                if (freq % 2 == 0) {                
                    if (freq < minEven) {
                        minEven = freq;
                    }
                } else {                    
                    if (freq > maxOdd) {
                        maxOdd = freq;
                    }
                }
            }
        }        
        if (maxOdd == INT_MIN || minEven == INT_MAX) {
            return 0; 
        }
        return maxOdd - minEven;
    }
};
