class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char t : tasks){
            freq[t - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int maxFreq = freq[25];
        int countmaxFreq = 1;
        for(int i = 24; i >= 0; i--){
            if(freq[i] == maxFreq){
                countmaxFreq++;
            }else{
                break;
            }
        }
        int partCount = maxFreq - 1;
        int partLength = (n + 1) - countmaxFreq;
        int emptySlots = partCount * partLength;
        int remainingTasks = tasks.size() - (maxFreq * countmaxFreq);
        int ideals = max(0, emptySlots - remainingTasks);
        return tasks.size() + ideals;
    }
};
