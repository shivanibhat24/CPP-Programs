class ATM {
public:
    vector<long long>denom;
    ATM() {
        denom.resize(5);
    }
    void deposit(vector<int> bN) {
        for(int i = 0; i < bN.size(); ++i){
            denom[i] = denom[i] + bN[i];
        }
    }    
    vector<int> withdraw(int amt) {
        int q500 = min((long long)(amt / 500), denom[4]);
        amt -= q500 * 500;
        int q200 = min((long long)(amt / 200), denom[3]);
        amt -= q200 * 200;
        int q100 = min((long long)(amt / 100), denom[2]);
        amt -= q100 * 100;
        int q50 = min((long long)(amt / 50), denom[1]);
        amt -= q50 * 50;
        int q20 = min((long long)(amt / 20), denom[0]);
        amt -= q20 * 20;
        if (amt != 0) return {-1};  
        denom[4] -= q500;
        denom[3] -= q200;
        denom[2] -= q100;
        denom[1] -= q50;
        denom[0] -= q20;
        return {q20, q50, q100, q200, q500};
    }
};
