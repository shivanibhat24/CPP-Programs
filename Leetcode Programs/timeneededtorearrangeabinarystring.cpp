class Solution {
public:    
    void resolve(string &s, int &time){
        int currfr = 0;
                for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
                currfr++;
                s[i] = '1';
                s[i+1] = '0';
                i++;
            }    
        }        
        if(currfr==0){
            return;
        }        
        else{
            time++;
            resolve(s,time);
        }
    }    
    int secondsToRemoveOccurrences(string s) { 
        int zeros = 0, waitingTime = 0;
        int n = s.size();
        int lastOcc = -1;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                lastOcc=i;
            }
        }
        for(int i=0;i<=lastOcc;i++){

            if(i>0 and s[i]=='1' and s[i-1]=='1' and zeros > 0){
                waitingTime++;
            }
            else if(i>0 and s[i]=='0' and s[i-1]=='0' and waitingTime > 0){
                waitingTime--;
            }

            if(s[i]=='0'){
                zeros++;
            }
        }
        return zeros + waitingTime;
    }
};
