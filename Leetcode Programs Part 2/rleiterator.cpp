class RLEIterator {
public:
    vector<int>encoding;
    int i;
    RLEIterator(vector<int>& encoding) {
        this->encoding=encoding;
        i=0;
    }    
    int next(int n) {
        if(i>=encoding.size())
           return -1;
        int last=-1;   
        while(n>0 && i<encoding.size()) 
        {
            int val=encoding[i+1],count=encoding[i];
            if(count<=n)
               i+=2;
            else
               encoding[i]-=n;
            n-=count;
            last=val;   
        }
        if(n<=0)
           return last;
        return -1;   
    }
};
