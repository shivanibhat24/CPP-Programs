#include <ranges>
class MKAverage {
public:
    deque<int> q;
    map<int,int> m;
    int M,K;
    long total=0;
    MKAverage(int m, int k) {
        this->M=m;
        this->K=k;
    }
    void addElement(int num) {
        q.push_back(num);
        m[num]++;
        total+=num;
        if(q.size()>M){
            m[q.front()]--;
            if(m[q.front()]==0)
                m.erase(q.front());
            total-=q.front();
            q.pop_front();

        }
    }
    
    int calculateMKAverage() {
        if(q.size()<M)
            return -1;
        int j=K;
        int toRemove=0,toRemoveR=0;;
        for(auto  & [k, v]:m){
            if(j>v){
                toRemove+=k*v;
                j-=v;
                continue;
            }else{
                toRemove+=k*j;
                break;
            }

        }
        j=K;
        for (auto  & [k, v] : m | std::views::reverse){
           if(j>v){
                toRemoveR+=k*v;
                j-=v;
                continue;
            }else{
                toRemoveR+=k*j;
                break;
            }
        } 
        return (total - toRemove - toRemoveR) / (M-2*K);
    }
};
