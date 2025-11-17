class Solution {
public:
    int CompGCD(int a,int b){
        int n=a%b;
        if (n==0){
            return  b;
        }
        else{
            return CompGCD(b,n);
        }
    }
        long long countPairs(vector<int>& nums, int k) {
            unordered_map<int,long long>m;
            for(int num:nums){
                int gcd=CompGCD(k,num);
                m[gcd]++;
            }
            long long ans=0;
            for(auto it1=m.begin();it1!=m.end();it1++){
                for(auto it2=m.begin();it2!=m.end();it2++){
                    if((1LL*it1->first*it2->first)%k==0){
                        if(it1->first==it2->first){
                            ans+=(1LL*it1->second*(it2->second-1));
                    }
                    else{
                        ans+=(1LL*it1->second*it2->second);
                    }
                }
            }
            }
            return ans/2;
        }    
};
