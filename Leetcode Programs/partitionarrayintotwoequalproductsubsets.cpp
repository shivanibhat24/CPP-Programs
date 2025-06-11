class Solution {
public:
  bool ok = false;
  vector<int> v;
  bool checkEqualPartitions(vector<int>& nums, long long target) {
    v = nums;
    helper(target, target, 0);
    return ok;      
  }
  void helper(long a, long b, int id){
    if(ok) return;
    if(id == v.size()){
      if(a == 1 && b == 1) ok = true;
      return;
    }
    if(a % v[id] == 0) helper(a/v[id], b, id+1);
    if(b % v[id] == 0) helper(b/v[id], a, id+1);
  }
};
